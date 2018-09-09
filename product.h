#ifndef PRODUCT_H
#define PRODUCT_H
#include <QDate>
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>
#include "inputcontrol.h"


class Product
{
    int id_product;
    QDate added_date;
    int quantity;
    QString color;
    QString size;
    QString name;
    QString type_of_fabric;
    QString gender;
    QString category;
    float weight;
    float initial_price;
    int nb_point;
    float production_price;
    int existence;
public:

    /*--------------------------gets--------------------*/
    QString Get_name(){return name;}
    QString Get_color(){return color;}
    QString Get_size(){return size;}
    QString Get_type_of_fabric(){return type_of_fabric;}
    int Get_id_product(){return id_product;}
    int Get_quantity(){return quantity;}
    QString Get_category(){return category;}
    float Get_initial_price(){return initial_price ;}
    float Get_weight(){return weight;}
    QString Get_gender(){return gender ;}
    int Get_nb_point(){return nb_point;}
    float Get_production_price(){return production_price;}
    QDate Get_add_date(){return added_date;}

   /*--------data manipulation methods --------------*/
    Product();
    Product(QDate added_date,int quantity,QString color,QString size,QString name,QString type_of_fabric,QString gender,QString category,float weight,float initial_price,int nb_point,float production_price);
    bool add ();
    bool modify(int id);
    bool Supprimer(int id_product);
    void search();
    QSqlQueryModel *display_product();
    QSqlQueryModel *search_product(QString type, QString value);
    void select_product(int aux);
    QSqlQueryModel *select_ID_product();
};

#endif // PRODUCT_H
