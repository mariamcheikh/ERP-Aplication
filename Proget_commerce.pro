#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T00:50:28
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport
QT += network \
    webkit \
    xml \
    xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = Proget_commerce
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    catalogue.cpp \
    commande.cpp \
    commerce.cpp \
    product.cpp \
    raw_materials.cpp \
    production.cpp \
    email.cpp \
    smtp.cpp

HEADERS  += mainwindow.h \
    connexion.h \
    catalogue.h \
    commande.h \
    commerce.h \
    product.h \
    raw_materials.h \
    production.h \
    email.h \
    smtp.h

QT += axcontainer
FORMS    += mainwindow.ui \
    commerce.ui \
    production.ui \
    email.ui
RC_FILE = ressource.rc

DISTFILES += \
    ressource.rc \
    map.html

QT_LOGGING_RULES=qt.network.ssl.warning=false
