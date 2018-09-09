#ifndef IMPORT_H
#define IMPORT_H
#include<QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
#include "product.h"
using namespace std ;

class import
{
public:
    import();
    import(int id_order,QDate date_added,int id_supplier,int id_inventory );
    ~import();
private:
    int id_order;
    QDate date_added ;
    int id_supplier ;
    int id_inventory ;
    vector<Product> products ;




};

#endif // IMPORT_H
