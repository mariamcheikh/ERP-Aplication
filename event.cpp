#include "event.h"
#include "inputcontrol.h"
#include <vector>



Event::Event(int ID_second_responsible, int ID_building, QString name, int state, QDate beginning_date, QDate ending_date, int nb_add_employees)
{  this->ID_event=0;
   this-> ID_second_responsible=ID_first_responsible;
   this-> ID_second_responsible=ID_second_responsible;
   this-> ID_second_responsible=ID_building;
   this-> name=name;
   this-> state=state;
   this-> beginning_date= beginning_date;
   this-> ending_date= ending_date;
   this-> nb_add_employees=nb_add_employees;


}

bool Event::Add_event()
{
    inputcontrol p;
    ID_event=p.generate_bar_code("event");
    QSqlQuery query;
    query.prepare( "INSERT INTO  Event ( ID_event, ID_first_responsible, ID_second_responsible, ID_building,name, state, beginning_date,ending_date,nb_add_employees)"
                   "VALUES             (:ID_event, :ID_first_responsible, :ID_second_responsible, :ID_building, :name, :state, :beginning_date,:ending_date,:nb_add_employees)");


    query.bindValue(0,ID_event);
    query.bindValue(1, ID_first_responsible);
    query.bindValue(2,ID_second_responsible);
    query.bindValue(3, ID_building);
    query.bindValue(4,name);
    query.bindValue(5,state);
    query.bindValue(6,beginning_date);
    query.bindValue(7,ending_date);
    query.bindValue(8,nb_add_employees);

    Add_add_employees_in_DB();

    return query.exec();
}

bool Event:: Add_add_employees_in_DB()
{


        QSqlQuery query2;
            inputcontrol *p;
            bool res=false ;
            for(int i=0;i<add_employees.size();i++)

            {

                query2.prepare("INSERT INTO  Add_employees_for_event (ID_event,ID_emp,task)"
                        "VALUES                 (:ID_event,:ID_emp,:task)");
        //ajouter les vecteurs et les lire les unes aprés les autres
        p=new inputcontrol();

                query2.bindValue(0,ID_event);
                query2.bindValue(1,add_employees[i]);
                query2.bindValue(2,tasks[i]);
                delete p;

     qDebug()<<query2.lastError();
         res =query2.exec();
            }
            return res;


}

QSqlQueryModel * Event::Display_event()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from event");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID of the event :"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name :"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("State :"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Beginning date:"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Ending date :"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Second responsible :"));

    return model;
}

















Event::Event()
{

}
Event::~Event()
{

}

















