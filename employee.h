#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include <vector>
#include "vacation.h"
#include "raises.h"
#include "shift.h"
#include "inputcontrol.h"

using namespace std ;
class employee
{
public:
/*-----------------cons/dest------------------------*/
 employee();
 employee(QString post,double salary,QString contract_type,QString paiment_type);
 employee(QString name,QString family_name, QDate birthdate, QString social_state, long int social_sn,QString zip_code,QString street,QString area , QString city,int phone_number,int Cin ,double salary,QString post , QString gender ,bool activity ,QString contract_type ,QString paiment_type , int interveiwer , QString c_v ,QString m_l,QString photo,int building );
 ~employee();

/*--------------------------gets--------------------*/
 QString Get_name(){return name;}
 QString Get_lastname(){return family_name;}
 QString Get_photo(){return photo;}
 int Get_phone_number(){return phone_number;}
 int Get_id_employee(){return id_employee;}
 QDate Get_birthdate() {return birthdate;}
 long int Get_social_sn(){return social_sn;}
 QString Get_social_state(){return social_state;}
 QString Get_zip_code(){return zip_code;}
 QString Get_street(){return street ;}
 QString Get_area(){return area ; }
 QString Get_city(){return city;}
 int Get_Cin(){return Cin ;}
 double Get_salary(){return salary;}
 QString Get_post(){return post ;}
 QString Get_gender(){return gender ;}
 bool Get_activity (){return activity;}
 QString Get_contract_type(){return contract_type ;}
 QString Get_paiment_type(){return paiment_type ;}
 int Get_interveiwer(){return interveiwer;}
 QString Get_c_v (){return c_v;}
 QString Get_m_l(){return m_l;}
 int Get_building(){return building;}
 QDate Get_add_date(){return add_date;}
/*--------------statistics get methods ---------------*/
 double Get_females(){return females;}
 double Get_males(){return males;}
 double Get_interveiwers(){return interveiwers;}
 double Get_managers(){return managers;}
 double Get_drivers(){return drivers;}
 double Get_sellers(){return sellers;}
 double Get_inventory_staff(){return inventory_staff;}
 double Get_male_adults_60_50(){return male_adults_60_50;}
 double Get_male_adults_40_50(){return male_adults_40_50;}
 double Get_male_adults_30_40(){return male_adults_30_40;}
 double Get_male_adults_25_30(){return male_adults_25_30;}
 double Get_male_adults_18_25(){return male_adults_18_25;}
 double Get_female_adults_60_50(){return female_adults_60_50;}
 double Get_female_adults_40_50(){return female_adults_40_50;}
 double Get_female_adults_30_40(){return female_adults_30_40;}
 double Get_female_adults_25_30(){return female_adults_25_30;}
 double Get_female_adults_18_25(){return female_adults_18_25;}
 double Get_total_employees(){return total_employees;}
 double Get_employee_groupe(){return employee_groupe;}
/*--------data manipulation methods --------------*/
   bool add_employee();
   bool modify_employee(int id_employee);
   void select_employee(int employee);
   bool delete_employee(int employee,QString option);
   bool move_employee(int employee, int building);
   bool promote_employee(int employee);
   bool this_empolyee_got_a_break(int employee);
   bool this_employee_came_back_from_a_break(int employee);
   /*---------- check methods --------*/
   QString does_this_employee_exist();
/*--------statistics data gathering  methods --------------*/
   void select_gender();
   void select_posts();
   void select_ages();
/* ------------------select methods------------------------ */
   QSqlQueryModel *employee_list(QString order);//order  determens the order display
   QSqlQueryModel *employee_list();
   QSqlQueryModel *employee_list(QString var,QString building,QString exception);
   QSqlQueryModel *employee_id_list_with_exception(QString exception,QString exception2);
   QSqlQueryModel *employee_id_list(QString var);// for combobox specific ids
   QSqlQueryModel *employee_id_list(); // for combobox all ids
   QSqlQueryModel *employee_list(QString name, QString post);
   QSqlQueryModel *employee_list(QString name, QString post, QString order, QString org);
   QSqlQueryModel *employee_list_by_post(QString post);
   QSqlQueryModel *employee_id_list_dynamic(QString aux);
   QSqlQueryModel *employee_list(QString name, QString post, int order, QString org);
   QSqlQueryModel *employee_list_with_exception(QString exception, QString var);
   QSqlQueryModel *employee_list_with_exception2(QString exception, QString exception2);
   QSqlQueryModel *employee_list_with_exception2(QString exception, QString exception2,QString var);
   QSqlQueryModel *employee_list_promotion(QString var);
   QSqlQueryModel *employee_list_archived(QString name, QString post, int order, QString org);
   QSqlQueryModel *employee_list_shift(QString building, QString exception);
protected:
    int id_employee;
    QString name;
    QString family_name;
    QDate birthdate;
    QString social_state;
    long int social_sn;
    QString zip_code;
    QString street;
    QString area ;
    QString city;
    int phone_number;
    int Cin ;
    double salary;
    QString post ;
    QString gender ;
    bool activity ;
    QString contract_type ;
    QString paiment_type ;
    int interveiwer ;
    QString c_v ;
    QString m_l;
    QString photo ;
    int building;
    QDate add_date;
/*statistics variables */
    double males;
    double females ;
    double interveiwers;
    double managers;
    double inventory_staff;
    double drivers;
    double sellers;
    double female_adults_60_50;
    double female_adults_40_50;
    double female_adults_30_40;
    double female_adults_25_30;
    double female_adults_18_25;
    double male_adults_60_50;
    double male_adults_40_50;
    double male_adults_30_40;
    double male_adults_25_30;
    double male_adults_18_25;
    double employee_groupe;
    double total_employees;
/*----------vectors---------*/
    vector <vacation> vacations;
    vector <raises> rs;
    vector <shift> shifts ;
};
#endif // EMPLOYEE_H
