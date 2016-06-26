
#include "verticaldestroyer.h"

#include<QList>
#include<typeinfo>
#include "destroyer.h"
#include<QTimer>
#include<QDebug>
#include"brick.h"


verticaldestroyer::verticaldestroyer(int id,int firstx,int firsty,QGraphicsPixmapItem *parent):destroyer(id,firstx,firsty,parent)

{
    QTimer * timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}
void verticaldestroyer::move(){

    QList<QGraphicsItem*> colliding_item=collidingItems();

        if(flag2==1){
            mydestroyer=new QPixmap("://img/d5");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y-=5);
            flag2=flag2+1;

        }
        else if(flag2==2){
            mydestroyer=new QPixmap("://img/d6");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y-=5);
            flag2=flag2+1;

        }

        else if(flag2==3){
            mydestroyer=new QPixmap("://img/d7");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y-=5);
            flag2=flag2+1;

        }


        else if(flag2==4){
            mydestroyer=new QPixmap("://img/d8");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y-=5);
            flag2=1;

        }



        qDebug()<<colliding_item.size();

        for(int i=0;i<colliding_item.size();i++){
            if(typeid (*(colliding_item[i]))==typeid(brick)){
                if(y<y0){
                    flag3=1;
                    flag2=0;
                }
                else{
                    flag2=1;
                    flag3=0;
                }



    }
        }



       if(flag3==1){
            mydestroyer=new QPixmap("://img/d1");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y+=5);
            flag3=flag3+1;

        }
        else if(flag3==2){
            mydestroyer=new QPixmap("://img/d2");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y+=5);
            flag3=flag3+1;

        }

        else if(flag3==3){
            mydestroyer=new QPixmap("://img/d3");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y+=5);
            flag3=flag3+1;

        }


        else if(flag3==4){
            mydestroyer=new QPixmap("://img/d4");
            *mydestroyer=mydestroyer->scaled(width/21,height/15);
            setPixmap(*mydestroyer);
            this->setPos(x,y+=5);
            flag3=1;
}

}
