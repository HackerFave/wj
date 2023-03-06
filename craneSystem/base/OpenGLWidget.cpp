#include "OpenGLWidget.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QApplication>
#include <QDebug>
#include <QTimer>
#include <cstring>

#include "TGFrame.h"
#include "StreamThread.h"

#define  VERTEXIN       0
#define  TEXTUREIN      1


OpenGLWidget::OpenGLWidget(QWidget *parent):
    QOpenGLWidget(parent),
    m_isPlay(false),
    m_isWaitingReconn(false),
    m_pYData(nullptr,free),
    m_pUData(nullptr,free),
    m_pVData(nullptr,free)
{
    m_pFrame = new TGFrame(this);
    m_pFrame->move(0,0);
}

OpenGLWidget::~OpenGLWidget()
{
    this->makeCurrent();
    m_vertexTexture.destroy();
    m_pTextureY->destroy();
    m_pTextureU->destroy();
    m_pTextureV->destroy();
    this->doneCurrent();
    delete m_pTextureY;
    delete m_pTextureU;
    delete m_pTextureV;
}

void OpenGLWidget::startPlay(QString &url)
{
    if(m_isPlay && m_playUrl == url){
        qInfo() << "m_isPlay :" << m_isPlay << "m_playUrl == url";
        return;
    }
    stopPlay();
    m_playUrl = url;

    if(url.isEmpty()){
        return;
    }
    m_isPlay = true;
    StreamThread *pStreaming = new StreamThread();
    QMetaObject::Connection conn(connect(pStreaming, SIGNAL(sglFinished()), this, SLOT(reconnect())));
    connect(pStreaming, SIGNAL(sglSyncUpdateYUV(const uchar*,const uchar*,const uchar*,uint,uint)),
                    this,SLOT(syncUpdateYUV(const uchar*,const uchar*,const uchar*,uint,uint)),Qt::DirectConnection);
    connect(pStreaming, SIGNAL(sglAsyncUpdateUi()), this, SLOT(asyncUpdateUi()),Qt::QueuedConnection);
    connect(this, SIGNAL(sglResize(int,int)), pStreaming, SLOT(outputResize(int,int)),Qt::DirectConnection);
    pStreaming->setParameter(url,conn,this->width(),this->height());
    pStreaming->startThread();
}

void OpenGLWidget::stopPlay()
{
    if(m_isPlay){
        m_isPlay = false;
        m_isWaitingReconn = false;
        emit sglResize(0,0); //发送窗口大小为0信号，播放停止。
        this->update();
        QApplication::sync();
    }
}

void OpenGLWidget::syncUpdateYUV(const uchar *Yplane,
                                const uchar *Uplane,
                                const uchar *Vplane,
                                uint width,uint height)
{
    if(m_width != width || m_height != height ){
        m_width = width;
        m_height = height;
        m_pYData = std::unique_ptr<GLubyte,void(*)(void*)>{
            static_cast<GLubyte*>(malloc(sizeof(GLubyte)*m_width*m_height)),free
        };

        m_pUData = std::unique_ptr<GLubyte,void(*)(void*)>{
            static_cast<GLubyte*>(malloc(sizeof(GLubyte)*m_width*m_height/4)),free
        };

        m_pVData = std::unique_ptr<GLubyte,void(*)(void*)>{
            static_cast<GLubyte*>(malloc(sizeof(GLubyte)*m_width*m_height/4)),free
        };
    }
    std::memcpy(m_pYData.get(),Yplane,m_width*m_height);
    std::memcpy(m_pUData.get(),Uplane,m_width*m_height/4);
    std::memcpy(m_pVData.get(),Vplane,m_width*m_height/4);
}

void OpenGLWidget::reconnect()
{
    qInfo() << "OpenGLWidget::reconnect()";
    m_isWaitingReconn = true;
    QTimer::singleShot(2000,Qt::VeryCoarseTimer,this,[this](){
        if(this->m_isWaitingReconn){
            this->m_isWaitingReconn = false;
            this->stopPlay();
            this->startPlay(m_playUrl);
        }
    });
}

void OpenGLWidget::setShadowType(int type)
{
    m_pFrame->setFrameType(static_cast<TGFrame::TGFrameType>(type));
}

void OpenGLWidget::asyncUpdateUi()
{
    this->update();
}


void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

    initCoordinate();
    initShader();
    initTexture();

    glClearColor(0,0,0,0);
}

void OpenGLWidget::paintGL()
{
    if(m_isPlay && m_width != 0){
        copyTexture();
        updateRender();
    }else{
        glClearColor(0,0,0,0);
    }
}

void OpenGLWidget::resizeGL(int w,int h)
{
    m_pFrame->resize(w,h);
    if(m_isPlay){
        emit sglResize(w,h);
    }
}

void OpenGLWidget::initCoordinate()
{
    static const GLfloat coordinates[]{
        //顶点坐标
        -1.0f,-1.0f,
        -1.0f,+1.0f,
        +1.0f,+1.0f,
        +1.0f,-1.0f,
        //纹理坐标
        0.0f,1.0f,
        0.0f,0.0f,
        1.0f,0.0f,
        1.0f,1.0f,
    };

    m_vertexTexture.create();
    m_vertexTexture.bind();
    m_vertexTexture.allocate(coordinates,sizeof(coordinates));
}

