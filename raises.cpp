#include "raises.h"

raises::raises()
{
    this->title="";
    this->amount=0;
}
raises::~raises()
{

}
raises::raises(QString title, double amount)
{
    this->title=title;
    this->amount=amount;
}
bool raises::create_raise()
{
    QSqlQuery *query=new QSqlQuery();
    date_assigned=QDate::currentDate();
    inputcontrol *p=new inputcontrol();
    id_raise= p->generate_bar_code("raise");
    query->prepare("insert into raise (id_raise,date_added,title,amount) values (:id_raise,:date_added,:title,:amount)");
    query->bindValue(0,id_raise);
    query->bindValue(1,date_assigned);
    query->bindValue(2,title);
    query->bindValue(3,amount);
    qDebug()<<"creating raise...: "<<query->lastError();
    return query->exec();

}

bool raises::modify_raise(int id_raise)
{
    QSqlQuery *query=new QSqlQuery();

    query->prepare("update  raise set id_raise=:id_raise,title=:title,amount=:amount");
    query->bindValue(":id_raise",id_raise);
    query->bindValue(":title",title);
    query->bindValue(":amount",amount);
    qDebug()<<"updating raise ... : "<<query->lastError();
    return query->exec();
}

bool raises::delete_raise(int id_raise)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("delete from  raise where id_raise=:id_raise");
    query->bindValue(":id_raise",id_raise);
    qDebug()<<"deleting  raise ... : "<<query->lastError();
    delete_raises(id_raise);
    return query->exec();
}

bool raises::delete_raises(int id_raise)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("delete from  raises where raise_id=:id_raise");
    query->bindValue(":id_raise",id_raise);
    qDebug()<<"deleting assignes combinations from raises ... : "<<query->lastError();
    return query->exec();
}

void raises::select_raise(int id)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select * from raise where id_raise=:id_raise");
    query->bindValue(":id_raise",id);
    qDebug()<<" selecting raise n°"<<id<<" ... :"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()>0)
    {
        title=model->record(0).value("title").toString();
        amount=model->record(0).value("amount").toDouble();
    }
    else
    {
        qDebug()<<"someting went wrong too many rows found";
    }



}

QSqlQueryModel *raises::select_all_raises_accomplished_by_this_employee(int employee)
{
     QSqlQuery *query=new QSqlQuery();
     QSqlQueryModel *model=new QSqlQueryModel();
     query->prepare("select id_raise,date_added,title,amount from raise inner join raises on id_raise=raise_id where employee=:employee");
     query->bindValue(":employee",employee);
     qDebug()<<" selecting employee n° " <<employee <<"raises..:"<< query->lastError();
     query->exec();
     model->setQuery(*query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Raise"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date added"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Title"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Amount"));
     return model;

}

bool raises::assigne_this_raise_to_this_employee(int raise, int employee)
{
    QSqlQuery *query=new QSqlQuery();
    date_assigned=QDate::currentDate();
    inputcontrol *p=new inputcontrol();
    int id_combination;
    id_combination=p->generate_bar_code("combination");

    query->prepare("insert into raises (id_combination,raise_id,employee,date_assigned) values (:id_combination,:raise,:employee,:date_assigned)");
    query->bindValue(":id_combination",id_combination);
    query->bindValue(":raise",raise);
    query->bindValue(":employee",employee);
    query->bindValue(":date_assigned",date_assigned);
    qDebug()<<"assigning raise n° :"<< raise<<"to employee n°"<<employee<<" ... : "<<query->lastError();
    return query->exec();
}
bool raises::this_employee_has_no_longer_this_raise(int id_combination)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("delete from  raises where id_combination=:id_combination");
    query->bindValue(":id_combination",id_combination);
    qDebug()<<"deleting employee raise  combination  ... : "<<query->lastError();
    return query->exec();
}
QSqlQueryModel *raises::select_all_raises_ids()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_raise from raise");
    qDebug()<<" selection id list for raises ... :"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;

}

QSqlQueryModel *raises::select_raises(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select * from raise where title like :title or id_raise like :id_raise");
    query->bindValue(":title","%"+var+"%");
    query->bindValue(":id_raise","%"+var+"%");
    qDebug()<<" selection id list for raises ... :"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Raise"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date added"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Title"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Amount"));
    return model;
}

bool raises::does_this_raise_already_exist()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select * from raise where title=:title and amount=:amount");
    query->bindValue(":title",title);
    query->bindValue(":amount",amount);
    qDebug()<<" checking for raise dublication  ... :"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()>0)
    {
        date_assigned=model->record(0).value("date_added").toDate();
        qDebug()<< "found one created at"<<date_assigned;
        return true;
    }
    return false;

}

bool raises::does_this_employee_already_have_this_raise(int id_raise, int id_employee)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select * from raises where raise_id=:raise and employee=:employee");
    query->bindValue(":raise",id_raise);
    query->bindValue(":employee",id_employee);
    qDebug()<<" checking for raises combinations dublication  ... :"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if(model->rowCount()>0)
    {
        date_assigned=model->record(0).value("date_assigned").toDate();
        qDebug()<< "found one assigned at"<<date_assigned;
        return true;
    }
    return false;
}

