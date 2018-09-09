#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <QString>
#include <QDate>
#include "session.h"
#include<QString>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QSqlQuery>
#include <QSql>
class Supplier
{
    public:
        Supplier();
        ~Supplier();
        QString Getsupplier_name() { return supplier_name; }
        void Setsupplier_name(QString val) { supplier_name = val; }
        QString Getemail() { return email; }
        void Setemail(QString val) { email = val; }
        QString Getdescription() { return description; }
        void Setdescription(QString val) { description = val; }
        unsigned int Gettel() { return tel; }
        void Settel(unsigned int val) { tel = val; }
        unsigned int Getfax() { return fax; }
        void Setfax(unsigned int val) { fax = val; }
        QDate Getadd_date() { return add_date; }
        void Setadd_date(QDate val) { add_date = val; }
        long Getid_supplier() { return id_supplier; }
        void Setid_supplier(long val) { id_supplier = val; }
        QString getarea(){return area;}
        QString getstreet(){return street;}
        QString getzip(){return zip_code;}
        QString getcity(){return city;}
        Supplier(QString,QString,QString,int,int,QString,QString,QString,QString);

        bool add_supplier();
        bool modify_supplier( int);
        bool delete_supplier( int);
        QSqlQueryModel * search_supplier(QString,QString );
        QSqlQueryModel *  display_supplier();

        QSqlQueryModel *supplier_id_list();
        void select_supplier(int);



    private:

        QString supplier_name;
        QString email;
        QString description;
        int tel;
        int fax;
        QDate add_date;
        int id_supplier;
        QString zip_code;
        QString street;
        QString area;
        QString city;
};

#endif // SUPPLEIR_H
