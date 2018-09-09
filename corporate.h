#ifndef CORPORATE
#define CORPORATE
#include "customer.h"



class Corporate:public Customer
{
private:
    QString type_of_ID;
    QString corp_ID;
    QString corp_comm;
    int fax;
    QString type_of_contract;
    QString contract /*chemin absolu du fichier*/;

    /*stats*/
    int nb_clients;

public :
/*Constructeur et destructeur*/
    Corporate();
    ~Corporate();

    Corporate(QString type_of_ID, QString corp_ID, QString corp_comm, int fax, QString type_of_contract, QString contract, QString name, int number, QString mail, QString adress );
/*Méthodes*/
    bool add_new_corp();
    bool delete_corp(int ID_customer);
    bool modify_corp(int ID_customer);
    bool search_corp(QString type_of_ID, QString corp_ID, QString corp_comm, int fax, QString type_of_contract, QString contract, QString name, int number, QString mail, QString adress );

     QSqlQueryModel *display_corp();
    /*statistiques*/
     int get_nb_clients(){return nb_clients;}

};




#endif // CORPORATE

