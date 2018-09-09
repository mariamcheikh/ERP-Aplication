#ifndef DRIVER_H
#define DRIVER_H
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "employee.h"

class driver : public employee
{
public:
    /*--------- const /dest ---------*/
    driver();
    driver(int lisence,bool big_trucks,bool small_trucks,QDate expiration_date);
    driver(int lisence,bool big_trucks,bool small_trucks,QDate expiration_date,QString name,QString family_name, QDate birthdate, QString social_state, long int social_sn,QString zip_code,QString street,QString area , QString city,int phone_number,int Cin ,double salary,QString post , QString gender ,bool activity ,QString contract_type ,QString paiment_type , int interveiwer , QString c_v ,QString m_l,QString photo,int building);
    ~driver();
    /*-------- data input methods -------*/
    bool add_driver();
    void select_driver(int id);
    bool modify_driver(int id);
    bool delete_driver(int id);
    /*--------- transformation methods--------*/
    bool this_employee_became_a_driver(int employee);
    /*--------- gets -----------*/
    int Get_lisence(){return lisence;}
    bool Get_big_trucks(){return big_trucks;}
    bool Get_small_trucks(){return small_trucks;}
    QDate Get_expiration_date(){return expiration_date;}
private:
    int lisence;
    bool big_trucks;
    bool small_trucks;
    QDate expiration_date;


};

#endif // DRIVER_H
