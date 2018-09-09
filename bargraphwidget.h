#ifndef BARGRAPHWIDGET_H
#define BARGRAPHWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QMessageBox>


class bargraphwidget:public QWidget
{
    Q_OBJECT
public:
    explicit bargraphwidget(QWidget *parent = 0);
void insert_values(int,double,double);
void insert_values(int,double,double,double);
void insert_values(int,double,double,double,double);
void insert_values(int,double,double,double,double,double);
double get_max();
double Get_red_pos_x(){return red_pos_x;}
double Get_blue_pos_x(){return blue_pos_x;}
double Get_green_pos_x(){return green_pos_x;}
double Get_yellow_pos_x(){return yellow_pos_x;}
double Get_black_pos_x(){return black_pos_x;}
double Get_red_pos_y(){return red_pos_y;}
double Get_blue_pos_y(){return blue_pos_y;}
double Get_green_pos_y(){return green_pos_y;}
double Get_yellow_pos_y(){return yellow_pos_y;}
double Get_black_pos_y(){return black_pos_y;}
protected:
    void paintEvent(QPaintEvent *);
   int variables_number ;
   double first,second,third,fourth,fifth ;
   double distance_between_bars;
   double bar_width;
   double start_point_x;
   double start_point_y;
   double total;
   double red_pos_x,blue_pos_x,green_pos_x,yellow_pos_x,black_pos_x;
   double red_pos_y,blue_pos_y,green_pos_y,yellow_pos_y,black_pos_y;

};

#endif // BARGRAPHWIDGET_H
