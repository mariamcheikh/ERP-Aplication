#ifndef SHIFT_H
#define SHIFT_H
#include<QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
#include <QTime>
#include <inputcontrol.h>
#include <QSqlError>
using namespace std ;

class shift
{
public:
    /*---------------const/dest--------------*/
    shift();
    shift(QString type,QString day, QDate date ,int employee);
    shift(QString type,QString day,QDate date,QTime arrival_time,int employee,QString presence);
    ~shift();
    /*---------------data input methods -----------*/
    bool create_a_shift(int pos);
    bool edit_a_shift(int shift);
    bool archive_a_shift(int shift,QString mode);
    /*------------assigning methods--------*/
    bool this_employee_has_been_moved(int employee);
    /*---------pimp methods ----------*/
    bool this_employee_just_came_to_his_shift(int employee, QTime time);
    bool its_been_more_than_30_minutes_mark_all_employees_who_didnt_showup_absent();
    /*-----------check methods --------*/
    bool does_this_employee_have_a_shift_now();
    QString did_this_employee_show_up_today(int employee);
    /*--------- count methods ---------*/
    void count_places_left_for_this_week(QDate start_date,QDate end_date);
    /*------------ gets -----------------*/

           /*----morning ----*/
int Get_places_left_monday_morning(){return places_left_monday_morning;}
int Get_places_left_tuesday_morning(){return places_left_tuesday_morning;}
int Get_places_left_wednsday_morning(){return places_left_wednsday_morning;}
int Get_places_left_thursday_morning(){return places_left_thursday_morning;}
int Get_places_left_friday_morning(){return places_left_friday_morning;}
int Get_places_left_saturday_morning(){return places_left_saturday_morning;}
int Get_places_left_sunday_morning(){return places_left_sunday_morning;}
   /*------ after noon ----*/
int Get_places_left_monday_after_noon(){return places_left_monday_after_noon;}
int Get_places_left_tuesday_after_noon(){return places_left_tuesday_after_noon;}
int Get_places_left_wednsday_after_noon(){return places_left_wednsday_after_noon;}
int Get_places_left_thursday_after_noon(){return places_left_thursday_after_noon;}
int Get_places_left_friday_after_noon(){return places_left_friday_after_noon;}
int Get_places_left_saturday_after_noon(){return places_left_saturday_after_noon;}
int Get_places_left_sunday__after_noon(){return places_left_sunday__after_noon;}


private:
    int id_shift;
    QString type ;
    QString day ;
    QDate date ;
    QTime arrival_time ;
    int employee;
    QString presence ;
    /*---- counting containers ------*/
        /*----morning ----*/
    int places_left_monday_morning;
    int places_left_tuesday_morning;
    int places_left_wednsday_morning;
    int places_left_thursday_morning;
    int places_left_friday_morning;
    int places_left_saturday_morning;
    int places_left_sunday_morning;
       /*------ after noon ----*/
    int places_left_monday_after_noon;
    int places_left_tuesday_after_noon;
    int places_left_wednsday_after_noon;
    int places_left_thursday_after_noon;
    int places_left_friday_after_noon;
    int places_left_saturday_after_noon;
    int places_left_sunday__after_noon;


};

#endif // SHIFT_H
