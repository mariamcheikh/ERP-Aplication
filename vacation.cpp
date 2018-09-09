#include "vacation.h"

vacation::vacation()
{
    collision_direction="you need to preform a collison test first !";
         crop_or_extend="you need to preform a limit existence test first !";
         shorter_or_longer="you need to preform a size test first !";
}
vacation::~vacation()
{

}
vacation::vacation(QDate start_date,QDate end_date,QString type ,int employee)
{   this->start_date=start_date;
    this->end_date=end_date;
    this->type=type;
    this->employee=employee;
    collision_direction="you need to preform a collison test first !";
    crop_or_extend="you need to preform a limit existence first !";

}
bool vacation::add_vacation()
{inputcontrol p;
  QSqlQuery query;
id_vacation=p.generate_bar_code("vacation");
date_of_transaction=QDate::currentDate();
query.prepare("insert into vacation (id_vacation,start_date,end_date,type,date_transaction,employee) values (:id_vacation,:start_date,:end_date,:type,:date_transaction,:employee)");
query.bindValue(0,id_vacation);
query.bindValue(1,start_date);
query.bindValue(2,end_date);
query.bindValue(3,type);
query.bindValue(4,date_of_transaction);
query.bindValue(5,employee);
qDebug()<<query.lastError();
return query.exec();
}
bool vacation::modify_vacation()
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("update vacation set start_date= :start_date ,end_date=: end_date,type=:type, employee=:employee where id_vacation=:id_vacation");
    query->bindValue(":start_date",start_date);
    query->bindValue(":end_date",end_date);
    query->bindValue(":type",type);
    query->bindValue(":employee",employee);
    qDebug()<<query->lastError();
    return query->exec();
}
bool vacation::delay_vacation(int days, int id )
{
    QSqlQuery *query=new QSqlQuery();
    start_date.addDays(days);
            end_date.addDays(days);
    query->prepare("update vacation set start_date= :start_date where id_vacation=:id_vacation");
    query->bindValue(":start_date",start_date);
    query->bindValue(":end_date",end_date);
    query->bindValue(":id_vacation",id);
    qDebug()<<query->lastError();
    return query->exec();
}
bool vacation::extend_or_crop_vacation(int days,QString mode,int id_vacation)
{

    if(mode=="crop")
    {
      days=days*-1;
    }

    end_date=end_date.addDays(days);
    QSqlQuery *query=new QSqlQuery();
    query->prepare("update vacation set end_date=: end_date where id_vacation=:id_vacation");
    query->bindValue(":end_date",end_date);
    query->bindValue(":id_vacation",id_vacation);
    qDebug()<<query->lastError();
    return query->exec();

}

bool vacation::merge_vacations_into_one(int id, QDate new_start_date, QDate new_end_date)
{
QSqlQuery *query=new QSqlQuery();
query->prepare("update vacation set start_date=: start_date,end_date=: end_date where id_vacation=:id_vacation");
query->bindValue(":start_date",new_start_date);
query->bindValue(":end_date",new_end_date);
query->bindValue(":id_vacation",id);
qDebug()<<query->lastError();
return query->exec();

}
QSqlQueryModel *vacation::vacation_list_by_employee(QString employee)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();
    query->prepare("select * from vacation where employee = :employee");
    query->bindValue(":employee",employee);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model ;
}
QSqlQueryModel *vacation::vacation_id_list_by_employee(QString employee)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();
    query->prepare("select id_vacation from vacation where employee = :employee");
    query->bindValue(":employee",employee);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel *vacation::employees_id_list_with_vacations()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();
    query->prepare("select distinct employee from vacation");
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;
}

bool vacation::does_this_vacation_already_exist()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();

    query->prepare("select * from  vacation where start_date=:start_date and end_date=:end_date and employee=:employee");
    query->bindValue(":employee",employee);
    query->bindValue(":end_date",end_date);
    query->bindValue(":start_date",start_date);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()>0)
    {
        return true;
    }

    return false;

}

bool vacation::does_this_vacation_colisions_with_an_existing_one()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();

    query->prepare("select * from  vacation where (start_date=:end_date or end_date=:start_date  ) and employee=:employee");
    query->bindValue(":employee",employee);
    query->bindValue(":end_date",end_date);
    query->bindValue(":start_date",start_date);
    qDebug()<<" checking vacation collision... result :"<< query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()==0)
    {
        return false;
    }
    QDate existing_start_date,existing_end_date;
    existing_start_date=model->record(0).value("start_date").toDate();
    existing_end_date=model->record(0).value("end_date").toDate();
    qDebug()<<"existing end_date ="<<existing_end_date;
    qDebug()<<"existing  start_date="<<existing_start_date;
    qDebug()<<"start date entred ="<<start_date;
    qDebug()<<"end date entred ="<<end_date;
    if(start_date==existing_end_date)
    {
        collision_direction="right";
        qDebug()<<collision_direction;
return true ;
    }
    if(end_date==existing_start_date)
    {
        collision_direction="left";
        qDebug()<<collision_direction;
return true ;
    }
