#include "agepyramidwidget.h"

agepyramidwidget::agepyramidwidget(QWidget *parent) :QWidget(parent)
{
    this->first=0;
    this->second=0;
    this->third=0;
    this->fourth=0;
    this->fifth=0;
    this->sixth=0;
    this->seventh=0;
    this->eigth=0;
    this->nineth=0;
    this->tenth=0;
    this->left_side_limit=0;
    this->right_side_limit=0;
    this->bar_width=0;
    this->start_point_x=0;
    this->start_point_y=0;

}
agepyramidwidget::~agepyramidwidget()
{

}
void agepyramidwidget::set_left_values(double first,double second,double third,double fourth,double fifth)
{
    this->first=first;
    this->second=second;
    this->third=third;
    this->fourth=fourth;
    this->fifth=fifth;

}
void agepyramidwidget::set_right_values(double sixth,double seventh,double eigth,double nineth,double tenth)
{
    this->sixth=sixth;
    this->seventh=seventh;
    this->eigth=eigth;
    this->nineth=nineth;
    this->tenth=tenth;
}
double agepyramidwidget::get_max()
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
    if(max<sixth)
    {
        max=sixth;
    }
    if(max<seventh)
    {
        max=seventh;
    }
    if(max<eigth)
    {
        max=eigth;
    }
    if(max<nineth)
    {
        max=nineth;
    }
    if(max<tenth)
    {
        max=tenth;
    }

    return max;

}
void agepyramidwidget::paintEvent(QPaintEvent *)
{


    QPainter painter(this);

    distance_between_bars=80;
    bar_width =30;
    left_side_limit=520 ;
    right_side_limit=680 ;
    left_side_limit=520;
    double max=get_max();
    this->start_point_y=this->height()-distance_between_bars;
    start_point_x=(first*520)/max;
    //start_pointx_x=(this->width()/2-80)//minus the value of the first
    painter.setBrush(Qt::red);
    painter.drawRect(left_side_limit-start_point_x,this->start_point_y,start_point_x,bar_width);
    painter.setBrush(Qt::blue);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    start_point_x=(second*520)/max;
    painter.drawRect(left_side_limit-start_point_x,this->start_point_y,start_point_x,bar_width);
    painter.setBrush(Qt::red);
    distance_between_bars+=60;
    start_point_x=(third*520)/max;
    this->start_point_y=this->height()-distance_between_bars;
    painter.drawRect(left_side_limit-start_point_x,this->start_point_y,start_point_x,bar_width);
    painter.setBrush(Qt::blue);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    start_point_x=(fourth*520)/max;
    painter.drawRect(left_side_limit-start_point_x,this->start_point_y,start_point_x,bar_width);
    painter.setBrush(Qt::red);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    start_point_x=(fifth*520)/max;
    painter.drawRect(left_side_limit-start_point_x,this->start_point_y,start_point_x,bar_width);
    /*-----------painting the right side ------------------*/
    distance_between_bars=80;
    right_side_limit=680;

    this->start_point_y=this->height()-distance_between_bars;
    painter.setBrush(Qt::blue);
    start_point_x=(sixth*520)/max;
    painter.drawRect(  right_side_limit,this->start_point_y,start_point_x,bar_width);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    painter.setBrush(Qt::red);
    start_point_x=(seventh*520)/max;
    painter.drawRect(    right_side_limit,this->start_point_y,start_point_x,bar_width);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    painter.setBrush(Qt::blue);
    start_point_x=(eigth*520)/max;
    painter.drawRect(    right_side_limit,this->start_point_y,start_point_x,bar_width);
    painter.setBrush(Qt::red);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    start_point_x=(nineth*520)/max;
    painter.drawRect(    right_side_limit,this->start_point_y,start_point_x,bar_width);
    painter.setBrush(Qt::blue);
    distance_between_bars+=60;
    this->start_point_y=this->height()-distance_between_bars;
    start_point_x=(tenth*520)/max;
    painter.drawRect(    right_side_limit,this->start_point_y,start_point_x,bar_width);

}
