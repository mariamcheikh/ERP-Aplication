#ifndef DISCOUNT_EVENT_H
#define DISCOUNT_EVENT_H
#include"event.h"



class Discount_event : public Event
{
protected:
    int ID_discount;
    QVector<int> tg_products;
    QVector<int> amount;

public:

    /*constr destr*/
    Discount_event();
    ~Discount_event();
    Discount_event(int ID_second_responsible , int ID_building, QString name, int state , QDate beginning_date, QDate ending_date, int nb_add_employees );

    /*Methods*/
    bool Add_disc();
    bool Modify_disc();
     QSqlQueryModel * Display_disc();


};

#endif // DISCOUNT_EVENT_H
