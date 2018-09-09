#include "menu_inventory.h"
#include "ui_menu_inventory.h"
#include <QtPrintSupport/QPrinter>
#include "smtp.h"
#include "ui_mainframe.h"
#include <QPainter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtPrintSupport/QPrintDialog>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextEdit>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QPrinter>
#include <QPrintDialog>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>

Menu_Inventory::Menu_Inventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu_Inventory)
{
    ui->setupUi(this);
}



Menu_Inventory::~Menu_Inventory()
{
    delete ui;
}

void Menu_Inventory::size_follower(QString cat_size)
{
    if(cat_size=="T-Shirt"||cat_size=="Hoodie"||cat_size=="Sweeter")
    {

        ui->comboBox_Size->clear();
        ui->comboBox_Size->insertItem(0,"Select_Size");
        ui->comboBox_Size->insertItem(1,"S");
        ui->comboBox_Size->insertItem(2,"M");
        ui->comboBox_Size->insertItem(3,"L");
        ui->comboBox_Size->insertItem(4,"XL");
        ui->comboBox_Size->insertItem(5,"XXL");
    }
    else
    {

        ui->comboBox_Size->clear();
        ui->comboBox_Size->insertItem(0,"Select_Size");
        for(int i=1;i<=9;i++)
        {
            QString size=QString::number(i+28);
            ui->comboBox_Size->insertItem(i,size);

        }
    }
}

void Menu_Inventory::on_pushButton_3_clicked()
{

}

void Menu_Inventory::on_Disconnect_clicked()
{
    int res= QMessageBox::warning(this,"Warning","Are you sure you want to disconnect !\n","coninue","cancel");
            if(res==0)
            {
                this->hide();
            }
            else
            {
                //Do Nothing
            }
}

void Menu_Inventory::on_comboBox_Category_currentTextChanged(const QString &arg1)
{
    size_follower(arg1);
}

void Menu_Inventory::on_pushButton_Add_product_released()
{

    added_date=QDate::currentDate();
    quantity=ui->lineEdit_Quantity->text().toInt();
    color=ui->lineEdit_Color->text();
    size=ui->comboBox_Size->currentText();
    name=ui->lineEdit_Name->text();
    type_of_fabric=ui->lineEdit_Type_fabric->text();
    gender=ui->comboBox_Gender->currentText();
    category=ui->comboBox_Category->currentText();
    weight=ui->lineEdit_Weigh->text().toFloat();
    initial_price=ui->lineEdit_initial_price->text().toFloat();
    nb_point=ui->lineEdit_NB_Ponts->text().toFloat();
    production_price=ui->lineEdit_Production_price->text().toFloat();
    Product p(added_date,quantity,color,size,name,type_of_fabric,gender,category,weight,initial_price,nb_point,production_price);
    /******** control ********/
inputcontrol ctrl;
int err=0;
    if(ctrl.is_number(ui->lineEdit_Quantity->text())==false){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Production_price->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Color->text())==false){err++;}
    if(ui->comboBox_Category->currentIndex()==0){err++;}
    if(ui->comboBox_Size->currentIndex()==0){err++;}
    if(ui->comboBox_Gender->currentIndex()==0){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Weigh->text())==false){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_initial_price->text())==false){err++;}
    if(ctrl.is_number(ui->lineEdit_NB_Ponts->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Type_fabric->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Name->text())==false){err++;}

    if(err>0){QMessageBox::critical(0,"system","you have "+QString::number(err)+" errors",QMessageBox::Ok);}


else {

    /*********add**********/
    if(p.add()==true)
    {
        QMessageBox::information(0,"sucess","Succussfully Added",QMessageBox::Ok);
    };
    }
}

void Menu_Inventory::on_pushButton_Search_Display_released()
{

        QString type;
        type = ui->comboBox_Search_ID->currentText();
        ui->tableView_Search_Display->setModel(tempProduct.search_product(type, ui->lineEdit_Search_key->text()));

}


/*void  Menu_Inventory::modify_product()
{
   tempProduct.select_product(ui->SelectPM->currentText().toInt());

   ui->lineEdit_Modify_name->setText(tempProduct.Get_name());
   QString y=QString::number(tempProduct.Get_weight());
   QString u=QString::number(tempProduct.Get_quantity());
   QString z=QString::number(tempProduct.Get_production_price());
   QString x=QString::number(tempProduct.Get_nb_point());
   QString w=QString::number(tempProduct.Get_initial_price());
   ui->lineEdit_Modify_Weight->setText(y);
   ui->lineEdit_Modify_production_price->setText(z);
   ui->lineEdit_Modify_NB_point->setText(x);
   ui->lineEdit_Modify_initial_price->setText(w);
    ui->lineEdit_Modify_quantity->setText(u);
    ui->comboBox_Modify_Category->setCurrentText(tempProduct.Get_category());
    ui->comboBox_Modify_gender->setCurrentText(tempProduct.Get_gender());
    ui->comboBox_Modify_size->setCurrentText(tempProduct.Get_size().toInt());

QDate date_b=tempProduct.Get_add_date();
int year;
int month;
int day;
day=date_b.day();
month=date_b.month();
year=date_b.year();
ui->comboBox_Modify_day->setCurrentIndex(day);
ui->comboBox_Modify_month->setCurrentIndex(month);
ui->comboBox_Modify_year->setCurrentIndex(year-1919);

}*/


