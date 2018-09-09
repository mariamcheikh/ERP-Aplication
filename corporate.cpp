#include "customer.h"
#include "corporate.h"


Corporate::~Corporate()
{

}
Corporate::Corporate()
{

}
Corporate::Corporate(QString type_of_ID, QString corp_ID, QString corp_comm, int fax, QString type_of_contract, QString contract, QString name, int number, QString mail, QString adress ):Customer(name,number,mail,adress,nb_points)
{   this->type_of_ID=type_of_ID;
    this->corp_ID=corp_ID;
    this->corp_comm=corp_comm;
    this->fax=fax;
    this->type_of_contract=type_of_contract;
    this->contract=contract;
}

bool Corporate::add_new_corp()
{
    QSqlQuery query;
    add_new_customer();
    query.prepare("insert into Corporate (ID_customer,type_of_ID,corp_ID,corp_comm,fax,type_of_contract,contract) values (:ID_customer,:type_of_ID,:corp_ID,:corp_comm,:fax,:type_of_contract,:contract)");
    query.bindValue(0,ID_customer);
    query.bindValue(1,type_of_ID);
    query.bindValue(2,corp_ID);
    query.bindValue(3,corp_comm);
    query.bindValue(4,fax);
    query.bindValue(5,type_of_contract);
    query.bindValue(6,contract);
    qDebug()<<query.lastError();
    return query.exec();
}

QSqlQueryModel *Corporate::display_corp()
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select *from  Customer inner join Corporate on Customer.ID_customer=Corporate.ID_customer ");
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;
}

bool Corporate::delete_corp(int ID_customer)
{
    delete_customer(ID_customer);
    QSqlQuery query;
    QString str="delete from Corporate where ID_customer ="+QString::number(ID_customer);
    return true;
}
bool Corporate::modify_corp(int ID_customer)
{
    QSqlQuery query ;
       query.prepare("UPDATE Corporate SET  ID_customer=:ID_customer,type_of_ID=:type_of_ID,corp_ID=:corp_ID,corp_comm=:corp_comm,fax=:fax,type_of_contract=:type_of_contract,contract=:contract");
       query.bindValue(":ID_customer",ID_customer);
       query.bindValue(":type_of_ID",type_of_ID);
       query.bindValue(":corp_ID",corp_ID);
       query.bindValue(":corp_comm",corp_comm);
       query.bindValue(":fax",fax);
       query.bindValue(":type_of_contract",type_of_contract);
       query.bindValue(":contract",contract);
       qDebug()<<query.lastError();
       return query.exec();

}


