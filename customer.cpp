
#include "customer.h"

Customer::Customer()
{

}

Customer::Customer(QString name, int number, QString mail, QString adress, int nb_points)
{
    this->name=name;
    this->number=number;
    this->mail=mail;
    this->adress=adress;
    this->nb_points=nb_points;
}
Customer::~Customer()
{

}


bool Customer::add_new_customer()
{
    QSqlQuery query;
    inputcontrol p;
    ID_customer=p.generate_bar_code("customer");
    query.prepare("insert into Customer (ID_customer,name,number,mail,adress,adhesion_date,nb_points) values (:ID_customer,:name,:number,:mail,:adress,:adhesion_date,:nb_points)");
    query.bindValue(0,ID_customer);
    query.bindValue(1,name);
    nb_points=0;
    query.bindValue(2,number);
    query.bindValue(3,mail);
    query.bindValue(4,adress);
    QDate adhesion_date=QDate::currentDate();
    query.bindValue(5,adhesion_date);
    query.bindValue(6,nb_points);
    qDebug()<<query.lastError();
    return query.exec();
}



bool Customer::delete_customer(int ID_customer)
{
    QSqlQuery query;
           QString str="delete from Customer where ID_customer ="+QString::number(ID_customer);

           return query.exec(str);
}


bool Customer::modify_customer(int ID_customer)
{


    QSqlQuery query ;
    query.prepare("UPDATE Customer SET  ID_customer=:ID_customer,name=:name,number=:number,mail=:mail,adress=:adress");
    query.bindValue(":ID_customer",ID_customer);
    query.bindValue(":name",name);
    query.bindValue(":number",number);
    query.bindValue(":adress",mail);
    query.bindValue(":adress",adress);

    qDebug()<<query.lastError();
    return query.exec();

}
QSqlQueryModel *Customer::client_id_list()
{
    QSqlQueryModel *Model= new QSqlQueryModel() ;
    QSqlQuery *query= new QSqlQuery ();
    query->prepare("select id_client from client");
    query->exec();
    Model->setQuery(*query);
    return Model;
}
void Customer::select_client(int id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QString id1=QString::number(id);
    model->setQuery("select  name,total_nbr_points from client where id_client='"+id1+"' ");

    for(int i=0;i<model->rowCount();++i)
    {

        this->name=model->record(i).value("name").toString();

        this->nb_points=model->record(i).value("total_nbr_points").toInt();
    }




}
