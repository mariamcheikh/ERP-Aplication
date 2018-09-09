#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T05:26:57
#
#-------------------------------------------------

QT       += core gui sql printsupport network webkit
QT       += sql
QT += network \
    webkit \
    xml \
    xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fares_inventory
TARGET = smtp
TEMPLATE = app


SOURCES += main.cpp\
    menu_inventory.cpp \
    inputcontrol.cpp\
    uioptions.cpp\
    uiquicklog.cpp\
    employee.cpp\
    manager.cpp\
    product.cpp \
    refill_order.cpp \
    delivery.cpp \
    truck.cpp \
    import_order.cpp \
    supplier.cpp \
    session.cpp\
    uimainframe.cpp\
    repair_report.cpp \
    mail.cpp \
    smtp.cpp \
    productstat.cpp \
    stmp.cpp

HEADERS  += menu_inventory.h \
    product.h\
    ui_mainframe.h\
    inputcontrol.h\
    uioptions.h\
    uiquicklog.h\
    employee.h\
    manager.h\
    refill_order.h \
    delivery.h \
    truck.h \
    import_order.h \
    supplier.h \
session.h\
    repair_report.h \
    mail.h \
    smtp.h \
    productstat.h \
    stmp.h

FORMS    += menu_inventory.ui\
    uimainframe.ui\
    uioptions.ui\
    uipassword.ui\
    uiquicklog.ui \
    mail.ui
