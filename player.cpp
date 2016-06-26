#include"player.h"
#include"QDesktopWidget"
#include<QDebug>
#include<QList>
#include<typeinfo>
#include"key.h"
#include<QGraphicsScene>
#include"brick.h"
#include"horizontaldestroyer.h"
#include"verticaldestroyer.h"
#include"game.h"
#include"fire.h"
extern game* mygame;
player::player(int id,int mykey,int x,int y)
{
    imgid=id;
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();
    xplayer=x;
    yplayer=y;
    _x=x;
    _y=y;
    keynumber=mykey;
    if(imgid==1){

   playerimg=new QPixmap("://img/down1");
    }
    if(imgid==2){
         playerimg=new QPixmap("://img/down21");
    }
    *playerimg=playerimg->scaled(width/20,height/16);
    setPixmap(*playerimg);
    this->setPos(x,y);
    flagup=1;
    flagdown=1;
    flagright=1;
    flagleft=1;

}

void player::keyPressEvent(QKeyEvent* event)
{
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();
    switch (imgid){
    case 1:


        if(event->key()==Qt::Key_Up){
       keyaccident();
       destroyeraccident();
            if(flagup==1){
                playerimg=new QPixmap("://img/up1.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    yplayer=_y;
                    xplayer=_x;
                    this->setPos(xplayer,yplayer);
                    qDebug()<<"x"<<_x<<"y"<<_y;

                }

                flagup++;

            }

            if(flagup==2){
                playerimg=new QPixmap("://img/up2.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                 this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                    qDebug()<<"x"<<_x<<"y"<<_y;

                    //yplayer=yplayer+3;
                }

                flagup++;
            }
            if(flagup==3){
                playerimg=new QPixmap("://img/up3.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                 this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    yplayer=_y;
                    xplayer=_x;
                    this->setPos(xplayer,yplayer);
                    qDebug()<<"x"<<_x<<"y"<<_y;


                }

                flagup=1;
            }
            keyaccident();
            destroyeraccident();

        }
        if(event->key()==Qt::Key_Down){
       keyaccident();
       destroyeraccident();
            if(flagdown==1){
                playerimg=new QPixmap("://img/down1.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    yplayer=_y;
                    xplayer=_x;
                    this->setPos(xplayer,yplayer);
                    qDebug()<<"x"<<_x<<"y"<<_y;


                }
                flagdown++;

            }

            if(flagdown==2){
                playerimg=new QPixmap("://img/down2.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    yplayer=_y;
                    xplayer=_x;
                    this->setPos(xplayer,yplayer);
                    qDebug()<<"x"<<_x<<"y"<<_y;


                }
                flagdown++;
            }
            if(flagdown==3){
                playerimg=new QPixmap("://img/down3.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    yplayer=_y;
                    xplayer=_x;
                    this->setPos(xplayer,yplayer);
                    qDebug()<<"x"<<_x<<"y"<<_y;


                }
                flagdown=1;
            }
            keyaccident();
            destroyeraccident();

       }
        if(event->key()==Qt::Key_Right){
       keyaccident();
       destroyeraccident();
            if(flagright==1){
               playerimg=new QPixmap("://img/left1.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);

                }
                flagright++;

            }

            if(flagright==2){
                playerimg=new QPixmap("://img/left2.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }

                flagright++;
            }
            if(flagright==3){

               playerimg=new QPixmap("://img/left3.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    xplayer=xplayer-3;  xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }

                flagright=1;
            }
            keyaccident();
            destroyeraccident();

       }

        if(event->key()==Qt::Key_Left){
       keyaccident();
       destroyeraccident();
            if(flagleft==1){
                playerimg=new QPixmap("://img/right1.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagleft++;

            }

            if(flagleft==2){

                playerimg=new QPixmap("://img/right2.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagleft++;
            }
            if(flagleft==3){
                playerimg=new QPixmap("://img/right3.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer-3;
                this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }

                flagleft=1;
            }
            keyaccident();
            destroyeraccident();


       }


        break;

    //******************************************************************
    case 2:

        if(event->key()==Qt::Key_Up){
       keyaccident();
       destroyeraccident();
            if(flagup==1){
                playerimg=new QPixmap("://img/up21.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagup++;

            }

            if(flagup==2){
                playerimg=new QPixmap("://img/up22.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagup++;
            }
            if(flagup==3){
                playerimg=new QPixmap("://img/up23.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagup++;
            }
            if(flagup==4){
                playerimg=new QPixmap("://img/up24.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagup=1;
            }
            keyaccident();
            destroyeraccident();

        }
        if(event->key()==Qt::Key_Down){
       keyaccident();
       destroyeraccident();
            if(flagdown==1){
                playerimg=new QPixmap("://img/down21.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagdown++;

            }

            if(flagdown==2){
                playerimg=new QPixmap("://img/down22.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagdown++;
            }
            if(flagdown==3){
                playerimg=new QPixmap("://img/down23.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagdown++;
            }
            if(flagdown==4){
                playerimg=new QPixmap("://img/down24.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                yplayer=yplayer+3;
                this->setPos(xplayer,yplayer);
                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }

                flagdown=1;
            }
            keyaccident();
            destroyeraccident();

       }
        if(event->key()==Qt::Key_Right){
       keyaccident();
       destroyeraccident();
            if(flagright==1){
               playerimg=new QPixmap("://img/right21.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagright++;

            }

            if(flagright==2){
                playerimg=new QPixmap("://img/right22.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagright++;
            }
            if(flagright==3){

               playerimg=new QPixmap("://img/right23.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagright++;
            }
            if(flagright==4){

               playerimg=new QPixmap("://img/right24.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer+3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagright=1;
            }
            keyaccident();
            destroyeraccident();

       }

        if(event->key()==Qt::Key_Left){
       keyaccident();
       destroyeraccident();
            if(flagleft==1){
                playerimg=new QPixmap("://img/left21.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagleft++;

            }

            if(flagleft==2){

                playerimg=new QPixmap("://img/left22.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
               xplayer=xplayer-3;
               this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagleft++;
            }
            if(flagleft==3){
                playerimg=new QPixmap("://img/left23.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagleft++;
            }
            if(flagleft==4){
                playerimg=new QPixmap("://img/left24.png");
                *playerimg=playerimg->scaled(width/20,height/16);
                setPixmap(*playerimg);
                xplayer=xplayer-3;
                this->setPos(xplayer,yplayer);

                if(brickaccident()==true){
                    xplayer=_x;
                    yplayer=_y;
                    this->setPos(xplayer,yplayer);
                }
                flagleft=1;
            }
            keyaccident();
            destroyeraccident();


       }


        break;
//********************************************************************************
     default:


        break;
    }
}

void player::destroyeraccident(){
    QList<QGraphicsItem*> colliding_item=collidingItems();

        for(int i=0;i<colliding_item.size();i++){

            if(typeid (*(colliding_item[i]))==typeid(verticaldestroyer)||typeid (*(colliding_item[i]))==typeid(horizontaldestroyer)||typeid (*(colliding_item[i]))==typeid(fire)){
                if(imgid==1){
                 mygame->myhealth1->decrease();
                 playerhealth.getHealth()--;
                }
                if(imgid==2){
                 mygame->myhealth2->decrease();
                 playerhealth.getHealth()--;
                }
                if(imgid==3){
                 mygame->myhealth3->decrease();
                 playerhealth.getHealth()--;
                }
                qDebug()<<"playerhealth:"<<playerhealth.getHealth();
            }
        }
}
bool player::brickaccident(){
    QList<QGraphicsItem*> colliding_item=collidingItems();
       for(int i=0;i<colliding_item.size();i++){

           if(typeid (*(colliding_item[i]))==typeid(brick)){
                return true;
          }

   }
 return false;
}
void player::keyaccident(){
    QList<QGraphicsItem*> colliding_item=collidingItems();

        for(int i=0;i<colliding_item.size();i++){

            if(typeid (*(colliding_item[i]))==typeid(key)){
                if(imgid==1){
                 mygame->myscore1->increase();
                 playerscore.getscore()++;
                }
                if(imgid==2){
                 mygame->myscore2->increase();
                 playerscore.getscore()++;
                }
                if(imgid==3){
                 mygame->myscore3->increase();
                 playerscore.getscore()++;
                }
                scene()->removeItem(colliding_item[i]);
                delete colliding_item[i];
                return;
            }
        }
}
