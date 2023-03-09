#include "TGFrame.h"
#include <QPainter>
#include <QDebug>

TGFrame::TGFrame(QWidget *parent,TGFrameType type) : QWidget(parent),
    m_titleStr(QLatin1String("")),
    m_isShowTitle(false)
{
    setFrameType(type);
}

void TGFrame::setTitleString(QString str)
{
    m_titleStr = str;
    m_isShowTitle = true;
    this->update();
}

void TGFrame::setFrameType(TGFrameType type)
{
    m_frameType = type;
    if(m_frameType < Tip){
        m_frameImage.load(QString(QLatin1String(":/resource/frame/tgframe_%1.png"))
                          .arg(static_cast<int>(m_frameType)));
        this->update();
    }
}

TGFrame::TGFrameType TGFrame::frameType()
{
    return m_frameType;
}

void TGFrame::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::LosslessImageRendering);

    if(m_frameType < VideoFrame){
        drawInfoFrame(painter);
    }else if(m_frameType < Tip){
        drawFrame(painter);
    }else if(m_frameType < None){
        drawTip(painter);
    }
//    painter.translate(width()/2, height()/2);
//    qreal side = qMin(width()/WIDTH, height()/HEIGHT);

    painter.end();
}

void TGFrame::drawInfoFrame(QPainter &painter)
{
    painter.drawPixmap(this->rect(),m_frameImage,m_frameImage.rect());
    if(m_isShowTitle){
        painter.setPen(Qt::white);
        QFont font = painter.font();
        font.setPixelSize(20);
        painter.setFont(font);
        QPoint point(25,28);
        painter.drawText(point,m_titleStr);

        point += QPoint(0,10);
        painter.setPen(QPen(QColor(0xfa, 0x5a, 0x00),2));
        QLine line(point,point + QPoint(100,0));
        painter.drawLine(line);
    }
}

void TGFrame::drawFrame(QPainter &painter)
{
    painter.drawPixmap(this->rect(),m_frameImage,m_frameImage.rect());
}

void TGFrame::drawTip(QPainter &painter)
{
    painter.setPen(QPen(QColor(0x00, 0xba, 0xff),2));
    painter.setBrush(QColor(0x00, 0xba, 0xff,0x33));
    painter.drawRect(this->rect());

    painter.setBrush(QColor(0x00, 0xba, 0xff));
    int offset = qMin(width()/20.0, height()/5.0);

    QPolygon points;
    QPoint  point(0,0);
    points.append(point);
    points.append(point+QPoint(offset,0));
    points.append(point+QPoint(0,offset));
    painter.drawConvexPolygon(points);

    points.clear();
    point = QPoint(width(),0);
    points.append(point);
    points.append(point-QPoint(offset,0));
    points.append(point+QPoint(0,offset));
    painter.drawConvexPolygon(points);

    points.clear();
    point = QPoint(0,height());
    points.append(point);
    points.append(point+QPoint(offset,0));
    points.append(point-QPoint(0,offset));
    painter.drawConvexPolygon(points);

    points.clear();
    point = QPoint(width(),height());
    points.append(point);
    points.append(point-QPoint(offset,0));
    points.append(point-QPoint(0,offset));
    painter.drawConvexPolygon(points);

    painter.translate(width()/2, height()/2);

    painter.setPen(Qt::white);
    QFont font = painter.font();
    font.setPixelSize(20);
    painter.setFont(font);
    int size = 1;
    for(auto str : m_titleStr){
        ushort uni = str.unicode();
        if(uni >= 0x4E00 && uni <= 0x9FA5){
            size += 2;
        }else{
            size += 1;
        }
    }

    if(size > 0){
        point = QPoint(-5*size,5);
        painter.drawText(point,m_titleStr);

        point += QPoint(0,10);
        painter.setPen(QPen(QColor(0xfa, 0x5a, 0x00),2));
//        QLine line(point,point + QPoint(4*20,0));
//        painter.drawLine(line);

//        painter.setPen(QPen(QColor(0,0x1d,0x33),2));
//        line.setP1(point + QPoint(4*20,0));
//        line.setP2(point + QPoint(size*10,0));
//        painter.drawLine(line);
    }
}


