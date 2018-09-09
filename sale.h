#ifndef SALE_H
#define SALE_H
#include <QString>
#include <QDate>
#include<QSqlQuery>
#include<QSql>
#include<vector>
#include<QSqlQueryModel>
#include <QSqlError>
#include<QDebug>
//#include <QPrinter>
#include "QtPrintSupport/QPrintDialog"
#include "QtPrintSupport/QPrinter"
#include "QPainter"
class sale
{
    public:

        sale();
        ~sale();


        int update_line_quantity(int qnt, int pos);
        void updte_line(int id_product,int qnt,int pos);// function that modifys order_line

       /*--------- gets--------------------*/
        int GetID_sale() { return ID_sale; }
        void SetID_sale(long val) { ID_sale = val; }
        int Getnb_point() { return nb_point; }
        void Setnb_point(int val) { nb_point = val; }
        QDate Getdate() { return date; }
        void Setdate(QDate val) { date = val; }

       /*--------- ajout--------------------*/
        bool ajouter();
        bool add_sale_line_in_bd();
        void insert_sale_data(int id_client,int id_seller);
        void add_line(int id_product, int qunty);
        void cancel_line(int pos);

      /*--------- affichage--------------------*/
        QSqlQueryModel *Display_sale();
        QSqlQueryModel * afficher();
        /*--------- recherches--------------------*/
        QSqlQueryModel *search_sale(QString type, QString value);
        /*--------- suppression--------------------*/
        bool delete_sale(int ID_sale);

       /*--------statistics methods Bargraph --------------*/
       void select_date();
       /*--------statistics methods PieChart --------------*/
       void count_products();
      /*--------statistics Bargraph  Gets--------------*/
       double Get_sales_2010_2011(){return sales_2010_2011;}
       double Get_sales_2011_2012(){return sales_2011_2012;}
       double Get_sales_2012_2013(){return sales_2012_2013;}
       double Get_sales_2013_2014(){return sales_2013_2014;}
       double Get_sales_2014_2015(){return sales_2014_2015;}
       /*--------statistics PieChart  Gets--------------*/
       double Get_product_groupe(){return product_groupe;}
       double Get_total_products(){return total_products; }
private:
        int ID_sale;
        int ID_sale_line;
        int nb_point;
        int client;
        int seller;
        QDate date;
        int old_qt;
        int total_point_fidelity;
        QVector<int> products;
        QVector<int> quantity;
         double  sales_2010_2011;
         double sales_2011_2012;
         double sales_2012_2013;
         double sales_2013_2014;
         double sales_2014_2015;
         double total_products;
         double product_groupe;
         double sale_client;
         double total_sale;
};

#endif // SALE_H
