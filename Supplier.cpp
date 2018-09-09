#include "Supplier.h"
#include<QDebug>
#include <QVariant>
Supplier::Supplier()
{
    //ctor
}

Supplier::~Supplier()
{
    //dtor
}

Supplier ::Supplier(QString supplier_name,QString email,QString description,int tel,int fax,QString zip_code,QString street,QString area,QString city)
{
     this->supplier_name = supplier_name;
     this->email = email;
     this->description = description;
     this->tel = tel;
     this->fax = fax;
     this->zip_code = zip_code;
     this->street = street;
     this->area = area;
     this->city = city;

}
bool Supplier::add_supplier()
{
    QSqlQuery query;
    QString qtel= QString::number(tel);
    QString qfax= QString::number(fax);
     query.prepare("INSERT INTO Supplier( name , fax , feed_back , phone_number , zip_code , street , area , city , email)"
                 "VALUES               (:name, :fax ,:feed_back, :phone_number, :zip_code, :street, :area, :city, :email)");



   query.bindValue(0,supplier_name);
   query.bindValue(1,fax);
   query.bindValue(2,description);
   query.bindValue(3,tel);
   query.bindValue(4,zip_code);
   query.bindValue(5,street);
   query.bindValue(6,area);
   query.bindValue(7,city);
   query.bindValue(8,email);

   return query.exec();


}

QSqlQueryModel * Supplier ::display_supplier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Supplier group by name order by name ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Supplier name	"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));


    return model;

}
QSqlQueryModel *Supplier:: search_supplier(QString type,QString value)
{
    QSqlQuery querry;
    QSqlQueryModel * model = new QSqlQueryModel();
   if(value=="")
   {
     return display_supplier();
   }
   else
   {
       if (type=="by name")
    {
           value=value+"%";
           QString str="select * from Supplier where name like :name";
           querry.prepare(str);
           querry.bindValue(0,value);
           querry.exec();
           model->setQuery(querry);
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Supplier name	"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    }
       if (type=="by id")
    {
           QString str="select * from Supplier where id_supplier = :id_supplier";
           querry.prepare(str);
           querry.bindValue(0,value);
           querry.exec();
           model->setQuery(querry);
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Supplier name	"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    }

   }
    return model;
}
bool Supplier::delete_supplier(int id)
{
    QSqlQuery query;
       QString str="delete from Supplier where id_supplier ="+QString::number(id);

       return query.exec(str);

}
bool Supplier::modify_supplier(int id)
{
    QSqlQuery query;
    QString qtel= QString::number(tel);
    QString qfax= QString::number(fax);

    

    
    
    QString str="update Supplier "
            "set "
            "name= :name"
            ",fax=:fax"
            ",phone_number=:tel"
            ",feed_back=:description"
            ",zip_code=:zip_code"
            ",city=:city"
            ",street=:street"
            ",area=:area"
            ",email=:email"
            " where id_supplier=:id_supplier";

    query.prepare(str);
    query.bindValue(0,supplier_name);
    query.bindValue(1,fax);
    query.bindValue(2,tel);
    query.bindValue(3,description);
    query.bindValue(4,zip_code);
    query.bindValue(5,street);
    query.bindValue(6,area);
    query.bindValue(7,city);
    query.bindValue(8,email);
    query.bindValue(9,id);

    return query.exec();


qDebug()<<str;



}
QSqlQueryModel * Supplier::supplier_id_list()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QString str ="select id_supplier from Supplier";
    model->setQuery(str);
    return model;
}


void Supplier::select_supplier(int id)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString str="select * from Supplier where id_supplier="+QString::number(id);

    model->setQuery(str);
    id_supplier = model->data(model->index(0,0)).toInt();
    supplier_name = model->data(model->index(0,1)).toString();
    fax = model->data(model->index(0,2)).toInt();
    tel= model->data(model->index(0,4)).toInt();
    description=model->data(model->index(0,3)).toString();
    zip_code=model->data(model->index(0,5)).toString();
    city=model->data(model->index(0,8)).toString();
    area=model->data(model->index(0,7)).toString();
    street=model->data(model->index(0,6)).toString();
    email=model->data(model->index(0,9)).toString();

}
