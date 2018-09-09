#include "stats.h"*
#include <QPainter>


stats:: stats(QWidget *parent ):QWidget(parent)
{

}

void stats::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size = QRectF (10,10,this->height()-10, this->height()-10);
    painter.setBrush(Qt::black);
    painter.drawPie(size,0,90*16);
    painter.setBrush(Qt::red);
    painter.drawPie(size,90*16,270*16);
}

