#include "inhabitantdestroyer.h"
#include<QDesktopWidget>

inhabitantdestroyer::inhabitantdestroyer(int direct,int id,int x,int y, QObject *parent1, QGraphicsPixmapItem *parent2) :
    QObject(parent1),QGraphicsPixmapItem(parent2)
{
   this->id=id;
    this->x=x;
    this->y=y;
    this->direct=direct;
   if(id==1){
        mydestroyerimg=new QPixmap("://img/b5.png");
        * mydestroyerimg= mydestroyerimg->scaled(x,y);
        setPixmap(*mydestroyerimg);

  }




}

