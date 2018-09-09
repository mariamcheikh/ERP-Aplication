#include "driver.h"

driver::driver(int lisence, bool big_trucks, bool small_trucks, QDate expiration_date, QString name, QString family_name, QDate birthdate, QString social_state, long social_sn, QString zip_code, QString street, QString area, QString city, int phone_number, int Cin, double salary, QString post, QString gender, bool activity, QString contract_type, QString paiment_type, int interveiwer, QString c_v, QString m_l, QString photo, int building):employee(name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,building)
{this->lisence=lisence;
    this->big_trucks=big_trucks;
    this->small_trucks=small_trucks;
    this->expiration_date=expiration_date;
}
driver::driver()
{
    this->lisence=0;
    this->big_trucks=false;
    this->small_trucks=false;
    this->expiration_date=QDate::currentDate();
}

driver::driver(int lisence, bool big_trucks, bool small_trucks, QDate expiration_date)
{
    this->lisence=lisence;
    this->big_trucks=big_trucks;
    this->small_trucks=small_trucks;
    this->expiration_date=expiration_date;
}
driver::~driver()
{

}

bool driver::add_driver()
{
    QSqlQuery query;
    query.prepare("INSERT INTO driver (id_driver,lisence,big_trucks,small_trucks,expiration_date) VALUES (:id_driver,:lisence,:big_trucks,:small_trucks,:expiration_date)");
    add_employee();
    query.bindValue(0,id_employee);
    query.bindValue(1,lisence);
    query.bindValue(2,big_trucks);
    query.bindValue(3,small_trucks);
    query.bindValue(4,expiration_date);
    qDebug()<<"adding driving into data base... result :"<<query.lastError();
    return query.exec();
}
void driver::select_driver(int id)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from driver where id_driver = :id_driver");
    query->bindValue(":id_driver",id);
    qDebug()<<"selecting driver from data base "<<query->lastError();
    query->exec();
    model->setQuery(*query);


        id_employee=model->record(0).value("id_driver").toInt();
        lisence=model->record(0).value("lisence").toInt();
        big_trucks=model->record(0).value("big_trucks").toBool();
        small_trucks=model->record(0).value("small_trucks").toBool();
        expiration_date=model->record(0).value("expiration_date").toDate();



}
bool driver::modify_driver(int id)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("update driver set lisence=:lisence,big_trucks=:big_trucks,small_trucks=:small_trucks,expiration_date=:expiration_date  where id_driver=:id_driver");
    add_employee();
    query->bindValue(":id_driver",id);
    query->bindValue(":lisence",lisence);
    query->bindValue(":big_trucks",big_trucks);
    query->bindValue(":small_trucks",small_trucks);
    query->bindValue(":expiration_date",expiration_date);
    qDebug()<<"adding driving into data base... result :"<<query->lastError();
    return query->exec();
}

bool driver::delete_driver(int id)
{
     QSqlQuery *query=new  QSqlQuery();
     query->prepare("delete from driver where id_driver=:id_driver");
     query->bindValue(":id_driver",id);
     qDebug()<<"delete driver ... result: "<< query->lastError();
     return query->exec();

}

bool driver::this_employee_became_a_driver(int employee)
{
    QSqlQuery *query=new  QSqlQuery();
    query->prepare("INSERT INTO driver (id_driver,lisence,big_trucks,small_trucks,expiration_date) VALUES (:id_driver,:lisence,:big_trucks,:small_trucks,:expiration_date)");
    query->bindValue(0,employee);
    query->bindValue(1,lisence);
    query->bindValue(2,big_trucks);
    query->bindValue(3,small_trucks);
    query->bindValue(4,expiration_date);
    qDebug()<<query->lastError();
    return query->exec();
}