return false ;
}

bool vacation::does_this_vacation_exist_withing_an_existing_one()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();

    query->prepare("select * from  vacation where start_date<:start_date and :end_date<end_date and employee=:employee");
    query->bindValue(":employee",employee);
    query->bindValue(":end_date",end_date);
    query->bindValue(":start_date",start_date);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()==0)
    {
        return false;
    }
    QDate existing_start_date,existing_end_date;
    existing_start_date=model->record(0).value("end_date").toDate();
    existing_end_date=model->record(0).value("start_date").toDate();
   // if(existing_start_date<start_date&&end_date<existing_end_date)

return true ;


}

bool vacation::does_this_vacation_have_one_of_its_limits_withing_an_existing_one()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();
qDebug()<<"checking if vacation has another one's limits inside of it...";
    query->prepare("select * from  vacation where ((:start_date between start_date and end_date) or (:end_date between start_date and end_date)) and employee=:employee");
    query->bindValue(":employee",employee);
    query->bindValue(":end_date",end_date);
    query->bindValue(":start_date",start_date);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()==0)
    {
        qDebug()<<"no matching vacation found ";
        return false;
    }
    qDebug()<<"result: "<<model->rowCount()<<"rows ";
    QDate existing_start_date,existing_end_date;
   existing_start_date=model->record(0).value("end_date").toDate();
   existing_end_date=model->record(0).value("start_date").toDate();
   qDebug()<<"reading from data base the existing   end date :"<<existing_end_date;
   qDebug()<<"reading from data base the existing start date :"<<existing_start_date;
    if(existing_start_date>start_date)
    {
        crop_or_extend="extend";

return true ;
    }
    if(end_date>existing_end_date)
    {
        crop_or_extend="crop";
        qDebug()<<crop_or_extend;
return true ;
    }
    return false ;
}

bool vacation::does_this_vacation_have_another_vacation_living_inside_of_it()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();

    query->prepare("select * from  vacation where :start_date<start_date and end_date<:end_date and employee=:employee");
    query->bindValue(":employee",employee);
    query->bindValue(":end_date",end_date);
    query->bindValue(":start_date",start_date);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()==0)
    {
        return false;
    }
    QDate existing_start_date,existing_end_date;
   existing_start_date=model->record(0).value("end_date").toDate();
   existing_end_date=model->record(0).value("start_date").toDate();
   qDebug()<<"reading from data base the existing end date :"<<existing_end_date;
   qDebug()<<"reading from data base the existing start date :"<<existing_end_date;
    if(existing_start_date<start_date)
    {
        crop_or_extend="extend";

return true ;
    }
    if(existing_start_date<end_date)
    {
        crop_or_extend="crop";
        qDebug()<<crop_or_extend;
return true ;
    }
    return false ;
}

bool vacation::does_this_vacation_has_a_shorter_or_longer_version()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery ();

    query->prepare("select * from  vacation where (start_date=:start_date and  (end_date<:end_date or end_date>:end_date)) and employee=:employee");
    query->bindValue(":employee",employee);
    query->bindValue(":end_date",end_date);
    query->bindValue(":start_date",start_date);
    qDebug()<<" checking for vacation shorter versions... result :"<< query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()==0)
    {
        return false;
    }
    QDate existing_start_date,existing_end_date;
    existing_start_date=model->record(0).value("start_date").toDate();
    existing_end_date=model->record(0).value("end_date").toDate();
    qDebug()<<"existing end_date ="<<existing_end_date;
    qDebug()<<"existing  start_date="<<existing_start_date;
    qDebug()<<"start date entred ="<<start_date;
    qDebug()<<"end date entred ="<<end_date;
    if(existing_end_date<end_date)
    {
        shorter_or_longer="shorter";
        return true;
    }
    else  if(existing_end_date>end_date)
    {
        shorter_or_longer="longer";
        return true;
    }
return true ;
}
bool vacation::delete_vacation(int id)
{
    QSqlQuery *query =new QSqlQuery ();
    query->prepare("delete from  vacation where id_vacation = :id_vacation");
    query->bindValue(":id_vacation",id);
    qDebug()<<query->lastError();
    return  query->exec();
}
