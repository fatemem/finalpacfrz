#include"treasure.h"
#include<QObject>
treasure::treasure(QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    vec.push_back(QPair<int,int>(205,100));
     vec.push_back(QPair<int,int>(0,200));
      vec.push_back(QPair<int,int>(300,270));
       vec.push_back(QPair<int,int>(405,355));
        vec.push_back(QPair<int,int>(525,510));
        vec.push_back(QPair<int,int>(950,130));
         vec.push_back(QPair<int,int>(985,490));
          vec.push_back(QPair<int,int>(540,715));
           vec.push_back(QPair<int,int>(890,610));
            vec.push_back(QPair<int,int>(610,0));

     flag=0;

     treasureimg=new QPixmap("://image/treasure1");

     QDesktopWidget desktop;
     int desktopHight=desktop.geometry().height();
     int desktopWidth=desktop.geometry().width();

      * treasureimg= treasureimg->scaled(desktopWidth/20,desktopHight/15);

      setPixmap(*treasureimg);
     treasure_timer=new QTimer();
     treasure_timer->start(5000);


     connect(treasure_timer,SIGNAL(timeout()),this,SLOT(hiden_img()));


}


void treasure::hiden_img()
{



    this->setPos(vec[flag].first,vec[flag].second);
    flag++;
   if(flag==10)
        flag=0;
}

float treasure::rand01()
{
    return rand() / (float)RAND_MAX;
}





float treasure::randRange(float min, float max)
{

//natonestam behesh zamun bedam va error midad
    return  min + (max - min) *rand01();  //% 60; //(*(int*)(qsrand( QDateTime::currentDateTime().toTime_t() )))// QTime now = QTime::currentTime();   min + (max - min) * (qsrand(now.msec())); ;

}


void treasure::setpos_(int x, int y)
{
    this->setPos(x,y);
}
