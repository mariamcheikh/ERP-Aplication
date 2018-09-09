#ifndef TRUCK_H
#define TRUCK_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>

class Truck
{
private:
    int id_truck;
    QString type;
    int city_state_nb;
    QString size;
    QString power;
    float max_weight;
    float initial_weight;
    float price;
    QString contract;
    QString availability;
    QString reason;
    int serial_num;
    int building;
public:
    Truck();
    Truck(QString type, int city_state_nb, QString size, QString power, float max_weight, float initial_weight, float price, QString contract, QString availability, QString reason, int serial_num,int building);
    bool add ();

    bool modify(int aux);

    bool Supprimer_T(int id_truck);
    void search();

    void select_truck(int aux);


    /*--------------------------gets--------------------*/
    QString Get_type(){return type;}
    QString Get_power(){return power;}
    QString Get_size(){return size;}
    QString Get_availability(){return availability;}
    int Get_id_truck(){return id_truck;}
    int Get_city_state_nb(){return city_state_nb;}
    QString Get_reason(){return reason;}
    float Get_initial_weight(){return initial_weight ;}
    float Get_price(){return price;}
    QString Get_contract(){return contract ;}
    int Get_serial_num(){return serial_num;}
    float Get_max_weight(){return max_weight;}


    QSqlQueryModel *display_truck();
    QSqlQueryModel *display_driver();
    QSqlQueryModel *search_truck(QString value);
};

#endif // TRUCK_H
