#include "ui_mainframe.h"
#include <QApplication>
#include <string>
#include <iostream>
#include <cstdlib>
#include <QFile>
#include <QTextStream>
#include <QWidget>
#include <QRect>
#include <QPoint>
#include <QSplashScreen>
using namespace std ;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile stylesheet("C:/Qt/Tools/QtCreator/bin/Hamadi/style.qss");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    a.setStyleSheet(setSheet);



    //---------------------------------------------

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/gambler/Desktop/rsz_back_ground_global.PNG"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window..."),topRight, Qt::white);
    /*------- setting main window ------*/

    Mainframe w;
    QThread::sleep(2);
    /*------------------done ------------*/
    splash->showMessage(QObject::tr("Loading modules..."),topRight, Qt::white);
    QThread::sleep(2);
    /*-------------done-------------*/
    splash->showMessage(QObject::tr("Establishing connections..."),topRight, Qt::white);
    QThread::sleep(2);





    splash->finish(&w);
    delete splash;
    //-----------------------------------------------------


    QString appTitle("Hamadi");//setting the name of the app title
    w.setWindowTitle(appTitle);//setting the app title



    QString filename ;
    filename="config.txt";//setting file name
    QFile file(filename);// setting file
    file.open(QIODevice::ReadOnly|QIODevice::Text);//reading file
    QTextStream in(&file);//assigning file reference
    QString str=in.readLine ();//reading first line from config file
    QString str2=in.readLine();//reading second line from config file
    QString str3=in.readLine();//reading third line from config file

    if (str=="display:fullscreen" )
    {
        w.showFullScreen();    //display in fullscreen
    }

    else
    {
        w.show();//display in custom resolution
        if(str3=="resolution:1280*720")
        {
            int height=720;    //setting resolution and repositioning items
            int width=1280;
            w.resize(width,height);
        }
        else if(str3=="resolution:1080*720")
        {
            int height=720;    //------------------------------------------
            int width=1080;
            w.resize(width,height);
        }
        else if(str3=="resolution:680*400")
        {
            int height=400;    //---------------------------------------------
            int width=680;
            w.resize(width,height);
        }
    }

    w.reposition();//repositioning widget items
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());//centralising the mainframe in the screen
    file.close();//closing the config.txt file

    QString filenm ; //setting file name container
    filenm="config_ap.txt"; //assigning file name to container
    QFile fil(filenm);//setting us a file object
    fil.open(QIODevice::ReadOnly|QIODevice::Text);//opening a file to read it
    QTextStream ina(&fil);//assigning textstream to file reference
    QString strin=ina.readLine();//reading from file
    w.set_background(strin);//setting back ground choice from file
    fil.close();//closing filenm

    QString filenma ;//preparing a new container
    filenma="config_logo.txt";//assigning file name to container
    QFile fila(filenma);//setting us a new file object
    fila.open(QIODevice::ReadOnly|QIODevice::Text);//opening a file to read
    QTextStream inaa(&fila);//assigning textstream to file reference
    QString stringa=inaa.readLine();//reading line from config_logo.txt
    w.set_logo(stringa);// setting logo choice
    fila.close();//closing file
    return a.exec();//returning main exit values


}
