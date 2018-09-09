#include "uifinance.h"
#include "ui_finance.h"
#include <QString>
#include<QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtPrintSupport/QPrintDialog>
#include <QFile>
#include "statfinanace.h"
#include <QTextDocument>
finance::finance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finance)
{
    ui->setupUi(this);

            ui->leactif_2->setReadOnly(true);
            ui->lepassif_2->setReadOnly(true);

            ui->LEimmobilisationcorp_2->setReadOnly(true);
            ui->LEimmobilisationfinanciere_2->setReadOnly(true);
            ui->LEimmobilisationincorp_2->setReadOnly(true);

            ui->LEliquidit_2->setReadOnly(true);
            ui->LEstocks_2->setReadOnly(true);
            ui->LEcreanceclient_2->setReadOnly(true);
            ui->LEcreancehorsexp_2->setReadOnly(true);

            ui->LEfonds_2->setReadOnly(true);
            ui->LEdettesalongterme_2->setReadOnly(true);

            ui->LEdettefinanciere_2->setReadOnly(true);
            ui->LEdettesexp_2->setReadOnly(true);
            ui->LEdetteshorsexp_2->setReadOnly(true);


    ui->cbidbatiment_2->setModel(tempcharge.displayid());

    ui->supplier_list->setModel(tempSupplier.display_supplier());
    ui->advance_list->setModel(tempadvance.advancelist());
    ui->CBemployee->setModel(tempemp.employee_id_list());
    ui->cb_id_pay_emp->setModel(tempemp.employee_id_list());

    ui->CBsupplierid->setModel(tempSupplier.supplier_id_list());
    ui->CBidbuilding->setModel(tempcharge.displayid());
    ui->cbidbatiment->setModel(tempcharge.displayid());
    ui->CBidbuilding2->setModel(tempcharge.displayid());
    tempcharge.set_id();
    tempcharge.set_amount();

    ui->leactif->setReadOnly(true);
    ui->lepassif->setReadOnly(true);
    ui->widget->set_data(tempcharge.tab_amount,tempcharge.tab_id,tempcharge.tab_nom);
    ui->statc->setScene(Statclef(tempcharge.tab_nom));
    Payment_report p;
    ui->salarieslist->setModel(p.displayallpayslip());
    ui->chargelist->setModel(tempcharge.displaycharges());
}

finance::~finance()
{
    delete ui;
}

QGraphicsScene *finance::Statclef(vector<QString> tab)
{
    QGraphicsScene *  scene = new QGraphicsScene();
    double sum =0.0,percent=0.0;
   unsigned int i ;


    for( i=0;i<tempcharge.tab_amount.size();i++)
    {


        sum+=tempcharge.tab_amount[i];

    }


    i=0;
    QBrush color;
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    QGraphicsTextItem *tex;



  QString text="";
  vector<QString>::iterator it;
    for(it=tab.begin();it!=tab.end();it++)
    {
        percent=tempcharge.tab_amount[i]*100/sum;
        text=text+"\n"+(*it)+" : "+QString::number( percent)+" %";
        qDebug()<<text;
        i++;
    }
    tex = scene->addText(text, QFont("Arial", 12));
return scene;
}

void finance::on_PBaddSupplier_clicked()
{


   supplier_name =ui->LEname->text();
   email=ui->LEmail->text();
   description=ui->LEdiscribe->text();
   tel=ui->LEtel->text().toInt();
   fax=ui->LEfax->text().toInt();
   zip_code=ui->LEzip->text();
   street=ui->LEstreet->text();
   area=ui->LEarea->text();
   city=ui->LEcity->text();
if((supplier_name!="")&&(email!="")&&(description!="")&&(tel!=0)&&(fax!=0)&&(zip_code!="")&&(street!="")&&(area!="")&&(city!=""))
  { Supplier *S= new Supplier( supplier_name,email,description,tel,fax,zip_code,street,area,city);



      if( S->add_supplier()==true)
      {
          QMessageBox::information(0,"Hamadi ERP","supplier added",QMessageBox::Ok);
            clear();
      }
     else{
          QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
      }
      ui->supplier_list->setModel(tempSupplier.display_supplier());
      ui->CBsupplierid->setModel(tempSupplier.supplier_id_list());

 }
else {          QMessageBox::critical(0,"Hamadi ERP","Verifier les champs",QMessageBox::Cancel);


}



}