void Menu_Inventory::on_LoadM_clicked()
{
    ui->SelectPM->clear();
    ui->SelectPM->setEnabled(1);
    ui->LoadM->setDisabled(1);
    QSqlQuery query;
    QSqlQueryModel *model =tempProduct.display_product();
    for(int i=0;i<=ui->tableView_Search_Display->width();i++)
    {
        ui->SelectPM->addItem(model->data(model->index(i,0)).toString());
    }
}

void Menu_Inventory::on_Pushbutton_Modify_Delete_clicked()
{
    tempProduct.select_product(ui->SelectPM->currentText().toInt());
    ui->lineEdit_Modify_name->setText(tempProduct.Get_name());
    ui->lineEdit_Modify_color->setText(tempProduct.Get_color());
    ui->lineEdit_Modify_type_fabric->setText(tempProduct.Get_type_of_fabric());
    QString y=QString::number(tempProduct.Get_weight());
    QString u=QString::number(tempProduct.Get_quantity());
    QString z=QString::number(tempProduct.Get_production_price());
    QString x=QString::number(tempProduct.Get_nb_point());
    QString w=QString::number(tempProduct.Get_initial_price());
    ui->lineEdit_Modify_Weight->setText(y);
    ui->lineEdit_Modify_production_price->setText(z);
    ui->lineEdit_Modify_NB_point->setText(x);
    ui->lineEdit_Modify_initial_price->setText(w);
     ui->lineEdit_Modify_quantity->setText(u);
     ui->comboBox_Modify_Category->setCurrentText(tempProduct.Get_category());
     ui->comboBox_Modify_gender->setCurrentText(tempProduct.Get_gender());
     ui->comboBox_Modify_size->setCurrentText(tempProduct.Get_size());

 /*QDate date_b=tempProduct.Get_add_date();
 int year;
 int month;
 int day;
 day=date_b.day();
 month=date_b.month();
 year=date_b.year();
 ui->comboBox_Modify_day->setCurrentIndex(day);
 ui->comboBox_Modify_month->setCurrentIndex(month);
 ui->comboBox_Modify_year->setCurrentIndex(year-1919);*/
}

void Menu_Inventory::on_pb_pdf_clicked()
{
    QString filename="Refill_Order.pdf";
          //Settings
          QPrinter printer;
          printer.setOrientation(QPrinter::Landscape);
          printer.setOutputFileName("C:/Users/Fares/Desktop/Refill_Order.pdf");
          printer.setPaperSize(QPrinter::A4);
          printer.setOutputFormat(QPrinter::PdfFormat);

          QPainter painter(&printer);
          painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
          ui->tableView_Search_Refill_Order_Display_2->render (&painter );
          painter.end();
          QMessageBox::information(this,tr("Exported!"),tr("Refill Orders list is now availble in pdf format "));

}

void Menu_Inventory::on_pushButton_Delete_Product_in_Modify_clicked()
{
    Product *pd= new Product();
        int id_product =ui->SelectPM->currentText().toInt();
        pd->Supprimer(id_product);
        if (pd->Supprimer(id_product)==true)
        {
            int res= QMessageBox::warning(this,"Warning","Are you sure you want to Delete this Product !\n","Delete","cancel");
                    if(res==0)
                    {
                        QMessageBox::information(0, qApp->tr("Add"),
                            qApp->tr("An exesting Product has been deleted"), QMessageBox::Ok);
                    }
                    else
                    {
                        //Do Nothing
                    }

        }
        else
            QMessageBox::critical(0, qApp->tr("Add"),
                qApp->tr("Problem?"), QMessageBox::Cancel);
     //   ui->spview->setModel(tmpSp.Afficher());
}



void Menu_Inventory::on_pushButton_Add_Truck_released()
{
    //id_truck = ui->lineEdit_Truck_ID->text().toInt();
    type = ui->lineEdit_Truck_Type->text();
    city_state_nb = ui->comboBox_Truck_City->currentText().toInt();
    sizeT = ui->comboBox_Truck_size->currentText();
    power = ui->lineEdit_Truck_Power->text();
    max_weight = ui->lineEdit_Truck_Max_weight->text().toFloat();
    initial_weight = ui->lineEdit_Truck_initial_weight->text().toFloat();
    price = ui->lineEdit_Truck_price->text().toFloat();
    contract = ui->lineEdit_Truck_Contract->text();
    availability = ui->comboBox_Truck_status->currentText();
    reason = ui->lineEdit_Add_Truck_reason->text();
    serial_num = ui->lineEdit_Add_Truck_serial_nb->text().toInt();
    /******** control ********/
inputcontrol ctrl;
int err=0;
    //if(ctrl.is_number(ui->lineEdit_Truck_ID->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Truck_Type->text())==false){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Truck_Max_weight->text())==false){err++;}
    if(ui->comboBox_Truck_City->currentIndex()==0){err++;}
    if(ui->comboBox_Truck_size->currentIndex()==0){err++;}
    if(ui->comboBox_Truck_status->currentIndex()==0){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Truck_initial_weight->text())==false){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Truck_price->text())==false){err++;}
    if(ctrl.is_number(ui->lineEdit_Add_Truck_serial_nb->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Truck_Contract->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Add_Truck_reason->text())==false){err++;}

    if(err>0){QMessageBox::critical(0,"system","you have "+QString::number(err)+" errors",QMessageBox::Ok);}


