#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>


class discount
{
public:
    discount();

private :
    int id_discount ;
    double amount ;
    QDate add_date ;
};

#endif // DISCOUNT_H
