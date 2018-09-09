#ifndef REFILL_ORDER_H
#define REFILL_ORDER_H
#include <QDate>
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>


class Refill_Order
{
private:
    int id_refill;
    QDate date;
    QString state;
    QString type;
    QDate ETA;
    int id_building;
public:
    Refill_Order();
    Refill_Order(QDate date, QString state, QString type, QDate ETA, int id_building);

    //-------GETS-------
    int get_id(){return id_refill;}
    QDate get_date(){return date;}
    QString get_state(){return state;}
    QString get_type(){return type;}
    QDate get_eta(){return ETA;}
    int get_building(){return id_building;}
    bool add ();
    bool modify(int id);
    bool archive(int x);
    void search();
    void select_order(int aux);


    QSqlQueryModel *display_Refill();
    QSqlQueryModel *search_Refill(QString value);
};

#endif // REFILL_ORDER_H
