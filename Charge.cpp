#include "Charge.h"

Charge::Charge()
{
    //ctor
}

Charge::~Charge()
{
    //dtor
}

Charge::Charge(QString Description, QString Type, int ID_building, double amount,QString date )
{
    this->Description=Description;
    this->Type= Type;
    this->ID_building=ID_building;
    this->amount=amount;
    this->date=date;
}

bool Charge::create_charge()
{

    QSqlQuery querry;
    querry.prepare("insert into charges(type, description, amount, id_building, date)"
                   "values            (:type,:description,:amount,:id_building,:date) ") ;
    querry.bindValue(0,Type);
    querry.bindValue(1,Description);
    querry.bindValue(2,amount);
    querry.bindValue(3,ID_building);
    querry.bindValue(4,date);

return querry.exec();
}

QSqlQueryModel * Charge::displayid()
{

    QSqlQueryModel *model =new QSqlQueryModel();
            model->setQuery("SELECT id_building from building");
            return model;
}


void Charge::set_id()
{
    tab_id.clear();
    tab_nom.clear();
    QSqlQueryModel * model =new QSqlQueryModel();

    QString str = "Select 	charges.id_building , building.name from charges,building where charges.id_building=building.id_building ";

set <int > tab;
set <int>::iterator it;
set <QString > tab1;
set <QString>::iterator ite;
    model->setQuery(str);
    for (int i = 0; i < model->rowCount(); ++i)
    {
        tab.insert(model->data(model->index(i,0)).toInt());
        tab1.insert(model->data(model->index(i,1)).toString());

    }
for(it=tab.begin();it!=tab.end();it++)
{
    tab_id.push_back(*it);
}

for(ite=tab1.begin();ite!=tab1.end();ite++)
{
    tab_nom.push_back(*ite);
    qDebug()<<*ite;
}
//qDebug()<<tab_id.size();
//qDebug()<<tab_nom[i];
//qDebug()<<tab_id[1];
}

void Charge::set_amount()
{
    tab_amount.clear();
    int aux=0;
    vector<int>::iterator id;
  //  vector<double>::iterator amount;

    QSqlQueryModel * model1 =new QSqlQueryModel();

    QSqlQuery querry;
    for(id=tab_id.begin();id!=tab_id.end();id++)
    {
        QString str = "Select amount from charges where id_building=:id";

        querry.prepare(str);
        querry.bindValue(0,*id);
        querry.exec();
        model1->setQuery(querry);
        qDebug()<<str;
        for (int i = 0; i < model1->rowCount(); ++i)
        {
           aux += model1->data(model1->index(i,0)).toDouble();

        }
        tab_amount.push_back(aux);

qDebug()<<tab_amount.size();
qDebug()<<tab_amount.back();

        aux=0;
    }

}

QSqlQueryModel *Charge::displaycharges()
{
   QSqlQueryModel *model= new QSqlQueryModel();
   QString str ="Select charges.id_charges,charges.type,charges.amount,charges.date "
    "       ,building.type,building.name from charges,building where "
   "        building.id_building=charges.id_building";
           model->setQuery(str);
   return model;
}

QSqlQueryModel *Charge::displaychargesbyname(QString value)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    value=value+"%";
    QString str ="Select charges.id_charges,charges.type,charges.amount,charges.date ,building.type,building.name"
                 " from charges,building where"
                 " building.id_building = charges.id_building"
                 " and building.name like '"+value+"'";
    qDebug()<<str;
            model->setQuery(str);
    return model;

}

