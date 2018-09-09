#include "Financial_balance.h"
#include <QDebug>

Financial_balance::Financial_balance()
{
    //ctor
}

Financial_balance::~Financial_balance()
{
    //dtor
}
Financial_balance::Financial_balance(double Intangible_Assets,double Tangible_assets,double financial_assets,
                                     double Inventory_value,double Trade_Receivable,double Non_operating_Depts,double Liquidity,double Equity,
                                     double Trade_accounts,double Financial_Depts,double Non_operating_credits,double depts,
                                     QString mounth,QString year,int id_building)
{

    this->Intangible_Assets=Intangible_Assets;
    this->Tangible_assets=Tangible_assets;
    this->financial_assets=financial_assets;
    this->Inventory_value=Inventory_value;
    this->Trade_Receivable=Trade_Receivable;
    this->Non_operating_Depts=Non_operating_Depts;
    this->Liquidity=Liquidity;
    this->Equity=Equity;
    this->Trade_accounts=Trade_accounts;
    this->Financial_Depts=Financial_Depts;
    this->Non_operating_credits=Non_operating_credits;
    this->depts =depts;
    this->mounth=mounth;
    this->year=year;
    this->id_building=id_building;
}


bool  Financial_balance:: add_finacial_balance()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    QString str ="select * from financial_balance where mounth ='"+mounth+"' and addyear = '"+year+"' and id_building ="+QString ::number(id_building);
    model->setQuery(str);
    qDebug()<<str;
    if(model->rowCount()==0)
    {
    QSqlQuery querry;
   /* QString str=  "insert into financial_balance (intagible_assests,tangible_assets,financial_assets,inventory_value,trade_recivable,non_operating_depts"
                  ",liquidity,equity,depts,trade_account,financial_depts,non_operating_credits,mounth,year,id_building) "
                   "values (:intagible_assests,:tangible_assets,:financial_assets,:inventory_value,:trade_recivable,:non_operating_depts"
                  ",:liquidity,:equity,:depts,:trade_account,:financial_depts,:non_operating_credits,:mounth,:addyear,:id_building)";
           qDebug()<<str;
    querry.prepare(str);
    querry.bindValue(0,Intangible_Assets);
    querry.bindValue(1,Tangible_assets );
    querry.bindValue(2,financial_assets );
    querry.bindValue(3,Inventory_value);
    querry.bindValue(4,Trade_Receivable);
    querry.bindValue(5,Non_operating_Depts );
    querry.bindValue(6,Liquidity );
    querry.bindValue(7,Equity );
    querry.bindValue(8,depts);
    querry.bindValue(9,Trade_accounts );
    querry.bindValue(10,Financial_Depts);
    querry.bindValue(11,Non_operating_credits);
    querry.bindValue(12,mounth );
    querry.bindValue(13,year);
    querry.bindValue(14,id_building);

    */
    QString str= "insert into financial_balance (intangible_assests,tangible_assets,financial_assets,inventory_value,trade_recivable,non_operating_depts"
                     ",liquidity,equity,depts,trade_accounts,financial_depts,non_operating_credits,mounth,addyear,id_building) "
                     "values ("+QString::number(Intangible_Assets)+","+QString::number(Tangible_assets)+","+QString::number(financial_assets)+","+QString::number(Inventory_value)+","+QString::number(Trade_Receivable)+
            ","+QString::number(Non_operating_Depts)+","+QString::number(Liquidity)+","+QString::number(Equity)+","+QString::number(depts)+","+QString::number(Trade_accounts)+","+QString::number(Financial_Depts)+","
            +QString::number(Non_operating_credits)+",'"+mounth+"','"+year+"',"+QString::number(id_building)+")";
qDebug()<<str;
   return querry.exec(str);
}
    else
        return false;
}

