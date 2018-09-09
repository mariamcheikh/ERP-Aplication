#ifndef CLIENT
#define CLIENT
#include "customer.h"


class Client : public Customer
{
private:

    QString  family_name;
    QString gender;
    QDate birth_date;
    QString CIN;
public :
/*Constructeur et destructeur*/
    Client();
    ~Client();

    Client(QString family_name, QString gender, QDate birth_date, QString CIN, QString name, int number, QString mail, QString adress);
/*Méthodes*/
    bool add_new_client();
    bool delete_client(int ID_customer);
    bool modify_client(int ID_customer);
    QSqlQueryModel * search_client();
    QSqlQueryModel *display_client();
/*statistiques*/



};






#endif // CLIENT

