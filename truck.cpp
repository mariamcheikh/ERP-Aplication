#include "truck.h"
#include "inputcontrol.h"

Truck::Truck()
{

}

Truck::Truck(QString type, int city_state_nb, QString size, QString power, float max_weight, float initial_weight, float price, QString contract, QString availability, QString reason, int serial_num, int building)
{
    //this-> id_truck = id_truck;
    this-> type = type;
    this-> city_state_nb = city_state_nb;
    this-> size = size;
    this-> power = power;
    this-> max_weight = max_weight;
    this-> initial_weight = initial_weight;
    this-> price = price;
    this-> contract = contract;
    this-> availability = availability;
    this-> reason = reason;
    this-> serial_num = serial_num;
    this->building=building;

}

      bool Truck::add()
      {
          QSqlQuery query;
          query.prepare("insert into truck (id_truck,type,city_state_num,size,power,max_weight,initial_weight,price,contract,availability,reason,serial_num,building) "
                        "values(:id_truck,:type,:city_state_num,:size,:power,:max_weight,:initial_weight,:price,:contract,:availability,:reason,:serial_num,:building) ");
          inputcontrol p;
          id_truck= p.generate_bar_code("product");
          query.bindValue(0,id_truck);
          query.bindValue(1,type);
          query.bindValue(2,city_state_nb);
          query.bindValue(3,size);
          query.bindValue(4,power);
          query.bindValue(5,size);
          query.bindValue(6,max_weight);
          query.bindValue(7,initial_weight);
          query.bindValue(8,price);
          query.bindValue(9,contract);
          query.bindValue(10,availability);
          query.bindValue(11,reason);
          query.bindValue(12,serial_num);

          return query.exec();

      }


      QSqlQueryModel * Truck ::display_truck()
      {
          QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from truck");
          return model;

      }


      QSqlQueryModel * Truck ::display_driver()
      {
          QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from driver");
          return model;

      }





      QSqlQueryModel *Truck::search_truck(QString value)
      {
          QSqlQueryModel * model = new QSqlQueryModel();
          if (value == "")
          {
              return display_truck();
          }
          else
          {


              QString str = "select * from truck where id_truck like '%" + value + "%'";
              model->setQuery(str);

              model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_truck"));
              model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
              model->setHeaderData(2,Qt::Horizontal,QObject::tr("city_state_num"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("size"));
              model->setHeaderData(4,Qt::Horizontal,QObject::tr("power"));
              model->setHeaderData(5,Qt::Horizontal,QObject::tr("max_weight"));
              model->setHeaderData(6,Qt::Horizontal,QObject::tr("initial_weight"));
              model->setHeaderData(7,Qt::Horizontal,QObject::tr("price"));
              model->setHeaderData(8,Qt::Horizontal,QObject::tr("contract"));
              model->setHeaderData(9,Qt::Horizontal,QObject::tr("availability"));
              model->setHeaderData(10,Qt::Horizontal,QObject::tr("reason"));
              model->setHeaderData(11,Qt::Horizontal,QObject::tr("serial_num"));

          }
          return model;
      }




      bool Truck::Supprimer_T(int id_truck)
      {

          QSqlQuery query;
              query.prepare("delete from truck where id_truck =?");
              query.bindValue(0,id_truck);
         return     query.exec();
      }


// Mate5demch !!!!



      bool Truck::modify(int aux)
      {
          QSqlQuery query;

         // qDebug()<<query.lastError();
          query.prepare(  "update truck set type=:type,city_state_num=:city_state_num,size=:size,power=:power,max_weight=:max_weight,initial_weight=:initial_weight,price=:price,contract=:contract,availability=:availability,reason=:reason,serial_num=:serial_num,building=:building where id_truck=:id_truck");
          query.bindValue(":id_truck",aux);
          query.bindValue(":type",type);
          query.bindValue(":city_state_num",city_state_nb);
          query.bindValue(":size",size);
          query.bindValue(":power",power);
          query.bindValue(":max_weight",max_weight);
          query.bindValue(":initial_weight",initial_weight);
          query.bindValue(":price",price);
          query.bindValue(":contract",contract);
          query.bindValue(":availability",availability);
          query.bindValue(":reason",reason);
          query.bindValue(":serial_num",serial_num);
          query.bindValue(":building",building);

          qDebug()<< query.lastError();
          return query.exec();
      }



      void Truck::select_truck(int aux)
      {
          QSqlQueryModel model;

          model.setQuery("SELECT * from truck where id_truck= '"+QString::number(aux)+"'");
          for (int i = 0; i < model.rowCount(); ++i)
          {
         id_truck=model.record(i).value("id_truck").toInt();
         type=model.record(i).value("type").toString();
         city_state_nb=model.record(i).value("city_state_num").toInt();
         size=model.record(i).value("size").toString();
         power=model.record(i).value("power").toString();
         max_weight=model.record(i).value("max_weight").toFloat();
         initial_weight=model.record(i).value("initial_weight").toFloat();
         price=model.record(i).value("price").toFloat();
         contract=model.record(i).value("contract").toString();
         availability=model.record(i).value("availability").toString();
         reason=model.record(i).value("reason").toString();
         serial_num=model.record(i).value("serial_num").toInt();

      }

      }
