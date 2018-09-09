#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H
#include <QPainter>
#include <QMessageBox>
#include <QWidget>

using namespace std ;

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = 0);
void insert_values(int, double, double, double, double,double);
void insert_values(int,double,double,double,double);
void insert_values(int,double,double,double);
void insert_values(int,double,double);
protected:
    void paintEvent(QPaintEvent *);
    int variables_number;

    double red,blue,green,yellow,black ;







};
#endif // PIECHARTWIDGET_H