void finance::on_PBvaliderSupplier_clicked()
{
    QString type;
    type=ui->CBsearchSupplier->currentText();
    ui->supplier_list->setModel(tempSupplier.search_supplier(type,ui->LEsearchSupplier->text()));

}
void finance::clear()
{
    ui->LEname->setText("");
    ui->LEmail->setText("");
    ui->LEdiscribe->setText("");
    ui->LEtel->setText("");
    ui->LEfax->setText("");
    ui->LEzip->setText("");
    ui->LEstreet->setText("");
    ui->LEarea->setText("");
    ui->LEcity->setText("");
}
void finance::on_PBclear_clicked()
{
clear();
}



void finance::on_PBdisconnect_clicked()
{
    int res = QMessageBox::warning(this,"System","Are you sure?","Yes","No");
    if (res==0)
    {
        this->hide();
    }
}

void finance::on_PBarchivesupplier_clicked()
{

   if(id_supplier!=0)
   {
       int res = QMessageBox::warning(this,"System","Are you sure?","Yes","No");
       if (res==0)
       {
       if(tempSupplier.delete_supplier(id_supplier)	==true)
       {
        ui->supplier_list->setModel(tempSupplier.display_supplier());
        QMessageBox::information(0,"Hamadi ERP","supplier deleted",QMessageBox::Ok);
       }
       else
           QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
    }
}

   else
       QMessageBox::critical(0,"Hamadi ERP","No Supplier specified",QMessageBox::Cancel);
id_supplier=0;
ui->CBsupplierid->setModel(tempSupplier.supplier_id_list());

}

void finance::on_PBupdateSupplier_clicked()
{
    int id=ui->CBsupplierid->currentText().toInt();
    supplier_name =ui->LEname_edit->text();
    email=ui->LEmail_edit->text();
    description=ui->LEdiscribe_edit->text();
    tel=ui->LEtel_edit->text().toInt();
    fax=ui->LEfax_edit->text().toInt();
    zip_code=ui->LEzip_edit->text();
    street=ui->LEstreet_edit->text();
    area=ui->LEarea_edit->text();
    city=ui->LEcity_edit->text();
    if(id!=0){
        if((supplier_name!="")&&(email!="")&&(description!="")&&(tel!=0)&&(fax!=0)&&(zip_code!="")&&(street!="")&&(area!="")&&(city!=""))
        {
        Supplier *S= new Supplier( supplier_name,email,description,tel,fax,zip_code,street,area,city);



          if( S->modify_supplier(id)==true)
          {
              QMessageBox::information(0,"Hamadi ERP","supplier Updated",QMessageBox::Ok);
                clear();
          }
         else{
              QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
          }
          ui->supplier_list->setModel(tempSupplier.display_supplier());

          ui->LEarea_edit->setText("");
          ui->LEcity_edit->setText("");
          ui->LEdiscribe_edit->setText("");
          ui->LEfax_edit->setText("");
          ui->LEmail_edit->setText("");
          ui->LEname_edit->setText("");
          ui->LEtel_edit->setText("");
          ui->LEzip_edit->setText("");
          ui->LEstreet_edit->setText("");
     }
        else
          QMessageBox::critical(0,"Hamadi ERP","there are empty fields",QMessageBox::Cancel);

    }
else
  QMessageBox::critical(0,"Hamadi ERP","No Supplier specified",QMessageBox::Cancel);

}


void finance::on_PBaddAdvance_clicked()
{
   Advance *A=new   Advance(ui->LEadvancevalue->text().toDouble(),ui->LEadvanceDesc->text(),ui->DEadvancedate->text(),ui->CBemployee->currentText().toInt());
   if( A->add_advance()==true)
   {
       QMessageBox::information(0,"Hamadi ERP","Advance added",QMessageBox::Ok);
         clear();
   }
  else{
       QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
   }

   ui->advance_list->setModel(tempadvance.advancelist());

}

void finance::on_supplier_list_clicked(const QModelIndex &index)
{
    int pos =index.row();
    id_supplier=ui->supplier_list->model()->data(ui->supplier_list->model()->index(pos,0)).toInt();
}

