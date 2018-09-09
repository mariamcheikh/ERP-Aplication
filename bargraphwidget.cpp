
#include "bargraphwidget.h"
bargraphwidget::bargraphwidget(QWidget *parent) :QWidget(parent)
{
    this->variables_number=0;
    this->first=0;
    this->second=0;
    this->third=0;
    this->fourth=0;
    this->fifth=0;
}
void   bargraphwidget::insert_values(int variables_number, double first, double second)
{
    this->variables_number=variables_number;
    this->first=first;
    this->second=second;
    this->third=0;
    this->fourth=0;
    this->fifth=0;

}
void   bargraphwidget::insert_values(int variables_number, double first, double second,double third)
{
    this->variables_number=variables_number;
    this->first=first;
    this->second=second;
    this->third=third;
    this->fourth=0;
    this->fifth=0;
}
void   bargraphwidget::insert_values(int variables_number, double first, double second,double third,double fourth)
{
    this->variables_number=variables_number;
    this->first=first;
    this->second=second;
    this->third=third;
    this->fourth=fourth;
    this->fifth=0;
}
void   bargraphwidget::insert_values(int variables_number, double first, double second,double third,double fourth,double fifth)
{
    this->variables_number=variables_number;
    this->first=first;
    this->second=second;
    this->third=third;
    this->fourth=fourth;
    this->fifth=fifth;
}
double bargraphwidget::get_max()
{
    double max ;
    max=first;
    if(max<second)
    {
        max=second;
    }
    if(max<third)
    {
        max=third;
    }
    if(max<fourth)
    {
        max=fourth;
    }
    if(max<fifth)
    {
        max=fifth;
    }
    return max;

}
void   bargraphwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    double max =get_max();


    if(variables_number==2)
    {

        bar_width=120;
        distance_between_bars=70;

        painter.setBrush(Qt::red);
        start_point_y=this->height()-(first*500)/max;


        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());

        painter.setBrush(Qt::blue);
        start_point_y=this->height()-(second*500)/max;
        start_point_x=+bar_width+distance_between_bars*1;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());

        start_point_x=0;

    }
    else if(variables_number==3)
    {
        bar_width=120;
        distance_between_bars=70;
        painter.setBrush(Qt::red);
        start_point_y=this->height()-(first*500)/max;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::blue);
        start_point_y=this->height()-(second*500)/max;
        start_point_x=+bar_width+distance_between_bars*1;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::green);
        start_point_y=this->height()-(third*500)/max;
        start_point_x=+bar_width+distance_between_bars*2;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        start_point_x=0;


    }
    else if(variables_number==4)
    {
        bar_width=120;
        distance_between_bars=70;
        painter.setBrush(Qt::red);
        start_point_y=this->height()-(first*500)/max;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::blue);
        start_point_y=this->height()-(second*500)/max;
        start_point_x=+bar_width+distance_between_bars*1;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::green);
        start_point_y=this->height()-(third*500)/max;
        start_point_x=+bar_width+distance_between_bars*2;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::yellow);
        start_point_y=this->height()-(fourth*500)/max;
        start_point_x=+bar_width+distance_between_bars*3;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        start_point_x=0;
    }
    else if(variables_number==5)
    {
        bar_width=120;
        distance_between_bars=70;
        painter.setBrush(Qt::red);
        start_point_y=this->height()-(first*500)/max;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::blue);
        start_point_y=this->height()-(second*500)/max;
        start_point_x=+bar_width+distance_between_bars*1;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::green);
        start_point_y=this->height()-(third*500)/max;
        start_point_x=+(bar_width+distance_between_bars)*2;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::yellow);
        start_point_y=this->height()-(fourth*500)/max;
        start_point_x=+(bar_width+distance_between_bars)*3;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        painter.setBrush(Qt::black);
        start_point_y=this->height()-(fifth*500)/max;
        start_point_x=+(bar_width+distance_between_bars)*4;
        painter.drawRect(start_point_x,start_point_y,bar_width,this->height());
        start_point_x=0;
    }

}
