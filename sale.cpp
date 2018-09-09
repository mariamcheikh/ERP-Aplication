 #include "sale.h"
#include "inputcontrol.h"
#include <QSqlRecord>



sale::sale()
{
    ID_sale=0;
    nb_point=0;
    QDate d(0,0,0);
    date=d;
    total_point_fidelity=0;


}
sale::~sale()
{

}


/*--------- ajout--------------------*/
bool sale::ajouter()
{ inputcontrol p;
        ID_sale=p.generate_bar_code("sale");
        QSqlQuery query;


        query.prepare( "INSERT INTO  sale (id_sale,total_nbr_points,date,seller,client)"
                       "VALUES            (:id_sale,:total_nbr_points,:date,:seller,:client)");



        query.bindValue(0,ID_sale);
        query.bindValue(1,total_point_fidelity);
        date=QDate::currentDate();
        query.bindValue(2,date);
        query.bindValue(3,seller);
        query.bindValue(4,client);

 add_sale_line_in_bd();
        return query.exec();

     }

bool sale::add_sale_line_in_bd()
{ QSqlQuery query2;
    inputcontrol *p;
    bool res;
    for(int i=0;i<quantity.size();i++)

    { ID_sale_line=(p->generate_bar_code("sale_line")*i+1);
        if(ID_sale_line<0){ID_sale_line=ID_sale_line*-1;}
        query2.prepare("INSERT INTO  sale_line (id_sale_line,quantity,sale,product)"
                "VALUES                 (:id_sale_line,:quantity,:sale,:product)");
//ajouter les vecteurs et les lire les unes aprés les autres
p=new inputcontrol();

        query2.bindValue(0,ID_sale_line);
        query2.bindValue(1,quantity[i]);
        query2.bindValue(2,ID_sale);
        query2.bindValue(3,products[i]);
        delete p;

 res =query2.exec();
qDebug()<<query2.lastError();
    }
    return res;
}
void sale::add_line(int id_product , int qunty)
{
    products.push_back(id_product);
    quantity.push_back(qunty);
}
void sale::insert_sale_data(int id_client, int id_seller)
{
    this->client=id_client;
    this->seller=id_seller;
}
void sale::cancel_line(int pos)
{bool existence =false;
 for(int i=0;i<products.size();i++)
 {
     if(products[i]==pos)
     {existence =true;
         for (i;i<products.size()-1;i++)
         {
             products[i]=products[i+1];// here we started erasing data by overwriting the element we wanted with it's neighbor until we reach the " new end"
             quantity[i]=quantity[i+1];// of the vector which is the size of the unmodified vector -1
         }
 }
}
 if(existence)
 {
     products.pop_back();// now if vector deleted something it will be decreasing size by 1 and the last element will be still existant
     quantity.pop_back();// so we use pop_back to delete that last repeated occurence of the before_last element and that only when a delete occurs
 }
}
int sale::update_line_quantity(int qnt, int pos)
{int qt=quantity[pos];
quantity[pos]+=qnt;
qDebug("hello");
return qt;
}
/*--------- affichage--------------------*/
QSqlQueryModel *sale::afficher()
{QSqlQueryModel *Model=new (QSqlQueryModel);
return Model ;
}
QSqlQueryModel *sale::Display_sale()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from sale");
    return model;
}
/*--------- Recherche--------------------*/
QSqlQueryModel *sale::search_sale(QString type, QString value)
{
    QSqlQuery query;
    QSqlQueryModel * model = new QSqlQueryModel();
    if (value == "")
    {
        return Display_sale();
    }
    else
    {

        if (type == "by sale")
        {value = "%" + value + "%";
            QString str = "select * from sale where id_sale like :id_sale ";
            query.prepare(str);
            query.bindValue(0,value);
            query.exec();
            model->setQuery(query);

        }
        if (type == "by date")
        { value = "%" + value + "%";
            QString str = "select * from sale where date like :date";
            query.prepare(str);
            query.bindValue(0,value);
            query.exec();
            model->setQuery(query);
        }

        if (type == "by seller")
        { value = "%" + value + "%";
            QString str = "select * from sale where seller like :seller";
            query.prepare(str);
            query.bindValue(0,value);
            query.exec();
            model->setQuery(query);
        }
        if (type == "by client")
        {   value = "%" + value + "%";
            QString str = "select * from sale where client Like :client";
            query.prepare(str);
            query.bindValue(0,value);
            query.exec();
         model->setQuery(query);
        }
    }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_sale"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("seller"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("client"));

    return model;
}
/*--------- Suppression--------------------*/
bool sale::delete_sale(int ID_sale)
{
    QSqlQuery query1;
    query1.prepare("select * from sale where id_sale=:id_sale");
    query1.bindValue(0,ID_sale);
    query1.exec();
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(query1);
    if(model->rowCount()!=0)
    {
    QSqlQuery query;
    query.prepare("delete from sale where id_sale =:ID_sale");
    query.bindValue(":ID_sale",ID_sale);
    if (query.exec()) return true;
    else
    {
return false;
    }
    }
    else
        return false;
}

/*--------statistics methods Bargraph --------------*/
void sale::select_date()
{
    QSqlQueryModel model;
     sales_2010_2011=0;
     sales_2011_2012=0;
     sales_2012_2013=0;
     sales_2013_2014=0;
     sales_2014_2015=0;
     QDate current_date=QDate::currentDate();
     int current_year=current_date.year();
     int year ;


        model.setQuery("SELECT date from sale ");
        for (int i = 0; i < model.rowCount(); i++)
       {   date = model.record(i).value("sale").toDate();
            year=date.year();

          if(current_year-year>=2011)
            {
                sales_2010_2011++;
            }

       if(current_year-year>=2011&&current_year-year<2012)
            {
                sales_2011_2012++;
            }
     if(current_year-year>=2012&&current_year-year<2013)
           {
              sales_2012_2013++;
           }
       if(current_year-year>=2013&&current_year-year<2014)
           {
                 sales_2013_2014++;
           }
       if(current_year-year>=2014&&current_year-year<2015)
           {
                 sales_2014_2015++;
           }
}

}
/*--------statistics methods PieChart --------------*/
void sale::count_products()
{ QSqlQueryModel*model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    product_groupe=0;
    query->prepare("select color from product");
    qDebug()<<"query returned:"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    for (int i=0;i<model->rowCount();i++)
    {
if(model->record(i).value("color").toString()=="black")
{
    product_groupe++;
}
}
total_products=model->rowCount();
}

