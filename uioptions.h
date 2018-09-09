#ifndef UIOPTIONS_H
#define UIOPTIONS_H

#include <QDialog>
#include <fstream>
#include <QTextStream>
#include <Qfile>
#include <QString>
#include <string>
#include <QProcess>
#include <QMessageBox>
#include <QTime>
#include <QFileDialog>
using namespace std ;
namespace Ui {
class Options;
}
class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();
   int Getsize(){return size;}
   bool Getwindow(){return window ; }
   int Getlanguage(){return language; }
   void setwindow(bool signal){window=signal;}


private slots:
    void on_cancel_clicked();

    void on_fullscreen_clicked();

    void on_window_clicked();

    bool on_ok_clicked();

    void on_pushButton_clicked();

    void on_modify_logo_clicked();

private:
    Ui::Options *ui;
    int size ;
    bool window ;
    int language ;



};
#endif // OPTIONS_H
