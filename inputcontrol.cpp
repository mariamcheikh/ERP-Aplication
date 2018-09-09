#include "inputcontrol.h"

inputcontrol::inputcontrol()
{

}
inputcontrol::~inputcontrol()
{

}
bool inputcontrol::is_number(QString name)
{   if       (name.contains("a", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("b", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("c", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("d", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("e", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("f", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("g", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("h", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("i", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("j", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("k", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("l", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("m", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("n", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("o", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("p", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("q", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("r", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("s", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("t", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("u", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("v", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("w", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("x", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("y", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("z", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("A", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("B", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("C", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("D", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("E", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("F", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("G", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("H", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("I", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("J", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("K", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("L", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("M", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("N", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("O", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("P", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("Q", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("R", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("S", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("T", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("U", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("V", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("W", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("X", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("Y", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("Z", Qt::CaseInsensitive)){return false;}

    else if  (name.contains("*", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("/", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("_", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("-", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("+", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("%", Qt::CaseInsensitive)){return false;}
    else if  (name.contains(" ", Qt::CaseInsensitive)){return false;}
    else if  (name.contains(".", Qt::CaseInsensitive)){return false;}
    else if (name.contains("#", Qt::CaseInsensitive)){return false;}
    else if (name.contains("'", Qt::CaseInsensitive)){return false;}
    else if (name.contains("�", Qt::CaseInsensitive)){return false;}
    else if (name.contains("|", Qt::CaseInsensitive)){return false;}
    else if (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if (name.contains(" ", Qt::CaseInsensitive)){return false;}

    else {return true;}

}
bool inputcontrol::is_ssn(QString ssn)
{if(is_number(ssn)==true)
    {
        if(ssn.length()==13)
        {if(ssn.toInt()/1000000000000!=1||ssn.toInt()/1000000000000!=2){return false; }
            else     { return true;}
        }
        else {return false ;}
    }
    else {return false ;}
}
bool inputcontrol::is_leap_year(int year)
{
    if(  year%4!=0){return false;}


    else{return true ;}

}
int  inputcontrol::generate_bar_code(QString object)
{/* missing check method */

    if(object=="employee")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%99999+54321;
        return number ;
    }
    else if(object=="shift")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%9999+5831;
        return number ;
    }
    else if(object=="sale")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%9999999+5636971;
        return number ;
    }
    else if(object=="sale_line")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%999999+2569971;
        return number ;
    }
    else if(object=="export_order")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%999999+2569971;
        return number ;
    }
    else if(object=="export_line")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%999999+2569971;
        return number ;
    }
    else if(object=="customer")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%99999+5945421;
        return number ;
    }
    else if(object=="event")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%9999999+59432421;
        return number ;
    }
    else if(object=="discount")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%9999999+59432421;
        return number ;
    }
    else if(object=="vacation")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%99999999+54343521;
        return number ;
    }
    else if(object=="movement")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%999999+543421;
        return number ;
    }
    else if(object=="promotion")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%99999+54763521;
        return number ;
    }
    else if(object=="raise")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%999+54321;
        return number ;
    }
    else if(object=="combination")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%9999999+547679321;
        return number ;
    }
   else if(object=="product")
    {
        int number ;
        time_t t;
        qsrand((unsigned) time(&t));
        number=qrand()%9999999+5467321;
        return number ;
    }



    qDebug()<<"dude specify a valid type"<<" the object you specified  :"<<object;
        return -1;


}
bool inputcontrol::is_valid_cin_or_phone(QString number)
{
    if(is_number(number))
    {if(number.length()==8)
        {return true;}
        else{return false ;}
    }
    else {
        return false ;
    }
}
bool inputcontrol::is_valid_name(QString name)
{

    if (name.contains("0", Qt::CaseInsensitive)){return false;}
    else if (name.contains("1", Qt::CaseInsensitive)){return false;}
    else if (name.contains("2", Qt::CaseInsensitive)){return false;}
    else if (name.contains("3", Qt::CaseInsensitive)){return false;}
    else if (name.contains("4", Qt::CaseInsensitive)){return false;}
    else if (name.contains("5", Qt::CaseInsensitive)){return false;}
    else if (name.contains("6", Qt::CaseInsensitive)){return false;}
    else if (name.contains("7", Qt::CaseInsensitive)){return false;}
    else if (name.contains("8", Qt::CaseInsensitive)){return false;}
    else if (name.contains("9", Qt::CaseInsensitive)){return false;}
    else if (name.contains("*", Qt::CaseInsensitive)){return false;}
    else if (name.contains("/", Qt::CaseInsensitive)){return false;}
    else if (name.contains("_", Qt::CaseInsensitive)){return false;}
    else if (name.contains("-", Qt::CaseInsensitive)){return false;}
    else if (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if (name.contains(".", Qt::CaseInsensitive)){return false;}
    else if (name.contains("+", Qt::CaseInsensitive)){return false;}
    else if (name.contains("%", Qt::CaseInsensitive)){return false;}
    else if (name.contains("#", Qt::CaseInsensitive)){return false;}
    else if (name.contains("'", Qt::CaseInsensitive)){return false;}
    else if (name.contains("�", Qt::CaseInsensitive)){return false;}
    else if (name.contains("|", Qt::CaseInsensitive)){return false;}
    else if (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if (name.contains("@", Qt::CaseInsensitive)){return false;}

    else {return true;}
}
bool inputcontrol::is_valid_email(QString name)
{
    if (name.contains("#", Qt::CaseInsensitive)){return false;}
    else if (name.contains("'", Qt::CaseInsensitive)){return false;}
    else if (name.contains("�", Qt::CaseInsensitive)){return false;}
    else if (name.contains("|", Qt::CaseInsensitive)){return false;}
    else if (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if (name.contains(" ", Qt::CaseInsensitive)){return false;}
    else if (name.contains("*", Qt::CaseInsensitive)){return false;}
    else if (name.contains("/", Qt::CaseInsensitive)){return false;}
    else if (name.contains("-", Qt::CaseInsensitive)){return false;}
    else if (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if (name.contains("+", Qt::CaseInsensitive)){return false;}
    else if (name.contains("%", Qt::CaseInsensitive)){return false;}
    else if (name.contains(",", Qt::CaseInsensitive)){return false;}
    if (name.count('@', Qt::CaseInsensitive)>1) {return false;}

    else{return true ;}
}
bool inputcontrol::is_valid_float(QString name)
{
    if  (name.contains("a", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("b", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("c", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("d", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("e", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("f", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("g", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("h", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("i", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("j", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("k", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("l", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("m", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("n", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("o", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("p", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("q", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("r", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("s", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("t", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("u", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("v", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("w", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("x", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("y", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("z", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("A", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("B", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("C", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("D", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("E", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("F", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("G", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("H", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("I", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("J", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("K", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("L", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("M", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("N", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("O", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("P", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("Q", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("R", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("S", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("T", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("U", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("V", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("W", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("X", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("Y", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("Z", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("*", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("/", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("_", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("-", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("!", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("+", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("%", Qt::CaseInsensitive)){return false;}
    else if  (name.contains(" ", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("@", Qt::CaseInsensitive)){return false;}
    else if  (name.contains(",", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("#", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("'", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("�", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("|", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("?", Qt::CaseInsensitive)){return false;}
    else if  (name.contains("!", Qt::CaseInsensitive)){return false;}



    else {return true;}
}