void finance::on_PBpdf_clicked()
{
    int reponse = QMessageBox::question(this, "export", "do you want to export the supplier's table to PDF file?", QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)


        {QString ttt ;
            ttt =  "<body>"
                   "<table border="
                   "2"
                   ">"
                   "<tr><th>ID</th> \n"
                   "<th>Name</th> \n"
                   "<th>FAX</th> \n"
                   "<th>Feed back</th> \n"
                   "<th>Phone number</th> \n"
                   "<th>Zip code</th> \n"
                   "<th>Street</th> \n"
                   "<th>Area</th> \n"
                   "<th>City</th> \n"
                   "<th>Email</th></tr> \n";

            for (int i = 0; i < ui->supplier_list->model()->rowCount(); ++i) {


                ttt+="<tr><td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,0)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,1)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,2)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,3)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,4)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,5)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,6)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,7)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,8)).toString()+"</td> \n";
                ttt+="<td>"+ui->supplier_list->model()->data(ui->supplier_list->model()->index(i,9)).toString()+"</td></tr> \n";

            }
            ttt+="</table></body>";


            QTextDocument doc;
            doc.setHtml(ttt);

            QPrinter printer;
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/Khalil/Desktop/projet/Supplier.pdf");
            doc.print(&printer);}
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::critical(0, qApp->tr("erreur d exportation"),
                                  qApp->tr("exportation annulée"), QMessageBox::Cancel);
        }












    /* QString filename="Supplier.pdf";
              //Settings
              QPrinter printer;
              printer.setOrientation(QPrinter::Landscape);
              printer.setOutputFileName("C:/Users/khalil/Desktop/Supplier.pdf");
              printer.setPaperSize(QPrinter::A4);
              printer.setOutputFormat(QPrinter::PdfFormat);
              QPainter painter(&printer);
              painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
              ui->supplier_list->render (&painter );
              painter.end();
              QMessageBox::information(this,tr("Exported!"),tr("Supplier list is now availble in pdf format "));*/
}

void finance::on_exportcsv_clicked()
{
    QString MyQuery = "select * from Supplier";

    QSqlQuery query(MyQuery);

    if(query.exec())
    {
        qDebug()<<QDateTime::currentDateTime()<<"QUERY SUCCESS ";


        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery(MyQuery);
        //ui->tableViewOra->setModel(model);

        QString textData;
        int rows=model->rowCount();
        int columns=model->columnCount();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                textData += model->data(model->index(i,j)).toString();
                textData += "; ";      // for .csv file format
            }
            textData += "\n";             // (optional: for new line segmentation)
        }

        QFile csvfile("C:/Users/khalil/Desktop/exported.csv");
        if(csvfile.open(QIODevice::WriteOnly))
        {
            QTextStream out(&csvfile);
            out<<textData;
        }
        csvfile.close();
    }

}

void finance::on_exportpdf_2_clicked()
{

}

void finance::on_pbChoisir_clicked()
{
        tempSupplier.select_supplier(ui->CBsupplierid->currentText().toInt());
        ui->LEarea_edit->setText(tempSupplier.getarea());
        ui->LEcity_edit->setText(tempSupplier.getcity());
        ui->LEdiscribe_edit->setText(tempSupplier.Getdescription());
        ui->LEfax_edit->setText(QString::number(tempSupplier.Getfax()));
        ui->LEmail_edit->setText(tempSupplier.Getemail());
        ui->LEname_edit->setText(tempSupplier.Getsupplier_name());
        ui->LEtel_edit->setText(QString::number(tempSupplier.Gettel()));
        ui->LEzip_edit->setText(tempSupplier.getzip());
        ui->LEstreet_edit->setText(tempSupplier.getstreet());
}

void finance::on_PBaddcharge_clicked()
{
    int id_building = ui->CBidbuilding->currentText().toInt();
    QString desc   =ui->LEchargedesc->text();
    QString type =ui->CBTYPE->currentText();
    QString date =ui->Datecharge->text();
    double amount=ui->LEamount->text().toDouble();

    if((id_building!=0)&&(desc!="")&&(type!="")&&(amount!=0)&&(date!=""))
      { Charge *c= new Charge(desc,type,id_building,amount,date);



          if( c->create_charge()==true)
          {
              QMessageBox::information(0,"Hamadi ERP","Charge added",QMessageBox::Ok);
                clear();
          }
         else{
              QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
          }


     }
    else {          QMessageBox::critical(0,"Hamadi ERP","Verifier les champs",QMessageBox::Cancel);}

    ui->chargelist->setModel(tempcharge.displaychargesbyname(ui->LEsearchcharges->text()));


}

