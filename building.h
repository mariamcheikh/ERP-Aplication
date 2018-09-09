#ifndef BUILDING_H
#define BUILDING_H
#include <QString>
#include <QDate>
#include <vector>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "employee.h"
#include "product.h"
class building
{
public:
    building();
    building(int id_building,QString name,QString zip_code,QString street,QString area,QString city,double superficy,QString size,unsigned int max_employee_capacity,QDate add_date);
    ~building();
    QSqlQueryModel *building_id_list();
    QSqlQueryModel *building_id_list(QString);
    QSqlQueryModel *building_list_for_mouvement_transactions(QString var);
    int           how_much_space_is_left_in_this_building(int building);
    /*------------gets---------------*/
    int Get_id_building(){return id_building;}
    QString Get_name(){return name;}
    QString Get_zip_code(){return zip_code;}
    QString Get_street(){return street;}
    QString Get_area(){return area ;}
    QString Get_city(){return city;}
    QString Get_type(){return type;}
    double Get_superficy(){return superficy ;}
    QString Get_size(){return size ;}
    unsigned int Get_max_employee_capacity(){return max_employee_capacity;}
    double Get_inventory_capacity(){return inventory_capacity;}
    QDate Get_add_date(){return add_date;}
    /*----------------*/
    void select_building(int building);
private:
    int id_building;
    QString name;
    QString zip_code;
    QString street;
    QString area ;
    QString city;
    QString type;
    double superficy ;
    QString size ;
    unsigned int max_employee_capacity;
    double inventory_capacity;
    QDate add_date;
    vector<employee> workspace ;
    vector<Product> stock;



};

#endif // BUILDING_H
