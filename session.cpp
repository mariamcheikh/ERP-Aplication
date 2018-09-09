#include "session.h"

session::session()
{

}
session::~session()
{

}
session::session(int id,QString mdp)
{
id_manager=id;
password=mdp;
}
void session::connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/gambler/Desktop/erp_hamadi");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
            "Click Cancel to exit.", QMessageBox::Cancel);


    }
    else
    {


    }



}
bool session::change_password()
{
        QSqlQuery query;

        query.prepare("update manager set password=:password where( id_manager = :id_manager)");

        query.bindValue(":id_manager",id_manager);
        query.bindValue(":password",password);

        qDebug()<<query.lastError();

        return(query.exec());
}

