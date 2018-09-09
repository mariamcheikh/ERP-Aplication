#include "statfinanace.h"
#include<QPainter>
statfinanace::statfinanace(QWidget *parent) : QWidget(parent)
{

}

statfinanace::statfinanace()
{

}
statfinanace::~statfinanace()
{

}
void statfinanace::set_data(vector<double>tab_amount ,vector<int> tab_id,vector<QString > tab_nom)
{
   this->tab_nom=tab_nom;
   this-> tab_amount= tab_amount;
   this->tab_id =tab_id;
    repaint();
    update();
}

void statfinanace::paintEvent(QPaintEvent *)
{


  // vector<double>::iterator amount;



   QPainter painter(this);
   QPen pen;
   QRectF size,name;
   pen.setColor(Qt::black);
   pen.setWidth(2);
   painter.setPen(pen);
   if(this->height() > this->width())
   {
       size=QRectF(5,5,this->width()-10,this->width()-10);
   }
   else
   {
       size=QRectF(5,5,this->height()-10,this->height()-10);
   }

   double sum =0.0,startangle=0.0;
   double angle=0.0,endangle=0.0,percent=0.0;


   for(unsigned int i=0;i<tab_amount.size();i++)
   {


       sum+=tab_amount[i];

   }
   for(unsigned int i=0;i<tab_amount.size();i++)
   {

qDebug()<< startangle;

       percent=tab_amount[i]/sum;

qDebug()<<percent;
       angle=percent*360.0;
       qDebug()<<angle;
       endangle=startangle+angle;
qDebug()<<endangle;
       switch (i%4) {
       case 0:
           painter.setBrush(Qt::blue);
           break;
       case 1:
           painter.setBrush(Qt::red);

           break;
       case 2:
           painter.setBrush(Qt::yellow);

           break;
       case 3:
           painter.setBrush(Qt::green);

           break;
       }

       painter.drawPie(size,startangle*16,angle*16);
       startangle = endangle;



   }


}





