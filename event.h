#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QDate>
#include "employee.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
#include <QDebug>
using namespace std;
class Event
{
protected:
    int ID_event;
    int ID_first_responsible;
    int ID_second_responsible;
    int ID_building;
    QString name;
    int state;
    QDate beginning_date;
    QDate ending_date;
    int nb_add_employees;
    QVector<int> add_employees;
    QVector<QString> tasks;


public:

    /*  constructeurs et destructeur : */

    Event();
    ~Event();
    Event(int ID_second_responsible , int ID_building, QString name, int state , QDate beginning_date, QDate ending_date, int nb_add_employees );


   /*  Méthodes : */
    bool Add_event();
    bool Add_add_employees_in_DB();
    bool Activate_event();
    bool Modify_event();
    QSqlQueryModel *Display_event(); /*type adresse (pointeur)*/
    QSqlQueryModel * Search(QString var);

    Archive();


    /* Gets  */
     int Get_ID_event(){return ID_event;}
     QString Get_name(){return name;}
     int Get_state(){return state;}
     QDate Get_beginning_date() {return beginning_date;}
     QDate Get_ending_date() {return ending_date;}
     int Get_nb_add_employees(){return nb_add_employees;}
     int Get_ID_second_responsible(){return ID_second_responsible;}



};



#endif // EVENT_H
