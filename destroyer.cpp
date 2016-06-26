
#include "destroyer.h"
#include<QDesktopWidget>


destroyer::destroyer(int id,int firstx,int firsty,QGraphicsPixmapItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    QDesktopWidget desktop;
       height=desktop.geometry().height();
       width=desktop.geometry().width();
      img_id=id;
    if(img_id==1){
        x=firstx;
        y=firsty;
        x0=x;
        y0=y;
        mydestroyer=new QPixmap("://image/d9.png");
        *mydestroyer=mydestroyer->scaled(width/20,height/17);
         setPixmap(*mydestroyer);
         this->setPos(x,y);



    }
    else if(img_id==2){
        x=firstx;
        y=firsty;
        x0=x;
        y0=y;
        mydestroyer=new QPixmap("://image/d9.png");
        *mydestroyer=mydestroyer->scaled(width/20,height/17);
         setPixmap(*mydestroyer);
         this->setPos(x,y);




    }
    else if(img_id==3){

        x=firstx;
        y=firsty;
        x0=x;
        y0=y;
        mydestroyer=new QPixmap("://image/d9.png");
        *mydestroyer=mydestroyer->scaled(width/20,height/17);
         setPixmap(*mydestroyer);
         this->setPos(x,y);

    }


}
