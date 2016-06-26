#include "horizontaldestroyer.h"
#include<QList>
#include<typeinfo>
#include<QTimer>
#include<QDebug>
#include"brick.h"



horizontaldestroyer::horizontaldestroyer(int id,int firstx,int firsty,QGraphicsPixmapItem *parent):destroyer(id,firstx,firsty,parent)

{
    QTimer * timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void horizontaldestroyer::move(){
     QList<QGraphicsItem*> colliding_item=collidingItems();
        if(flag==1){
            mydestroyer=new QPixmap("://img/d13.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x+=5,y);
            flag=flag+1;

        }
        else if(flag==2){
            mydestroyer=new QPixmap("://img/d14.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x+=5,y);
            flag=flag+1;

        }

        else if(flag==3){
            mydestroyer=new QPixmap("://img/d15.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x+=5,y);
            flag=flag+1;

        }


        else if(flag==4){
            mydestroyer=new QPixmap("://img/d16.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x+=5,y);
            flag=1;

        }




        qDebug()<<colliding_item.size();

        for(int i=0;i<colliding_item.size();i++){
            if(typeid (*(colliding_item[i]))==typeid(brick)){

                if(x>x0){
                    flag1=1;
                    flag=0;
                }
                else{
                    flag=1;
                    flag1=0;
                }



    }
        }



       if(flag1==1){
            mydestroyer=new QPixmap("://img/d9.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x-=5,y);
            flag1=flag1+1;

        }
        else if(flag1==2){
            mydestroyer=new QPixmap("://img/d10.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x-=5,y);
            flag1=flag1+1;

        }

        else if(flag1==3){
            mydestroyer=new QPixmap("://img/d11.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x-=5,y);
            flag1=flag1+1;

        }


        else if(flag1==4){
            mydestroyer=new QPixmap("://img/d12.png");
            *mydestroyer=mydestroyer->scaled(width/20,height/16);
            setPixmap(*mydestroyer);
            this->setPos(x-=5,y);
            flag1=1;

        }



    }