void OpenGLWidget::initShader()
{
    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex,this);
    const char *vsrc =
   "attribute vec4 vertexIn;    \
    attribute vec2 textureIn;   \
    varying vec2 textureOut;    \
    void main(void)             \
    {                           \
        gl_Position = vertexIn; \
        textureOut = textureIn; \
    }";
    vshader->compileSourceCode(vsrc);

    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment,this);
    const char *fsrc = "varying vec2 textureOut; \
    uniform sampler2D tex_y; \
    uniform sampler2D tex_u; \
    uniform sampler2D tex_v; \
    void main(void) \
    { \
        vec3 yuv; \
        vec3 rgb; \
        yuv.x = texture2D(tex_y, textureOut).r; \
        yuv.y = texture2D(tex_u, textureOut).r - 0.5; \
        yuv.z = texture2D(tex_v, textureOut).r - 0.5; \
        rgb = mat3( 1,       1,         1, \
                    0,       -0.39465,  2.03211, \
                    1.13983, -0.58060,  0) * yuv; \
        gl_FragColor = vec4(rgb, 1); \
    }";
    fshader->compileSourceCode(fsrc);

    QOpenGLShaderProgram *pShaderProgram = new QOpenGLShaderProgram(this);
    pShaderProgram->addShader(vshader);
    pShaderProgram->addShader(fshader);
    pShaderProgram->bindAttributeLocation("vertexIn",VERTEXIN);
    pShaderProgram->bindAttributeLocation("textureIn",TEXTUREIN);
    pShaderProgram->link();
    pShaderProgram->bind();
    pShaderProgram->enableAttributeArray(VERTEXIN);
    pShaderProgram->enableAttributeArray(TEXTUREIN);
    pShaderProgram->setAttributeBuffer(VERTEXIN,GL_FLOAT,0,2,2*sizeof(GLfloat));
    pShaderProgram->setAttributeBuffer(TEXTUREIN,GL_FLOAT,8*sizeof(GLfloat),2,2*sizeof(GLfloat));

    m_pTextureUniformY = pShaderProgram->uniformLocation("tex_y");
    m_pTextureUniformU = pShaderProgram->uniformLocation("tex_u");
    m_pTextureUniformV = pShaderProgram->uniformLocation("tex_v");
}

void OpenGLWidget::initTexture()
{
    m_pTextureY = new QOpenGLTexture(QOpenGLTexture::Target2D);
    m_pTextureU = new QOpenGLTexture(QOpenGLTexture::Target2D);
    m_pTextureV = new QOpenGLTexture(QOpenGLTexture::Target2D);
    m_pTextureY->create();
    m_pTextureU->create();
    m_pTextureV->create();

    glBindTexture(GL_TEXTURE_2D,m_pTextureY->textureId()); //绑定y分量纹理对象id到激活的纹理单元
    //设置纹理参数
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_2D,m_pTextureU->textureId()); //绑定U分量纹理对象id到激活的纹理单元
    //设置纹理参数
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_2D,m_pTextureV->textureId()); //绑定V分量纹理对象id到激活的纹理单元
    //设置纹理参数
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

}

void OpenGLWidget::copyTexture()
{
    glActiveTexture(GL_TEXTURE0);  //激活纹理单元GL_TEXTURE0
    glBindTexture(GL_TEXTURE_2D,m_pTextureY->textureId()); //绑定y分量纹理对象id到激活的纹理单元
    //拷贝Y分量纹理数据到纹理单元
    glTexImage2D(GL_TEXTURE_2D,0,GL_RED,m_width,m_height,0,GL_RED,GL_UNSIGNED_BYTE,m_pYData.get());
    //指定y纹理要使用新值
    glUniform1i(m_pTextureUniformY, 0);

    glActiveTexture(GL_TEXTURE1); //激活纹理单元GL_TEXTURE1
    glBindTexture(GL_TEXTURE_2D,m_pTextureU->textureId()); //绑定U分量纹理对象id到激活的纹理单元
    //拷贝U分量纹理数据到纹理单元
    glTexImage2D(GL_TEXTURE_2D,0,GL_RED,m_width >> 1, m_height >> 1,0,GL_RED,GL_UNSIGNED_BYTE,m_pUData.get());
    //指定u纹理要使用新值
    glUniform1i(m_pTextureUniformU, 1);


    glActiveTexture(GL_TEXTURE2); //激活纹理单元GL_TEXTURE2
    glBindTexture(GL_TEXTURE_2D,m_pTextureV->textureId());//绑定V分量纹理对象id到激活的纹理单元
    //拷贝V分量纹理数据到纹理单元
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_width >> 1, m_height >> 1, 0, GL_RED, GL_UNSIGNED_BYTE, m_pVData.get());
    //指定v纹理要使用新值
    glUniform1i(m_pTextureUniformV, 2);
}

void OpenGLWidget::updateRender()
{
    //使用顶点数组方式绘制图形
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
