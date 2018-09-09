#include "uipassword.h"
#include "ui_uipassword.h"


password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
    this->setWindowTitle("Session Control");
    QPixmap pix("C:/Users/gambler/Pictures/icon_hamadi.jpg");

    QIcon p=pix.scaled(128,128);

    this->setWindowIcon(p);
    this->setAutoFillBackground(true);


}

password::~password()
{
    delete ui;
}

void password::on_change_clicked()
{
int id1=ui->id_employer->text().toInt();

   QString oldpwd=  ui->ancien_mdp->text();
   QString conpwd=  ui->conf_mdp->text();
   QString newpwd=  ui->mdp->text();
   if(oldpwd!=pass)
   {QMessageBox::critical(0,"fatal","the password you entred does not match the existing password ", QMessageBox::Ok);}
   else if(conpwd!=newpwd)
  {QMessageBox::critical(0,"fatal","passwords missmatch" ,QMessageBox::Ok);;}

else
{


    int res= QMessageBox::warning(this,"warning","  أنت على وشك تغيير كلمة المرور الخاصة بك   ! \n are you sure ? ","yes","no");
    if(res==1)
    {
QMessageBox::information(0,"system","password change request canceled",QMessageBox::Accepted);
    }
    else if(res==0)
    {session s(id1,newpwd);pass=newpwd;
     if(s.change_password()==false){QMessageBox::critical(0,"fatal","date base time out" ,QMessageBox::Ok);}
else{QMessageBox::information(0,"fatal","password changed بنجاح" ,QMessageBox::Ok);}
    }
}
    }
void password::load_credentials(int ide, QString pwd)

{
    QString id1=QString::number(ide);
    ui->id_employer->setText(id1);
    pass=pwd;



}
