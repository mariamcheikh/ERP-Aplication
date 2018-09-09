#ifndef UIQUICKLOG_H
#define UIQUICKLOG_H
#include <QDialog>
#include <QProcess>
#include <QMessageBox>
#include <QCloseEvent>
using namespace std ;
namespace Ui {
class quicklog;
}
class quicklog : public QDialog
{
    Q_OBJECT

public:
    explicit quicklog(QWidget *parent =0);
    ~quicklog();
    void set_session(int id,QString pwd,int time_limit);
    void closeEvent(QCloseEvent *event);


private slots:

    void on_connection_clicked();


    void on_close_clicked();

private:
    Ui::quicklog *ui;
    int id ;
    QString pwd ;
    int attempts;
    int time_limit;
};
#endif // QUICKLOG_H
