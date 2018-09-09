#include "refill_order.h"
#include <QDebug>
#include "inputcontrol.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

Refill_Order::Refill_Order()
{

}

Refill_Order::Refill_Order(QDate date, QString state, QString type, QDate ETA, int id_building)
{
    //this-> id_refill=id_refill;
    this-> date=date;
    this-> state =state;
    this-> type=type;
    this-> ETA=ETA;
    this-> id_building=id_building;
}



bool Refill_Order::add ()
{
    QSqlQuery query;
    query.prepare("insert into refill_order (id_refill_line,date,state,type,eta,inventory) "
                  "values(:id_refill_line,:date,:state,:type,:eta,:inventory) ");
    inputcontrol p;
    id_refill= p.generate_bar_code("product");
    query.bindValue(0,id_refill);
    query.bindValue(1,date);
    query.bindValue(2,state);
    query.bindValue(3,type);
    query.bindValue(4,ETA);
    query.bindValue(5,id_building);
    return query.exec();
}



QSqlQueryModel *Refill_Order::display_Refill()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from refill_order");
    return model;
}


QSqlQueryModel *Refill_Order::search_Refill(QString value)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    if (value == "")
    {
        return display_Refill();
    }
    else
    {


        QString str = "select * from refill_order where id_refill_line like '%" + value + "%'";
        model->setQuery(str);

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("refill_line"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("state"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("eta"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("inventory"));

    }
    return model;
}



bool Refill_Order::archive(int x)
{

    QSqlQuery query;
        query.prepare("delete from refill_order where id_refill_line =?");
        query.bindValue(0,x);
        query.exec();

    /*QSqlQuery query;
    QString str="delete from refill_line where id_refill_line ="+QString::number(x);
    qDebug()<<str;
    query.exec(str);*/
}

void Refill_Order::select_order(int aux)
{
    QSqlQueryModel model;

    model.setQuery("SELECT * from refill_order where id_refill_line= '"+QString::number(aux)+"'");
    for (int i = 0; i < model.rowCount(); ++i)
    {
   id_refill=model.record(i).value("id_refill_line").toInt();
   date=model.record(i).value("date").toDate();
   state=model.record(i).value("state").toString();
   type=model.record(i).value("type").toString();
   ETA=model.record(i).value("eta").toDate();
   id_building=model.record(i).value("inventory").toInt();
}
}



bool Refill_Order::modify(int id)
{

    QSqlQuery query;
    query.prepare("update refill_order set date=:date,state=:state,type=:type,eta=:eta,inventory=:inventory where id_refill_line=:id_refill_line");

    query.bindValue(":id_refill_line",id);
    query.bindValue(":date",date);
    query.bindValue(":state",state);
    query.bindValue(":type",type);
    query.bindValue(":eta",ETA);
    query.bindValue(":inventory",id_building);
    return query.exec();

    /*QSqlQuery query;

    QString str = "update refill_line set state='"+ state +"', type='"+type+"',eta ='"+ETA+"',inventory='"+QString::number(id_building)+"' where id_refill_line='"+QString::number(id)+"'";
    query.prepare(str);
    qDebug () << str;
    qDebug()<<query.lastError();
    return query.exec();*/
}


