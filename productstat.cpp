#include "productstat.h"

ProductStat::ProductStat(QWidget *parent) : QWidget(parent)
{

}

ProductStat :: ProductStat (int a)
{
    this->a=a;
}
void ProductStat::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size= QRectF (10,10,400,400);
    painter.setBrush(Qt::blue);
    QString r1="SELECT * FROM product";
    QString r2="SELECT * FROM product where gender ='Female'";
    QString r3="SELECT * FROM product where gender ='Male'";


    QSqlQuery q1,q2,q3;
    QString n;
    q1.exec(r1);
    q2.exec(r2);
    q3.exec(r3);



    int tot=0,male=0,female=0,rfn=0;
    while ( q1.next() )
       {
            tot++;
       }
    while ( q2.next() )
       {
            female++;
       }
    while ( q3.next() )
       {
            male++;
       }

    male=(((male*100)/tot)*360)/100;
    female=(((female*100)/tot)*360)/100;
    //other=(((other*100)/tot)*360)/100;
    rfn=360-(male+female);

    painter.drawPie(size ,0,male*16);
    painter.setBrush(Qt::green);
    painter.drawPie(size ,male*16,female*16);
    painter.setBrush(Qt::blue);
    painter.drawPie(size ,male*16+female*16,rfn*16);
  /*  painter.setBrush(Qt::red);
    painter.drawPie(size ,male*16+female*16+other*16,rfn*16);*/




}
