#include "uiquicklog.h"
#include "ui_uiquicklog.h"

quicklog::quicklog(QWidget *parent) : QDialog(parent),ui(new Ui::quicklog)
{
    ui->setupUi(this);
    this->setWindowTitle("Activity monitor");
    ui->time_limit_lab->setText(QString::number(time_limit));

    ui->wrong_attempts->setText(QString::number(3));


}

void quicklog::set_session(int id, QString pwd, int time_limit)
{this->id=id;
    this->pwd=pwd;
    attempts=3;
    this->time_limit=time_limit;
    ui->wrong_attempts->setText("3");

}

quicklog::~quicklog()
{
    delete ui;
}
void quicklog::closeEvent(QCloseEvent *event)
{
 return event->ignore();
}


void quicklog::on_connection_clicked()
{
  int idc=ui->id->text().toInt();
  QString pwdc=ui->password->text();
   if(idc==id&&pwd==pwdc)
   {
       QMessageBox::information(0,"system","welcome back !",QMessageBox::Ok);
      this->hide();
   }
 else {    if(attempts>1)
             {
              attempts--;
               QString timelimit=QString::number(time_limit);
               ui->time_limit_lab->setText(timelimit);
               QString w_attempts=QString::number(attempts);
               ui->wrong_attempts->setText(w_attempts);

             }
         else
             {
           QMessageBox::critical(0,"system","you have failed to specify the right id/password\n you will be logged off ",QMessageBox::Ok);
           QProcess::startDetached(QApplication::applicationFilePath());exit(12);
             }
     }
}

void quicklog::on_close_clicked()
{int choice=QMessageBox::warning(0,"system","by pressing continue \nyou are loging yourself off  ","continue","cancel");
   if(choice==0)
   { this->close();
    QProcess::startDetached(QApplication::applicationFilePath());exit(12);
   }
   else {
       /* stand by */
   }
}