else {

    /*********add**********/
    Truck T(type,city_state_nb,sizeT,power,max_weight,initial_weight,price,contract,availability,reason,serial_num,887);//later you must add building id
    if(T.add()==true)
    {
        QMessageBox::information(0,"sucess","Truck Added",QMessageBox::Ok);
    };
}
}



void Menu_Inventory::size_follower_modify(QString cat_size)
{
    if(cat_size=="T-Shirt"||cat_size=="Hoodie"||cat_size=="Sweeter")
    {

        ui->comboBox_Modify_size->clear();
        ui->comboBox_Modify_size->insertItem(0,"Select_Size");
        ui->comboBox_Modify_size->insertItem(1,"S");
        ui->comboBox_Modify_size->insertItem(2,"M");
        ui->comboBox_Modify_size->insertItem(3,"L");
        ui->comboBox_Modify_size->insertItem(4,"XL");
        ui->comboBox_Modify_size->insertItem(5,"XXL");
    }
    else
    {

        ui->comboBox_Modify_size->clear();
        ui->comboBox_Modify_size->insertItem(0,"Select_Size");
        for(int i=1;i<=9;i++)
        {
            QString size=QString::number(i+28);
            ui->comboBox_Modify_size->insertItem(i,size);

        }
    }
}


void Menu_Inventory::on_comboBox_Modify_Category_currentIndexChanged(const QString &arg1)
{
    size_follower_modify(arg1);
}

void Menu_Inventory::on_pushButton_Truck_Display_clicked()
{
    ui->tableView_Search_Truck_List->setModel(tempTruck.search_truck(ui->lineEdit_Search_Truck_ID->text()));

}

void Menu_Inventory::on_pushButton_Load_Truck_Modify_clicked()
{
    ui->comboBox_Truck_Modify_Select_ID->clear();
    ui->comboBox_Truck_Modify_Select_ID->setEnabled(1);
    ui->pushButton_Load_Truck_Modify->setDisabled(1);
    QSqlQuery query;
    QSqlQueryModel *model =tempTruck.display_truck();
    for(int i=0;i<=ui->tableView_Search_Truck_List->width();i++)
    {
        ui->comboBox_Truck_Modify_Select_ID->addItem(model->data(model->index(i,0)).toString());
    }
}

void Menu_Inventory::on_pushButton_Truck_Delete_clicked()
{
    Truck *Tc= new Truck();
        int id_truck =ui->comboBox_Truck_Modify_Select_ID->currentText().toInt();
        Tc->Supprimer_T(id_truck);
        if (Tc->Supprimer_T(id_truck)==true)
        {
            int res= QMessageBox::warning(this,"Warning","Are you sure you want to Delete Truck !\n","Delete","cancel");
                    if(res==0)
                    {
                        QMessageBox::information(0, qApp->tr("Add"),
                            qApp->tr("An exesting Truck has been deleted"), QMessageBox::Ok);
                    }
                    else
                    {
                        //Do Nothing
                    }

            ui->pushButton_Load_Truck_Modify->setEnabled(1);
        }
        else
            QMessageBox::critical(0, qApp->tr("Add"),
                qApp->tr("Problem?"), QMessageBox::Cancel);
     //   ui->spview->setModel(tmpSp.Afficher());
}



