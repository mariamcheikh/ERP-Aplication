#ifndef STATFINANACE_H
#define STATFINANACE_H
#include "session.h"
#include <QWidget>
#include <set>
#include <vector>

using namespace std;
class statfinanace : public QWidget
{
    Q_OBJECT
public:
    ~statfinanace();
    explicit statfinanace(QWidget *parent = 0);
    statfinanace();
    void set_data(vector<double>,vector<int>,vector<QString >);
protected:
    void paintEvent(QPaintEvent *);
    vector<QString > tab_nom;
    vector<int> tab_id;
    vector <double> tab_amount;
		
    
   // void set_id();
   // void set_amount();
signals:

public slots:
};

#endif // STATFINANACE_H
