#include "promotion.h"

promotion::promotion()
{

}
promotion::promotion(QString original_p, QString foreign_p, double bonus_salary, int employee)
{
    this->original_p=original_p;

    this->foreign_p=foreign_p;

    this->bonus_salary=bonus_salary;

    this->employee=employee;

}
bool promotion::add_promotion()
{
    QSqlQuery *query=new QSqlQuery();
    inputcontrol p;
    id_promotion=p.generate_bar_code("promotion");
    date_added=QDate::currentDate();
    query->prepare("insert into promotion (id_promotion,employee,date_assigned,original_post,new_post,bonus_salary)values (:id_promotion,:employee,:date_assigned,:original_post,:new_post,:bonus_salary) ");
    query->bindValue(0,id_promotion);
    query->bindValue(1,employee);
    query->bindValue(2,date_added);
    query->bindValue(3,original_p);
    query->bindValue(4,foreign_p);
    query->bindValue(5,bonus_salary);
    qDebug()<<query->lastError();
    return  query->exec();

}
bool promotion::modify_promotion(int promotion)
{
      QSqlQuery *query=new QSqlQuery();
      query->prepare("update promotion set original_post=:original_post,new_post=:new_post,bonus_salary=:bonus_salary where id_promotion=:id_promotion");
      query->bindValue(":id_promotion",promotion);
      query->bindValue(":original_post",original_p);
      query->bindValue("new_post",foreign_p);
      query->bindValue(":bonus_salary",bonus_salary);
      qDebug()<<query->lastError();
      return query->exec();

}
bool promotion::delete_promotion(int promotion)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("delete from promotion where id_promotion=:id_promotion");
    query->bindValue(":id_promotion",promotion);
    qDebug()<<query->lastError();
    return query->exec();
}

QSqlQueryModel *promotion::select_all_promotions_id()
{
    QSqlQuery *query=new QSqlQuery();

    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select id_promotion from promotion  ");
    qDebug()<< query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;

}

QSqlQueryModel *promotion::select_all_promotions_id(int employee)
{
    QSqlQuery *query=new QSqlQuery();

    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select id_promotion from promotion  where employee =:employee ");
    query->bindValue(":employee",employee);
    qDebug()<< query->lastError();
    query->exec();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel *promotion::select_all_promotions(QString var, QString column, QString order)
{
    QSqlQuery *query=new QSqlQuery();

    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select id_employee,name,last_name,post,original_post,bonus_salary,date_assigned from promotion INNER JOIN Employee on promotion.employee=Employee.id_employee (where promotion.id_promotion like : id_promotion or Employee.name=:name or Employee.last_name=:last_name) ORDER BY "+column+" "+order+" ");
    query->bindValue(":employee",var);
    query->bindValue(":id_promotion",var);
    query->bindValue(":name",var);
    query->bindValue(":last_name",var);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id employee"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("current post"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("original post"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("bonus salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date assigned"));

    return model ;

}
void promotion::count_salarys_for_this_fella(int employee)
{
    QSqlQuery *query=new QSqlQuery();

    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select bonus_salary,base_salary from promotion inner join Employee on Employee.id_employee=promotion.employee  (where employee = :employee  ");
    query->bindValue(":employee",employee);
    qDebug()<<query->lastError();
    query->exec();
    model->setQuery(*query);
    for( int i=0;i<model->rowCount();i++)
    {
        bonus_salary+=model->record(i).value("bonus_salary").toDouble();


    }
    bonus_salary+=model->record(0).value("base_salary").toDouble();
}

int promotion::get_me_this_employee_promotions_history(int employee)
{QDate e_promotion;
    double e_salary;
    QSqlQuery *query=new QSqlQuery();

    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select bonus_salary,base_salary,date_assigned from promotion inner join Employee on Employee.id_employee=promotion.employee  (where employee = :employee  ");
    query->bindValue(":id_employee",employee);
    qDebug()<<query->lastError();
    query->exec();
    for(int i=0;i<model->rowCount();i++)
    {
        e_promotion=model->record(i).value("date_assigned").toDate();
        e_salary=model->record(i).value("base_salary").toDouble()+model->record(i).value("bonus_salary").toDouble()*model->record(i).value("base_salary").toDouble();
    promotions_employee.push_back(e_promotion);
    salarys_employee.push_back(e_salary);
    }
    return promotions_employee.size();
}

