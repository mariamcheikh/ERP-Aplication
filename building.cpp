#include "building.h"

building::building()
{

}
building::~building()
{

}

QSqlQueryModel *building::building_id_list()
{
    QSqlQueryModel *model=new QSqlQueryModel() ;

    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_building from building    ");


    query->exec();
    model->setQuery(*query);


    return model;
}
QSqlQueryModel *building::building_id_list(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;

    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_building from building  where  name like '%"+var+"%'  ");


    query->exec();
    model->setQuery(*query);


    return model;
}
QSqlQueryModel *building::building_list_for_mouvement_transactions(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;

    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_building,name,city,area,zip_code,size,max_employee_c,type,superficy from building  where  (name like :name or area like :area or city like :city )  ");
    query->bindValue(":name","%"+var+"%");
    query->bindValue(":area","%"+var+"%");
    query->bindValue(":city","%"+var+"%");
    qDebug()<<"selecting building list for t.v... result :" <<query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;
}

int building::how_much_space_is_left_in_this_building(int building)
{   QSqlQueryModel *model =new QSqlQueryModel ();
    QSqlQuery *query=new QSqlQuery();
   query->prepare(" select * from Employee where building = :building") ;
   query->bindValue(":building",building);
   qDebug()<<"counting employee for "<<building<<"..." << "result :"<<query->lastError();
   query->exec();
   model->setQuery(*query);
   return model->rowCount();

}
void building::select_building(int building)
{
    QSqlQueryModel model;
        QSqlQuery *query=new QSqlQuery();
        query->prepare("SELECT * from building where id_building= :id_building");
        query->bindValue(":id_building",building);
        query->exec();



        model.setQuery(*query);
        for (int i=0; i <model.rowCount(); ++i)
        {
            id_building=model.record(i).value("id_building").toInt();
            name=model.record(i).value("name").toString();
            zip_code=model.record(i).value("zip_code").toString();
            street=model.record(i).value("street").toString();
            city=model.record(i).value("city").toString();
            area=model.record(i).value("area").toString();
            max_employee_capacity=model.record(i).value("max_employee_c").toInt();
            add_date=model.record(i).value("add_date").toDate();
            size=model.record(i).value("size").toString();
            superficy=model.record(i).value("superficy").toDouble();
            type=model.record(i).value("type").toString();
            inventory_capacity=model.record(i).value("inventory_capacity").toDouble();
        }
}
