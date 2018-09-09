#ifndef MANAGER_H
#define MANAGER_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QSqlQuery>
#include <QSql>
#include "employee.h"


using namespace std ;

class manager:public employee
{
private:

    QString pwd;
    QString type;
    QString email;
public:
    /*------ const/dest------*/
    manager();
    manager(QString pwd, QString type, QString email);
    manager(QString pwd, QString type, QString email, QString name, QString family_name, QDate birthdate, QString social_state, long int social_sn, QString zip_code, QString street, QString area , QString city, int phone_number, int Cin , double salary, QString post , QString gender , bool activity , QString contract_type , QString paiment_type , int interveiwer , QString c_v , QString m_l, QString photo, int building);
    manager(QString type, QString email, QString name, QString family_name, QDate birthdate, QString social_state, long int social_sn, QString zip_code, QString street, QString area , QString city, int phone_number, int Cin , double salary, QString post , QString gender , bool activity , QString contract_type , QString paiment_type , int interveiwer , QString c_v , QString m_l, QString photo, int building);
   /*-------- gets-------*/
    QString getpwd(){return pwd;}
    QString gettype(){return type;}
    QString get_email(){return email;}
    /*--------data input methods -------*/
    bool add_manager();
    bool modify_manager(int id);
    bool delete_manager(int id);
    /*--------data selection methods-----*/
    void select_manager(int);
    /*-------- data transformation methods -----*/
    bool this_employee_became_a_manager(int employee);







};

#endif // MANAGER_H
