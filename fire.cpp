#include "fire.h"


fire::fire (int direct,int x,int y, QObject *parent1, QGraphicsPixmapItem *parent2) :
    QObject(parent1),QGraphicsPixmapItem(parent2)
{



    int height=700;
    int width=1000;

     this->x=x;
     this->y=y;
     this->direct=direct;

         fire_img=new QPixmap("://img/b22.png");
         * fire_img= fire_img->scaled(width/20,height/16);
         setPixmap(*fire_img);

    inhabthread * timer;
    timer=new inhabthread();
    timer->run(15);
    connect(timer,SIGNAL(mysignal()),this,SLOT(moving()));
    timer->start();
}



void fire::moving()
{
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();
   // setPixmap(*fire_img);


    if(direct==1){
        *fire_img=fire_img->scaled(width/20,height/16);
        setPixmap(*fire_img);
        this->setPos(x+=3,y);

    }
    if(direct==2){

        *fire_img=fire_img->scaled(width/20,height/16);
        setPixmap(*fire_img);
        this->setPos(x-=3,y);
    }
    if(direct==3){

        *fire_img=fire_img->scaled(width/20,height/16);
        setPixmap(*fire_img);
        this->setPos(x,y-=3);
    }
    if(direct==4){

        *fire_img=fire_img->scaled(width/20,height/16);
        setPixmap(*fire_img);
        this->setPos(x,y+=3);
    }
    if(direct==5){

        *fire_img=fire_img->scaled(width/20,height/16);
        setPixmap(*fire_img);
        this->setPos(x-=3,y-=3);
    }
    if(direct==6){

        *fire_img=fire_img->scaled(width/20,height/16);
        setPixmap(*fire_img);
        this->setPos(x+=3,y+=3);
    }




}
