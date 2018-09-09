#include "Advance.h"

Advance::Advance()
{
    //ctor
}

Advance::~Advance()
{
    //dtor
}

bool Advance::delete_advance(int id_advance)
{
    QSqlQuery query;
    query.prepare("delete from advances where id_advance=:id_advance");
    query.bindValue(0, id_advance);
    return query.exec();
}
Advance::Advance(double amount,QString description ,QString add_date,int id_employee)
{

    this->amount=amount;
    this->Description=description;
    this->add_date=add_date;
    this->id_employee=id_employee;

}
bool Advance:: add_advance()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    
    QDate date = QDate::fromString(add_date,"dd/MM/yyyy");
    model->setQuery("select * from advances where id_emp="+QString::number(id_employee));
    for(int i=0;i< model->rowCount();i++)
  {  QDate qdate;
   qdate=  QDate::fromString(model->data(model->index(i,3)).toString(),"dd/MM/yyyy");
   if(qdate.year()==date.year()&&qdate.month()==date.month())
{QMessageBox::critical(0,"Error!","This employee has alredy an advance this month",QMessageBox::Cancel);
       return  false;}

  }
    model->setQuery("select base_salary from Employee where id_employee= "+QString::number(id_employee));
    double salary = model->data(model->index(0,0)).toDouble() *0.2;


    if(amount < salary )
    {
    QSqlQuery querry;
    querry.prepare("insert into advances (amount,description,date,id_emp) values(:amount,:description,:date,:id_emp)");
    querry.bindValue(0,amount);
    querry.bindValue(1,Description);
    querry.bindValue(2,add_date);
    querry.bindValue(3,id_employee);
    return querry.exec();
    }
    else QMessageBox::critical(0,"Error!","The advance must be less than  20% ("+QString::number(salary)+")of the base salary",QMessageBox::Cancel);
    return false;
}
QSqlQueryModel * Advance::advancelist()
{
    QSqlQueryModel *model =new QSqlQueryModel();

    model->setQuery("SELECT Employee.id_employee,Employee.name,Employee.last_name,advances.id_advance,advances.amount,advances.date,advances.description "
                    " FROM Employee,advances"
                    " WHERE Employee.id_employee=advances.id_emp");
    return model;
}

QSqlQueryModel *Advance::searchadvance(int id)
{


        QSqlQueryModel *model =new QSqlQueryModel();
        QSqlQuery querry;
        QString str ="SELECT Employee.id_employee,Employee.name,Employee.last_name,advances.id_advance,advances.amount,advances.date,advances.description "
                     " FROM Employee,advances"
                     " WHERE Employee.id_employee=advances.id_emp and advances.id_emp=:id";
        querry.prepare(str);
        querry.bindValue(0,id);
        querry.exec();
        model->setQuery(querry);
       qDebug()<<str;
       return model;
}

