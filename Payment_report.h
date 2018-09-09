#ifndef PAYMENT_REPORT_H
#define PAYMENT_REPORT_H
#include <QString>
#include <QDateTime>
#include "session.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
class Payment_report
{
    public:
        Payment_report();
        ~Payment_report();
        unsigned int Getid_payslip() { return id_payslip; }
        void Setid_payslip(unsigned int val) { id_payslip = val; }
        double Getnet_pay() { return net_pay; }
        void Setnet_pay(double val) { net_pay = val; }
        double Getbasic_pay() { return basic_pay; }
        void Setbasic_pay(double val) { basic_pay = val; }
        double Getraises() { return raises; }
        void Setraises(double val) { raises = val; }
        double Getadvances() { return advances; }
        void Setadvances(double val) { advances = val; }
        double Gettaxes() { return taxes; }
        void Settaxes(double val) { taxes = val; }
        double Getinsurance() { return insurance; }
        void Setinsurance(double val) { insurance = val; }
        double Getpension() { return pension; }
        void Setpension(double val) { pension = val; }
        QDate Getpay_date() { return pay_date; }
        void Setpay_date(QDate val) { pay_date = val; }
        
        bool calculate_payslip(unsigned int, int , int);
        void displaypayslip(unsigned int, int , int);
        QSqlQueryModel *displayallpayslip();
        QSqlQueryModel *searchpayslip(QString);

        void export_pdf_payslip(unsigned int);
        void print_payslip(unsigned int);


        QStringList List;



    protected:
    private:
        unsigned int id_payslip;
        double net_pay;
        double basic_pay;
        double raises;
        double advances;
        double taxes;
        double insurance;
        double pension;
        QDate pay_date;
};

#endif // PAYMENT_REPORT_H