void Menu_Inventory::on_pushButton_Add_Refill_Submit_clicked()
{
    date= QDate::currentDate();
    state = ui->comboBox_Refill_Select_state->currentText();
    type_o = ui->comboBox_Refill_Select_Type->currentText();
    ETA= ui->dateEdit_refill_order->date();
    id_building = ui->comboBox_Refill_Select_Building->currentText().toInt();

    Refill_Order R(date,state,type_o,ETA,id_building);

    /******** control ********/
inputcontrol ctrl;
int err=0;
    //if(ctrl.is_number(ui->lineEdit_Refill_Add_ID->text())==false){err++;}
    if(ui->comboBox_Refill_Select_state->currentIndex()==0){err++;}
    if(ui->comboBox_Refill_Select_Type->currentIndex()==0){err++;}

    if(ETA<date){err++;}
    if(ui->comboBox_Refill_Select_Building->currentIndex()==0){err++;}

    if(err>0){QMessageBox::critical(0,"system","you have "+QString::number(err)+" errors",QMessageBox::Ok);}


else {

        /*********add**********/

    if(R.add()==true)
    {

            int res= QMessageBox::warning(this,"Warning","Do you want to Export this Refill Order to PDF!\n","Yes","No");
                    if(res==0)
                    {
                        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty())
                        {
                            fileName.append(".pdf");
                        }
                        QPrinter printer(QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setPaperSize(QPrinter::A4);
                        printer.setOutputFileName(fileName);
                        QTextDocument doc;
                        int x=R.get_date().day();
                        int y=R.get_date().month();
                        int z=R.get_date().year();

                        int u=R.get_eta().day();
                        int v=R.get_eta().month();
                        int w=R.get_eta().year();
                            doc.setHtml("<body><h1 align=center color=red><i><img src=C:/Users/Fares/Desktop/rsz_back_ground_global.png widh= 140px height= 140px/>Hammadi ABID </i></h1> <table><tr><td><br></td><td><img src=C:/Users/Fares/Desktop/rsz_back.ico align=right/></td></tr></table><br><h2 align=center>REFILL ORDER n° "+QString::number(R.get_id())+"</h2><br><h3>Order Description:<h3><br><p>The Order has been submitted <i>on "+ QString::number(x) +"/"+ QString::number(y) +"/"+ QString::number(z) +" .</i> <br><br> It's being currently prepared for shippment to the Hammadi Abid's <i>Building n°"+QString::number(R.get_building())+"</i> located in <i>"+R.get_state()+"</i> City.<br><br>the urgency of the order is <i>"+R.get_type()+"</i>. <br><br> And it will be expected at the destination on <i>"+ QString::number(u) +"/"+ QString::number(v) +"/"+ QString::number(w) +" .</i></p></body>");
                          doc.setPageSize(printer.pageRect().size());
                            doc.print(&printer);
                    }
                    else
                    {
                        //Do Nothing
                    }

            ui->pushButton_Load_Refill_Modify->setEnabled(1);

        QMessageBox::information(0,"sucess","Successfully Added",QMessageBox::Ok);
    };

    }
}

void Menu_Inventory::on_pushButton_Search_Refill_Order_Display_2_clicked()
{
     ui->tableView_Search_Refill_Order_Display_2->setModel(tempRefill.search_Refill(ui->lineEdit_Search_Refill_ORDER_ID->text()));
    //tableView_Search_Refill_Order_Display_2
}

void Menu_Inventory::on_pushButton_Load_Refill_Modify_clicked()
{
    ui->comboBox_Refill_modify_Select_order_ID->clear();
    ui->comboBox_Refill_modify_Select_order_ID->setEnabled(1);
    ui->pushButton_Load_Refill_Modify->setDisabled(1);
    QSqlQuery query;
    QSqlQueryModel *model =tempRefill.display_Refill();
    for(int i=0;i<=ui->tableView_Search_Refill_Order_Display_2->width();i++)
    {
        ui->comboBox_Refill_modify_Select_order_ID->addItem(model->data(model->index(i,0)).toString());
    }
}

void Menu_Inventory::on_pushButton_Refill_Order_Modify_Delete_clicked()
{
    Refill_Order *RO = new Refill_Order();
        int id_refill =ui->comboBox_Refill_modify_Select_order_ID->currentText().toInt();
        RO->archive(id_refill);
        if (RO->archive(id_refill)==true)
        {
            int res= QMessageBox::warning(this,"Warning","Are you sure you want to Archive this Refill Order !\n","Confirm","cancel");
                    if(res==0)
                    {
                        QMessageBox::information(0, qApp->tr("Add"),
                            qApp->tr("An exesting Refill Order has been Archived"), QMessageBox::Ok);
                    }
                    else
                    {
                        //Do Nothing
                    }

            ui->pushButton_Load_Refill_Modify->setEnabled(1);
        }
        else
            QMessageBox::critical(0, qApp->tr("Add"),
                qApp->tr("Problem?"), QMessageBox::Cancel);
     //   ui->spview->setModel(tmpSp.Afficher());
}

void Menu_Inventory::on_pushButton_Load_Delivery_Details_clicked()
{
    ui->comboBox_Refill_Delivery_Driver_ID->clear();
    ui->comboBox_Refill_Delivery_Driver_ID->setEnabled(1);
    ui->pushButton_Load_Delivery_Details->setDisabled(1);
    QSqlQuery query;
    QSqlQueryModel *model =tempTruck.display_driver();
    ui->tableView_Driver_Display->setModel(tempTruck.display_driver());
    for(int i=0;i<=ui->tableView_Driver_Display->width();i++)
    {
        //ui->comboBox_Refill_Delivery_Driver_ID->insertItem(model->data(model->index(i,0)).toString());
        ui->comboBox_Refill_Delivery_Driver_ID->addItem(model->data(model->index(i,0)).toString());
    }


    ui->comboBox_Refill_Delivery_Truck_ID->clear();
    QSqlQueryModel *model2 =tempTruck.display_truck();
    for(int i=0;i<=ui->tableView_Search_Truck_List->width();i++)
    {
        //ui->comboBox_Refill_Delivery_Truck_ID->insertItem(model2->data(model->index(i,0)).toString());
        ui->comboBox_Refill_Delivery_Truck_ID->addItem(model2->data(model->index(i,0)).toString());
    }


    ui->comboBox_Refill_Delivery_Order_ID->clear();
    QSqlQueryModel *model3 =tempRefill.display_Refill();
    for(int i=0;i<=ui->tableView_Search_Refill_Order_Display_2->width();i++)
    {
        ui->comboBox_Refill_Delivery_Order_ID->addItem(model3->data(model->index(i,0)).toString());
    }


}



