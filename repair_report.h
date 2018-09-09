#ifndef REPAIR_REPORT_H
#define REPAIR_REPORT_H
#include <QString>

class Repair_report
{
private:
    int id_repair;
    QString date;
    int time;
    float amount;
    int id_truck;
public:
    Repair_report();
    void add ();
    void modify();
    void archive();
    void search();
};

#endif // REPAIR_REPORT_H
