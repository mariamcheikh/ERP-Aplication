#ifndef PROMOTION_H
#define PROMOTION_H
#include<QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <vector>
#include "inputcontrol.h"
using namespace std;

class promotion
{
public:
    /*------- const/dest---------*/
    promotion();
    promotion(QString original_p,QString foreign_p ,double bonus_salary,int employee );
    ~promotion();
    /*-----------data input methods ----------*/
    bool add_promotion();
    bool modify_promotion(int promotion);
    bool delete_promotion(int promotion);
    /*----------data manipulations methods---------*/
    QSqlQueryModel *select_all_promotions_id();
    QSqlQueryModel *select_all_promotions_id(int employee);
    QSqlQueryModel *select_all_promotions(QString var, QString column , QString order);
    /*---------- statistics data gathering --------*/
    void count_salarys_for_this_fella(int employee);
    int get_me_this_employee_promotions_history(int employee);
    /*---------------gets for statistics-----------*/
    double get_salary(int order_in_vector){return salarys_employee[order_in_vector];}
    QDate get_promotion_date_from_list(int order_in_vector){return promotions_employee[order_in_vector];}




private:
    int id_promotion;
    QDate date_added;
    QString original_p;
    QString foreign_p;
    double bonus_salary;
    int employee;
    vector<double>salarys_employee;
    vector<QDate> promotions_employee;


};

#endif // PROMOTION_H
