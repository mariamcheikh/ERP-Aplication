#ifndef AGEPYRAMIDWIDGET_H
#define AGEPYRAMIDWIDGET_H

#include <QWidget>
#include <QPainter>

class agepyramidwidget:public QWidget
{
    Q_OBJECT
public:
    explicit agepyramidwidget(QWidget *parent = 0);
    ~agepyramidwidget();
    void set_left_values(double first,double second,double third,double fourth,double fifth);
    void set_right_values(double sixth,double seventh,double eigth,double nineth,double tenth);
    double get_max();
protected:
    void paintEvent(QPaintEvent *);

    double first,second,third,fourth,fifth,sixth,seventh,eigth,nineth,tenth;
    double distance_between_bars;
    double bar_width;
    double start_point_x;
    double start_point_y;
    double left_side_limit;
    double right_side_limit;





};

#endif // AGEPYRAMIDWIDGET_H
