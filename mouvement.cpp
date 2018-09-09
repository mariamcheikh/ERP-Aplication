#include "mouvement.h"

mouvement::mouvement()
{
    this->original_building=0;
    this->new_building=0;
    this->description="";
}
mouvement::mouvement(int original_building, int new_building, QString description)
{
    this->original_building=original_building;
    this->new_building=new_building;
    this->description=description;
}
mouvement::~mouvement()
{

}

bool mouvement::add_mouvement()
{
    QSqlQuery *query=new QSqlQuery();
    inputcontrol p;
    id_mouvement=p.generate_bar_code("movement");
    date_transaction=QDate::currentDate();

    query->prepare("insert into movement (id_movement,date_transaction,original_building,new_building,description) values (:id_mouvement,:date_transaction,:original_building,:new_building,:description)");
    query->bindValue(0,id_mouvement);
    query->bindValue(1,date_transaction);
    query->bindValue(2,original_building);
    query->bindValue(3,new_building);
    query->bindValue(4,description);
    qDebug()<<" adding mouvement trace into data base ..."<<query->lastError();
    return query->exec();
}
