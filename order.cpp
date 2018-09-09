#include "Order.h"

Order::Order()
{
    id_order=0;
    client=0;
    QDate d(0,0,0);
    date_of_transaction=d;
    client_phone_number=0;
    client_name="";
    delivery=false;
    status="";


}

Order::~Order()
{

}
 /*------- Ajout -----*/
bool Order::ajouter()
{inputcontrol p;
   id_order=p.generate_bar_code("export_order");

    date_of_transaction=QDate::currentDate();
    if(client_name=="")
    {
        client_name="regular client";
        client_phone_number=-1;
    }
    QSqlQuery query;
    query.prepare( "INSERT INTO  export_order (id_order,date,client_name,client_number,status,delivery,client)"
                   "VALUES            (:id_order,:date,:client_name,:client_number,:status,:delivery,:client)");
    query.bindValue(0,id_order);
    query.bindValue(1,date_of_transaction);
    query.bindValue(2,client_name);
    query.bindValue(3,client_phone_number);
    query.bindValue(4,status);
    query.bindValue(5,delivery);
    query.bindValue(6,client);
qDebug()<< "adding into data base your order stand by ...."<<query.lastError();
add_order_line_in_bd();
    return query.exec();

}
bool Order::add_order_line_in_bd()
{
    QSqlQuery query2;
        inputcontrol *p;
        bool res;
        for(unsigned int i=0;i<quantity.size();i++)

        { id_export_line=(p->generate_bar_code("export_line")*i);
            if(id_export_line<0){id_export_line=id_export_line*-1;}
            query2.prepare("INSERT INTO  export_line(id_line,quantity,export,product)"
                    "VALUES (:id_line,:quantity,:export,:product)");
    //ajouter les vecteurs et les lire les unes aprés les autres
    p=new inputcontrol();

            query2.bindValue(0,id_export_line);
            query2.bindValue(1,quantity[i]);

            query2.bindValue(2,id_order);
            query2.bindValue(3,products[i]);

            delete p;
     qDebug()<<query2.lastError();
     res =query2.exec();

        }
        return res;
}
void Order::insert_order_data_2(int order_id_client)
{
   // this->delivery=delivery;
    this->client=order_id_client;

    //this->client_name="";
   // this->client_phone_number=0;
}
void Order::insert_order_data(QString client_name, int client_phone_number, bool delivery)
{   this->client_name=client_name;
    this->client_phone_number=client_phone_number;
    this->delivery=delivery;
    this->client=0;

}
void Order::add_line(int id_product, int qunty)
{
   products.push_back(id_product);
   quantity.push_back(qunty);
}

int Order::update_line_quantity(int qnt, int pos)
{
    int qt=quantity[pos];
    quantity[pos]+=qnt;
    qDebug("quantity updated");
    return qt;
}

void  Order::updte_line(int id_product, int qnt, int pos)
{

    quantity[pos]=qnt;// replacing old quantity with the new one
    products[pos]=id_product;// replacing old product with the new one
    qDebug("line updated");

}
void Order::cancel_line(int pos)
{
    bool existence =false;
     for(unsigned int i=0;i<products.size();i++)
     {
         if(products[i]==pos)
         {existence =true;
             for (unsigned int j=i;j<products.size()-1;j++)
             {
                 products[j]=products[j+1];// here we started erasing data by overwriting the element we wanted with it's neighbor until we reach the " new end"
                 quantity[j]=quantity[j+1];// of the vector which is the size of the unmodified vector -1
             }
     }

     }
     if(existence)
     {
         products.pop_back();// now if vector deleted something it will be decreasing size by 1 and the last element will be still existant
         quantity.pop_back();// so we use pop_back to delete that last repeated occurence of the before_last element and that only when a delete occurs
     }
}
/*------- Afficher -----*/
QSqlQueryModel *Order::afficher()
{QSqlQueryModel *Model=new (QSqlQueryModel);
return Model ;
}
QSqlQueryModel *Order::Display_Order()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from export_order");
    return model;
}
/*------- Recherche-----*/
QSqlQueryModel *Order::search_Order(QString type, QString value)
{   QSqlQuery query;
    QSqlQueryModel * model = new QSqlQueryModel();
    if (value == "")
    {
        return Display_Order();
    }
    else
    {

        if (type == "by Order")
        {value = "%" + value + "%";
            QString str = "select * from export_order where export_order_id like :export_order_id";
            query.prepare(str);
           query.bindValue(0,value);
           query.exec();
           model->setQuery(query);
        }
        if (type == "by date")
        {   value = "%" + value + "%";
            QString str = "select * from export_order where date like :export_order";
            query.prepare(str);
           query.bindValue(0,value);
           query.exec();
            model->setQuery(query);
        }

        if (type == "by client name")
        {   value = "%" + value + "%";
            QString str = "select * from export_order where client name like '%" + value + "%'";
            query.prepare(str);
           query.bindValue(0,value);
           query.exec();
            model->setQuery(query);
        }

    }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("export_order_id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("client name"));


    return model;
}
/*------- Suppression-----*/
bool Order::delete_Order(int id_order)
{QSqlQuery query1;
    query1.prepare("select * from export_order where export_order_id=:export_order_id");
    query1.bindValue(0,id_order);
    query1.exec();
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(query1);
    if(model->rowCount()!=0)
    {
   QSqlQuery query;
           query.prepare("delete from export_order where export_order_id =:export_order_id");
           query.bindValue(":export_order_id",id_order);
           if (query.exec()) return true;
           else{
       return false;
           }
    }
    else return false;
}
/*------- Modify-----*/