void finance::on_pbrechercheavance_clicked()
{
    if(ui->lerechercheavance->text().toInt()!= 0)
    ui->advance_list->setModel(tempadvance.searchadvance(ui->lerechercheavance->text().toInt()));
    else
        ui->advance_list->setModel(tempadvance.advancelist());

}

void finance::on_PBaddFB_clicked()
{
    double Intangible_Assets=ui->LEimmobilisationincorp->text().toDouble();

    double Tangible_assets=ui->LEimmobilisationcorp->text().toDouble();
    double financial_assets=ui->LEimmobilisationfinanciere->text().toDouble();

    double Inventory_value=ui->LEstocks->text().toDouble();
    double Trade_Receivable=ui->LEcreanceclient->text().toDouble();
    double Non_operating_Depts=ui->LEcreancehorsexp->text().toDouble();
    double Liquidity=ui->LEliquidit->text().toDouble();

    double Equity=ui->LEfonds->text().toDouble();
    double depts=ui->LEdettesalongterme->text().toDouble() ;

    double Trade_accounts=ui->LEdettesexp->text().toDouble();
    double Financial_Depts=ui->LEdettefinanciere->text().toDouble();
    double Non_operating_credits=ui->LEdetteshorsexp->text().toDouble();

    QString  mounth=ui->CBaddmounth->currentText();
    QString year=ui->CBaddyear->currentText();
    int id_building=ui->cbidbatiment->currentText().toInt();




    if((Intangible_Assets !=0)&&(Tangible_assets !=0)&& (Inventory_value !=0)&&(financial_assets !=0)&&(Trade_Receivable !=0)&&(Non_operating_Depts !=0)&&(Liquidity !=0)
       &&(Equity !=0)&&(Trade_accounts !=0)&&(Financial_Depts !=0)&&(Non_operating_credits !=0))
      {
ui->leactif->setText(QString::number(Intangible_Assets+Tangible_assets+financial_assets+Inventory_value+Trade_Receivable+Non_operating_Depts+Liquidity));
ui->lepassif->setText(QString::number(Trade_accounts+Financial_Depts+Non_operating_credits+depts+Equity));
if(ui->leactif->text().toDouble()!=ui->lepassif->text().toDouble())

        {  QMessageBox::critical(0,"Hamadi ERP","Bilan non equilibré",QMessageBox::Cancel);}
        else{
        Financial_balance *f= new Financial_balance( Intangible_Assets, Tangible_assets,financial_assets,
                                                     Inventory_value, Trade_Receivable, Non_operating_Depts, Liquidity, Equity,
                                                     Trade_accounts, Financial_Depts, Non_operating_credits,depts,
                                                     mounth, year, id_building);




          if(f->add_finacial_balance()==true)
          {
              QMessageBox::information(0,"Hamadi ERP","Balance added",QMessageBox::Ok);

          }
         else{
              QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
          }


}}
    else {          QMessageBox::critical(0,"Hamadi ERP","Verifier les champs",QMessageBox::Cancel);}
    }



void finance::on_LEsearchSupplier_cursorPositionChanged()
{
    QString type;
    type=ui->CBsearchSupplier->currentText();
    if(type=="by name")
    ui->supplier_list->setModel(tempSupplier.search_supplier(type,ui->LEsearchSupplier->text()));

}



void finance::on_PBsatat_clicked()
{
    tempcharge.set_id();
    tempcharge.set_amount();


    ui->widget->set_data(tempcharge.tab_amount,tempcharge.tab_id,tempcharge.tab_nom);
}



void finance::on_LEname_cursorPositionChanged()
{
         QRegExp re("[_a-zA-Z][_a-zA-Z]+");
        QRegExpValidator *v = new QRegExpValidator(re);
        ui->LEname->setValidator(v);
}


