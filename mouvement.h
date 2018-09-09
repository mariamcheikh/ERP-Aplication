#ifndef MOUVEMENT_H
#define MOUVEMENT_H
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QSqlRecord>
#include "inputcontrol.h"
class mouvement
{
public:
    /*--------desc/const-----------*/
    mouvement();
    mouvement(int original_building,int new_building,QString description);
   ~mouvement();
    /*------------data input methods ---------*/
   bool add_mouvement();
   bool modify_mouvement();
   bool archive_mouvement();
   bool delete_mouvement();

   /*---------------data fetch methods -------*/




private:
   int id_mouvement ;
   QDate date_transaction;
   int original_building;
   int new_building;
   QString description;
};

#endif // MOUVEMENT_H
