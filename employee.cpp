#include "employee.h"


employee::employee()
{

}
employee::~employee()
{

}
employee::employee(QString post, double salary, QString contract_type, QString paiment_type)
{

    this->post=post;
    this->salary=salary;
    this->contract_type=contract_type;
    this->paiment_type=paiment_type;

}

employee::employee(QString name, QString family_name, QDate birthdate, QString social_state, long social_sn, QString zip_code, QString street, QString area, QString city, int phone_number, int Cin, double salary, QString post, QString gender, bool activity, QString contract_type, QString paiment_type, int interveiwer, QString c_v, QString m_l, QString photo,int building)
{  this-> name=name;
    this-> family_name=family_name;
    this-> birthdate= birthdate;
    this-> social_state= social_state;
    this-> social_sn=social_sn;
    this-> zip_code=zip_code;
    this-> street=street;
    this-> area=area ;
    this-> city=city;
    this-> phone_number=phone_number;
    this-> Cin=Cin ;
    this-> salary=salary;
    this-> post = post;
    this-> gender=gender ;
    this-> activity =activity;
    this-> contract_type=contract_type ;
    this-> paiment_type=paiment_type ;
    this-> interveiwer=interveiwer;
    this-> c_v =c_v;
    this-> m_l=m_l;
    this-> photo=photo;
    this->building=building;

}
bool employee::add_employee()
{inputcontrol p;
    id_employee=p.generate_bar_code("employee");
    QSqlQuery query;

    query.prepare( "INSERT INTO  Employee ( id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, type_of_contract, type_of_paiment, interveiwer, cv, motivation_letter, photo, building, add_date,archive)"
                   "VALUES                (:id_employee,:name,:last_name,:birthdate,:social_state,:social_sn,:zip_code,:street,:city,:area,:phone_number,:cin,:base_salary,:post,:gender,:activity_state,:type_of_contract,:type_of_paiment,:interveiwer,:cv,:motivation_letter,:photo,:building,:add_date,:archive)");


    QString ssn=QString::number(social_sn);
    query.bindValue(0,id_employee);
    query.bindValue(1,name);
    query.bindValue(2,family_name);
    query.bindValue(3,birthdate);
    query.bindValue(4,social_state);
    query.bindValue(5,ssn);
    query.bindValue(6,zip_code);
    query.bindValue(7,street);
    query.bindValue(8,city);
    query.bindValue(9,area);
    query.bindValue(10,phone_number);
    query.bindValue(11,Cin);
    query.bindValue(12,salary);
    query.bindValue(13,post);
    query.bindValue(14,gender);
    query.bindValue(15,activity);
    query.bindValue(16,contract_type);
    query.bindValue(17,paiment_type);
    query.bindValue(18,interveiwer);
    query.bindValue(19,c_v);
    query.bindValue(20,m_l);
    query.bindValue(21,photo);
    QDate dateaj=QDate::currentDate();
    query.bindValue(22,building);
    query.bindValue(23,dateaj);
    query.bindValue(24,false);
    return query.exec();
}
QSqlQueryModel *employee::employee_list_by_post(QString post)
{QSqlQueryModel *model=new QSqlQueryModel() ;

    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_employee from Employee  where( post = :post) and archive='0' ");
    query->bindValue(":post",post);
    query->exec();
    model->setQuery(*query);






    return model;

}
QSqlQueryModel *employee::employee_id_list_dynamic(QString aux)
{QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();

    query->prepare("SELECT id_employee from Employee where  post = 'interveiwer' and (name Like :name or last_name Like :last_name or phone_number Like :phone_number ) and  archive='0'");
    query->bindValue(":name","%"+aux+"%");
    query->bindValue(":last_name","%"+aux+"%");
    query->bindValue(":phone_number","%"+aux+"%");
    query->exec();
    model->setQuery(*query);
    return model ;
}
void employee::select_employee(int aux)
{QSqlQueryModel model;
    QSqlQuery *query=new QSqlQuery();
    query->prepare("SELECT * from Employee where id_employee= :id_employee ");
    query->bindValue(":id_employee",aux);
    query->exec();



    model.setQuery(*query);
    for (int i=0; i <model.rowCount(); ++i)
    {
        id_employee=model.record(i).value("id_employee").toInt();
        name=model.record(i).value("name").toString();
        family_name=model.record(i).value("last_name").toString();
        birthdate=model.record(i).value("birthdate").toDate();
        social_state=model.record(i).value("social_state").toString();
        social_sn=model.record(i).value("social_sn").toInt();
        zip_code=model.record(i).value("zip_code").toString();
        street=model.record(i).value("street").toString();
        city=model.record(i).value("city").toString();
        area=model.record(i).value("area").toString();
        phone_number=model.record(i).value("phone_number").toInt();
        Cin=model.record(i).value("cin").toInt();
        salary=model.record(i).value("base_salary").toFloat();
        post=model.record(i).value("post").toString();
        gender=model.record(i).value("gender").toString();
        activity=model.record(i).value("activity_state").toBool();
        contract_type=model.record(i).value("type_of_contract").toString();
        paiment_type=model.record(i).value("type_of_paiment").toString();
        interveiwer=model.record(i).value("interveiwer").toInt();
        c_v=model.record(i).value("cv").toString();
        m_l=model.record(i).value("motivation_letter").toString();
        photo=model.record(i).value("photo").toString();
        building=model.record(i).value("building").toInt();
        add_date=model.record(i).value("add_date").toDate();
    }

}
QSqlQueryModel *employee::employee_list(QString name, QString post)
{QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();

    if(post=="All employees")

    {
        query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                       " from Employee where (name Like :name or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) and archive='0'");

        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();

    }
    else
    {
        query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                       " from Employee where  post = :post and (name Like :name or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) and archive='0'");
        query->bindValue(":post",post);
        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug() <<query->lastError();

    }
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("birthdate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("social_state"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("social security number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("zip_code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("street"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("area"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("phone_number"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("base_salary"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("gender"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("activity_state"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("interveiwer"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("building"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}
QSqlQueryModel *employee::employee_list(QString name, QString post, QString order, QString org)
{QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();


    if(post=="All employees")
    { query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                     " from Employee where   (name Like :name or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) and archive='0' ORDER BY "+order+" "+org+"");


        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();

    }

    else {query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                         " from Employee where  post = :post and (name Like :name  or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) and archive = '0' ORDER BY "+order+" "+org+"");
        query->bindValue(":post",post);
        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();


    }
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("birthdate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("social_state"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("social security number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("zip_code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("street"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("area"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("phone_number"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("base_salary"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("gender"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("activity_state"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("interveiwer"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("building"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}
QSqlQueryModel *employee::employee_list()
{QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date   from Employee where archive='0' ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("birthdate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("social_state"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("social security number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("zip_code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("street"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("area"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("phone_number"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("base_salary"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("gender"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("activity_state"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("interveiwer"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("building"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}

QSqlQueryModel *employee::employee_list(QString var, QString building, QString exception)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT  id_employee, name, last_name, phone_number, cin, post, gender, activity_state, building, add_date   from Employee where archive='0' and building=:building and not post=:post and (name Like :name  or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) ");
    query->bindValue(":building",building);
    query->bindValue(":post",exception);
    query->bindValue(":name","%"+var+"%");
    query->bindValue(":last_name","%"+var+"%");
    query->bindValue(":phone_number","%"+var+"%");
    query->bindValue(":cin","%"+var+"%");
    qDebug()<<"employee list with building and exception query returned :"<<query->lastError();
    query->exec();

        model->setQuery(*query);


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("phone_number"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("post"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("gender"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("activity_state"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("building"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("add_date"));


        return model ;
}
QSqlQueryModel *employee::employee_list_shift(QString building, QString exception)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;

    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_employee from Employee  where( not post = :post and  building = :building  and archive='0') ");
    query->bindValue(":post",exception);
    query->bindValue(":building",building);

    query->exec();
    model->setQuery(*query);

    return model;
}

QSqlQueryModel *employee::employee_id_list_with_exception(QString exception,QString exception2)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;

    QSqlQuery *query=new QSqlQuery();
    query->prepare("select id_employee from Employee  where( not post = :post and not post = :post2 ) and archive='0' ");
    query->bindValue(":post",exception);
    query->bindValue(":post2",exception2);

    query->exec();
    model->setQuery(*query);

    return model;
}
QSqlQueryModel *employee::employee_list(QString order)
{
    order="xD";
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date  from Employee where archive='0' order by add_date DESC");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("birthdate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("social_state"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("social security number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("zip_code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("street"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("area"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("phone_number"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("base_salary"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("gender"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("activity_state"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("interveiwer"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("building"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("add_date"));
    return model ;

}
QSqlQueryModel *employee::employee_id_list()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("SELECT id_employee from Employee where archive='0'  ");
    query->exec();
    model->setQuery(*query);
    return model ;
}
void employee::select_gender()
{ QSqlQueryModel model;
    females=0;
    males=0;

    model.setQuery("SELECT gender from Employee where archive='0'");
    for (int i = 0; i < model.rowCount(); i++)
    { gender = model.record(i).value("gender").toString();
        if(gender=="female")
        {
            females++;
        }

        if(gender=="male")
        {
            males++;
        }

    }
}
void employee::select_posts()
{
    QSqlQueryModel model;
    inventory_staff=0;
    sellers=0;
    managers=0;
    drivers=0;
    interveiwers=0;

    model.setQuery("SELECT post from Employee where archive='0'");
    for (int i = 0; i < model.rowCount(); i++)
    {   post = model.record(i).value("post").toString();
        if(post=="manager")
        {
            managers++;
        }

        if(post=="inventory staff")
        {
            inventory_staff++;
        }
        if(post=="seller")
        {
            sellers++;
        }
        if(post=="driver")
        {
            drivers++;
        }
        if(post=="interveiwer")
        {
            interveiwers++;
        }
    }

}
void employee::select_ages()
{
    QSqlQueryModel model;
    male_adults_60_50=0;
    male_adults_40_50=0;
    male_adults_30_40=0;
    male_adults_25_30=0;
    male_adults_18_25=0;
    female_adults_60_50=0;
    female_adults_40_50=0;
    female_adults_30_40=0;
    female_adults_25_30=0;
    female_adults_18_25=0;
    QDate current_date=QDate::currentDate();
    int current_year=current_date.year();
    int year ;


    model.setQuery("SELECT birthdate,gender from Employee where archive='0'");
    for (int i = 0; i < model.rowCount(); i++)
    {   birthdate = model.record(i).value("birthdate").toDate();
        gender   =model.record(i).value("gender").toString();
        year=birthdate.year();

        if(current_year-year>=50)
        {if(gender=="female")
            {female_adults_60_50++;}
            else {male_adults_60_50++;}
        }

        if(current_year-year>=40&&current_year-year<50)
        {if(gender=="female")
            { female_adults_40_50++;}
            else {male_adults_40_50++;}
        }
        if(current_year-year>=30&&current_year-year<40)
        {if(gender=="female")
            { female_adults_30_40++;}
            else {male_adults_30_40++;}
        }
        if(current_year-year>=25&&current_year-year<30)
        {if(gender=="female")
            {female_adults_25_30++;}
            else {male_adults_25_30++;}
        }
        if(current_year-year>=18&&current_year-year<25)
        {if(gender=="female")
            { female_adults_18_25++;}
            else {male_adults_18_25++;}
        }
    }

}
bool employee::modify_employee(int id_employee)
{

    QSqlQuery query ;
    query.prepare("UPDATE Employee SET  name=:name, last_name=:last_name, birthdate=:birthdate, social_state=:social_state, social_sn=:social_sn, zip_code=:zip_code, street=:street, city=:city, area=:area, phone_number=:phone_number, cin=:cin, base_salary=:base_salary, post=:post, gender=:gender, activity_state=:activity_state, type_of_contract=:type_of_contract, type_of_paiment=:type_of_paiment, interveiwer=:interveiwer, cv=:cv, motivation_letter=:motivation_letter, photo=:photo, building=:building where id_employee=:id_employee");
    QString ssn=QString::number(social_sn);
    query.bindValue(":id_employee",id_employee);
    query.bindValue(":name",name);
    query.bindValue(":last_name",family_name);
    query.bindValue(":birthdate",birthdate);
    query.bindValue(":social_state",social_state);
    query.bindValue(":social_sn",ssn);
    query.bindValue(":zip_code",zip_code);
    query.bindValue(":street",street);
    query.bindValue(":city",city);
    query.bindValue(":area",area);
    query.bindValue(":phone_number",phone_number);
    query.bindValue(":cin",Cin);
    query.bindValue(":base_salary",salary);
    query.bindValue(":post",post);
    query.bindValue(":gender",gender);
    query.bindValue(":activity_state",activity);
    query.bindValue(":type_of_contract",contract_type);
    query.bindValue(":type_of_paiment",paiment_type);
    query.bindValue(":interveiwer",interveiwer);
    query.bindValue(":cv",c_v);
    query.bindValue(":motivation_letter",m_l);
    query.bindValue(":photo",photo);
    query.bindValue(":building",building);
    qDebug()<<query.lastError();
    return query.exec();
}
bool employee::delete_employee(int id,QString option)
{
    QSqlQuery query;
    bool res=false;
    if(option=="delete")
    {

        query.prepare("delete from Employee where id_employee=:id_employee");
        query.bindValue(":id_employee",id);
        qDebug()<<"delete option returned :"<<query.lastError();
        res= query.exec();
    }
    else if(option=="archive")
    {
        query.prepare("update Employee set archive='1' where id_employee=:id_employee");
        query.bindValue(":id_employee",id);
        qDebug()<<"archive option returned"<<query.lastError();
        res= query.exec();
    }
    return res;


}

bool employee::move_employee(int employee,int building)
{
    QSqlQuery query ;
    query.prepare("UPDATE Employee SET  building=:building where id_employee=:id_employee");
    query.bindValue(":id_employee",employee);
    query.bindValue(":building",building);
    qDebug()<<"moving employee to"<<building <<"..."<< query.lastError();
    return query.exec();
}
bool employee::promote_employee(int employee)
{
    QSqlQuery query ;
    query.prepare("UPDATE Employee SET  base_salary=:base_salary, post=:post, type_of_contract=:type_of_contract, type_of_paiment=:type_of_paiment  where id_employee=:id_employee");
    query.bindValue(":id_employee",employee);
    query.bindValue(":base_salary",salary);
    query.bindValue(":post",post);
    query.bindValue(":type_of_contract",contract_type);
    query.bindValue(":type_of_paiment",paiment_type);
    qDebug()<< query.lastError();
    return query.exec();
}

QString employee::does_this_employee_exist()
{

    QSqlQuery *query =new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();

    query-> prepare("select *from Employee where  name=:name and last_name=:last_name and  birthdate=:birthdate and  social_state=:social_state and  social_sn=:social_sn and  zip_code=:zip_code and  street=:street and  city=:city and  area=:area and  phone_number=:phone_number and  cin=:cin and  base_salary=:base_salary and  post=:post and  gender=:gender and  activity_state=:activity_state and  type_of_contract=:type_of_contract and  type_of_paiment=:type_of_paiment and  interveiwer=:interveiwer and  cv=:cv and  motivation_letter=:motivation_letter and  photo=:photo and  building=:building ");
    QString ssn=QString::number(social_sn);
    query-> bindValue(":id_employee",id_employee);
    query-> bindValue(":name",name);
    query-> bindValue(":last_name",family_name);
    query-> bindValue(":birthdate",birthdate);
    query-> bindValue(":social_state",social_state);
    query-> bindValue(":social_sn",ssn);
    query-> bindValue(":zip_code",zip_code);
    query-> bindValue(":street",street);
    query-> bindValue(":city",city);
    query-> bindValue(":area",area);
    query-> bindValue(":phone_number",phone_number);
    query-> bindValue(":cin",Cin);
    query-> bindValue(":base_salary",salary);
    query-> bindValue(":post",post);
    query-> bindValue(":gender",gender);
    query-> bindValue(":activity_state",activity);
    query-> bindValue(":type_of_contract",contract_type);
    query-> bindValue(":type_of_paiment",paiment_type);
    query-> bindValue(":interveiwer",interveiwer);
    query-> bindValue(":cv",c_v);
    query-> bindValue(":motivation_letter",m_l);
    query-> bindValue(":photo",photo);
    query-> bindValue(":building",building);
    qDebug()<<"selection query from data base returned :"<<query-> lastError();

    query-> exec();
    model->setQuery(*query);
    if(model->rowCount()>0)
        return "yes:"+model->record(0).value("id_employee").toString();

    query->prepare("select * from Employee where  cin=:cin and archive='1' ");
    query->bindValue(":cin",Cin);
    qDebug()<<"selection query from data base returned :"<<query->lastError();
    query->exec();
    model->setQuery(*query);
    if (model->rowCount()>0)
    {return "cin";}
    return "no";
}
QSqlQueryModel *employee::employee_list(QString name, QString post, int order, QString org)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    vector<QString> column_name;
    column_name.push_back("id_employee");
    column_name.push_back("name");
    column_name.push_back("last_name");
    column_name.push_back("birthdate");
    column_name.push_back("social_state");
    column_name.push_back("social_sn");
    column_name.push_back("zip_code");
    column_name.push_back("street");
    column_name.push_back("city");
    column_name.push_back("area");
    column_name.push_back("phone_number");
    column_name.push_back("cin");
    column_name.push_back("base_salary");
    column_name.push_back("post");
    column_name.push_back("gender");
    column_name.push_back("interviewer");
    column_name.push_back("building");
    column_name.push_back("activity_state");
    column_name.push_back("add_date");

    if(post=="All employees")
    { query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                     " from Employee where   (name Like :name or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin )and  archive='0' ORDER BY "+column_name[order]+" "+org+"");


        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();

    }

    else {query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                         " from Employee where  post = :post and (name Like :name  or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) and archive='0' ORDER BY "+column_name[order]+" "+org+"");
        query->bindValue(":post",post);
        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();


    }
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("birthdate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("social_state"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("social security number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("zip_code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("street"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("area"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("phone_number"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("base_salary"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("gender"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("activity_state"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("interveiwer"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("building"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}

QSqlQueryModel *employee::employee_list_archived(QString name, QString post, int order, QString org)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    vector<QString> column_name;
    column_name.push_back("id_employee");
    column_name.push_back("name");
    column_name.push_back("last_name");
    column_name.push_back("birthdate");
    column_name.push_back("social_state");
    column_name.push_back("social_sn");
    column_name.push_back("zip_code");
    column_name.push_back("street");
    column_name.push_back("city");
    column_name.push_back("area");
    column_name.push_back("phone_number");
    column_name.push_back("cin");
    column_name.push_back("base_salary");
    column_name.push_back("post");
    column_name.push_back("gender");
    column_name.push_back("interviewer");
    column_name.push_back("building");
    column_name.push_back("activity_state");
    column_name.push_back("add_date");

    if(post=="All employees")
    { query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                     " from Employee where   (name Like :name or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin )and  archive='1' ORDER BY "+column_name[order]+" "+org+"");


        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();

    }

    else {query->prepare("SELECT  id_employee, name, last_name, birthdate, social_state, social_sn, zip_code, street, city, area, phone_number, cin, base_salary, post, gender, activity_state, interveiwer, building, add_date"
                         " from Employee where  post = :post and (name Like :name  or last_name Like :last_name or phone_number Like :phone_number or cin Like :cin) and archive='1' ORDER BY "+column_name[order]+" "+org+"");
        query->bindValue(":post",post);
        query->bindValue(":name","%"+name+"%");
        query->bindValue(":last_name","%"+name+"%");
        query->bindValue(":phone_number","%"+name+"%");
        query->bindValue(":cin","%"+name+"%");
        qDebug()<<query->lastError();


    }
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("family_name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("birthdate"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("social_state"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("social security number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("zip_code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("street"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("city"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("area"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("phone_number"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("base_salary"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("gender"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("activity_state"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("interveiwer"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("building"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}
QSqlQueryModel *employee::employee_list_with_exception(QString exception,QString var)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("select id_employee,Employee.name,last_name,gender,phone_number,Employee.area,cin,post,building,building.name from Employee inner join building on Employee.building=building.id_building where not post =:post and (Employee.name like :name or last_name like :last_name)and archive='0' ");
    query->bindValue(":post",exception);
    query->bindValue(":name","%"+var+"%");
    query->bindValue(":last_name","%"+var+"%");
    qDebug()<<"employee list with exception returned :"<<query->lastError();

    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Family name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Gender"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Number"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adress"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Post"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("ID Building"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("building name"));

    return model ;
}

QSqlQueryModel *employee::employee_list_with_exception2(QString exception, QString exception2)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare(" select id_employee,name,last_name,gender,post,cin,phone_number,add_date from Employee where  (not post =:post and not post=:post2)and archive='0' ;");
    query->bindValue(":post",exception);
    query->bindValue(":post2",exception2);
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Family name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Post"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("phone number"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}

QSqlQueryModel *employee::employee_list_with_exception2(QString exception, QString exception2, QString var)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare(" select id_employee,name,last_name,gender,post,cin,phone_number,add_date from Employee where  (not post =:post and not post=:post2) and (name like  :name or last_name like :last_name or cin like :cin ) and archive='0' ");
    query->bindValue(":name","%"+var+"%");
    query->bindValue(":last_name","%"+var+"%");
    query->bindValue(":cin","%"+var+"%");
    query->bindValue(":post",exception);
    query->bindValue(":post2",exception2);
    query->exec();
    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Family name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Post"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("phone number"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("add_date"));


    return model ;
}
QSqlQueryModel *employee::employee_list_promotion(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare(" select id_employee,Employee.name,last_name,gender,post,cin,phone_number,Employee.add_date,id_building,building.name from Employee inner join building on Employee.building=building.id_building where  ( Employee.name like  :name or last_name like :last_name or cin like :cin )and archive='0' ");
    query->bindValue(":name","%"+var+"%");
    query->bindValue(":last_name","%"+var+"%");
    query->bindValue(":cin","%"+var+"%");
    qDebug()<<"employee list promotion function returned :"<<query->lastError();
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Family name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Post"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("phone number"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("add_date"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("building id"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("building name"));
    return model ;
}
