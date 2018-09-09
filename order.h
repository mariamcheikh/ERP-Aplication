#ifndef ORDER_H
#define ORDER_H
#include<QDate>
#include<QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include<QSqlRecord>
#include <vector>
#include "inputcontrol.h"
using namespace std;

class Order
{
    public:
        Order();
        ~Order();

        /*------- Ajout -----*/

            bool ajouter();
            bool add_order_line_in_bd();
            void insert_order_data_2(int order_id_client);
            void insert_order_data( QString client_name,int client_phone_number,bool delivery);
            void add_line(int id_product, int qunty);
            int update_line_quantity(int qnt, int pos);

            void cancel_line(int pos);
         /*------- Affichage-----*/
             QSqlQueryModel *Display_Order();
             QSqlQueryModel * afficher();
         /*------- Recherche-----*/
             QSqlQueryModel *search_Order(QString type, QString value);
         /*------- Suppression  -----*/
             bool delete_Order(int id_order);

         /*------------ modify ---------------*/
            void updte_line(int id_product,int qnt,int pos);// function that modifys order_line

          /*------- Gets and methods needed in modify  -----*/

             int get_product() {return product;}
             void set_product (int value);
             int get_quatity() {return quantity_tool;}
             void fetch_line_order_values(int ID_order);
             int get_rows_quantity(){return product;}
             void  insert_table_items ();
             int get_id_line (int pos){return id_lines_edited[pos];}
             int get_quatity(int pos ){return quantity[pos];}







private:
    int id_order;
    int id_export_line;
    int client ;
    QString client_name;
    int     client_phone_number;
    QString status;
    bool delivery ;
    QDate date_of_transaction;
    vector<int> products;
    vector<int> quantity;
     vector<int>id_lines_edited;
      int quantityy;
int quantity_tool ;
int product;

};
#endif // ORDER_H
