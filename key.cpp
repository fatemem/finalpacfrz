
#include "key.h"
#include<QSize>
#include<QRect>
#include<QDebug>
#include<QDesktopWidget>
#include<QGraphicsScene>
#include"inhabthread.h"

key::key(int id,QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
QDesktopWidget desktop;
int desktopHight=desktop.geometry().height();
int desktopWidth=desktop.geometry().width();
if(id==1){
    keyimg=new QPixmap("://img/mykey.png");
    * keyimg= keyimg->scaled(desktopWidth/35,desktopHight/25);
    setPixmap(*keyimg);
}
if(id==2){
    keyimg=new QPixmap("://img/K3tB9-1.png");
    * keyimg= keyimg->scaled(desktopWidth/30,desktopHight/20);
    setPixmap(*keyimg);
    flag=1;
    timer=new inhabthread();
    timer->run(100);
    connect(timer,SIGNAL(mysignal()),this,SLOT(moveimg()));
    timer->start();
}
}
void key::setpos_(int x, int y)
{
    this->setPos(x,y);
}
void key::moveimg(){
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();

    if(flag==1){
        keyimg=new QPixmap("://img/K3tB9-1.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    else if(flag==2){
        keyimg=new QPixmap("://img/K3tB9-2.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }

    else if(flag==3){
        keyimg=new QPixmap("://img/K3tB9-3.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }


    else if(flag==4){
        keyimg=new QPixmap("://img/K3tB9-4.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    if(flag==5){
        keyimg=new QPixmap("://img/K3tB9-5.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    else if(flag==6){
        keyimg=new QPixmap("://img/K3tB9-6.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }

    else if(flag==7){
        keyimg=new QPixmap("://img/K3tB9-7.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }


    else if(flag==8){
        keyimg=new QPixmap("://img/K3tB9-8.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    else if(flag==9){
        keyimg=new QPixmap("://img/K3tB9-9.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    else if(flag==10){
        keyimg=new QPixmap("://img/K3tB9-10.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    else if(flag==11){
        keyimg=new QPixmap("://img/K3tB9-11.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=flag+1;

    }
    else if(flag==12){
        keyimg=new QPixmap("://img/K3tB9-12.png");
        *keyimg=keyimg->scaled(width/30,height/20);
        setPixmap(*keyimg);
        flag=1;

    }




}

