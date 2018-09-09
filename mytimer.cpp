#include "mytimer.h"


Mytimer::Mytimer()
{

}
Mytimer::Mytimer(int id, QString pass, int time_limit)
{
    this->id=id;
    this->password=pass;
    this->time_limit=time_limit;
    this->progress_time=0;
}
 void Mytimer::lets_go()
{

     current_p=QCursor::pos();


    timer =new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT (timed_out()));//boucle repetitive chaque 1000 ms(1 seconde )
    timer->start(1000);
 }
 void Mytimer::unleash_the_dog()
{
    timer_2 =new QTimer(this);
    connect(timer_2,SIGNAL(timeout()),this,SLOT (check_out()));//boucle repetitive chaque 1000 ms(1 seconde )
    timer_2->start(1000);
 }
 void Mytimer::check_out()
 {

 }

 void Mytimer::timed_out()
 {QPoint pos=QCursor::pos();



             if(current_p!=pos){current_p=pos;progress_time=0;}// if our user is in action then timer resets
             else {if(progress_time<time_limit){progress_time++;}// else if timer still hasn't reachec the time limit it keeps counting untill it reaches the end or a movement occurs
                 else if(progress_time>=time_limit){progress_time=0;// when progress time reaches the limit the pop up window will occure
log=new quicklog();
log->set_session(id,password,time_limit);
log->setFixedSize(340,200);
log->exec();



                    }
                  ;}
 }
