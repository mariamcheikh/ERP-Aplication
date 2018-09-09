#ifndef UISALES_H
#define UISALES_H
#include <QWidget>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QtPrintSupport/QPrinterInfo>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include  <QDir>
#include <SmtpClient-for-Qt-1.1/src/smtpclient.h>
#include <SmtpClient-for-Qt-1.1/src/mimetext.h>
#include<QTextDocument>
#include<QFileDialog>
#include<QModelIndexList>
#include "employee.h"
#include "product.h"
#include "customer.h"
#include "sale.h"
#include"Order.h"
#include"bargraphwidget.h"
#include"session.h"
#include"uipassword.h"
#include"inputcontrol.h"
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>


namespace Ui {
class uisales;
}

class uisales : public QWidget
{
    Q_OBJECT

public:
    explicit uisales(QWidget *parent = 0);
    ~uisales();
    bool check_existence(QString id);
    void increment_quantity(int pos);
    bool check_existence(QString id, QString object_name);
    void increment_quantity(int pos, QString object_name);
    void  insert_table_items ();
    void set_session(int id,QString pwd);

private slots:
    void on_id_seller_com_currentTextChanged(const QString &arg1);
    void on_id_product_com_currentTextChanged(const QString &arg1);
    void on_id_client_com_currentTextChanged(const QString &arg1);
    void on_create_sale_line_clicked();
    void on_seller_enable_toggled(bool checked);
    void on_client_enable_toggled(bool checked);
    void on_finish_sale_clicked();
    void on_cancel_sale_line_clicked();
    void on_create_sale_line_2_clicked();
    void on_delete_sale_QPB_clicked();
    void on_display_histogram_clicked();
    void on_create_order_line_clicked();
    void on_id_product_com_oder_currentTextChanged(const QString &arg1);
    void on_id_client_com_order_currentTextChanged(const QString &arg1);
    void on_cancel_order_line_clicked();
    void on_submit_order_clicked();
    void on_QPB_display_order_clicked();
    void on_delete_sale_QPB_2_clicked();
    void on_create_sale_line_3_clicked();
    void on_create_sale_line_6_clicked();
    void on_create_sale_line_5_clicked();
    void on_display_histogram_2_clicked();
    void on_create_sale_line_4_clicked();
    void on_create_sale_line_7_clicked();
    void on_create_sale_line_9_clicked();
    void on_create_sale_line_8_clicked();

    void on_modify_order_line_clicked();



    void on_Disconnect_clicked();

    void on_Change_Password_clicked();

    void on_send_email_clicked();

    void on_Export_to_excel_2_clicked();

    void on_send_email_2_clicked();

    void on_Export_to_excel_clicked();

private:
    Ui::uisales *ui;
    employee *e;
    Product *p;
    Customer *c;
    sale *s;
    Order *o;
    inputcontrol i;
    password *pwd ;
    QString pass;
    int ide;
    int total_product_points_number;
    int row_order;
    int old_qt;
    int choice;
    double total_price;
    double net_price;
    int id_employee;
    int id_client;
    int id_order;
    int id_export_line;
     sale tempsale;
      Order tempOrder;
     QDate date;
     int quantityy;
  /*------- order infos ------*/
     int order_total_product_points_number;
     int order_row_order;
     int order_old_qt;
     int order_choice;
     double order_total_price;
     double order_net_price;
     int order_id_employee;
     int order_id_client;

};

#endif // UISALES_H