void finance::on_LEdiscribe_cursorPositionChanged( )
{
    QRegExp re("[_a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEdiscribe->setValidator(v);
}

void finance::on_LEtel_cursorPositionChanged( )
{
    QIntValidator *v = new QIntValidator(20000000,99999999);
    ui->LEtel->setValidator(v);
}

void finance::on_LEfax_cursorPositionChanged( )
{
    QIntValidator *v = new QIntValidator(20000000,99999999);
    ui->LEfax->setValidator(v);

}

void finance::on_LEmail_cursorPositionChanged( )
{
    QRegExp re("[_0-9a-zA-Z.]+[@][_a-zA-Z]+[.][_a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEmail->setValidator(v);
}

void finance::on_LEzip_cursorPositionChanged( )
{
    QIntValidator *v = new QIntValidator(1000,9999);
    ui->LEzip->setValidator(v);
}

void finance::on_LEcity_cursorPositionChanged( )
{
    QRegExp re("[_a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEcity->setValidator(v);
}

void finance::on_LEarea_cursorPositionChanged( )
{
    QRegExp re("[_a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEarea->setValidator(v);
}

void finance::on_LEstreet_cursorPositionChanged( )
{
    QRegExp re("[ _0-9a-zA-Z][ _0-9a-zA-Z][ _0-9a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEstreet->setValidator(v);
}

void finance::on_LEname_edit_cursorPositionChanged( )
{
         QRegExp re("[_a-zA-Z][_a-zA-Z]+");
        QRegExpValidator *v = new QRegExpValidator(re);
        ui->LEname_edit->setValidator(v);
}


void finance::on_LEdiscribe_edit_cursorPositionChanged( )
{
    QRegExp re("[_a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEdiscribe_edit->setValidator(v);
}

void finance::on_LEtel_edit_cursorPositionChanged( )
{
    QIntValidator *v = new QIntValidator(20000000,99999999);
    ui->LEtel_edit->setValidator(v);
}

void finance::on_LEfax_edit_cursorPositionChanged( )
{
    QIntValidator *v = new QIntValidator(20000000,99999999);
    ui->LEfax_edit->setValidator(v);

}

void finance::on_LEmail_edit_cursorPositionChanged( )
{
    QRegExp re("[_0-9a-zA-Z.]+[@][_a-zA-Z]+[.][_a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEmail_edit->setValidator(v);
}

void finance::on_LEzip_edit_cursorPositionChanged( )
{
    QIntValidator *v = new QIntValidator(1000,9999);
    ui->LEzip_edit->setValidator(v);
}

void finance::on_LEcity_edit_cursorPositionChanged( )
{
    QRegExp re("[_a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEcity_edit->setValidator(v);
}

void finance::on_LEarea_edit_cursorPositionChanged( )
{
    QRegExp re("[_a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEarea_edit->setValidator(v);
}

void finance::on_LEstreet_edit_cursorPositionChanged( )
{
    QRegExp re("[ _0-9a-zA-Z][ _0-9a-zA-Z][ _0-9a-zA-Z][ _a-zA-Z]+");
   QRegExpValidator *v = new QRegExpValidator(re);
   ui->LEstreet_edit->setValidator(v);
}

void finance::on_s_clicked()
{
    tempcharge.set_id();
    tempcharge.set_amount();


    ui->widget->set_data(tempcharge.tab_amount,tempcharge.tab_id,tempcharge.tab_nom);
    ui->statc->setScene(Statclef(tempcharge.tab_nom));
}

void finance::on_LEadvancevalue_cursorPositionChanged( )
{
    QRegExp re("[ _0-9]+[.][ _0-9]+");
    QRegExpValidator *v = new QRegExpValidator(re);
    ui->LEadvancevalue->setValidator(v);
}

void finance::on_PBcreerratio_clicked()
{
    Financial_balance b;
    int id =ui->CBidbuilding2->currentText().toLong();
    b.create_ratio(ui->CBmois->currentText(),ui->CBannee->currentText(),id);
   QStringListModel  * model = new QStringListModel(this);
    model->setStringList(b.List);
    ui->LVratio->setModel(model);
}


void finance::on_PBpayslip_clicked()
{
   Payment_report p;
   if( p.calculate_payslip(ui->cb_id_pay_emp->currentText().toInt(),ui->CBaddmounth_2->currentText().toInt(),ui->CBaddyear_2->currentText().toInt())==true)
   {
       QMessageBox::information(0,"Hamadi ERP","Payslip created",QMessageBox::Ok);
       p.displaypayslip(ui->cb_id_pay_emp->currentText().toInt(),ui->CBaddmounth_2->currentText().toInt(),ui->CBaddyear_2->currentText().toInt());
       QStringListModel  * model = new QStringListModel(this);
        model->setStringList(p.List);
        ui->salarieslist->setModel(p.displayallpayslip());

   }
  else{
       QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
   }
   ui->salarieslist->setModel(p.displayallpayslip());

}

void finance::on_pbdisplaypay_clicked()
{
  Payment_report p;
  p.displaypayslip(ui->cb_id_pay_emp->currentText().toInt(),ui->CBaddmounth_2->currentText().toInt(),ui->CBaddyear_2->currentText().toInt());
  QStringListModel  * model = new QStringListModel(this);
   model->setStringList(p.List);
   ui->LVpayslip->setModel(model);}


void finance::on_pBmail_clicked()
{


//    uimail mail;

//   mail.setModal(true);
//   mail.exec();

}

void finance::on_Print_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
        QPrintDialog *dlg = new QPrintDialog(&printer, this);
        QPixmap pix = QPixmap::grabWidget(ui->supplier_list);
        QPainter painter( &printer );
        dlg->setWindowTitle(tr("Print Document"));

        if (dlg->exec() == QDialog::Accepted) {
             painter.drawPixmap( 0, 0,2200,1600, pix );
        }
        delete dlg;

}


void finance::on_advance_list_clicked(const QModelIndex &index)
{

    int pos =index.row();
    id_advance=ui->advance_list->model()->data(ui->advance_list->model()->index(pos,3)).toInt();
}

void finance::on_pbdeleteadvance_clicked()
{
    if(id_advance!=0)
    {
        int res = QMessageBox::warning(this,"System","Are you sure?","Yes","No");
        if (res==0)
        {
        if(tempadvance.delete_advance(id_advance)	==true)
        {
         ui->advance_list->setModel(tempadvance.advancelist());
         QMessageBox::information(0,"Hamadi ERP","advance deleted",QMessageBox::Ok);
        }
        else
            QMessageBox::critical(0,"Hamadi ERP","error",QMessageBox::Cancel);
     }
}
    else             QMessageBox::critical(0,"Hamadi ERP","Advance deleted",QMessageBox::Cancel);

}

void finance::on_LEsearchcharges_cursorPositionChanged()
{
    ui->chargelist->setModel(tempcharge.displaychargesbyname(ui->LEsearchcharges->text()));
}

void finance::on_pbSearch_clicked()
{
    ui->chargelist->setModel(tempcharge.displaychargesbyname(ui->LEsearchcharges->text()));

}

void finance::on_PBdisplayFB_clicked()
{
    Financial_balance b;
    b.displaybalance(ui->CBaddmounth_3->currentText(),ui->CBaddyear_3->currentText(),ui->cbidbatiment_2->currentText().toInt());
    ui->LEimmobilisationcorp_2->setText(QString::number(b.GetTangible_assets()));
    ui->LEimmobilisationfinanciere_2->setText(QString::number(b.Getfinancial_assets()));
    ui->LEimmobilisationincorp_2->setText(QString::number(b.GetIntangible_Assets()));

    ui->LEliquidit_2->setText(QString::number(b.GetLiquidity()));
    ui->LEstocks_2->setText(QString::number(b.GetInventory_value()));
    ui->LEcreanceclient_2->setText(QString::number(b.GetTrade_Receivable()));
    ui->LEcreancehorsexp_2->setText(QString::number(b.GetNon_operating_Debts()));

    ui->LEfonds_2->setText(QString::number(b.GetEquity()));
    ui->LEdettesalongterme_2->setText(QString::number(b.Getdepts()));

    ui->LEdettefinanciere_2->setText(QString::number(b.GetFinancial_Depts()));
    ui->LEdettesexp_2->setText(QString::number(b.GetTrade_accounts()));
    ui->LEdetteshorsexp_2->setText(QString::number(b.GetNon_operating_Credit()));

    double totalactif=b.GetTangible_assets()+b.Getfinancial_assets()
            +b.GetIntangible_Assets()+b.GetLiquidity()+b.GetInventory_value()+b.GetNon_operating_Debts()+b.GetTrade_Receivable();
    double totalpassif=b.GetEquity()+b.GetTrade_accounts()+b.Getdepts()+b.GetNon_operating_Credit()+b.GetNon_operating_Debts() ;
    ui->leactif_2->setText(QString::number(totalactif));
    ui->lepassif_2->setText(QString::number(totalpassif));
}
