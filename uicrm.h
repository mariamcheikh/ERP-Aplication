#ifndef UICRM_H
#define UICRM_H

#include <QWidget>
#include <QDate>
#include <QString>
#include "customer.h"
#include <QMessageBox>
#include "client.h"
#include "corporate.h"
#include "employee.h"
namespace Ui {
class uicrm;
}

class uicrm : public QWidget
{
    Q_OBJECT

public:
    explicit uicrm(QWidget *parent = 0);
    ~uicrm();
   void clear_client_line_edits();
   void clear_corp_line_edits();

private slots:
    void on_pb_add_disc_finish_clicked();

    void on_pb_add_client_finish_clicked();

    void on_pb_add_corp_finish_clicked();

    void on_le_search_sec_responsible_prom_textChanged(const QString &arg1);

    void on_tw_employee_list_prom_doubleClicked(const QModelIndex &index);

    void on_le_search_add_employee_prom_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::uicrm *ui;
    Client *cl;
    Corporate *corp;
    QString name;
    int number;
    QString mail;
    QString adress;
    QString  family_name;
    QString gender;
    QDate birth_date;
    QString CIN;
    QString type_of_ID;
    QString corp_ID;
    QString corp_comm;
    int fax;
    QString type_of_contract;
    QString contract;
};

#endif // UICRM_H
