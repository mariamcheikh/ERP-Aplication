#include "Payment_report.h"

Payment_report::Payment_report()
{
    //ctor
}

Payment_report::~Payment_report()
{
    //dtor
}

bool Payment_report::calculate_payslip(unsigned int id, int month,int  year)
{
    QSqlQueryModel *model =new QSqlQueryModel();
QString str ="Select * from payslip where employee ="+QString::number(id)+" and month="+QString::number(month)+" and year ="+QString::number(year);
    model->setQuery(str);

    qDebug()<<str;

    qDebug()<<model->rowCount();

    if(model->rowCount()==0)
   {
    basic_pay=0;
    net_pay=0;
    insurance=0;
    pension=0;
    raises=0;
    advances=0;
    taxes=0;
    vector<int> tab_id_raise;
    vector<int> tab_id_advance;

    QDate date ;

    model->setQuery("select base_salary from Employee where id_employee="+QString::number(id));
    basic_pay=model->data(model->index(0,0)).toInt();

    model->setQuery("select raises.raise,date_assigned from raises where employee="+QString::number(id));
    for(int i =0;i<model->rowCount();i++)
    {
        date = QDate::fromString(model->data(model->index(i,1)).toString(),"dd/MM/yyyy");


               if(date.month()==month&&date.year()==year)

        tab_id_raise.push_back(model->data(model->index(i,0)).toInt());
    }
    for(unsigned int i=0 ;i<tab_id_raise.size();i++)
    {
        model->setQuery("select amount from raise where id_raise="+QString::number(tab_id_raise[i]));
        raises=raises+model->data(model->index(i,0)).toDouble();
    }


    pension =  basic_pay *0.086;
    insurance =basic_pay * 0.015;
    taxes =basic_pay * 0.25;

    model->setQuery("select date , amount from advances where id_emp="+QString::number(id));
    for(int i =0;i<model->rowCount();i++)
    {
        date = QDate::fromString(model->data(model->index(i,0)).toString(),"dd/MM/yyyy");


       if(date.month()==month&&date.year()==year)


        advances+=model->data(model->index(i,1)).toInt();
       // qDebug()<<advances;
    }
   net_pay=basic_pay-pension-insurance-taxes-advances+raises;


   QSqlQuery querry;

   querry.prepare("insert into payslip ( employee, base_salary, raises, month, year, advances, pension, insurance, net_salary,status)"
               "Values                 (:employee,:base_salary,:raises,:month,:year,:advances,:pension,:insurance,:net_salary,'true') ");

   querry.bindValue(0,id);
   querry.bindValue(1,basic_pay);
   querry.bindValue(2,raises);
   querry.bindValue(3,month);
   querry.bindValue(4,year);
   querry.bindValue(5,advances);
   querry.bindValue(6,pension);
   querry.bindValue(7,insurance);
   querry.bindValue(8,net_pay);

return   querry.exec();
    }
    else QMessageBox ::information(0,"Error!","This Employee has a payslip for this month",QMessageBox::Ok);
        return false;

}

void Payment_report::displaypayslip(unsigned int id, int month, int year)
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("select payslip.employee, Employee.last_name,Employee.name ,payslip.base_salary, payslip.raises,"
                    " payslip.month, payslip.year, payslip.advances, payslip.pension,"
                    " payslip.insurance, payslip.net_salary from payslip ,Employee "
                    " Where payslip.employee ="+QString::number(id)+" and"
                    " month="+QString::number(month)+" and year ="+QString::number(year)+
                    " and  Employee.id_employee = payslip.employee ");

List << "               Emplyee : " + model->data(model->index(0,1)).toString() +" " +model->data(model->index(0,2)).toString()
       + " Mois :"+model->data(model->index(0,5)).toString()+ " Année :"+model->data(model->index(0,6)).toString()
    << + " Salaire de base :"+model->data(model->index(0,3)).toString()
    << + " Primes :"+model->data(model->index(0,4)).toString()
    << + " Avances :"+model->data(model->index(0,7)).toString()
    << + " Retraire :"+model->data(model->index(0,8)).toString()
    << + " Assurance :"+model->data(model->index(0,9)).toString()
    << + " Salaire nette :"+model->data(model->index(0,10)).toString();



}

QSqlQueryModel *Payment_report::displayallpayslip()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("select payslip.employee, Employee.last_name,Employee.name "
                    ",payslip.base_salary, payslip.raises, payslip.month,"
                    " payslip.year, payslip.advances, payslip.pension, payslip.insurance,"
                    " payslip.net_salary from payslip ,Employee Where Employee.id_employee = payslip.employee");
    return model;
}
