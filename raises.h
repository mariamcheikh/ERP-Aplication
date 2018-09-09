#ifndef RAISES_H
#define RAISES_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include "inputcontrol.h"


class raises
{
public:
    raises();
    raises(QString title, double amount);
   ~raises();
    /*-------data input methds --------*/
   bool create_raise();
   bool  modify_raise(int id_raise);
   bool delete_raise(int id_raise);
   bool delete_raises(int id_raise);
   /*------- gets-----------*/
   QDate Get_date_assigned(){return date_assigned;}
   QString Get_title(){return title;}
   double Get_amount(){return amount;}
   void select_raise(int id);
  QSqlQueryModel * select_all_raises_accomplished_by_this_employee(int employee);
    /*--------data_assigning methods -----*/

   bool assigne_this_raise_to_this_employee(int raise,int employee);
   bool this_employee_has_no_longer_this_raise(int id_combination);
   /*---------- data fetch methods ---------*/
   QSqlQueryModel *select_all_raises_ids();
   QSqlQueryModel *select_raises(QString var );

   /*------- check methods --------*/
   bool does_this_raise_already_exist();
   bool does_this_employee_already_have_this_raise(int id_raise,int id_employee);

private :
    int id_raise ;
    QDate date_assigned ;
    QString title ;
    double amount ;







};


#endif // RAISES_H
