#include "uicrm.h"
#include "ui_uicrm.h"

uicrm::uicrm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uicrm)
{
    ui->setupUi(this);
    /* insert date data inside combobox */

    QDate date;
            date=QDate::currentDate();
            int limit=date.year()-1970,i;
            for(i=1;i<=12;i++)
                   {
                QString month=QString::number(i);
                ui->cb_birthday_client_month->insertItem(i,month);

                   }
            for(i=1;i<=31;i++)
                   {
                QString day=QString::number(i);
                ui->cb_birthday_client_day->insertItem(i,day);

                   }
           for(i=1;i<=limit;i++)
                  {
               QString year=QString::number(i+1969);
               ui->cb_birthday_client_year->insertItem(i,year);

                  }cl=new Client();
           ui->tw_display_clients->setModel(cl->display_client());
}

uicrm::~uicrm()
{
    delete ui;


}

void uicrm::on_pb_add_disc_finish_clicked()
{/*
        int ID_event;
        QString name;
        int state;
        QDate beginning_date;
        QDate ending_date;
        int ID_second_responsible;
        int nb_add_employees;
        QVector<int> ID_add_employees;
        QVector<QString> tasks;
        QVector<int> tg_products;
        QVector<int> discount;
        int min_discount;
        int max_discount;

        name=ui->le_name_disc->text();
        state=ui->cb_state_disc->currentText();
        beginning_date_day=ui->cb_beg_date_disc_day->currentText();
        beginning_date_month=ui->cb_beg_date_disc_month->currentText();
        beginning_date_year=ui->cb_beg_date_disc_year->currentText();
        end_date_day=ui->cb_end_date_disc_day->currentText();
        end_date_month=ui->cb_end_date_disc_month->currentText();
        end_date_year=ui->cb_end_date_disc_year->currentText();
        nb_add_employees=ui->sb_nb_add_employees_disc->currentText();
        discount=ui->sb_discount_disc->currentText();
        sec_resp=ui->le_sec_resp_disc->text().toInt();

  if(Add_disc()==true)
        {
            QMessageBox::critical(0,"Your event was added with success",QMessageBox::Ok);
        };

*/

}










void uicrm::on_pb_add_client_finish_clicked()
{
        name=ui->le_name_client->text();
        number=ui->le_number_client->text().toInt();
        mail=ui->le_email_client->text();
        adress=ui->le_adress_client->text();
        family_name=ui->le_family_name_client->text();
        gender=ui->cb_gender_client->currentText();
        birth_date=QDate (ui->cb_birthday_client_year->currentText().toInt(),ui->cb_birthday_client_month->currentText().toInt(),ui->cb_birthday_client_day->currentText().toInt());
        CIN=ui->le_CIN_client->text();

        cl=new Client(family_name,gender,birth_date,CIN,name,number,mail,adress);

 if(cl->add_new_client())
 {
     QMessageBox::information(0,"system","added with success",QMessageBox::Ok);
         ui->tw_display_clients->setModel(cl->display_client());
         clear_client_line_edits();
 }
else
 {
  QMessageBox::critical(0,"system","something went wrong ",QMessageBox::Ok);
 }
}


void uicrm::clear_client_line_edits()
{
   ui->le_name_client->clear();
   ui->le_number_client->clear();
   ui->le_email_client->clear();
   ui->le_adress_client->clear();
   ui->le_family_name_client->clear();
   ui->cb_gender_client->setCurrentIndex(0);
   ui->cb_birthday_client_year->setCurrentIndex(0);
   ui->cb_birthday_client_month->setCurrentIndex(0);
   ui->cb_birthday_client_day->setCurrentIndex(0);
   ui->le_CIN_client->clear();
}

void uicrm::on_pb_add_corp_finish_clicked()
{
    name=ui->le_name_corp->text();
    type_of_ID=ui->cb_type_ID_corp->currentText();
    corp_ID=ui->le_ID_corp->text();
    adress=ui->le_adress_corp->text();
    corp_comm=ui->le_assignee_corp->text();
    number=ui->le_number_corp->text().toInt();
    mail=ui->le_email_corp->text();
    fax=ui->le_fax_corp->text().toInt();
    adress=ui->le_adress_client->text();

    corp =new Corporate (type_of_ID,corp_ID,corp_comm,fax,type_of_contract,contract,name,number,mail,adress);
if(corp->add_new_corp())
{
 QMessageBox::information(0,"system","added with success",QMessageBox::Ok);
     ui->tw_display_corps->setModel(corp->display_corp());
     clear_corp_line_edits();
}
else
{
QMessageBox::critical(0,"system","something went wrong ",QMessageBox::Ok);
}
}


void uicrm::clear_corp_line_edits()
{


    ui->le_name_corp->clear();
    ui->cb_type_ID_corp->setCurrentIndex(0);
    ui->le_ID_corp->clear();
    ui->le_adress_corp->clear();
    ui->le_assignee_corp->clear();
    ui->le_number_corp->clear();
    ui->le_email_corp->clear();
    ui->le_fax_corp->clear();


}

void uicrm::on_le_search_sec_responsible_prom_textChanged(const QString &arg1)
{
employee e;
ui->tw_employee_list_prom->setModel(e.employee_list_with_exception("manager",arg1));
ui->tw_employee_list_prom->resizeColumnsToContents();
ui->tw_employee_list_prom->resizeRowsToContents();


}

void uicrm::on_tw_employee_list_prom_doubleClicked(const QModelIndex &index)
{
   if(ui->le_ID_sec_responsible_prom->text()=="")
     {  int pos =index.row();
    QString var=ui->tw_employee_list_prom->model()->data(ui->tw_employee_list_prom->model()->index(pos,0)).toString();
     QString var2=ui->tw_employee_list_prom->model()->data(ui->tw_employee_list_prom->model()->index(pos,1)).toString();
      var2+="  "+ui->tw_employee_list_prom->model()->data(ui->tw_employee_list_prom->model()->index(pos,2)).toString();
      ui->le_search_sec_responsible_prom->setText(var2);
      ui->le_ID_sec_responsible_prom->setText(var);
   }
   else
   {
       int pos =index.row();
           QString var=ui->tw_employee_list_prom->model()->data(ui->tw_employee_list_prom->model()->index(pos,0)).toString();
            QString var2=ui->tw_employee_list_prom->model()->data(ui->tw_employee_list_prom->model()->index(pos,1)).toString();
             var2+="  "+ui->tw_employee_list_prom->model()->data(ui->tw_employee_list_prom->model()->index(pos,2)).toString();
             ui->le_search_add_employee_prom->setText(var2);
             ui->le_ID_add_employee_prom->setText(var);
   }
}

void uicrm::on_le_search_add_employee_prom_textChanged(const QString &arg1)
{employee e;
    ui->tw_employee_list_prom->setModel(e.employee_list_with_exception("manager",arg1));
    ui->tw_employee_list_prom->resizeColumnsToContents();
    ui->tw_employee_list_prom->resizeRowsToContents();

}

void uicrm::on_pushButton_clicked()
{
    if(QMessageBox::warning(0,"Hamadi ERP","you have requested a session closure \nare you sure ? ","Yes","No")==0)
    {
        this->close();
    }
    else
    {
        /* do nothing */
    }
}
