#include "promotionnal.h"
#include "event.h"


Promotionnal::~Promotionnal()
{
//ctor//
}
Promotionnal::Promotionnal()
{

}
Promotionnal::Promotionnal(QString type, QString description, float budget, QString name, int state, QDate beginning_date, QDate ending_date, int ID_second_responsible, int nb_add_employees ,int ID_building):Event(ID_second_responsible ,ID_building ,name,state,beginning_date,ending_date,nb_add_employees)
{
    this-> type=type;
    this-> description=description;
    this->budget=budget;


}


bool Promotionnal:: Add_prom()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Promotionnal(ID_promotionnal,type,description,remaining_budget,budget) VALUES (:ID_promotionnal, :type,:description,:remaining_budget, :budget)");
    Add_event();
    query.bindValue(0,ID_event);
    query.bindValue(1,type);
    query.bindValue(2,description);
    query.bindValue(3,remaining_budget);
    query.bindValue(4,budget);

    Add_extra_buying_in_DB();
  qDebug("Promotionnal event added with success!");
    return query.exec();
}






bool Promotionnal:: Add_extra_buying_in_DB()
{
        QSqlQuery query2;
            inputcontrol *p;
            bool res;
            for(int i=0;i<buyings.size();i++)

            {

                query2.prepare("INSERT INTO extra_buyings (ID_event,buying,price)"
                        "VALUES                 (:ID_event,:buying,:price)");
        //ajouter les vecteurs et les lire les uns après les autres
        p=new inputcontrol();

                query2.bindValue(0,ID_event);
    //            query2.bindValue(1,buyings[i]);
                query2.bindValue(2,price[i]);
                delete p;

     qDebug()<<query2.lastError();
         res =query2.exec();
            }
            return res;


}



QSqlQueryModel * Promotionnal::Display_prom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select *from  Event inner join Promotionnal on Event.ID_event=Promotionnal.ID_event ");
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);

    return model;
}


/*bool Promotionnal:: Add_prom()
{
    QSqlQuery query;
    //query.prepare("INSERT INTO Promotionnal(ID_promotionnal,type,description,if_extra_buyings,/*extra_buyings,*///budget) VALUES (:ID_promotionnal, :type,:description,:if_extra_buyings,/*:extra_buyings,*/ :budget)");
   // Add_event();
    //query.bindValue(0,Get_ID_event());
    //query.bindValue(1,type);
    //query.bindValue(2,description);
    //query.bindValue(3,if_extra_buyings);
   /* query.bindValue(4,extra_byings);*/
//    query.bindValue(5, budget);

  //  qDebug("Promotionnal event added with success!");

    //return query.exec();
//}

//QSqlQueryModel * Promotionnal::Display_prom()
//{
 //   QSqlQueryModel * model= new QSqlQueryModel();

   // model->setQuery("select * from Promotionnal");
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type:"));
   // model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description :"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("if_extra_buyings :"));
   // model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget:"));
   // return model;
//}






















