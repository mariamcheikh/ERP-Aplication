#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include <QPoint>
#include <QObject>
#include <QtCore>
#include <QMessageBox>
#include "uiquicklog.h"
using namespace std ;
class Mytimer : public QObject
{
    Q_OBJECT
public:
    Mytimer();
    Mytimer(int id,QString pass,int time_limit);
    QTimer *timer ;
    QTimer *timer_2;
    void setactivity_time_limit(int t){time_limit=t;}


private:

    QPoint current_p;
    int progress_time;
    int time_limit;
    int id;
    QString password;
    quicklog *log ;








public slots:
    void timed_out();
     void lets_go();
     void unleash_the_dog();
     void check_out();


};
#endif // MYTIMER_H
