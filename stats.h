#ifndef STATS_H
#define STATS_H

#include <QPaintEngine>
#include <QPaintEvent>
#include <QWidget>


class stats: public QWidget
{
public:

    explicit stats(QWidget *parent =0);

protected:
    void paintEvent (QPaintEvent *);

};

#endif // STATS_H


