#ifndef SLICEPIEWIDGET_H
#define SLICEPIEWIDGET_H
#include <QPainter>
#include <QMessageBox>
#include <QWidget>
using namespace std ;

class  slicepiewidget : public QWidget
{
    Q_OBJECT
public:
    explicit  slicepiewidget(QWidget *parent = 0);
void insert_values(int, double, double, double, double,double);
void insert_values(int,double,double,double,double);
void insert_values(int,double,double,double);
void insert_values(int,double,double);
protected:
    void paintEvent(QPaintEvent *);
    int variables_number;
    double red,blue,green,yellow,black ;


};




#endif // SLICEPIEWIDGET_H
