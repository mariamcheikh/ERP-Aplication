#include "statistique.h"

statistique::statistique(QWidget *parent):QWidget (parent)
{

}
void statistique:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    double a=first_var;
     first_var=first_var-second_var;
    double  p1=((((first_var*100)/a)*360)/100)*16;
    double  p2=((((second_var*100)/a)*360)/100)*16;

    painter.setBrush(Qt::red);
   painter.drawPie(this->rect(),0,p2);
    painter.setBrush(Qt::black);
    painter.drawPie(this->rect(),p2,p1);

}
void statistique::insert_values(double first_var, double second_var)
{
    this->first_var=first_var;
    this->second_var=second_var;
}
