//#ifndef CTOPENGLWIDGET_H
//#define CTOPENGLWIDGET_H


//class ctopenglwidget : public QOpenGLWidget
//{
//public:
//    ctopenglwidget();
//};

//#endif // CTOPENGLWIDGET_H

#ifndef CTOPENGLWIDGET_H
#define CTOPENGLWIDGET_H

#include <QOpenGLWidget>

class ctOpenglWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    ctOpenglWidget(QWidget *parent = nullptr);
    ~ctOpenglWidget();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void slot_showImage(const QImage& image);

private:
    QImage m_image;

};

#endif // CTOPENGLWIDGET_H

