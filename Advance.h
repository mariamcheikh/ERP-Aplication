#ifndef ADVANCE_H
#define ADVANCE_H
#include <QString>
#include "session.h"
#include "employee.h"
class Advance
{
    public:
        Advance();
        Advance(double,QString,QString,int);
        ~Advance();
         int Getid() { return id; }
        void Setid( int val) { id = val; }
        double Getamount() { return amount; }
        void Setamount(double val) { amount = val; }
        QString GetDescription() { return Description; }
        void SetDescription(QString val) { Description = val; }
        QString Getadd_date() { return add_date; }
        void Setadd_date( QString val) { add_date = val; }
        int Getid_employee() { return id_employee; }
        void Setid_employee(int val) { id_employee = val; }
        bool delete_advance(int);
        bool add_advance();
        QSqlQueryModel *advancelist();
        QSqlQueryModel *searchadvance(int );
    protected:
    private:
         int id;
        double amount;
        QString Description;
        QString add_date;
        int id_employee;
};

#endif // ADVANCE_H
