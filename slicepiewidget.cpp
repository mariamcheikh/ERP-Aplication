#include "slicepiewidget.h"



slicepiewidget::slicepiewidget(QWidget *parent) :QWidget(parent)
   {
   red=0 ;
  blue=0 ;
 green=0 ;
yellow=0 ;
 black=0 ;
}
void slicepiewidget::insert_values(int variables_number,double red, double blue , double green, double yellow, double black)
{this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->yellow=yellow;
    this->black=black;


}
void slicepiewidget::insert_values(int variables_number,double red, double blue, double green, double yellow)
{
    this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->yellow=yellow;
    this->black=0;
}
void slicepiewidget::insert_values(int variables_number,double red,double blue,double green)
{
    this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=green;
    this->yellow=0;
    this->black=0;
}
void slicepiewidget::insert_values(int variables_number,double red,double blue)
{
    this->variables_number=variables_number;
    this->red=red;
    this->blue=blue;
    this->green=0;

}
void slicepiewidget::paintEvent(QPaintEvent * )
{/*
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
    }*/

    QPainter painter(this);

 //   QRectF size = QRectF(40,10,this->width()-80,this->height()-80);
    QRectF size2 = QRectF(0,30,this->width()-80,this->height()-80);
    painter.setBrush(Qt::black);
   painter.drawChord(size2,0,45*16);
   painter.setBrush(Qt::blue);
   painter.drawArc(size2,45*16,90*16);

  /*  painter.setBrush(Qt::red);
    painter.drawPie(size,0,45*16);
    painter.setBrush(Qt::blue);
    painter.drawPie(size,45*16,20*16);
    painter.setBrush(Qt::green);
    painter.drawPie(size,65*16,25*16);
    painter.setBrush(Qt::yellow);
    painter.drawPie(size2,90*16,120*16);
    painter.setBrush(Qt::black);
    painter.drawPie(size2,210*16,150*16);*/
}



