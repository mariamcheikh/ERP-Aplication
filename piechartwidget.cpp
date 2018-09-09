#include "piechartwidget.h"

PieChartWidget::PieChartWidget(QWidget *parent) :QWidget(parent)
   {
   red=0 ;
  blue=0 ;
 green=0 ;
yellow=0 ;
 black=0 ;
}
void PieChartWidget::insert_values(int variables_number,double red, double blue , double green, double yellow, double black)
{this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->yellow=yellow;
    this->black=black;


}
void PieChartWidget::insert_values(int variables_number,double red, double blue, double green, double yellow)
{this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->yellow=yellow;
    this->black=0;
}
void PieChartWidget::insert_values(int variables_number,double red,double blue,double green)
{
    this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->yellow=0;
    this->black=0;
}
void PieChartWidget::insert_values(int variables_number,double red,double blue)
{
    this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=0;

}
void PieChartWidget::paintEvent(QPaintEvent * )
{
if(variables_number==2)
{

    double  a = red+blue;
    double p1 = ((((red*100)/a)*360)/100)*16;
    double p2 = ((((blue*100)/a)*360)/100)*16;
    QPainter painter(this);

        QRectF size = QRectF(10,10,this->width()-20,this->width()-20);
        painter.setBrush(Qt::red);
        painter.drawPie(size,0,p1);
        painter.setBrush(Qt::blue);
        painter.drawPie(size,p1,p2);
}
else if(variables_number==3)
{

    double  a = red+blue+green;
    double p1 = ((((red*100)/a)*360)/100)*16;
    double p2 = ((((blue*100)/a)*360)/100)*16;
    double p3 = ((((green*100)/a)*360)/100)*16;
    QPainter painter(this);

        QRectF size = QRectF(10,10,this->width()-20,this->width()-20);
        painter.setBrush(Qt::red);
        painter.drawPie(size,0,p1);
        painter.setBrush(Qt::blue);
        painter.drawPie(size,p1,p2);
        painter.setBrush(Qt::green);
        painter.drawPie(size,p1+p2,p3);
}
else if(variables_number==4)
{

    double  a = red+green+blue+yellow ;
    double p1 = ((((red*100)/a)*360)/100)*16;
    double p2 = ((((blue*100)/a)*360)/100)*16;
    double p3 = ((((green*100)/a)*360)/100)*16;
    double p4 = ((((yellow*100)/a)*360)/100)*16;




    QPainter painter(this);

    QRectF size = QRectF(10,10,this->width()-20,this->width()-20);
    painter.setBrush(Qt::red);
    painter.drawPie(size,0,p1);
    painter.setBrush(Qt::blue);
    painter.drawPie(size,p1,p2);
    painter.setBrush(Qt::green);
    painter.drawPie(size,p2+p1,p3);
    painter.setBrush(Qt::yellow);
    painter.drawPie(size,p3+p2+p1,p4);
}
else if(variables_number==5)
    {

        double  a = red+green+blue+yellow+black ;
        double p1 = ((((red*100)/a)*360)/100)*16;
        double p2 = ((((blue*100)/a)*360)/100)*16;
        double p3 = ((((green*100)/a)*360)/100)*16;
        double p4 = ((((yellow*100)/a)*360)/100)*16;
        double p5 = ((((black*100)/a)*360)/100)*16;




        QPainter painter(this);
        QRectF size = QRectF(10,10,this->width()-20,this->width()-20);
        painter.setBrush(Qt::red);
        painter.drawPie(size,0,p1);
        painter.setBrush(Qt::blue);
        painter.drawPie(size,p1,p2);
        painter.setBrush(Qt::green);
        painter.drawPie(size,p2+p1,p3);
        painter.setBrush(Qt::yellow);
        painter.drawPie(size,p3+p2+p1,p4);
        painter.setBrush(Qt::black);
        painter.drawPie(size,p4+p3+p2+p1,p5);
    }
}



