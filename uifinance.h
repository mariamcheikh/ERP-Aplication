#ifndef FINANCE_H
#define FINANCE_H

//#include "uimail.h"
#include <QWidget>
#include"Supplier.h"
#include "Advance.h"
#include "Charge.h"
#include "Financial_balance.h"
#include "statfinanace.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QStringListModel>
#include "Payment_report.h"
namespace Ui {
class finance;
}

class finance : public QWidget
{
    Q_OBJECT

public:
    explicit finance(QWidget *parent = 0);
    ~finance();

private slots:
    QGraphicsScene *Statclef(vector<QString>);


    
    void on_PBaddSupplier_clicked();

    void on_PBvaliderSupplier_clicked();

    void on_PBclear_clicked();



    void on_PBdisconnect_clicked();

    void on_PBarchivesupplier_clicked();

    void on_PBupdateSupplier_clicked();


    void on_PBaddAdvance_clicked();

    void on_supplier_list_clicked(const QModelIndex &index);

    void on_PBpdf_clicked();

    void on_exportcsv_clicked();

    void on_exportpdf_2_clicked();

    void on_pbChoisir_clicked();

    void on_PBaddcharge_clicked();

    void on_pbrechercheavance_clicked();

    void on_PBaddFB_clicked();




    void on_LEsearchSupplier_cursorPositionChanged();

    void on_PBsatat_clicked();
    void on_LEname_cursorPositionChanged();

    void on_LEdiscribe_cursorPositionChanged( );

    void on_LEtel_cursorPositionChanged( );

    void on_LEfax_cursorPositionChanged( );

    void on_LEmail_cursorPositionChanged( );

    void on_LEzip_cursorPositionChanged( );

    void on_LEcity_cursorPositionChanged( );

    void on_LEarea_cursorPositionChanged( );

    void on_LEstreet_cursorPositionChanged( );

    void on_LEname_edit_cursorPositionChanged( );

    void on_LEdiscribe_edit_cursorPositionChanged( );

    void on_LEtel_edit_cursorPositionChanged( );

    void on_LEfax_edit_cursorPositionChanged( );

    void on_LEmail_edit_cursorPositionChanged( );

    void on_LEzip_edit_cursorPositionChanged( );

    void on_LEcity_edit_cursorPositionChanged( );

    void on_LEarea_edit_cursorPositionChanged( );

    void on_LEstreet_edit_cursorPositionChanged( );

    void on_s_clicked();

    void on_LEadvancevalue_cursorPositionChanged( );

    void on_PBcreerratio_clicked();


    void on_PBpayslip_clicked();

    void on_pbdisplaypay_clicked();

    void on_pBmail_clicked();

    void on_Print_clicked();



    void on_advance_list_clicked(const QModelIndex &index);
    
    void on_pbdeleteadvance_clicked();

    void on_LEsearchcharges_cursorPositionChanged();

    void on_pbSearch_clicked();

    void on_PBdisplayFB_clicked();

private:
    Ui::finance *ui;
    QString supplier_name;
    QString email;
    QString description;
    int tel;
    int fax;
    QDate add_date;
    int id_supplier;
    QString zip_code;
    QString street;
    QString area;
    QString city;
    void clear();
    Supplier tempSupplier;
    employee tempemp;
    Advance tempadvance;
    Charge tempcharge;
   int id_advance;

};

#endif // FINANCE_H