void Menu_Inventory::on_pushButton_Modify_Product_Confirm_clicked()
{ added_date=QDate::currentDate();
    id_product=ui->SelectPM->currentText().toInt();
    quantity=ui->lineEdit_Modify_quantity->text().toInt();
    color=ui->lineEdit_Modify_color->text();
    size=ui->comboBox_Modify_size->currentText();
    name=ui->lineEdit_Modify_name->text();
    type_of_fabric=ui->lineEdit_Modify_type_fabric->text();
    gender=ui->comboBox_Modify_gender->currentText();
    category=ui->comboBox_Modify_Category->currentText();
    weight=ui->lineEdit_Modify_Weight->text().toFloat();
    initial_price=ui->lineEdit_Modify_initial_price->text().toFloat();
    nb_point=ui->lineEdit_Modify_NB_point->text().toFloat();
    production_price=ui->lineEdit_Modify_production_price->text().toFloat();



    Product *p = new Product (added_date,quantity,color,size,name,type_of_fabric,gender,category,weight,initial_price,nb_point,production_price);
    qDebug() << ui->SelectPM->currentText();

    /******** control ********/
inputcontrol ctrl;
int err=0;
    if(ctrl.is_number(ui->lineEdit_Modify_quantity->text())==false){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Modify_production_price->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Modify_color->text())==false){err++;}
    if(ui->comboBox_Modify_Category->currentIndex()==0){err++;}
    if(ui->comboBox_Modify_size->currentIndex()==0){err++;}
    if(ui->comboBox_Modify_gender->currentIndex()==0){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Modify_Weight->text())==false){err++;}
    if(ctrl.is_valid_float(ui->lineEdit_Modify_initial_price->text())==false){err++;}
    if(ctrl.is_number(ui->lineEdit_Modify_NB_point->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Modify_type_fabric->text())==false){err++;}
    if(ctrl.is_valid_name(ui->lineEdit_Modify_name->text())==false){err++;}

    if(err>0){QMessageBox::critical(0,"system","you have "+QString::number(err)+" errors",QMessageBox::Ok);}


else {

    /*********add**********/

    if (p->modify(id_product))
     {
         qDebug() << p->Get_name();
         QMessageBox::information(0, qApp->tr("Updating"),
             qApp->tr("the provider is updated"), QMessageBox::Ok);
        ui->tableView_Search_Display->setModel(p->display_product());
       }
       else
         { QMessageBox::critical(0, qApp->tr("Updating"),
             qApp->tr("Error Updating"), QMessageBox::Cancel);

         }
}

}



void Menu_Inventory::on_pushButton_Modify_Truck_Submit_clicked()
{
    id_truck = ui->comboBox_Truck_Modify_Select_ID->currentText().toInt();
    type = ui->lineEdit_Truck_Modify_Type->text();
    city_state_nb = ui->comboBox_Truck_Modify_City->currentText().toInt();
    sizeT = ui->comboBox_Truck_Modify_size->currentText();
    power = ui->lineEdit_Truck_Modify_Power->text();
    max_weight = ui->lineEdit_Truck_Modify_Max_weight->text().toFloat();
    initial_weight = ui->lineEdit_Truck_Modify_initial_weight->text().toFloat();
    price = ui->lineEdit_Truck_Modify_price->text().toFloat();
    contract = ui->lineEdit_Truck_Modify_Contract->text();
    availability = ui->comboBox_Truck_Modify_status->currentText();
    reason = ui->lineEdit_Modify_Truck_reason->text();
    serial_num = ui->lineEdit_Modify_Truck_serial_nb->text().toInt();



    Truck *T = new Truck (type,city_state_nb,sizeT,power,max_weight,initial_weight,price,contract,availability,reason,serial_num,9454);//later you must present id building
    qDebug() << ui->comboBox_Truck_Modify_Select_ID->currentText();

    if (T->modify(id_truck))
    {
        QMessageBox::information(0, qApp->tr("Updating"),
            qApp->tr("the Truck is updated"), QMessageBox::Ok);
       ui->tableView_Search_Truck_List->setModel(T->display_truck());
      }
      else
        { QMessageBox::critical(0, qApp->tr("Updating"),
            qApp->tr("Error Updating"), QMessageBox::Cancel);
        }
}


void Menu_Inventory::on_pushButton_Email_clicked()
{

//    mail e;
//    e.setModal(true);
//    e.exec();
}

void Menu_Inventory::on_tabWidget_3_destroyed()
{

}

void Menu_Inventory::on_pushButton_Modify_Refill_Show_clicked()
{
    tempRefill.select_order(ui->comboBox_Refill_modify_Select_order_ID->currentText().toInt());
    QString x=QString::number(tempRefill.get_building());
    ui->dateEdit_Modify_refill_order->setDate(tempRefill.get_eta());
     ui->comboBox_Refill_Modify_Select_Building_2->setCurrentText(x);
     ui->comboBox_Refill_Modify_Select_Type->setCurrentText(tempRefill.get_type());
     ui->comboBox_Refill_modify_Select_state->setCurrentText(tempRefill.get_state());
}

void Menu_Inventory::on_pushButton_Modify_Refill_Submit_clicked()
{


       date=QDate::currentDate();
       id_refill=ui->comboBox_Refill_modify_Select_order_ID->currentText().toInt();
       id_building=ui->comboBox_Refill_Modify_Select_Building_2->currentText().toInt();
       ETA= ui->dateEdit_Modify_refill_order->date();
       type=ui->comboBox_Refill_Modify_Select_Type->currentText();
       state=ui->comboBox_Refill_modify_Select_state->currentText();

       Refill_Order *RO = new Refill_Order (date,state,type,ETA,id_building);

       qDebug() << ui->comboBox_Refill_modify_Select_order_ID->currentText();

       /******** control ********/
   inputcontrol ctrl;
   int err=0;
       if(ui->comboBox_Refill_modify_Select_state->currentIndex()==0){err++;}
       if(ui->comboBox_Refill_Modify_Select_Type->currentIndex()==0){err++;}
       if(ETA<date){err++;}
       if(ui->comboBox_Refill_Modify_Select_Building_2->currentIndex()==0){err++;}

       if(err>0){QMessageBox::critical(0,"system","you have "+QString::number(err)+" errors",QMessageBox::Ok);}


   else {

           /*********Modify**********/

        if (RO->modify(id_refill))
        {
            qDebug() << RO->get_state();
            QMessageBox::information(0, qApp->tr("Updating"),
                qApp->tr("the Order is updated"), QMessageBox::Ok);
           ui->tableView_Search_Refill_Order_Display_2->setModel(RO->display_Refill());
          }
          else
            { QMessageBox::critical(0, qApp->tr("Updating"),
                qApp->tr("Error Updating"), QMessageBox::Cancel);

            }
}
}



void Menu_Inventory::on_pushButton_Add_Import_Submit_clicked()
{
    id_order = ui->lineEdit_Import_Add_ID->text().toInt();

    id_product_i = ui->comboBox_Import_select_product->currentText().toInt();
    quantity_i = ui->lineEdit_Import_Add_QUantity->text().toInt();

    /******** control ********/

    inputcontrol ctrl;
    int err=0;
    if(ctrl.is_number(ui->lineEdit_Import_Add_ID->text())==false){err++;}
    if(ctrl.is_number(ui->lineEdit_Import_Add_QUantity->text())==false){err++;}

    if(err>0){QMessageBox::critical(0,"system","you have "+QString::number(err)+" errors",QMessageBox::Ok);}


else {

        /*********add**********/

    Import_order I(id_order,id_product_i,quantity_i,6652);
    if(I.add()==true)
    {
        QMessageBox::information(0,"sucess","Seccessfully Added",QMessageBox::Ok);
    };

    }
}



/*  */

void Menu_Inventory::on_pushButton_Load_Product_List_clicked()
{
//    ui->comboBox_Import_select_product->clear();
      ui->comboBox_Import_select_product->setEnabled(1);
      ui->pushButton_Load_Product_List->setDisabled(1);
      QSqlQuery query;
      QSqlQueryModel *model =tempProduct.display_product();
      for(int i=0;i<=ui->tableView_Search_Display->width();i++)
      {
          ui->comboBox_Import_select_product->addItem(model->data(model->index(i,0)).toString());
      }
}

void Menu_Inventory::on_pushButton_Show_Truck_clicked()
{
    tempTruck.select_truck(ui->comboBox_Truck_Modify_Select_ID->currentText().toInt());
    ui->lineEdit_Truck_Modify_Type->setText(tempTruck.Get_type());
    ui->lineEdit_Truck_Modify_Power->setText(tempTruck.Get_power());
    ui->lineEdit_Truck_Modify_Contract->setText(tempTruck.Get_contract());
    ui->lineEdit_Modify_Truck_reason->setText(tempTruck.Get_reason());
    QString y=QString::number(tempTruck.Get_max_weight());
    QString z=QString::number(tempTruck.Get_initial_weight());
    QString w=QString::number(tempTruck.Get_price());
    QString u=QString::number(tempTruck.Get_serial_num());
    QString x=QString::number(tempTruck.Get_city_state_nb());
    ui->lineEdit_Truck_Modify_Max_weight->setText(y);
    ui->lineEdit_Truck_Modify_initial_weight->setText(z);
    ui->lineEdit_Truck_Modify_price->setText(w);
    ui->lineEdit_Modify_Truck_serial_nb->setText(w);
     ui->comboBox_Truck_Modify_status->setCurrentText(tempTruck.Get_availability());
     ui->comboBox_Truck_Modify_size->setCurrentText(tempTruck.Get_size());
     ui->comboBox_Truck_Modify_City->setCurrentText(x);

}

void Menu_Inventory::on_pushButton_export_Excel_clicked()
{

    QSqlQueryModel  *model = new QSqlQueryModel() ;
    QString linki = QFileDialog::getSaveFileName(this, tr("Export CSV"),"/liste_products.csv", tr("Comma Separated Values (*.csv)"));


Product *e=new (Product);

    int x = 0;
    QString exportdata;
    model=e->display_product();
    int counthidden = 0, jint = 0;

    while (jint < model->columnCount()) {

    counthidden+=ui->tableView_Search_Display->isColumnHidden(jint);
    jint++;
    }


    while (x < model->columnCount()){

    if (!ui->tableView_Search_Display->isColumnHidden(x)) {

    exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());
    //msgbox(exportdata);
    if (model->columnCount() - x != counthidden)
    exportdata.append(";");
    else
    exportdata.append("\n");

    }
    x++;

    }

    int z = 0;

    exportdata.append("\n");
    while (z < model->rowCount()) {

    x = 0;
    while (x < model->columnCount()) {
    if (!ui->tableView_Search_Display->isColumnHidden(x)) {

    exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


    if (model->columnCount() - x != counthidden)
    {
        exportdata.append(";");

    }
    else
    {
    exportdata.append("\n");

    }
    }

    x++;

    }
    exportdata.append("\n");
    z++;
    }



       QFile file;
       if (!linki.isEmpty()) {
     file.setFileName(linki);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
    }
    QByteArray ttext;
    ttext.append(exportdata);
    file.write(ttext);
    /* closing the file */

}



