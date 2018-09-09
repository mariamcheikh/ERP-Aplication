#include "uioptions.h"
#include "ui_uioptions.h"

Options::Options(QWidget *parent) :QDialog(parent),ui(new Ui::Options)
{
    ui->setupUi(this);
    this->setWindowTitle("Options");
    QString filename ;
    filename="config.txt";
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString str=in.readLine();
    QString str2=in.readLine();
    QString str3=in.readLine();
    if(str=="display:fullscreen")
    {ui->fullscreen->setChecked(true);ui->resolution->hide();
        ui->label->hide();}
    else {ui->fullscreen->setChecked(false);ui->window->setChecked(true);ui->resolution->show();
        ui->label->show();}
    if(str3=="resolution:680*400"){ui->resolution->setCurrentIndex(2);}
    if(str3=="resolution:1080*720"){ui->resolution->setCurrentIndex(1);}
    if(str3=="resolution:1280*720"){ui->resolution->setCurrentIndex(0);}
    file.close();
}

Options::~Options()
{
    delete ui;
}

void Options::on_cancel_clicked()
{
    this->close();
}
void Options::on_fullscreen_clicked()
{
    ui->resolution->hide();
    ui->label->hide();
}
void Options::on_window_clicked()
{
    ui->resolution->show();
    ui->label->show();
}
bool Options::on_ok_clicked()
{
    if(ui->fullscreen->isChecked())
    {
        QString filename ;
        filename="config.txt";
        QFile file(filename);
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream out(&file);
        /*out<<"---config_erp---"<<endl;*/
        out<<"display:fullscreen"<<endl;
        QString    langue=ui->language->currentText() ;
        out<<"language:"<<langue<<endl;
        QString size=ui->resolution->currentText();
        out<<"resolution:"<<"default"<<endl;
        file.close();












    }
    else if(ui->window->isChecked())
    { QString filename ;
        filename="config.txt";                                                     /*initialisation du nom de fichier*/
        QFile file(filename);                                                         /*selection du fichier */
        file.open(QIODevice::WriteOnly|QIODevice::Text);                                 /*ouverture du fichier */
        QTextStream out(&file);                                                            /*initialisation du fichier source */
        /*out<<"---config_erp---"<<endl;*/
        out<<"display:windows"<<endl;                                                          /*ecriture dans la fichier */
        QString    langue=ui->language->currentText() ;                                           /*selection de la source du texte*/
        out<<"language:"<<langue<<endl;
        QString size=ui->resolution->currentText();
        out<<"resolution:"<<size<<endl;










        file.close();


    }
    QMessageBox::information(0, qApp->tr("system "),                                        /*info message before rebooting */
                             qApp->tr("system now rebooting."), QMessageBox::Accepted);
    QTime current=QTime::currentTime();
    QString time=current.toString("hh : mm : ss");












    QProcess::startDetached(QApplication::applicationFilePath());exit(12);/* reboot squence */


}
void Options::on_pushButton_clicked()
{
    QString  fileName = QFileDialog::getOpenFileName(this,
                                                     tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if(fileName==""){/*do nothing */ }
    else {
        QString filenm ;
        filenm="config_ap.txt";                                                     /*initialisation du nom de fichier*/
        QFile file(filenm);                                                         /*selection du fichier */
        file.open(QIODevice::WriteOnly|QIODevice::Text);                                 /*ouverture du fichier */
        QTextStream out(&file);                                                            /*initialisation du fichier source */
        out<<fileName<<endl;
        file.close();






        QMessageBox::information(0, qApp->tr("system "),                                        /*info message before rebooting */
                                 qApp->tr("system now rebooting."), QMessageBox::Accepted);
        QProcess::startDetached(QApplication::applicationFilePath());exit(12);}
}
void Options::on_modify_logo_clicked()
{
    QString  fileName = QFileDialog::getOpenFileName(this,
                                                     tr("modify logo"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if(fileName==""){/*do nothing */ }
    else {
        QString filenm ;
        filenm="config_logo.txt";                                                     /*initialisation du nom de fichier*/
        QFile file(filenm);                                                         /*selection du fichier */
        file.open(QIODevice::WriteOnly|QIODevice::Text);                                 /*ouverture du fichier */
        QTextStream out(&file);                                                            /*initialisation du fichier source */
        out<<fileName<<endl;
        file.close();
        QMessageBox::information(0, qApp->tr("system "),                                        /*info message before rebooting */
                                 qApp->tr("system now rebooting."), QMessageBox::Accepted);
        QProcess::startDetached(QApplication::applicationFilePath());exit(12);
    }
}
