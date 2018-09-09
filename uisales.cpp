#include "uisales.h"
#include "ui_uisales.h"


uisales::uisales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uisales)
{row_order=0;
    order_row_order=0;
    choice=0;
    e=new employee();
     p=new Product();
     c=new Customer();
     o=new Order();

     s=new sale();
      id_employee=0;
      id_client=0;
      id_order=0;
      id_export_line=0;

    ui->setupUi(this);
    ui->id_seller_com->setModel(e->employee_id_list());
    ui->id_product_com->setModel(p->select_ID_product());
    ui->id_client_com->setModel(c->client_id_list());
    ui->id_product_com_oder->setModel(p->select_ID_product());
    ui->id_client_com_order->setModel(c->client_id_list());
    s->count_products();
    s->select_date();
   ui->histograph->insert_values(s->Get_sales_2010_2011(),
                              s->Get_sales_2011_2012(),
                              s->Get_sales_2012_2013(),
                              s->Get_sales_2013_2014(),
                              s->Get_sales_2014_2015());
    ui->stat->insert_values(s->Get_total_products(),s->Get_product_groupe());
    total_product_points_number=0;
    total_price=0;
    ui->TV_display_sale->setModel(s->Display_sale());
}
uisales::~uisales()
{
    delete ui;
    delete e;
    delete p;
    delete c;
    delete s;
}
/*--------- ajout seller information for sales--------------------*/
void uisales::on_id_seller_com_currentTextChanged(const QString &arg1)
{


    int var=arg1.toInt();
    e->select_employee(var);
    ui->name_seller_le->setText(e->Get_name()+" "+e->Get_lastname());
    ui->phone_number_seller->setText(QString::number(e->Get_phone_number()));


}
/*--------- ajout id product for sales--------------------*/
void uisales::on_id_product_com_currentTextChanged(const QString &arg1)
{
    int var=arg1.toInt();
    p->select_product(var);
    ui->name_product_le->setText(p->Get_name());
    ui->category_le->setText(p->Get_category());
    ui->bounty_points_le->setText(QString::number(p->Get_nb_point()));
    ui->product_size_le->setText(p->Get_size());
}
/*--------- ajout client information for sales --------------------*/
void uisales::on_id_client_com_currentTextChanged(const QString &arg1)
{
    int var=arg1.toInt();
    c->select_client(var);
    ui->name_client_le->setText(c->Get_family_name());
    ui->total_client_points_le->setText(QString::number(c->Get_nb_points()));
}
/*--------- create sale line--------------------*/
void uisales::on_create_sale_line_clicked()
{
    QString quantity=ui->product_quantity->text();
    if(i.is_number(quantity))
    {
    if(check_existence(ui->id_product_com->currentText()))
    {

       int modification_pos=ui->sale_lines_com->currentIndex();
int new_quantity=old_qt+ui->product_quantity->text().toInt();
         ui->sale_lines->setItem(modification_pos,1,new QTableWidgetItem(QString::number(new_quantity)));
 p->select_product(ui->id_product_com->currentText().toInt());
         float x=p->Get_initial_price();
 QString quantity=ui->product_quantity->text();     /* selection des valeur */
         double net_product_price=quantity.toInt()*x;
         total_price=total_price+(net_product_price*18)/100+net_product_price;
         ui->total_price_le->setText(QString::number(total_price));
         net_price=total_price-total_price*18/100;
         ui->net_price_le->setText(QString::number(net_price));
    }
 else   {
    QString quantity=ui->product_quantity->text();     /* selection des valeur */
    QString id_product=ui->id_product_com->currentText(); /*  a partir du combobox et du lineedit*/
    ui->sale_lines->insertRow(row_order); /* insertion d'un record dans le tablewidget */
    ui->sale_lines->setItem(row_order,0,new QTableWidgetItem(id_product)); /* insertion du 1er champ */
    ui->sale_lines->setItem(row_order,1,new QTableWidgetItem(quantity));/* insertion du 2eme champ */
    s->add_line(id_product.toInt(),quantity.toInt()); /* insertion de la ligne dans les vecteur de la vente */
    p->select_product(ui->id_product_com->currentText().toInt());/* fetch de valeur de la base de donnée */


    float x=p->Get_initial_price();
    ui->tva_le->setText("18%");
    double net_product_price=quantity.toInt()*x;
    total_price=total_price+(net_product_price*18)/100+net_product_price;
    ui->total_price_le->setText(QString::number(total_price)); /* insertion des valeur dans les champs corrsepondant + calcul de nouveau resultats*/
    total_product_points_number +=p->Get_nb_point()*quantity.toInt();
    ui->discount_value_le->setText(QString::number(total_product_points_number ));
    net_price=total_price-total_price*18/100;
    ui->net_price_le->setText(QString::number(net_price));
    row_order++;
    ui->sale_lines_com->insertItem(row_order,ui->id_product_com->currentText());
    choice=0;
    }
    }
    else
    {
        QMessageBox::critical(0,"system","Verify your quantity field! ",QMessageBox::Ok);
    }
}
/*--------- ajout seller information--------------------*/
void uisales::on_seller_enable_toggled(bool checked)
{

    ui->name_seller_le->setDisabled(checked);
    ui->phone_number_seller->setDisabled(checked);
    ui->id_seller_com->setDisabled(checked);

}
/*--------- ajout client informations--------------------*/
void uisales::on_client_enable_toggled(bool checked)
{

    ui->name_client_le->setDisabled(checked);

    ui->total_client_points_le->setDisabled(checked);
    ui->id_client_com->setDisabled(checked);
}
/*--------- ajout sales--------------------*/
void uisales::on_finish_sale_clicked()
{
   if(ui->seller_enable->checkState())
    {id_employee=0;}
    else
    {id_employee=ui->id_seller_com->currentText().toInt();}
 if(ui->client_enable->checkState())
    {id_client=0;}
 else {id_client=ui->id_client_com->currentText().toInt();}
      s->insert_sale_data(id_client,id_employee);
if(ui->sale_lines_com->count()==0)
{ QMessageBox::critical(0,"system","you didn't add ",QMessageBox::Ok);}
else
{
if(s->ajouter())
         {
    QMessageBox::information(0,"system","added with success",QMessageBox::Ok);
         }
else
         {
    QMessageBox::critical(0,"system","error with data base",QMessageBox::Ok);
    delete s;/* liberation de la mémoire et liberation des vecteurs */
    s=new sale();
         }
}
}
/*--------- cancel sale line--------------------*/
void uisales::on_cancel_sale_line_clicked()
{
    if(ui->id_product_com->currentText()=="")
    {
        QMessageBox::critical(0,"system","no sale lines to cancel",QMessageBox::Ok);
    }
    else
    { //if()
        //int id=ui->sale_lines_com->currentText().toInt();
       // s->cancel_line(id);
        ui->sale_lines->removeRow(ui->sale_lines_com->currentIndex());
        row_order--;

        ui->sale_lines_com->removeItem(ui->sale_lines_com->currentIndex());
    }
}
/*---------fonction for ajout sales--------------------*/
void uisales::increment_quantity(int pos)
{
old_qt=s->update_line_quantity(ui->product_quantity->text().toInt(),pos);
}
/*---------fonction for ajout sales--------------------*/
bool uisales::check_existence(QString id )
{
for(int i=0;i<=row_order;i++)
 {ui->sale_lines_com->setCurrentIndex(i);

    if(id==ui->sale_lines_com->currentText())
    {

      increment_quantity(i);
        return true;}

    }

return false;

}
/*---------fonction for ajout sales--------------------*/
void uisales::increment_quantity(int pos,QString object_name)
{
    qDebug()<< "trying for a quantity increase for order or sale line fingers crossed if you didn't hear from me then it's the pointer";
    if(object_name=="sale")
    {
        old_qt=s->update_line_quantity(ui->product_quantity->text().toInt(),pos);
    }

    else if(object_name=="order")
    {
        qDebug()<<"trying to cast an quantity increase in order ... stand by";
        order_old_qt=o->update_line_quantity(ui->product_quantity_order->text().toInt(),pos);
    }


}
/*---------fonction for ajout sales --------------------*/


