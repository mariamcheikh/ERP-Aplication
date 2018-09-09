#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T13:29:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += widgets
QT       += core
QT       +=network
QT       += core gui xml printsupport
QT       +=webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hamadi
TEMPLATE = app

INCLUDEPATH += $$PWD
SOURCES += main.cpp\
    mytimer.cpp \
    session.cpp \
    inputcontrol.cpp \
    employee.cpp \
    manager.cpp \
    vacation.cpp \
    driver.cpp \
    product.cpp \
    building.cpp \
    truck.cpp \
    repairs.cpp \
    event.cpp \
    discount.cpp \
    import.cpp \
    refill.cpp \
    order.cpp \
    sale.cpp \
    client.cpp \
    promotion.cpp \
    shift.cpp \
    raises.cpp \
    uigestionrh.cpp \
    uimainframe.cpp \
    uioptions.cpp \
    uiquicklog.cpp \
    uipassword.cpp \
    piechartwidget.cpp \
    bargraphwidget.cpp \
    agepyramidwidget.cpp \
    slicepiewidget.cpp \
    mouvement.cpp \
    uisales.cpp \
    customer.cpp \
    corporate.cpp \
    uicrm.cpp \
    smtp.cpp \
    delivery.cpp \
    menu_inventory.cpp \
    import_order.cpp \
    refill_order.cpp \
    Advance.cpp \
    Charge.cpp \
    Financial_balance.cpp \
    Payment_report.cpp \
    statfinanace.cpp \
    Supplier.cpp \
    uifinance.cpp \
    gmail_smtp.cpp \
    statistique.cpp \
    productstat.cpp \
    discount_event.cpp \
    promotionnal.cpp \
    stats.cpp

HEADERS  += \
    mytimer.h \
    session.h \
    inputcontrol.h \
    employee.h \
    manager.h \
    vacation.h \
    driver.h \
    product.h \
    building.h \
    truck.h \
    repairs.h \
    event.h \
    discount.h \
    import.h \
    refill.h \
    order.h \
    sale.h \
    client.h \
    promotion.h \
    shift.h \
    raises.h \
    uigestionrh.h \
    ui_mainframe.h \
    uioptions.h \
    uiquicklog.h \
    uipassword.h \
    piechartwidget.h \
    bargraphwidget.h \
    agepyramidwidget.h \
    slicepiewidget.h \
    mouvement.h \
    uisales.h \
    customer.h \
    corporate.h \
    uicrm.h \
    delivery.h \
    smtp.h \
    menu_inventory.h \
    import_order.h \
    refill_order.h \
    Advance.h \
    Charge.h \
    Financial_balance.h \
    Payment_report.h \
    statfinanace.h \
    Supplier.h \
    uifinance.h \
    gmail_smtp.h \
    statistique.h \
    SmtpClient-for-Qt-1.1/src/mimetext.h \
    SmtpClient-for-Qt-1.1/src/smtpclient.h \
    productstat.h \
    discount_event.h \
    promotionnal.h \
    stats.h

FORMS    += \
    uigestionrh.ui \
    uimainframe.ui \
    uiquicklog.ui  \
    uipassword.ui  \
    uioptions.ui \
    uisales.ui \
    uicrm.ui \
    menu_inventory.ui \
    finance.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/ -lSMTPEmail

#INCLUDEPATH += $$PWD/build-SMTPEmail-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug
INCLUDEPATH += $$PWD/SmtpClient-for-Qt-1.1/src
DEPENDPATH += $$PWD/build-SMTPEmail-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug

