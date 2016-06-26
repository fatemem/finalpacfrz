#include<QGraphicsScene>
#include "brick.h"
int brick::img_id=1;
int brick::img_id1=1;
brick::brick(int id,int h, int w, QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
if(id==1){
    if(img_id==5){
     img_id=1;
     }
    if(img_id==1){
    brick_img=new QPixmap("://img/b1");
    * brick_img= brick_img->scaled(w/20,h/15);
    setPixmap(*brick_img);
}
    if(img_id==2){
        brick_img=new QPixmap("://img/b2");
        * brick_img= brick_img->scaled(w/20,h/15);
        setPixmap(*brick_img);
    }
    if(img_id==3){
        brick_img=new QPixmap("://img/b6");
        * brick_img= brick_img->scaled(w/20,h/15);
        setPixmap(*brick_img);
    }
    if(img_id==4){
    brick_img=new QPixmap("://img/b7");
    * brick_img= brick_img->scaled(w/20,h/15);
    setPixmap(*brick_img);
}
    if(img_id==5){
    brick_img=new QPixmap("://img/b8");
    * brick_img= brick_img->scaled(w/20,h/15);
    setPixmap(*brick_img);
}
img_id++;
}
if(id==2){
        if(img_id1==5){
         img_id1=1;
         }
        if(img_id1==1){
        brick_img=new QPixmap("://img/b24");
        * brick_img= brick_img->scaled(w/20,h/15);
        setPixmap(*brick_img);
    }
        if(img_id1==2){
            brick_img=new QPixmap("://img/b24");
            * brick_img= brick_img->scaled(w/20,h/15);
            setPixmap(*brick_img);
        }
        if(img_id1==3){
            brick_img=new QPixmap("://img/b25");
            * brick_img= brick_img->scaled(w/20,h/15);
            setPixmap(*brick_img);
        }
        if(img_id1==4){
        brick_img=new QPixmap("://img/b24");
        * brick_img= brick_img->scaled(w/20,h/15);
        setPixmap(*brick_img);
    }
        if(img_id1==5){
        brick_img=new QPixmap("://img/b25");
        * brick_img= brick_img->scaled(w/20,h/15);
        setPixmap(*brick_img);
    }
    img_id1++;
    }


}

void brick::setpos_(int x, int y)
{
    this->setPos(x,y);
}



