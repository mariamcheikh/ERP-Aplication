#ifndef REPAIRS_H
#define REPAIRS_H
#include<QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>



class repairs
{
public:
    repairs();
    repairs(int id_repair,QDate date,QDate prediction_date,double amount,QString description);
    ~repairs();
private:
    int id_repair;
    QDate date;
    QDate prediction_date;
    double amount ;
    QString description;



};

#endif // REPAIRS_H
