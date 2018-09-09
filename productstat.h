#ifndef PRODUCTSTAT_H
#define PRODUCTSTAT_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QSqlQuery>
class ProductStat : public QWidget
{
    Q_OBJECT
public:
    ProductStat (int);
    explicit ProductStat(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
private :
    int a ;
};

#endif // PRODUCTSTAT_H