bool uisales::check_existence(QString id,QString object_name )
{

    if(object_name=="sale")
    { for(int i=0;i<=row_order;i++)
        {qDebug()<< "incrementing quantity for sale";
            ui->sale_lines_com->setCurrentIndex(i);

            if(id==ui->sale_lines_com->currentText())
            {

                increment_quantity(i,object_name);
                return true;
            }

        }
    }
    else if (object_name=="order")
    {
        qDebug()<< "incrementing quantity for order";
        for(int i=0;i<=order_row_order;i++)
        {ui->order_lines_com->setCurrentIndex(i);

            if(id==ui->order_lines_com->currentText())
            {

                increment_quantity(i,object_name);
                return true;
            }}}
    return false;


}





/*---------suppression sales--------------------*/
void uisales::on_delete_sale_QPB_clicked()

{
 QString deletet=ui->delete_sales_QLE->text();
    if(i.is_number(deletet))
{
 int ID_sale = ui->delete_sales_QLE->text().toInt();
     if (ui->delete_sales_QLE->text()!="")
     {

     int choise= QMessageBox::warning(0,"Hamadi ERP","are you sure you want to delete it ?","Yes","No");
         if(choise==0)
         {


         if(tempsale.delete_sale(ID_sale)==true)
                 {
ui->TV_display_sale->setModel(tempsale.Display_sale());
             ui->delete_sales_QLE->setText("");
         QMessageBox::information(0,"Hamadi ERP","sale deleted",QMessageBox::Ok);
                 }
         else

          { QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);}

        }
         else
         {

         }


}
    else { QMessageBox::critical(0,"Hamadi ERP"," please write Id sale to delete",QMessageBox::Cancel);}

}
    else
    QMessageBox::critical(0,"system"," please verify your deleting field",QMessageBox::Cancel);

}
/*---------Display sale--------------------*/
void uisales::on_create_sale_line_2_clicked()
{
    QString type;
    type = ui->type->currentText();
    QString word = ui->name_product_le_2->text();
    ui->TV_display_sale->setModel(s->search_sale(type, word));


}
/*---------Barchart statistics--------------------*/
void uisales::on_display_histogram_clicked()
{
    sale *s=new sale;
    if(ui->graph_data->currentText()=="date"){
        ui->graph_error->hide();
        ui->histograph->close();
        s->select_date();
        ui->histograph->insert_values(5,s->Get_sales_2010_2011(),
                                      s->Get_sales_2011_2012(),
                                      s->Get_sales_2012_2013(),
                                      s->Get_sales_2013_2014(),
                                      s->Get_sales_2014_2015()
                                      );
    //hide_graph_titels();
        ui->histograph->show();
        ui->red_graph->setText("sales_2010_2011 to sales_2011_2012");ui->red_graph->show();
        ui->blue_graph->setText("sales_2011_2012 to sales_2012_2013");ui->blue_graph->show();
        ui->green_graph->setText("sales_2012_2013 to sales_2013_2014");ui->green_graph->show();
        ui->yellow_graph->setText("sales_2013_2014 to sales_2014_2015");ui->yellow_graph->show();
    }
}
/*---------select product for order --------------------*/
void uisales::on_id_product_com_oder_currentTextChanged(const QString &arg1)
{
    int var=arg1.toInt();
    p->select_product(var);
    ui->name_product_le_order->setText(p->Get_name());
    ui->category_le_order->setText(p->Get_category());
    ui->bounty_points_le_order->setText(QString::number(p->Get_nb_point()));
    ui->product_size_le_order->setText(p->Get_size());
}

