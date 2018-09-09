#include "shift.h"

shift::shift()
{

}

shift::shift(QString type, QString day, QDate date, int employee)
{
    this->type=type;
    this->day=day;
    this->date=date;
    this->employee=employee;
}

shift::shift(QString type, QString day, QDate date, QTime arrival_time, int employee, QString presence)
{
    this->type=type;
    this->day=day;
    this->date=date;
    this->arrival_time=arrival_time;
    this->employee=employee;
    this->presence=presence;
}
shift::~shift()
{

}

bool shift::create_a_shift(int pos)
{
QSqlQuery *query =new QSqlQuery();
inputcontrol p;
id_shift=p.generate_bar_code("shift")*pos+1;
query->prepare("insert into shift (id_shift,type,day,date,presence,arrival_time,employee,archive) values (:id_shift,:type,:day,:date,:presence,:arrival_time,:employee,:archive)");
query->bindValue(0,id_shift);
query->bindValue(1,type);
query->bindValue(2,day);
query->bindValue(3,date);
query->bindValue(4,presence);
query->bindValue(5,arrival_time);
query->bindValue(6,employee);
query->bindValue(7,false);
qDebug()<<"shift creation returned...:"<<query->lastError();
return query->exec();

}

bool shift::edit_a_shift(int shift)
{
    QSqlQuery *query =new QSqlQuery();
    query->prepare("update shift set type=:type,day=:day,date=:date,presence=:presence,arrival_time=:arrival_time,employee=:employee where id_shift =:id_shift");
    query->bindValue(":id_shift",shift);
    query->bindValue(":type",type);
    query->bindValue(":day",day);
    query->bindValue(":date",date);
    query->bindValue(":presence",presence);
    query->bindValue(":arrival_time",arrival_time);
    query->bindValue(":employee",employee);
    qDebug()<<"shift editing returned...:"<<query->lastError();
    return query->exec();
}

bool shift::archive_a_shift(int shift, QString mode)
{
    bool res=false;
    QSqlQuery *query =new QSqlQuery();
    if(mode=="archive")
    {

query->prepare("update shift set archive='true' where id_shift=:id_shift");
query->bindValue(":id_shift",shift);
qDebug()<<"archiving a shift returned :"<<query->lastError();
   res=query->exec();}
    else if(mode=="delete")
    {

query->prepare("delete from shift where id_shift=:id_shift");
qDebug()<<"deleting a shift returned :"<<query->lastError();
   res=query->exec();
    }
    return res;
}

void shift::count_places_left_for_this_week(QDate start_date, QDate end_date)
{
     QSqlQuery *query =new QSqlQuery();
     QSqlQueryModel *model = new QSqlQueryModel();/* ill be back */


}


