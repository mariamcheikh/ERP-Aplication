#include "manager.h"

manager::manager()
{

}

manager::manager(QString pwd, QString type, QString email)
{
    this->pwd=pwd;
    this->type=type;
    this->email=email;
}
void manager::select_manager(int id)
{
    QSqlQueryModel* model =new QSqlQueryModel();

QSqlQuery *query= new QSqlQuery();
query->prepare("select * from manager where id_manager = :id_manager");
query->bindValue(":id_manager",id);
qDebug()<<"selecting manager from data base ... result :"<<query->lastError();
query->exec();
    model->setQuery(*query);


        id_employee=model->record(0).value("id_manager").toInt();
        pwd=model->record(0).value("password").toString();
        type=model->record(0).value("type").toString();
        email=model->record(0).value("email").toString();

}
manager::manager(QString pwd,QString type,QString email,QString name,QString family_name, QDate birthdate, QString social_state, long int social_sn,QString zip_code,QString street,QString area , QString city,int phone_number,int Cin ,double salary,QString post , QString gender ,bool activity ,QString contract_type ,QString paiment_type , int interveiwer , QString c_v ,QString m_l,QString photo,int building):employee(name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,building)
{
    this->pwd=pwd;
    this->type=type;
    this->email=email;
}

manager::manager(QString type, QString email, QString name, QString family_name, QDate birthdate, QString social_state, long social_sn, QString zip_code, QString street, QString area, QString city, int phone_number, int Cin, double salary, QString post, QString gender, bool activity, QString contract_type, QString paiment_type, int interveiwer, QString c_v, QString m_l, QString photo, int building):employee(name,family_name,birthdate,social_state,social_sn,zip_code,street,area,city, phone_number,Cin,salary,post ,gender ,activity ,contract_type ,paiment_type ,interveiwer,c_v,m_l, photo,building)
{
    this->pwd="";
    this->type=type;
    this->email=email;
}
bool manager::add_manager()
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("INSERT INTO manager (id_manager,password,type,email) VALUES (:id_manager,:password,:type,:email)");
    add_employee();
    query->bindValue(0,id_employee);
    query->bindValue(1,pwd);
    query->bindValue(2,type);
    query->bindValue(3,email);
    qDebug()<<query->lastError();
    return query->exec();
}

bool manager::modify_manager(int id)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("update  manager set type=:type,email=:email  where id_manager=:id_manager ");
    modify_employee(id);
    query->bindValue(":id_manager",id);
    query->bindValue(":type",type);
    query->bindValue(":email",email);
    qDebug()<<" updating manager ... result :"<<query->lastError();
    modify_employee(id);
    return query->exec();
}
bool manager::this_employee_became_a_manager(int employee)
{
    QSqlQuery *query= new QSqlQuery();
    query->prepare("insert into manager (id_manager,password,type,email)VALUES (:id_manager,:password,:type,:email)");
    query->bindValue(0,employee);
    query->bindValue(1,pwd);
    query->bindValue(2,type);
    query->bindValue(3,email);
    qDebug()<<" transforming emlpoyee into a manager... result :"<<query->lastError();
    return query->exec();

}
bool manager::delete_manager(int id)
{
   QSqlQuery *query= new QSqlQuery();
   query->prepare("delete from manager where id_manager=:id_manager");
   query->bindValue(":id_manager",id);
   qDebug()<<"deleting manager ... result :"<<query->lastError();
   return query->exec();

}

