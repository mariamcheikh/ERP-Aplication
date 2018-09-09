#ifndef CHARGE_H
#define CHARGE_H

#include <QString>
#include <QDate>
#include "session.h"
#include<QString>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QSqlQuery>
#include <QSql>
#include "building.h"
#include <set>
#include <vector>
class Charge
{
    public:
        Charge(QString,QString,int,double,QString);
        Charge();
        ~Charge();
        int Getid_charge() { return id_charge; }
        void Setid_charge( int val) { id_charge = val; }
        QString GetDescription() { return Description; }
        void SetDescription(QString val) { Description = val; }
        QString GetType() { return Type; }
        void SetType(QString val) { Type = val; }
         int GetID_building() { return ID_building; }
        void SetID_building( int val) { ID_building = val; }
        double Getamount() { return amount; }
        void Setamount(double val) { amount = val; }

        bool create_charge();
        void modify_chare(unsigned int );
        void delete_charge(unsigned int);
        QSqlQueryModel * displayid();


        vector<QString> tab_nom;
        vector<int> tab_id;
        vector <double> tab_amount;
        void set_id();
        void set_amount();
        QSqlQueryModel *displaycharges();
        QSqlQueryModel *displaychargesbyname(QString value);



protected:
    private:
        int id_charge;
        QString Description;
        QString Type;
        int ID_building;
        double amount;
        QString date;

};

#endif // CHARGE_H
