#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include<QWidget>
#include<QPaintEvent>
#include<QPainter>
class statistique:public QWidget
{
public:
   explicit statistique(QWidget*parent=0);
       void insert_values(double first_var, double second_var);
protected:
    void paintEvent(QPaintEvent *);
    double first_var;
    double second_var;







};

#endif // STATISTIQUE_H
