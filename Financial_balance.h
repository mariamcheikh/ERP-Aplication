#ifndef FINANCIAL_BALANCE_H
#define FINANCIAL_BALANCE_

#include <QString>
#include <QDate>
#include "session.h"
#include<QString>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QSqlQuery>
#include <QSql>
#include "building.h"
#include <QVariant>


class Financial_balance
{
    public:
    Financial_balance(double,double,double,double,double,double,double,double,double,double,double,double,QString,QString,int);
        Financial_balance();
        ~Financial_balance();
        int Getid_balance() { return id_balance; }
        void Setid_balance( int val) { id_balance = val; }

        double GetIntangible_Assets() { return Intangible_Assets; }
        void SetIntangible_Assets(double val) { Intangible_Assets = val; }

        double GetTangible_assets() { return Tangible_assets; }
        void SetTangible_assets(double val) { Tangible_assets = val; }

        double Getfinancial_assets() { return financial_assets; }
        void Setfinancial_assets(double val) { financial_assets = val; }

        double GetInventory_value() { return Inventory_value; }
        void SetInventory_value(double val) { Inventory_value = val; }

        double GetTrade_Receivable() { return Trade_Receivable; }
        void SetTrade_Receivable(double val) { Trade_Receivable = val; }

        double GetNon_operating_Debts() { return Non_operating_Depts; }
        void SetNon_operating_Debts(double val) { Non_operating_Depts = val; }

        double GetLiquidity() { return Liquidity; }
        void SetLiquidity(double val) { Liquidity = val; }

        double GetEquity() { return Equity; }
        void SetEquity(double val) { Equity = val; }

        double GetTrade_accounts() { return Trade_accounts; }
        void SetTrade_accounts(double val) { Trade_accounts = val; }

        double GetFinancial_Depts() { return Financial_Depts; }
        void SetFinancial_Depts(double val) { Financial_Depts = val; }

        int Getid_building() { return id_building; }
        void Setid_building(int val) { id_building = val; }

        double Getdepts() { return depts; }
        void Setdepts(double val) { depts = val; }

        QString Getyear() { return year; }
        void Setyear(QString val) { year = val; }

        QString Getmounth() { return mounth; }
        void Setmounth(QString val) { mounth = val; }

        double GetNon_operating_Credit() { return Non_operating_credits; }
        void SetNon_operating_Credits(double val) { Non_operating_credits= val; }

        bool add_finacial_balance();
        void create_ratio(QString, QString, long );
        void displaybalance(QString, QString, long );
        //void print_financial_balance();
        QStringList List;


    protected:
    private:
        int id_balance;
        double Intangible_Assets;
        double Tangible_assets;
        double financial_assets;
        double Inventory_value;
        double Trade_Receivable;
        double Non_operating_Depts;
        double Liquidity;
        double Equity;
        double Trade_accounts;
        double Financial_Depts;
        double Non_operating_credits;
        double depts ;

        QString  mounth;
        QString year;
        int id_building;
};

#endif // FINANCIAL_BALANCE_H