void Financial_balance::create_ratio(QString mois, QString annee,long id)
{
   QSqlQueryModel *model = new QSqlQueryModel();


               QString str="select * from financial_balance "
                   "where mounth ='"+mois+"' "
                   "and addyear ='"+annee+"' "
                   "and id_building="+QString::number(id);

               qDebug()<<str;
               model->setQuery(str);
         Intangible_Assets= model->data(model->index(0,3)).toReal();
         qDebug()<<Intangible_Assets;
         Tangible_assets=model->data(model->index(0,4)).toReal();
         qDebug()<<Tangible_assets;

         financial_assets=    model->data(model->index(0,15)).toReal();
         qDebug()<<financial_assets;

         Inventory_value=model->data(model->index(0,5)).toReal();
         qDebug()<<Inventory_value;

         Trade_Receivable=  model->data(model->index(0,6)).toReal();
         qDebug()<<Trade_Receivable;

         Non_operating_Depts=  model->data(model->index(0,7)).toReal();
         qDebug()<<Non_operating_Depts;

         Liquidity=model->data(model->index(0,8)).toReal();
         qDebug()<<Liquidity;

         Equity=model->data(model->index(0,9)).toReal();
         qDebug()<<Equity;

         depts=model->data(model->index(0,10)).toReal();
         qDebug()<<depts;

         Trade_accounts=model->data(model->index(0,11)).toReal();
         qDebug()<<Trade_accounts;

         Financial_Depts=model->data(model->index(0,12)).toReal();
         qDebug()<<Financial_Depts;

         Non_operating_credits=model->data(model->index(0,14)).toReal();
         qDebug()<<Non_operating_credits;

         double  ratio_emprut_capitaux_propres= (Equity  +depts +Trade_accounts +Financial_Depts+Non_operating_credits)/Equity;
         double ratio_de_liquidite_generale = ( Inventory_value + Trade_Receivable + Non_operating_Depts+Liquidity)/(Trade_accounts+Financial_Depts+Non_operating_credits);
            double endettement = (Inventory_value + Trade_Receivable + Non_operating_Depts+Liquidity+Intangible_Assets+Tangible_assets+financial_assets)*100/((Trade_accounts+Financial_Depts+Non_operating_credits)+depts+Equity);
         

         List <<"                                 Ratio pour le batiment : "+QString::number(id)+"    Mois : " +mois+"    Année: "+annee<< "Ratio Emprunt/Capitaux propres"
         " : "+QString::number(ratio_emprut_capitaux_propres)<< "Ratio De LIQUIDITÉ GÉNÉRALE : " +QString::number(ratio_de_liquidite_generale)
    <<"Endettement  : "+QString::number(endettement);




}

void Financial_balance::displaybalance(QString mois , QString annee, long id)
{
    QSqlQueryModel *model = new QSqlQueryModel();


                QString str="select * from financial_balance "
                    "where mounth ='"+mois+"' "
                    "and addyear ='"+annee+"' "
                    "and id_building="+QString::number(id);

                qDebug()<<str;
                model->setQuery(str);
          Intangible_Assets= model->data(model->index(0,3)).toReal();
          qDebug()<<Intangible_Assets;
          Tangible_assets=model->data(model->index(0,4)).toReal();
          qDebug()<<Tangible_assets;

          financial_assets=    model->data(model->index(0,15)).toReal();
          qDebug()<<financial_assets;

          Inventory_value=model->data(model->index(0,5)).toReal();
          qDebug()<<Inventory_value;

          Trade_Receivable=  model->data(model->index(0,6)).toReal();
          qDebug()<<Trade_Receivable;

          Non_operating_Depts=  model->data(model->index(0,7)).toReal();
          qDebug()<<Non_operating_Depts;

          Liquidity=model->data(model->index(0,8)).toReal();
          qDebug()<<Liquidity;

          Equity=model->data(model->index(0,9)).toReal();
          qDebug()<<Equity;

          depts=model->data(model->index(0,10)).toReal();
          qDebug()<<depts;

          Trade_accounts=model->data(model->index(0,11)).toReal();
          qDebug()<<Trade_accounts;

          Financial_Depts=model->data(model->index(0,12)).toReal();
          qDebug()<<Financial_Depts;

          Non_operating_credits=model->data(model->index(0,14)).toReal();
          qDebug()<<Non_operating_credits;
}


