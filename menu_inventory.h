#ifndef MENU_INVENTORY_H
#define MENU_INVENTORY_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QWidget>
#include "product.h"
#include <QMessageBox>
#include <QString>
#include <QSqlRecord>
#include <QDate>
#include "truck.h"
#include "import_order.h"
#include "refill_order.h"



namespace Ui {
class Menu_Inventory;
}

class Menu_Inventory : public QWidget
{
    Q_OBJECT

public:
void size_follower(QString);

void size_follower_modify(QString);

    explicit Menu_Inventory(QWidget *parent = 0);
    ~Menu_Inventory();

private slots:
    void on_pushButton_3_clicked();

    void on_Disconnect_clicked();

    void on_comboBox_Category_currentTextChanged(const QString &arg1);

    void on_pushButton_Add_product_released();

    void on_pushButton_Search_Display_released();

    void on_LoadM_clicked();

    void on_Pushbutton_Modify_Delete_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_Delete_Product_in_Modify_clicked();

    void on_pushButton_Add_Truck_released();

    void on_comboBox_Modify_Category_currentIndexChanged(const QString &arg1);

    void on_pushButton_Truck_Display_clicked();

    void on_pushButton_Load_Truck_Modify_clicked();

    void on_pushButton_Truck_Delete_clicked();

    void on_pushButton_Add_Refill_Submit_clicked();

    void on_pushButton_Search_Refill_Order_Display_2_clicked();

    void on_pushButton_Load_Refill_Modify_clicked();

    void on_pushButton_Refill_Order_Modify_Delete_clicked();

    void on_pushButton_Load_Delivery_Details_clicked();

     void on_pushButton_Modify_Product_Confirm_clicked();

    void on_pushButton_Modify_Truck_Submit_clicked();

    void on_pushButton_Email_clicked();

    void on_tabWidget_3_destroyed();

    void on_pushButton_Modify_Refill_Show_clicked();

    void on_pushButton_Modify_Refill_Submit_clicked();

    void on_pushButton_Add_Import_Submit_clicked();

    void on_pushButton_Load_Product_List_clicked();

    void on_pushButton_Show_Truck_clicked();

    void on_pushButton_export_Excel_clicked();


    void on_pushButton_clicked();



private:
    QSqlDatabase db;
    Ui::Menu_Inventory *ui;


    //attribus Refill
    int id_refill;
    QDate date;
    QString state;
    QString type_o;
    QDate ETA;
    int id_building;

    //attribus Import
    int id_order;
    int quantity_i;
    int id_product_i;

    //attribus produits
    Product tempProduct;
    Truck tempTruck;
    Refill_Order tempRefill;
    Import_order tempImport;
    int id_product;
    QDate added_date;
    int quantity;
    QString color;
    QString size;
    QString name;
    QString type_of_fabric;
    QString gender;
    QString category;
    float weight;
    float initial_price;
    int nb_point;
    float production_price;

    //attribus Trucks

    int id_truck;
    QString type;
    int city_state_nb;
    QString sizeT;
    QString power;
    float max_weight;
    float initial_weight;
    float price;
    QString contract;
    QString availability;
    QString reason;
    int serial_num;

};

#endif // MENU_INVENTORY_H