/*void Menu_Inventory::on_pushButton_Export_PDF_Refill_clicked()
{
    QString id_refill = ui->lineEdit_Refill_Add_ID->text();
        tempRefill.search_Refill(id_refill);
        ui->lineEdit_Refill_Add_ID->setText(QString::number(tempRefill.get_id()));
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        QTextDocument doc;
      //  doc.setHtml("<body><h1><i><img src=C:/Users/AZUS/Desktop/2A7/Projet/ProjetFinale/MSI-Gaming-Logo-Large.png widh= 40px height= 40px/>CONTRACT FOR SERVICES: "+tmpCt.GetnameC()+"</i></h1><br><img src=C:/Users/AZUS/Desktop/2A7/Projet/ProjetFinale/DS_logo.png widh= 40px height= 40px/><br>Unless otherwise stated, the Young Workers Advisory Service (YWAS)<br>accepts no liability for the contents of this document except where subsequently<br>confirmed in writing. YWAS will not be held liable to you or to any other person for loss<br>and damage (including direct, consequential or economic loss or damage) however caused<br>and whether by negligence or otherwise which may result directly or indirectly from the<br>receipt or use of this communication or attached information.<br>Nothing in this document should be taken to constitute legal advice.<br><br><br>THIS CONTRACT is made BETWEEN<br>MSI[hereinafter called “Purchaser”]<br>AND <br>"+tmpSp.Getname()+" [hereinafter called “Supplier”]<br>WHEREAS<br>The Supplier has its own Australian Business Number (ABN ………………………….) and is an<br>entity in its own right.<br>The Purchaser has an Australian Business Number (ABN ………………………….) and is an<br>entity in its own right.<br>The parties desire to record the terms of their agreement.<br>THE PARTIES AGREE AS FOLLOWS<br><b><i>1. BRIEF OR SERVICES REQUIRED</i></b><br>1.1. The Supplier will provide that detailed in SCHEDULE 1<br>1.2. Commencement date<br>1.3. Completion date<br>1.4. The parties will divide the workspace equitably in view of the number of employees,<br>placements and volunteers and equipment and resources required to be<br>accommodated.<br><b><i>2. EQUIPMENT</i></b><br>2.1. The Supplier will provide that listed in SCHEDULE 2.<br>2.2. The Purchaser will provide that listed in SCHEDULE 3.2<br><b><i>3. OTHER CONTRACTORS OR EMPLOYEES</i></b><br>3.1. The Supplier is free to engage Employees or other Contractors with the agreement of<br>the Purchaser.<br>3.2. The Purchaser will not make an unreasonable refusal regarding 3.1.<br><b><i>4. TRAINING AND DEVELOPMENT</i></b><br>4.1. The Supplier is responsible for the their own training and development. velop and<br>implement joint in house training, team building and group supervision in good faith.<br>4.2. The Purchaser will provide training and development for the following:<br><b><i>5. PAYMENT</i></b><br>5.1. Subject to this agreement, the Purchaser will pay the Supplier on the payment basis as<br>detailed in SCHEDULE 4.<br>5.2. The Purchaser’s obligation to pay the amount specified in SCHEDULE 4 is subject to<br>compliance by the Supplier of its obligations under this contract.<br>5.3. The Purchaser may withhold payment where there is doubt as to the Supplier’s<br>compliance with this contract or entitlement to payment.<br>5.4. Any payment made by the Purchaser shall not be construed as an acknowledgement<br>that the Supplier has discharged its obligations under this contract.<br><b><i>6. PROMOTION</i></b><br>6.1. The parties are not required to promote the other party’s services while networking and<br>undertaking other activities.<br><b><i>7. MANAGEMENT</i></b><br>7.1. The parties will facilitate and participate in good faith in regular meetings in order to<br>assist communication and address matters that may impact on each other.<br><b><i>8. TERMINATION</i></b><br>8.1. The parties may terminate the contract in any of the following circumstances upon …….<br>written notice to the other party:<br><b>a) either party determines that the other is no longer compliant with this contract;</b><br><b>b) control of either business is transferred to a new organisation without prior approval</b><br><b>of the other party;</b><br><b>c) either party fails to remedy any breach of this contract in respect of which the otherparty has requested in writing that the party remedy, within seven (7) days of therequest being given; or</b><br><b>d) either party ceases to carry on business; becomes bankrupt; enters into liquidation;has a receiver or official manager appointed; or any other insolvency proceedingsare taken.</b><br><b><i>9. CONSEQUENCES OF TERMINATION</i></b><br>9.1 Termination of this contract shall be without prejudice and in addition to such other rightsas the parties have against each other.<br>9.2 If one party terminates this contract, the other party may:<br><b>a) in relation to any payment which has not yet been paid to the party under thiscontract, retain that payment entirely or reduce it proportionally; and</b><br><b>b) in relation to any payment which has been paid to the Supplier under this contract,recover that payment entirely or proportionally;according to the proportion of the agreement actually delivered by the party beforetermination.</b><br>9.3 The rights set out in Clause 8.2 are in addition to any other rights the State of Queenslandmay have.<br><b><i>10. OBSERVANCE OF LAWS AND AWARD CONDITIONS</i></b><br>10.1. The parties must comply with all Commonwealth, State and Local laws for thetime being in force and must not do or permit to be done any act which may conflict withsuch law, including (but without limiting the generality of this Clause) the following:<br><b>a) all award conditions, workplace health and safety provisions and any other industrialrelations requirements applicable to the Grantee undertaking the Project;<br><b>b) the provisions of the Anti-Discrimination Act 1991 at all times when undertakingthe Project;<br><b>c) the provisions of the Commission for Children and Young People and ChildGuardian Act 2000;</b><br><br><br>IN WITNESS WHEREOF the parties have executed this contract on the dates below.SIGNED, for and on behalf of :<br><br><br><p><i>"+tmpCt.Getresponsible()+"</i></p>. by MSI<br>................................................................<br>................................................................<br>................................................................[Print Name] ] [Signature] …………………<br>this <p><i>"+tmpCt.Getdat_begin()+"</i></p> day of beginning.<br>in the presence of MSI<br>[Print Witness’ Name] ] [Signature] …………………<br>SIGNED, for and on behalf of ]…………………………………………………………….<br>by <p><i>"+tmpCt.Getresponsible()+"</i></p><br>[Print Name] ] [Signature] …………………<br>this <p><i>"+tmpCt.Getdate_end()+"</i></p> day of ending.<br>in the presence of MSI.<br>*************<br>*************<br>*************<br>*************<br>*************<br>To Conclde this contract, here some infos about this supplier: <br>Name of the contract: "+tmpCt.GetnameC()+"<br>The contract begins at: "+tmpCt.Getdat_begin()+"<br>The contract ends at: "+tmpCt.Getdate_end()+"<br>this contract made by: mr."+tmpCt.Getresponsible()+" to produce us more "+tmpCt.Gettyple()+" and to assure this contract here's some infos installed in our database: "+QString::number(tmpCt.Getid())+"<br>Adresse: "+tmpCt.Getadresse1()+" "+tmpCt.Getadresse2()+" "+QString::number(tmpCt.Getcp())+" from "+tmpCt.Getcity()+" "+tmpCt.Getcountry()+"</body>");
            doc.setHtml("<body><h1><i>Hammadi ABID </i></h1> <table><tr><td><h2>REFILL ORDER n° "+QString::number(tempRefill.get_id())+"</h2></td><td><img src=C:/Users/Fares/Desktop/rsz_back_ground_global.png/></td></tr></table><br><h3>Description<h3><br><p>The has been submitted on ****** and it's being currently prepared for shippment<br> to the Hammadi Abid's Building°"+QString::number(tempRefill.get_building())+" located in "+tempRefill.get_state()+" City.<br>the urgency of the order is "+tempRefill.get_type()+" <br> and it will be expected at destination on ******</p></body>");
         //   "+ tempRefill.get_eta() +"
            //"+ tempRefill.get_date() +"
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}*/

void Menu_Inventory::on_pushButton_clicked()
{
    tempRefill.select_order(ui->comboBox_Refill_Delivery_Order_ID->currentText().toInt());
    QString x=QString::number(tempRefill.get_building());
    ui->dateEdit_Delivery_ETA_order_2->setDate(tempRefill.get_eta());
    ui->dateEdit_Delivery_ETA_order_2->setDisabled(1);
}