/*---------select client for order--------------------*/
void uisales::on_id_client_com_order_currentTextChanged(const QString &arg1)
{
    int var=arg1.toInt();
    c->select_client(var);
    ui->name_client_le_order->setText(c->Get_family_name());
    ui->total_client_points_le_order->setText(QString::number(c->Get_nb_points()));

}
/*--------- Ajout Order line --------------------*/
void uisales::on_create_order_line_clicked()
{

    QString quantity=ui->product_quantity_order->text();
    if(i.is_number(quantity))
{
    if(check_existence(ui->id_product_com_oder->currentText(),"order"))
    {
        qDebug()<< "product already there  recalculating...";
        int modification_pos=ui->order_lines_com->currentIndex();

        int new_quantity=order_old_qt+ui->product_quantity_order->text().toInt();
        ui->order_line->setItem(modification_pos,1,new QTableWidgetItem(QString::number(new_quantity)));
        p->select_product(ui->id_product_com_oder->currentText().toInt());
        float x=p->Get_initial_price();
        QString quantity=ui->product_quantity_order->text();     /* selection des valeur */
        double net_product_price=quantity.toInt()*x;
        qDebug()<<net_product_price;
        order_total_price=order_total_price+(net_product_price*18)/100+net_product_price;

        ui->total_price_le_order->setText(QString::number(order_total_price));
        order_net_price=order_total_price-order_total_price*18/100;
        qDebug()<<" order net price :" <<order_net_price;

        ui->net_price_le_order->setText(QString::number(order_net_price));
    }
    else
    {
        QString quantity=ui->product_quantity_order->text();     /* selection des valeur */
        QString id_product=ui->id_product_com_oder->currentText(); /*  a partir du combobox et du lineedit*/
        ui->order_line->insertRow(order_row_order); /* insertion d'un record dans le tablewidget */
        ui->order_line->setItem(order_row_order,0,new QTableWidgetItem(id_product)); /* insertion du 1er champ */
        ui->order_line->setItem(order_row_order,1,new QTableWidgetItem(quantity));/* insertion du 2eme champ */
        o->add_line(id_product.toInt(),quantity.toInt()); /* insertion de la ligne dans les vecteur de la vente */
        p->select_product(ui->id_product_com_oder->currentText().toInt());/* fetch de valeur de la base de donnée */


        float x=p->Get_initial_price();
        ui->tva_le_order->setText("18%");
        double net_product_price=quantity.toInt()*x;
        qDebug()<< "initial price :"<<x;
        qDebug()<< "quantity  :"<< quantity ;
        qDebug()<<net_product_price;
        order_total_price=order_total_price+(net_product_price*18)/100+net_product_price;
        ui->total_price_le_order->setText(QString::number(order_total_price)); /* insertion des valeur dans les champs corrsepondant + calcul de nouveau resultats*/
        order_total_product_points_number +=p->Get_nb_point()*quantity.toInt();
        ui->discount_value_le_order->setText(QString::number(order_total_product_points_number ));
        qDebug()<<" order total price :" <<order_total_price;
        order_net_price=order_total_price-order_total_price*18/100;
        qDebug()<<" order net price :" <<order_net_price;
        ui->net_price_le_order->setText(QString::number(order_net_price));
        order_row_order++;
        ui->order_lines_com->insertItem(order_row_order,ui->id_product_com_oder->currentText());
        order_choice=0;
    }
    }
    else
    {
        QMessageBox::critical(0,"system","Plese verify your quantity field ",QMessageBox::Ok);
    }
}
/*---------cancel Order line--------------------*/
void uisales::on_cancel_order_line_clicked()
{Order *o=new Order();
    if(ui->id_product_com->currentText()=="")
    {
        QMessageBox::critical(0,"system","no order lines to cancel",QMessageBox::Ok);
    }
    else
    {
        int id=ui->order_lines_com->currentText().toInt();
        o->cancel_line(id);
        ui->order_line->removeRow(ui->order_lines_com->currentIndex());
        order_row_order--;

        ui->order_lines_com->removeItem(ui->order_lines_com->currentIndex());
    }
}
/*---------Add Order--------------------*/
void uisales::on_submit_order_clicked()
{

   if(ui->client_enable_2->checkState())
        {order_id_client=0;}
     else {order_id_client=ui->id_client_com_order->currentText().toInt();}
          o->insert_order_data_2(order_id_client);

          if(ui->order_lines_com->count()==0)
          { QMessageBox::critical(0,"system","you didn't add ",QMessageBox::Ok);}
          else
          {
    if(o->ajouter())
             {
        QMessageBox::information(0,"system","added with success",QMessageBox::Ok);
       delete o;/* liberation de la mémoire et liberation des vecteurs */
        o=new Order();
             }
    else
             {
        QMessageBox::critical(0,"system","error with data base",QMessageBox::Ok);

             }

}
}
/*---------affichage order--------------------*/
void uisales::on_QPB_display_order_clicked()
{ Order *o=new Order();
    QString recherche=ui->QLE_ID_order__search->text();
        if(i.is_number(recherche))
        {
    QString type;
    type = ui->type_2->currentText();
    QString word = ui->QLE_ID_order__search->text();
    ui->TV_display_sale_2->setModel(o->search_Order(type, word));
        }
        else
        {
            QMessageBox::critical(0,"system","Please verify your searching area",QMessageBox::Ok);
}}

