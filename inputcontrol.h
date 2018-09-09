#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H
#include <QString>
#include <time.h>
#include <QDebug>
using namespace std;


class inputcontrol
{
public:
    inputcontrol();
    ~inputcontrol();
    bool is_number(QString );
    bool is_ssn(QString);
    bool is_leap_year(int);
    int generate_bar_code(QString object);
    bool is_valid_name(QString);
    bool is_valid_cin_or_phone(QString);
    bool is_valid_email(QString);
    bool is_valid_float(QString);



};

#endif // INPUTCONTROL_H
