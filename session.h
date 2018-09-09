#ifndef SESSION_H
#define SESSION_H
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "session.h"
using namespace std ;

class session
{
private:
   int id_manager;
   QString password ;
public:
    session();
    session(int ,QString);
    ~session();
    void connection();
    bool change_password();



};

#endif // SESSION_H
