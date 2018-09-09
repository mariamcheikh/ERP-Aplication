#include "import_order.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

Import_order::Import_order()
{

}

Import_order::Import_order(int id_order, int quantity, int id_product, int line)
{
    this-> id_order=id_order;
    this-> quantity=quantity;
    this-> id_product =id_product;
    this->line=line;
}


bool Import_order::add()
{
    QSqlQuery query;
    query.prepare("insert into Import_order (id_order,quantity,id_product,line) "
                  "values(:id_order,:quantity,:id_product,:line)");
    query.bindValue(0,id_order);
    query.bindValue(1,quantity);
    query.bindValue(2,id_product);
    query.bindValue(3,line);

    qDebug()<<query.lastError();
    return query.exec();
}
