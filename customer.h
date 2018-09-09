#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<QString>
#include<QDate>
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <vector>
#include <QSqlError>
#include <QDebug>
#include <inputcontrol.h>


using namespace std ;





class Customer
{
protected:
    int ID_customer;
    QString name;
    int number;
    QString mail;
    QString adress;
    int nb_points;


     int nb_cust;
     int nb_cust_18_25;
     int nb_cust_25_30;
     int nb_cust_30_60 ;
     int nb_cust_over_60 ;


public:
   /*Constructeur et destructeur*/
    Customer();
    ~Customer();
    Customer(QString name,int number,QString mail,QString adress, int nb_points);
    /*Méthodes*/
    bool add_new_customer();
    bool modify_customer(int ID_customer);
    bool delete_customer(int ID_customer);
    Modify();
    Archive();
    /*Affichage*/
    QSqlQueryModel *Display();
    QSqlQueryModel *client_id_list();
    void select_client(int id);
    Get_nb_points(){return nb_points;}
    QString  Get_family_name(){return name;}
    /*statistiques*/
    int get_nb_cust(){return nb_cust;}
    int get_nb_cust_18_25() {return nb_cust_18_25;}
    int get_nb_cust_25_30 (){return nb_cust_25_30;}
    int get_nb_cust_30_60 (){return nb_cust_30_60;}
    int get_nb_cust_over_60 (){return nb_cust_over_60;}



};










#endif // CUSTOMER_H
