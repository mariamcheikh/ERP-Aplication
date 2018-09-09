#include "ui_uimainframe.h"
#include "ui_mainframe.h"
Mainframe::Mainframe(QDialog *parent) :QDialog(parent),ui(new Ui::Mainframe)
{
    ui->setupUi(this);
    this->setWindowTitle("Hamadi ERP");
    ui->identification->setFocus();
    //    QPixmap pix("C:/Users/gambler/Pictures/layout_bg.png");
    //    QPixmap mypixmap(pix.scaled(ui->loginpanel_bg->height(),ui->loginpanel_bg->width()));
    //    ui->loginpanel_bg->setPixmap(mypixmap);

}
Mainframe::~Mainframe()
{
    delete ui;
}
void Mainframe::on_options_clicked()
{
    fenetre=new Options(this);
    fenetre->show();
    fenetre->setFixedSize(400,300);
}
void Mainframe::on_connection_clicked()
{int id ;
    QString aux;
    QString pwd;
    inputcontrol test ;
    manager m ;
    session s;
    id=ui->identification->text().toInt();
    pwd=ui->password->text();
    ui->identification->setFocus();
    if(test.is_number(aux))
    {
        id=ui->identification->text().toInt();
        pwd=ui->password->text();
        s.connection();
        m.select_manager(id);
        if(m.Get_id_employee()==id&&m.getpwd()==pwd)
        { this->id_m=id;
            this->pwd=pwd;
            t=new Mytimer(id_m,pwd,60);
            t->lets_go();

            if(m.gettype()=="grh")
            {

                mgrh=new gestionrh(this); //setting the layout
                mgrh->set_session(id_m,pwd);
                mgrh->show(); //showing the new widget
                //hide_items();

               clear_session_details();
            }
            else  if(m.gettype()=="sales")
            {
ss= new uisales(this);
ss->show();
clear_session_details();
            }
            else  if(m.gettype()=="finance")
            {
ff= new finance(this);
ff->show();
clear_session_details();
            }
            else  if(m.gettype()=="crm")
            {
cc=new uicrm(this);
cc->show();
clear_session_details();
            }
            else  if(m.gettype()=="inventory")
            {
mm=new Menu_Inventory(this);
mm->show();
clear_session_details();
            }


        }
        else
        {   ui->id_error->setText("incorrect id");
            ui->id_error->setStyleSheet("QLabel {  color : white; }");
            ui->identification->clear();
            ui->pwd_error->setText("incorrect password");
            ui->pwd_error->setStyleSheet("QLabel {color :white;}");
            ui->password->clear();

        }

    }

}
void Mainframe::reposition()
{ QRect rec = geometry() ; /* Getting started initialisation */
    int height = rec.height();/*getting height from screen */
    int width = rec.width();/*getting width from screen */
    QPoint pt(width*0.85,height*0.15);//initialisation
    QPoint px(width*0.45,height*0.70);//----------------
    QPoint py(width*0.45,height*0.75);//----------------
    QPoint pb(width*0.615,height*0.725);//----------------
    QPoint pd(width*0.45,height*0.79);//----------------

    ui->options->move(pt); //resetting objects positions
    // ui->identification->move(px);//-------------------------
    // ui->password->move(py);//-------------------------
    // ui->connection->move(pb);//-------------------------
    ui->background->resize(width,height);
    ui->logo->resize(width*0.15,height*0.15);
    ui->logo->hide();



}
void Mainframe::resize(int x,int y)
{

    setFixedSize(x,y);
}
void Mainframe::set_background(QString path)
{
    QRect rec = geometry() ; /* Getting started initialisation */
    int height = rec.height();/*getting height from screen */
    int width = rec.width();/*getting width from screen */

    QPixmap myPixmap(path);/*creating image container */


    QPixmap scaledPixmap =myPixmap.scaled(width,height);/*scaling image to same screen height and width */
    ui->background->setPixmap(scaledPixmap);/*assiging background to qlaber */


}
void Mainframe::set_logo(QString path)
{

    QPixmap myPixmap(path);/*creating image container */
    ui->logo->setPixmap(path);/*assiging background to QLabel */

}
void Mainframe::on_identification_returnPressed()
{
    ui->password->setFocus();

}
void Mainframe::on_password_returnPressed()
{
    on_connection_clicked();
}
void Mainframe::hide_items()
{
    ui->password->hide();
    ui->identification->hide();
    ui->connection->hide();
}
void Mainframe::show_items()
{
    ui->password->show();
    ui->identification->show();
    ui->connection->hide();
}
void Mainframe::clear_session_details()
{
    ui->password->clear();
    ui->identification->clear();
    ui->pwd_error->clear();
    ui->id_error->clear();
}
