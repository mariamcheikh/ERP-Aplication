#ifndef UIPASSWORD_H
#define UIPASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include "session.h"
using namespace std;
namespace Ui {
class password;
}

class password : public QDialog
{
    Q_OBJECT

public:
    explicit password(QWidget *parent = 0);
    ~password();
    void load_credentials(int ide, QString pwd);
private:


private slots:
    void on_change_clicked();

private:
    Ui::password *ui;
    QString pass;
};

#endif // PASSWORD_H
