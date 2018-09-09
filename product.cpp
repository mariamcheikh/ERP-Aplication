#include "product.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
Product::Product()
{
/*    QString added_date="";
    int quantity=0;
    QString color="";
    QString size="";
    QString name="";
    QString type_of_fabric="";
    QString gender="";
    QString category="";
    float weight=0;
    float initial_price=0.0;
    int nb_point=0;
    float production_price=0.00;*/
}


Product::Product(QDate added_date, int quantity, QString color, QString size, QString name, QString type_of_fabric, QString gender, QString category, float weight, float initial_price, int nb_point, float production_price)
{

    this-> added_date=added_date;
    this-> quantity=quantity;
    this-> color=color;
    this-> size=size;
    this-> name=name;
    this-> type_of_fabric=type_of_fabric;
    this-> gender=gender;
    this-> category=category;
    this-> weight=weight;
    this-> initial_price=initial_price;
    this-> nb_point=nb_point;
    this-> production_price=production_price;

}

bool Product::add()
{
    QSqlQuery query;
    query.prepare("insert into product (id_product,name,add_date,quantity,color,size,type_of_fabric,category,gender,initial_price,nbr_of_points,weight_100_items,production_price,existence) "
                  "values(:id_product,:name,:add_date,:quantity,:color,:size,:type_of_fabric,:category,:gender,:initial_price,:nbr_of_points,:weight_100_items,:production_price,:existence) ");
    inputcontrol p;
   id_product= p.generate_bar_code("product");
    query.bindValue(0,id_product);
    query.bindValue(1,name);
    query.bindValue(2,added_date);
    query.bindValue(3,quantity);
    query.bindValue(4,color);
    query.bindValue(5,size);
    query.bindValue(6,type_of_fabric);
    query.bindValue(7,category);
    query.bindValue(8,gender);
    query.bindValue(9,initial_price);
    query.bindValue(10,nb_point);
    query.bindValue(11,weight);
    query.bindValue(12,production_price);
    //query.bindValue(13,0);

    return query.exec();

}


QSqlQueryModel * Product ::display_product()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from product");
    return model;

}


QSqlQueryModel *Product::search_product(QString type, QString value)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    if (value == "")
    {
        return display_product();
    }
    else
    {

        if (type == "by product_id")
        {
            QString str = "select * from product where id_product like '%" + value + "%'";
            model->setQuery(str);
        }
        if (type == "by gender")
        {
            QString str = "select * from product where gender like '%" + value + "%'";
            model->setQuery(str);
        }
        if (type == "by size")
        {
            QString str = "select * from product where size like '%" + value + "%'";
            model->setQuery(str);
        }
        if (type == "by name")
        {
            QString str = "select * from product where name like '%" + value + "%'";
            model->setQuery(str);
        }
        if (type == "by color")
        {
            QString str = "select * from product where color Like '%" + value + "%'";
            model->setQuery(str);
        }

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_product"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("add_date"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantity"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("color"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("size"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("type_of_fabric"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("category"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("initial_price"));
        model->setHeaderData(9,Qt::Horizontal,QObject::tr("nbr_of_points"));
        model->setHeaderData(10,Qt::Horizontal,QObject::tr("weight_100_items"));
        model->setHeaderData(11,Qt::Horizontal,QObject::tr("production_price"));

    }
    return model;
}


void Product::select_product(int aux)
{
    QSqlQueryModel model;

    model.setQuery("SELECT * from product where id_product= '"+QString::number(aux)+"'");
    for (int i = 0; i < model.rowCount(); ++i)
    {
   id_product=model.record(i).value("id_product").toInt();
   name=model.record(i).value("name").toString();
   added_date=model.record(i).value("added_date").toDate();
   quantity=model.record(i).value("quantity").toInt();
   color=model.record(i).value("color").toString();
   size=model.record(i).value("size").toString();
   type_of_fabric=model.record(i).value("type_of_fabric").toString();
   category=model.record(i).value("category").toString();
   gender=model.record(i).value("gender").toString();
   initial_price=model.record(i).value("initial_price").toFloat();
   nb_point=model.record(i).value("nbr_of_point").toInt();
   weight=model.record(i).value("weight_100_items").toFloat();
   production_price=model.record(i).value("production_price").toFloat();
}

}


bool Product::Supprimer(int id_product)
{
    /*QSqlQuery query;
    QString str="delete from product where id_product ="+QString::number(id_product);
    qDebug()<<str;
    return query.exec(str);*/

    QSqlQuery query;
        query.prepare("delete from product where id_product =?");
        query.bindValue(0,id_product);
       return query.exec();
}


bool Product::modify(int id)
{
    QSqlQuery query;

    /*QString str = "update product set name='"+ name +"', quantity='"+QString::number(quantity)+"', color='"+color+"',size='"+size+"',type_of_fabric='"+type_of_fabric+"',category='"+category+"',gender='"+gender+"',initial_price='"+QString::number(initial_price)+"',nbr_of_points='"+QString::number(nb_point)+"',weight_100_items='"+QString::number(weight)+"',production_price='"+QString::number(production_price)+"' where id_product='"+QString::number(id)+"'";
    qDebug () << str;
    qDebug()<<query.lastError();
    return query.exec(str);*/

    query.prepare(  "update product set name=:name,"
                    "quantity=:quantity,color=:color,"
                    "size=:size,type_of_fabric=:type_of_fabric"
                    ",category=:category,gender=:gender"
                    ",initial_price=:initial_price,"
                    "nbr_of_points=:nbr_of_points"
                    ",weight_100_items=:weight_100_items"
                    ",production_price=:production_price "
                    "where id_product=:id_product");

    query.bindValue(":id_product",id);
    query.bindValue(":name",name);
    query.bindValue(":color",color);
    query.bindValue(":size",size);
    query.bindValue(":type_of_fabric",type_of_fabric);
    query.bindValue(":category",category);
    query.bindValue(":gender",gender);
    query.bindValue(":initial_price",initial_price);
    query.bindValue(":nbr_of_points",nb_point);
    query.bindValue(":weight_100_items",weight);
    query.bindValue(":production_price",production_price);
    qDebug()<< query.lastError();
    return query.exec();
}
QSqlQueryModel *Product::select_ID_product()
{
    QSqlQueryModel *Model= new QSqlQueryModel() ;
    QSqlQuery *query= new QSqlQuery ();
    query->prepare("select id_product from product");
    query->exec();
    Model->setQuery(*query);
    return Model;
}



/*QSqlQuery query;
qDebug()<<query.lastError();
QString str = "update product set name='"+ name +"', quantity='"+quantity+"', color='"+color+"',size='"+size+"',type_of_fabric='"+type_of_fabric+"',category='"+category+"',gender='"+gender+"',initial_price='"+initial_price+"',nbr_of_points='"+nb_point+"',weight_100_items='"+weight+"',production_price='"+production_price+"' where id_product='"+id_product_1+"'";
qDebug () << str;
return query.exec(str);*/
