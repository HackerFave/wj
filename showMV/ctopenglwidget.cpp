//#include "ctopenglwidget.h"

//ctopenglwidget::ctopenglwidget()
//{

//}

#include "ctopenglwidget.h"
#include <QPainter>
#include "commondef.h"

ctOpenglWidget::ctOpenglWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

ctOpenglWidget::~ctOpenglWidget()
{
}

void ctOpenglWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter;

    painter.begin(this);//清理屏幕
    painter.drawImage(QPoint(0, 0), m_image);//绘制FFMpeg解码后的视频
    painter.end();
}

void ctOpenglWidget::slot_showImage(const QImage &image)
{
    if(image.width() > image.height())
        m_image = image.scaledToWidth(width(),Qt::SmoothTransformation);
    else
        m_image = image.scaledToHeight(height(),Qt::SmoothTransformation);

    update();
}