/*---------suppression Order--------------------*/

void uisales::on_delete_sale_QPB_2_clicked()
{
    Order *o=new Order();
    QString deleted=ui->delete_sales_QLE_2->text();
        if(i.is_number(deleted))
        {
    int id_order = ui->delete_sales_QLE_2->text().toInt();
    if (ui->delete_sales_QLE_2->text()!="")
    {


        int choise= QMessageBox::warning(0,"Hamadi ERP","are you sure you want to delete it ?","Yes","No");
                if(choise==0)
                {


        if(o->delete_Order(id_order)==true)
           {
            ui->TV_display_sale_2->setModel(tempOrder.Display_Order());
            ui->delete_sales_QLE_2->setText("");
             QMessageBox::information(0,"system","Order deleted",QMessageBox::Ok);
          }
        else
            QMessageBox::critical(0,"system","error",QMessageBox::Cancel);
                }
                else
                         {

                         }

}




else
       QMessageBox::critical(0,"system"," please write Id Order to delete",QMessageBox::Cancel);
        }
        else {
            QMessageBox::critical(0,"system"," please verify you deleting area",QMessageBox::Cancel);
        }


}


/*---------PRINT SALES--------------------*/
void uisales::on_create_sale_line_3_clicked()
{
    QPrinter Printer(QPrinter::HighResolution);
    Printer.setPageSize(QPrinter::A4);
    QPrintDialog *dialog = new QPrintDialog(&Printer, this);
    if (dialog->exec()== QDialog::Accepted)
   {
        QMessageBox::information(0, qApp->tr("Impression"),
                              qApp->tr("Printed"), QMessageBox::Ok);
    }
}
/*---------fonction--------------------*/
void uisales::on_create_sale_line_6_clicked()
{
    QPrinter Printer(QPrinter::HighResolution);
    Printer.setPageSize(QPrinter::A4);
    QPrintDialog *dialog = new QPrintDialog(&Printer, this);
    if (dialog->exec()== QDialog::Accepted)
   {
        QMessageBox::information(0, qApp->tr("Impression"),
                              qApp->tr("Printed"), QMessageBox::Ok);
    }
}
/*---------Print Order--------------------*/
void uisales::on_create_sale_line_5_clicked()
{
    QPrinter Printer(QPrinter::HighResolution);
    Printer.setPageSize(QPrinter::A4);
    QPrintDialog *dialog = new QPrintDialog(&Printer, this);
    if (dialog->exec()== QDialog::Accepted)
   {
        QMessageBox::information(0, qApp->tr("Impression"),
                              qApp->tr("Printed"), QMessageBox::Ok);
    }
}
/*---------Print statistics--------------------*/
void uisales::on_display_histogram_2_clicked()
{
    QPrinter Printer(QPrinter::HighResolution);
    Printer.setPageSize(QPrinter::A4);
    QPrintDialog *dialog = new QPrintDialog(&Printer, this);
    if (dialog->exec()== QDialog::Accepted)
   {
        QMessageBox::information(0, qApp->tr("Impression"),
                              qApp->tr("Printed"), QMessageBox::Ok);
    }
}
/*---------ScreenShot for sales--------------------*/
void uisales::on_create_sale_line_4_clicked()
{
    QString filename="Sale.pdf";
          //Settings
          QPrinter printer;
          printer.setOrientation(QPrinter::Landscape);
          printer.setOutputFileName("C:/Users/gambler/Desktop/Sale.pdf");
          printer.setPaperSize(QPrinter::A4);
          printer.setOutputFormat(QPrinter::PdfFormat);

          QPainter painter(&printer);
          painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
          ui->TV_display_sale->render (&painter );
          painter.end();
          QMessageBox::information(this,tr("Screenshot!"),tr("Sale list is now availble on screenshot"));


}
/*--------ScreenShot for Order-------------------*/
void uisales::on_create_sale_line_7_clicked()
{

    QString filename="Order.pdf";
          //Settings
          QPrinter printer;
          printer.setOrientation(QPrinter::Landscape);
          printer.setOutputFileName("C:/Users/gambler/Desktop/Order.pdf");
          printer.setPaperSize(QPrinter::A4);
          printer.setOutputFormat(QPrinter::PdfFormat);

          QPainter painter(&printer);
          painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
          ui->TV_display_sale_2->render (&painter );
          painter.end();
          QMessageBox::information(this,tr("Screenshot!"),tr("Order list is now availble on screenshot "));

}
/*---------Export to PDF for Order--------------------*/
void uisales::on_create_sale_line_9_clicked()
{
    int reponse = QMessageBox::question(this, "export", "do you want to export the product's table to PDF file?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)


        {QString ttt ;
            ttt =  "<body>"
                   "<table border="
                   "2"
                   ">"
                   "<tr><th>id Sale</th> \n"
                   "<th>date</th> \n"
                   "<th>total_number_points</th> \n"
                   "<th>seller</th> \n"
                   "<th>client</th></tr> \n";

            for (int i = 0; i < ui->TV_display_sale->model()->rowCount(); ++i) {


                ttt+="<tr><td>"+ui->TV_display_sale->model()->data(ui->TV_display_sale->model()->index(i,0)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale->model()->data(ui->TV_display_sale->model()->index(i,1)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale->model()->data(ui->TV_display_sale->model()->index(i,2)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale->model()->data(ui->TV_display_sale->model()->index(i,3)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale->model()->data(ui->TV_display_sale->model()->index(i,4)).toString()+"</td></tr> \n";

            }
            ttt+="</table></body>";


            QTextDocument doc;
            doc.setHtml(ttt);

            QPrinter printer;
            printer.setPaperSize(QPrinter::A3);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/gambler/Desktop/Sale_display.pdf");
            doc.print(&printer);}
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::critical(0, qApp->tr("erreur d exportation"),
                                  qApp->tr("Problème d'exportation"), QMessageBox::Cancel);
        }
}
/*---------Export to PDF for Order--------------------*/
void uisales::on_create_sale_line_8_clicked()
{ int reponse = QMessageBox::question(this, "export", "do you want to export the product's table to PDF file?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)


        {QString ttt ;
            ttt =  "<body>"
                   "<table border="
                   "2"
                   ">"
                   "<tr><th>export_order_id</th> \n"
                   "<th>date</th> \n"
                   "<th>client name</th> \n"
                   "<th>client number</th> \n"
                     "<th>status</th> \n"
                     "<th>delivery</th> \n"
                   "<th>client</th></tr> \n";

            for (int i = 0; i < ui->TV_display_sale_2->model()->rowCount(); ++i) {


                ttt+="<tr><td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,0)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,1)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,2)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,3)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,4)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,5)).toString()+"</td> \n";
                ttt+="<td>"+ui->TV_display_sale_2->model()->data(ui->TV_display_sale_2->model()->index(i,6)).toString()+"</td></tr> \n";

            }
            ttt+="</table></body>";


            QTextDocument doc;
            doc.setHtml(ttt);

            QPrinter printer;
            printer.setPaperSize(QPrinter::A3);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/gambler/Desktop/Order_display.pdf");
            doc.print(&printer);}
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::critical(0, qApp->tr("erreur d exportation"),
                                  qApp->tr("Problème d'exportation"), QMessageBox::Cancel);
        }
}
/*---------Modify Order Line--------------------*/
void uisales::on_modify_order_line_clicked()
{
;//reading id from combobox ;
o->updte_line(ui->id_product_com_oder->currentText().toInt(),ui->product_quantity_order->text().toInt(),ui->order_lines_com->currentIndex());
//ui->order_line->
ui->order_line->removeRow(ui->order_lines_com->currentIndex());
ui->order_line->insertRow(ui->order_lines_com->currentIndex());
ui->order_line->setItem(ui->order_lines_com->currentIndex(),0,new QTableWidgetItem(ui->id_product_com_oder->currentText())); /* updatein the  QTablewidget */
ui->order_line->setItem(ui->order_lines_com->currentIndex(),1,new QTableWidgetItem(ui->product_quantity_order->text()));
/*ui->order_lines_com->currentIndex()*/
}

/*---------Disconnect--------------------*/
void uisales::on_Disconnect_clicked()
{
    int res= QMessageBox::warning(this,"warning","you requested a session closure \n are you sure ? ! \n ","yes","no");
       if(res==0)
       {
           this->close();
       }
       else
       {
           /* do nothing*/
       }
}
/*---------fonction : session--------------------*/
void  uisales::set_session(int id,QString pwd)
{
    ide=id;
    this->pass=pwd;
}
/*---------Changer Mot de passe--------------------*/
void uisales::on_Change_Password_clicked()
{
    pwd=new password(this); //setting the layout
    pwd->load_credentials(ide,pass);
    pwd->show();

}
/*---------send mail for sales--------------------*/
void uisales::on_send_email_clicked()
{

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("hamadi.erp@gmail.com");
    smtp.setPassword("hamadi_erp");
    MimeMessage message;

    message.setSender(new EmailAddress("hamadi.erp@gmail.com", "Hamadi Abid"));

    QSqlQuery query;
    query.prepare("SELECT email,type FROM manager");

    query.exec();

    while(query.next())
    {
        message.addRecipient(new EmailAddress(query.value("email").toString(), query.value("type").toString()));
    }

    message.setSubject("Sales");
    MimeText text;

    text.setText("Product in need ! ");
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
    QMessageBox::information(this,"messsage:","Email sent","ok");

}
/*---------Export To Excel for Sales--------------------*/
void uisales::on_Export_to_excel_2_clicked()
{
    QSqlQueryModel  *model = new QSqlQueryModel() ;
            QString linki = QFileDialog::getSaveFileName(this, tr("Export CSV"),
          //QDesktopServices::storageLocationImpl(QStandardPaths::DesktopLocation)+"/liste_Sale.csv",
                                                                                                 tr("Comma Separated Values (*.csv)"));


            int x = 0;
            QString exportdata;
            model->setQuery("select * from sale");
            int counthidden = 0, jint = 0;

            while (jint < model->columnCount()) {

            counthidden+=ui->TV_display_sale->isColumnHidden(jint);
            jint++;
            }


            while (x < model->columnCount()){

            if (!ui->TV_display_sale->isColumnHidden(x)) {

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
            if (!ui->TV_display_sale->isColumnHidden(x)) {

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



}
/*---------Send Mail for Order--------------------*/
void uisales::on_send_email_2_clicked()
{

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("hamadi.erp@gmail.com");
    smtp.setPassword("hamadi_erp");
    MimeMessage message;

    message.setSender(new EmailAddress("hamadi.erp@gmail.com", "Hamadi Abid"));

    QSqlQuery query;
    query.prepare("SELECT email,type FROM manager");

    query.exec();

    while(query.next())
    {
        message.addRecipient(new EmailAddress(query.value("email").toString(), query.value("type").toString()));
    }

    message.setSubject("Order");
    MimeText text;

    text.setText("Product in large quantity in need ! ");
    message.addPart(&text);
    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
    QMessageBox::information(this,"messsage:","Email sent","ok");
}

/*---------Export Order TO EXCEL --------------------*/

void uisales::on_Export_to_excel_clicked()
{

    QSqlQueryModel  *model = new QSqlQueryModel() ;
            QString linki = QFileDialog::getSaveFileName(this, tr("Export CSV"),
          //QDesktopServices::storageLocationImpl(QStandardPaths::DesktopLocation)+"/liste_Sale.csv",
          tr("Comma Separated Values (*.csv)"));


            int x = 0;
            QString exportdata;
            model->setQuery("select * from export_order");
            int counthidden = 0, jint = 0;

            while (jint < model->columnCount()) {

            counthidden+=ui->TV_display_sale_2->isColumnHidden(jint);
            jint++;
            }


            while (x < model->columnCount()){

            if (!ui->TV_display_sale_2->isColumnHidden(x)) {

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
            if (!ui->TV_display_sale_2->isColumnHidden(x)) {

    exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());
 if (model->columnCount() - x != counthidden)
            { exportdata.append(";");}
            else {exportdata.append("\n");}}x++;}
            exportdata.append("\n");
            z++;}
            QFile file;
   if (!linki.isEmpty()) {
             file.setFileName(linki);
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                        return; }
            QByteArray ttext;
            ttext.append(exportdata);
            file.write(ttext);
}
