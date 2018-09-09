#ifndef PROMOTIONNAL_H
#define PROMOTIONNAL_H
#include"event.h"



class Promotionnal : public Event
{
protected:
    QString type;
    QString description;
    float budget;
    float remaining_budget;
    QVector<string> buyings;
    QVector<float> price;

public:

    /*Constr destr */

    Promotionnal();
    Promotionnal (QString , QString , float , QString , int , QDate , QDate , int ID_second_responsible, int , int ID_building);
    ~Promotionnal();
    /* Gets  */
   QString Get_type(){return type;}
   QString Get_description(){return description;}
   float Get_budget(){return budget;}

   /* Méthodes  */
   bool Add_prom();
   bool Modify_prom();
    QSqlQueryModel * Display_prom();
   /*QSqlQueryModel * Search_disc(QString type, QString description);*/
   bool Add_extra_buying_in_DB();


};

#endif // PROMOTIONNAL_H
