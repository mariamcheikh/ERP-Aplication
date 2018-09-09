#include "discount_event.h"

Discount_event::Discount_event()
{


}
Discount_event::~Discount_event()
{


}

Discount_event::Discount_event (int ID_second_responsible , int ID_building, QString name, int state , QDate beginning_date, QDate ending_date, int nb_add_employees ):Event(ID_second_responsible,ID_building,name,  state,  beginning_date,  ending_date,    nb_add_employees)
{


}

bool Discount_event:: Add_disc()
{
   QSqlQuery query;
   inputcontrol p ;
   bool res;
  ID_discount= p.generate_bar_code("discount");
  Add_event();
  for(int i=0;i<tg_products.size();i++)
  {
    query.prepare("INSERT INTO Discount(ID_event, ID_discount,tg_product,amount) VALUES (:ID_event,:ID_discount,:tg_product,:amount)");


    query.bindValue(0,ID_event);
    query.bindValue(1,ID_discount);
    query.bindValue(2,tg_products[i]);
    query.bindValue(3,amount[i]);

    qDebug()<<query.lastError();

    res=query.exec();
  }


 return res;

}

QSqlQueryModel * Discount_event::Display_disc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select *from  Event inner join Discount on Event.ID_event=Discount.ID_event ");
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);

    return model;
}






/*






//AJOUT VECTEUR

QSqlQuery query2;
    inputcontrol *p;
    bool res;
    for(int i=0;i<quantity.size();i++)

    { ID_sale_line=(p->generate_bar_code("sale_line")*(i+1));
        if(ID_sale_line<0){ID_sale_line=ID_sale_line*-1;}
        query2.prepare("INSERT INTO  sale_line (id_sale_line,quantity,sale,product)"
                "VALUES                 (:id_sale_line,:quantity,:sale,:product)");
//ajouter les vecteurs et les lire les unes aprés les autres
p=new inputcontrol();

        query2.bindValue(0,ID_sale_line);
        query2.bindValue(1,quantity[i]);
        query2.bindValue(2,ID_sale);
        query2.bindValue(3,products[i]);
        delete p;

 res =query2.exec();
qDebug()<<query2.lastError();
    }
    return res;
*/
