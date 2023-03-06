#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H


//class OpenGLWidget : public QOpenGLWidget
//{
//public:
//    OpenGLWidget();
//};


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
/************车道线***谭创****/
#include <QGL>
#include <QGLFormat>
#include <QSurfaceFormat>
#include  <qmath.h>
#include <vector>
#include <QPoint>
/************车道线***谭创****/
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)
QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)

class TGFrame;

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget *parent =0);
    ~OpenGLWidget();

    void     startPlay(QString &url);
    void     stopPlay();
    void     setShadowType(int);
    /*******************车道线*****************谭创******/

    /********************************车道线*******************/
public slots:

    void syncUpdateYUV(const uchar *Yplane,
                       const uchar *Uplane,
                       const uchar *Vplane,
                       uint width,uint height);
    void asyncUpdateUi();
//    void asyncUpdateUi(QPixmap img);
    void reconnect();

signals:

    void sglResize(int w,int h);
    void signalPixmap(QPixmap img);

protected:

    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w,int h) Q_DECL_OVERRIDE;

private:

    void initCoordinate();
    void initShader();
    void initTexture();
    void copyTexture();
    void updateRender();

private:

    TGFrame*       m_pFrame;
    QString        m_playUrl;
    bool           m_isPlay ;
    bool           m_isWaitingReconn;
    QOpenGLBuffer m_vertexTexture;

    GLuint m_pTextureUniformY;
    GLuint m_pTextureUniformU;
    GLuint m_pTextureUniformV; //Shader程序接口

    QOpenGLTexture *m_pTextureY = nullptr;
    QOpenGLTexture *m_pTextureU = nullptr;
    QOpenGLTexture *m_pTextureV = nullptr;

    GLuint m_width = 0;
    GLuint m_height = 0;

    std::unique_ptr<GLubyte,void(*)(void*)> m_pYData;
    std::unique_ptr<GLubyte,void(*)(void*)> m_pUData;
    std::unique_ptr<GLubyte,void(*)(void*)> m_pVData;

};



#endif // OpenGLWidget_H
