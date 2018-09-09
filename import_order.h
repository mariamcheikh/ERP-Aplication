#ifndef IMPORT_ORDER_H
#define IMPORT_ORDER_H
#include <QDate>
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>
#include "inputcontrol.h"


class Import_order
{
private:
    int id_order;
    int quantity;
    int id_product;
    int line;
public:
    Import_order();
    Import_order ( int id_order,int quantity,int id_product,int line);
    bool add ();
    void modify();
    void archive();
    void search();
};

#endif // IMPORT_ORDER_H
