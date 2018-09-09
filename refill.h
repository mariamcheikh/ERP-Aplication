#ifndef REFILL_H
#define REFILL_H
#include<QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>
#include "product.h"
#include "truck.h"
using namespace std ;

class refill
{
public:
    refill();
    refill(int id_shop,QDate date_added,QString state,QString type,int eta);
    ~refill();
private:
    int id_refill;
    int id_shop;
    QDate date_added ;
    QString state ;
    QString type ;
    int eta ;
    double gas_quantity ;
    double total_weight ;
    double distance ;
    vector<Product>products ;
    vector<Truck> trucks ;





};

#endif // REFILL_H
