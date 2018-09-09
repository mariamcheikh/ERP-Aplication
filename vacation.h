#ifndef VACATION_H
#define VACATION_H

#include<QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include "inputcontrol.h"

class vacation
{
public:
    /*---------dest/const---------*/
    vacation();
    vacation(QDate start_date,QDate end_date ,QString type ,int employee );
    ~vacation();
    /*-------gets--------*/
    QString Get_collision_direction() { return collision_direction;}
    QString Get_crop_or_extend(){return crop_or_extend;}
    QString Get_shorter_or_longer(){return shorter_or_longer;}

    /*---------data input methods --------*/
    bool add_vacation();
    bool modify_vacation();
    bool delay_vacation(int days, int id); // delay a vacation to a certain period
    bool modify_vacation(bool action,int id);//if action is true then it will be archived if false then it will be dearchived
    void select_vacation(int id); // insert a specific vacation values from data_base into instence
    bool delete_vacation(int id );// delete a specific vacation from data_base
    /*-------data fetch methods-------*/
    QSqlQueryModel *vacation_list(QString var);// dynamic data list for wigdet and static search too ( all )
    QSqlQueryModel *vacation_id_list();//id list for combobox
    QSqlQueryModel *vacation_id_list(QString var);//id list for combobox to narrow the search for vacations
    QSqlQueryModel *vacation_list_by_employee(QString employee);
    QSqlQueryModel *vacation_id_list_by_employee(QString employee);
    QSqlQueryModel *employees_id_list_with_vacations();
    /*------------check methods --------*/
    bool have_this_employee_got_a_vacation_already(QString employee);
    bool does_this_vacation_already_exist();
    bool does_this_vacation_colisions_with_an_existing_one();
    bool does_this_vacation_exist_withing_an_existing_one();
    bool does_this_vacation_have_one_of_its_limits_withing_an_existing_one();
    bool does_this_vacation_have_another_vacation_living_inside_of_it();
    bool does_this_vacation_has_a_shorter_or_longer_version();
    /*------------ data transformation methods---------*/
    bool extend_or_crop_vacation(int days, QString mode, int id_vacation);
    bool merge_vacations_into_one (int id, QDate new_start_date , QDate new_end_date);
    bool crop_vacation(int id,QDate new_start_date ,QDate new_end_date);





private:
    int           id_vacation ;
    QDate          start_date ;
    QDate            end_date ;
    QString              type ;
    QDate date_of_transaction ;
    int              employee ;
    /*------check vars------*/
    QString collision_direction;
    QString crop_or_extend;
    QString shorter_or_longer;




};

#endif // VACATION_H
