#include "customer.h"
#include "client.h"


Client::~Client()
{

}
Client::Client()
{

}
Client::Client(QString family_name,QString gender,QDate birth_date,QString CIN,QString name,int number,QString mail,QString adress):Customer(name,number,mail,adress,nb_points)
{   this->family_name=family_name;
    this->gender=gender;
    this->birth_date=birth_date;
    this->CIN=CIN;
}


bool Client::add_new_client()
{
    QSqlQuery query;
    add_new_customer();
    query.prepare("insert into Client (ID_customer,family_name,gender,birth_date,CIN) values (:ID_customer,:family_name,:gender,:birth_date,:CIN)");
    query.bindValue(0,ID_customer);
    query.bindValue(1,family_name);
    query.bindValue(2,gender);
    query.bindValue(3,birth_date);
    query.bindValue(4,CIN);
    qDebug()<<query.lastError();
    return query.exec();
}

QSqlQueryModel *Client::display_client()
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select *from  Customer inner join Client on Customer.ID_customer=Client.ID_customer ");
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;
}

QSqlQueryModel *Client::search_client()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      QString str="select * from Customer where ID_customer ="+QString::number(ID_customer);

      return model;

// etc etc etc

}

bool Client::delete_client(int ID_customer)
{
    delete_customer(ID_customer);
    QSqlQuery query;
    QString str="delete from Client where ID_customer ="+QString::number(ID_customer);

return true;
}

bool Client::modify_client(int ID_customer)
{
    QSqlQuery query ;
    query.prepare("UPDATE Corporate SET  ID_customer=:ID_customer,type_of_ID=:type_of_ID,corp_ID=:corp_ID,corp_comm=:corp_comm,fax=:fax,type_of_contract=:type_of_contract,contract=:contract");
    query.bindValue(":ID_customer",ID_customer);
    query.bindValue(":family_name",family_name);
    query.bindValue(":gender",gender);
    query.bindValue(":birth_date",birth_date);
    query.bindValue(":CIN",CIN);

    qDebug()<<query.lastError();
    return query.exec();
}
