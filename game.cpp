#include "game.h"
#include"brick.h"
#include"key.h"
#include"verticaldestroyer.h"
#include"horizontaldestroyer.h"
#include"player.h"
#include<QDesktopWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QTime>
#include<QDebug>
#include<QThread>
#include"destroyerthread.h"
#include<QtCore/QCoreApplication>
#include <QApplication>
#include"button.h"
#include"player.h"
#include"inhabthread.h"
#include<stdlib.h>
QGraphicsView* game::view=0;
game::game(QWidget *parent)
{

    QDesktopWidget desktop;
    desktopHight=desktop.geometry().height();
    desktopWidth=desktop.geometry().width();
    player1=new player(1,61,desktopWidth-(desktopWidth/10),desktopHight/11);
    view=new QGraphicsView;
    scene=new QGraphicsScene;
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(desktopWidth,desktopHight);
    scene->setSceneRect(0,0,desktopWidth,desktopHight);
    QTimer * timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(checkend()));
    timer->start(50);
    level=0;


    timerfire=new QTimer();
       connect(timerfire,SIGNAL(timeout()),this,SLOT(setdestroyer()));

       middlepagetimer=new QTimer();
       connect(middlepagetimer,SIGNAL(timeout()),this,SLOT(showmiddlepage()));

       music=new QMediaPlayer();
       music->setMedia(QUrl("qrc:/sound/level1.mp3"));
       music2=new QMediaPlayer();
       music2->setMedia(QUrl("qrc:/sound/level2.mp3"));

       id3=1;


       socket=new QTcpSocket(this);
           connect(socket,SIGNAL(connected()),this,SLOT(readmessage()));
             connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
             connect(socket,SIGNAL(readyRead()),this,SLOT(readmessage()));
             connect(socket,SIGNAL(bytewriten()),this,SLOT(bytewriten()));

             qDebug()<<"connecting...";
                socket->connectToHost("0.0.0.0",12345);
                if(!socket->waitForConnected(100)){
                    qDebug()<<"error"<<socket->errorString();
                }



}
void game::level0(){
    level=0;
    QImage background(":/img/background0.jpg");
    scene->setBackgroundBrush(background.scaled(desktopWidth,desktopHight));

    Button* play;
    play = new Button(QString(":/img/play-icon.png"));
    play->setPos((desktopWidth/2)-desktopWidth/10,(desktopHight/2)-desktopHight/10);
    scene->addItem(play);
    connect(play,SIGNAL(clicked()),this,SLOT(level1()));
     view->setScene(scene);

}
void game::level1(){
    scene->clear();
    level=1;
    QImage background(":/img/background.jpg");
    scene->setBackgroundBrush(background.scaled(desktopWidth,desktopHight));
    view->setScene(scene);
    //music play
    music2->stop();
    music->play();
//addbrick
    brick* rowbrick[20];
          int x=0;
          for(int i=0;i<20;i++){
              rowbrick[i]=new brick(1,desktopHight,desktopWidth);
              rowbrick[i]->setPos(x,0);
              x=x+(desktopWidth/20);
              scene->addItem(rowbrick[i]);
          }
          brick* colbrick[15];
          int y=0;
          for(int i=0;i<15;i++){
              colbrick[i]=new brick(1,desktopHight,desktopWidth);
              colbrick[i]->setPos(0,y);
              y=y+(desktopHight/15);
              scene->addItem(colbrick[i]);
          }
          brick* rowbrick1[20];
          x=0;
          for(int i=0;i<20;i++){
              rowbrick1[i]=new brick(1,desktopHight,desktopWidth);
              rowbrick1[i]->setPos(x,(desktopHight)-(desktopHight/15));
              x=x+(desktopWidth/20);
              scene->addItem(rowbrick1[i]);
          }
          brick* colbrick1[15];
          y=0;
          for(int i=0;i<15;i++){
              colbrick1[i]=new brick(1,desktopHight,desktopWidth);
              colbrick1[i]->setPos((desktopWidth)-(desktopWidth/20),y);
              y=y+(desktopHight/15);
              scene->addItem(colbrick1[i]);
          }

         //****************************************
          brick* colbrick2[15];
          y=0;
          for(int i=0;i<15;i++){
              colbrick2[i]=new brick(1,desktopHight,desktopWidth);
              colbrick2[i]->setPos((desktopWidth)/2,y);
              y=y+(desktopHight/15);
              scene->addItem(colbrick2[i]);
          }
          scene->removeItem(colbrick2[7]);
          scene->removeItem(colbrick2[6]);
          //**************************************
          brick* colbrick3[7];
          y=0;
          int y0=4*(desktopHight/15);
          for(int i=0;i<7;i++){
              colbrick3[i]=new brick(1,desktopHight,desktopWidth);
              colbrick3[i]->setPos((desktopWidth)/4,y+y0);
              y=y+(desktopHight/15);
              scene->addItem(colbrick3[i]);
          }
          scene->removeItem(colbrick3[4]);
          scene->removeItem(colbrick3[3]);

          //***************************************
          brick* rowbrick2[5];
              x=0;
              int x0=((desktopWidth)/4)-(2*(desktopWidth)/20);
              for(int i=0;i<5;i++){
                  rowbrick2[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick2[i]->setPos(x+x0,3*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick2[i]);
              }
          //*****************************************
              brick* rowbrick3[5];
                          x=0;
                          for(int i=0;i<5;i++){
                              rowbrick3[i]=new brick(1,desktopHight,desktopWidth);
                              rowbrick3[i]->setPos(x+x0,11*(desktopHight/15));
                              x=x+(desktopWidth/20);
                              scene->addItem(rowbrick3[i]);
                          }

           //*****************************************
              brick* rowbrick4[5];
              x=0;

              for(int i=0;i<5;i++){
                  rowbrick4[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick4[i]->setPos(x+x0,2*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick4[i]);
              }
            //******************************************
              brick* rowbrick5[5];
              x=0;

              for(int i=0;i<5;i++){
                  rowbrick5[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick5[i]->setPos(x+x0,12*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick5[i]);
              }

              //*****************************************
              brick* colbrick4[7];
              y=0;
              for(int i=0;i<7;i++){
                  colbrick4[i]=new brick(1,desktopHight,desktopWidth);
                  colbrick4[i]->setPos(((desktopWidth)/2)+3*(desktopWidth/20),y+y0);
                  y=y+(desktopHight/15);
                  scene->addItem(colbrick4[i]);
              }
              //******************************************
              brick* colbrick5[7];
              y=0;
              for(int i=0;i<7;i++){
                  colbrick5[i]=new brick(1,desktopHight,desktopWidth);
                  colbrick5[i]->setPos(((desktopWidth)/2)+6*(desktopWidth/20),y+y0);
                  y=y+(desktopHight/15);
                  scene->addItem(colbrick5[i]);
              }
              //*****************************************
              brick* rowbrick6[6];
              x=0;
              int x1=(desktopWidth/2)+2*(desktopWidth/20);
              for(int i=0;i<6;i++){
                  rowbrick6[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick6[i]->setPos(x+x1,11*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick6[i]);
              }
              //*******************************************
              brick* rowbrick7[6];
              x=0;
              for(int i=0;i<6;i++){
                  rowbrick7[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick7[i]->setPos(x+x1,12*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick7[i]);
              }
              //*********************************************
              brick* rowbrick8[6];
              x=0;
              for(int i=0;i<6;i++){
                  rowbrick8[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick8[i]->setPos(x+x1,2*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick8[i]);
              }

              scene->removeItem(rowbrick8[3]);
               scene->removeItem(rowbrick8[2]);
              //***********************************************
              brick* rowbrick9[6];
              x=0;
              for(int i=0;i<6;i++){
                  rowbrick9[i]=new brick(1,desktopHight,desktopWidth);
                  rowbrick9[i]->setPos(x+x1,3*(desktopHight/15));
                  x=x+(desktopWidth/20);
                  scene->addItem(rowbrick9[i]);
              }

              scene->removeItem(rowbrick9[3]);
               scene->removeItem(rowbrick9[2]);
              //**************************************************

//add destroyer
               QThread dthread;
               destroyerthread mythread1;
               mythread1.dowork(dthread);
               mythread1.moveToThread(&dthread);
               dthread.start(QThread::HighestPriority);
               horizontaldestroyer * destroyer1=new horizontaldestroyer(1,2*(desktopWidth/20),desktopHight-(2*(desktopHight/15)));
                     scene->addItem(destroyer1);
                     verticaldestroyer * destroyer2=new verticaldestroyer(1,(desktopWidth/2)+(desktopWidth/20),(1*(desktopHight/15)));
                      scene->addItem(destroyer2);
                      verticaldestroyer * destroyer3=new verticaldestroyer(1,(desktopWidth/20),(1*(desktopHight/15)));
                       scene->addItem(destroyer3);
                       horizontaldestroyer * destroyer4=new horizontaldestroyer(1,(desktopWidth/20),(1*(desktopHight/15)));
                        scene->addItem(destroyer4);
//add player

  player1=new player(1,61,(desktopWidth/2)-(desktopWidth/10),desktopHight-4*(desktopHight/11));
  (player1->playerscore).getscore()=0;

  player1->setFlag(QGraphicsItem::ItemIsFocusable);
  player1->setFocus();
  scene->addItem(player1);
//add key
  key *KEY[70];
      int yb=0;
      int yb0=(desktopHight/12);
      for(int i=13;i<20;i++){
          KEY[i]=new key(1);
          KEY[i]->setpos_(2*(desktopWidth/20),yb0+yb);
          yb+=2*(desktopHight/15);
         scene->addItem(KEY[i]);
      }
       yb=0;
       yb0=4*(desktopHight/14);
      for(int i=20;i<24;i++){
          KEY[i]=new key(1);
          KEY[i]->setpos_(3*(desktopWidth/20),yb0+yb);
          yb+=2*(desktopHight/15);
         scene->addItem(KEY[i]);
      }
      yb=0;
      yb0=4*(desktopHight/14);
      for(int i=24;i<28;i++){
          KEY[i]=new key(1);
          KEY[i]->setpos_(4*(desktopWidth/20),yb0+yb);
          yb+=2*(desktopHight/15);
         scene->addItem(KEY[i]);
      }
      yb=0;
      yb0=4*(desktopHight/14);
      for(int i=28;i<32;i++){
          KEY[i]=new key(1);
          KEY[i]->setpos_(6*(desktopWidth/20),yb0+yb);
          yb+=2*(desktopHight/15);
         scene->addItem(KEY[i]);
      }
      yb=0;
      yb0=4*(desktopHight/14);
      for(int i=32;i<36;i++){
          KEY[i]=new key(1);
          KEY[i]->setpos_(7*(desktopWidth/20),yb0+yb);
          yb+=2*(desktopHight/15);
         scene->addItem(KEY[i]);
      }
      yb=0;
      yb0=(desktopHight/12);
     for(int i=0;i<7;i++){//7 to 13
         KEY[i]=new key(1);
         KEY[i]->setpos_(8*(desktopWidth/20),yb0+yb);
         yb+=2*(desktopHight/15);
        scene->addItem(KEY[i]);
     }

     yb=0;
     yb0=4*(desktopHight/14);
     for(int i=43;i<47;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_((desktopWidth/2)+2*(desktopWidth/20),yb0+yb);
         yb+=2*(desktopHight/15);
        scene->addItem(KEY[i]);
     }
     yb=0;
     yb0=4*(desktopHight/14);
     for(int i=47;i<51;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_((desktopWidth/2)+4*(desktopWidth/20),yb0+yb);
         yb+=2*(desktopHight/15);
        scene->addItem(KEY[i]);
     }
     yb=0;
     yb0=4*(desktopHight/14);
     for(int i=51;i<55;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_((desktopWidth/2)+5*(desktopWidth/20),yb0+yb);
         yb+=2*(desktopHight/15);
        scene->addItem(KEY[i]);
     }
     yb=0;
     yb0=4*(desktopHight/14);
     for(int i=55;i<59;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_((desktopWidth/2)+7*(desktopWidth/20),yb0+yb);
         yb+=2*(desktopHight/15);
        scene->addItem(KEY[i]);
     }
     yb=0;
     yb0=(desktopHight/12);
     for(int i=59;i<66;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_((desktopWidth)-2*(desktopWidth/20),yb0+yb);
         yb+=2*(desktopHight/15);
        scene->addItem(KEY[i]);
     }
     int xb=0;
     int xb0=4*(desktopWidth/20);
     for(int i=7;i<9;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_(xb+xb0,(desktopHight/12));
         xb+=2*(desktopWidth/20);
        scene->addItem(KEY[i]);
     }
     xb=0;
     xb0=(desktopWidth/2)+3*(desktopWidth/20);
     for(int i=11;i<13;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_(xb+xb0,desktopHight-(desktopHight/8));
         x+=2*(desktopWidth/20);
        scene->addItem(KEY[i]);
     }
     xb=0;
     xb0=(desktopWidth/2)+2*(desktopWidth/20);
     for(int i=66;i<70;i++){
         KEY[i]=new key(1);
         KEY[i]->setpos_(xb+xb0,(desktopHight/12));
         xb+=2*(desktopWidth/20);
        scene->addItem(KEY[i]);
     }
//add score
     myscore1=new score();
     myscore1->setPos(desktopWidth/20,desktopHight/17);
     myscore1->getscore()=0;
     scene->addItem(myscore1);
     myhealth1=new Health();
     myhealth1->setPos(desktopWidth/20,desktopHight/11);
     scene->addItem(myhealth1);

}
void game::checkend(){
    //*****go next level***********
     if((player1->playerhealth).getHealth()<=0){
         qDebug()<<"health is 0";
         (player1->playerhealth).getHealth()=1;
         if(level==1){myscore1->getscore()=0;}
         if(level==2){myscore2->getscore()=0;}
          betweenlevel();
     }
    else if((player1->playerscore).getscore()==player1->keynumber){
         qDebug()<<(player1->playerscore).getscore()<<"full score";
         (player1->playerscore).getscore()=0;
         if(level==2){
          myscore2->getscore()=0;
         }
         level++;
         switch(level){
         case 1:
             level1();
             break;
         case 2:
             level2();
             break;
         case 3:
             level3();
             break;
          default:
             break;
         }
     }

}
void game::level2(){
    id3=1;
    level=2;
    scene->clear();
    QImage background2(":/img/background21");
    scene->setBackgroundBrush(background2.scaled(desktopWidth,desktopHight));
    view->setScene(scene);
music->stop();
music2->play();
//add brick

    int number_h=desktopHight/15;
                           int number_w=desktopWidth/20.6;
                           brick * brick_y[40];

                           int y =0;
                           for(int i=0;i<(desktopHight/number_h)+1;i++){
                           brick_y[i]=new brick(2,desktopHight,desktopWidth);
                           brick_y[i]->setpos_(0,y );
                           y+=desktopHight/15;
                           scene->addItem(brick_y[i]);
                           }
                           brick * brick_x[40];
                           int x=0;
                           for(int i=0;i<(desktopWidth/number_w)+1;i++){
                           brick_x[i]=new brick(2,desktopHight,desktopWidth);
                           brick_x[i]->setpos_(x,0 );
                           x+=desktopWidth/20.6;
                           scene->addItem(brick_x[i]);
                           }
                        //////right
                          int y1_rihgt=desktopHight/15;
                           brick *brick_y2[40];
                           for(int i=0;i<(desktopHight/number_h)+1;i++){
                           brick_y2[i]=new brick(2,desktopHight,desktopWidth);
                           brick_y2[i]->setpos_(desktopWidth-desktopWidth/20.6,y1_rihgt );
                           y1_rihgt+=desktopHight/15;
                           scene->addItem(brick_y2[i]);
                           }
                           /////down
                           brick * brick_x2[40];
                           int x1_down= desktopWidth/20.6;
                           for(int i=0;i<desktopWidth/number_w;i++){
                           brick_x2[i]=new brick(2,desktopHight,desktopWidth);
                           brick_x2[i]->setpos_(x1_down,desktopHight-desktopHight/15);
                           x1_down+=desktopWidth/20.6;
                           scene->addItem(brick_x2[i]);
                           }
                           int number_y_leftbrick=desktopHight/(4*(desktopHight/15));
                           /////left up
                           brick * brick_y_left1[40];
                           int y2_left =desktopHight/15;
                           for(int i=0;i<number_y_leftbrick;i++){
                           brick_y_left1[i]=new brick(2,desktopHight,desktopWidth);
                           brick_y_left1[i]->setpos_(desktopWidth/20.6,y2_left);
                           y2_left+=desktopHight/15;
                           scene->addItem(brick_y_left1[i]);
                           }

                               brick * brick_y_left2[40];
                               int y3_left =desktopHight/15;
                               for(int i=0;i<number_y_leftbrick;i++){
                               brick_y_left2[i]=new brick(2,desktopHight,desktopWidth);
                               brick_y_left2[i]->setpos_( (desktopWidth/20.7)*2,y3_left);
                               y3_left+=desktopHight/15;
                               scene->addItem(brick_y_left2[i]);

                           }

                                   brick * brick_y_left3[40];
                                   int y4_left =desktopHight/15;
                                   for(int i=0;i<number_y_leftbrick;i++){
                                   brick_y_left3[i]=new brick(2,desktopHight,desktopWidth);
                                   brick_y_left3[i]->setpos_( (desktopWidth/20.7)*3,y4_left);
                                   y4_left+=desktopHight/15;
                                   scene->addItem(brick_y_left3[i]);

                           }


                        ////////left down

                               brick * brick_y_leftdown1[40];
                               int y2_left_down =desktopHight-(((desktopHight/15)*2)-5);
                               for(int i=0;i<number_y_leftbrick;i++){
                               brick_y_leftdown1[i]=new brick(2,desktopHight,desktopWidth);
                               brick_y_leftdown1[i]->setpos_( desktopWidth/20.6,y2_left_down);
                               y2_left_down-=desktopHight/15;

        scene->addItem(brick_y_leftdown1[i]);
                               }
                                   brick * brick_y_leftdown2[40];
                                   int y3_left_down =desktopHight-(((desktopHight/15)*2)-5);
                                   for(int i=0;i<number_y_leftbrick;i++){
                                   brick_y_leftdown2[i]=new brick(2,desktopHight,desktopWidth);
                                   brick_y_leftdown2[i]->setpos_( (desktopWidth/20.7)*2,y3_left_down);
                                   y3_left_down-=desktopHight/15;
                                   scene->addItem(brick_y_leftdown2[i]);

                               }

                                       brick * brick_y_leftdown3[40];
                                       int y4_left_down =desktopHight-(((desktopHight/15)*2)-5);
                                       for(int i=0;i<number_y_leftbrick;i++){
                                       brick_y_leftdown3[i]=new brick(2,desktopHight,desktopWidth);
                                       brick_y_leftdown3[i]->setpos_( (desktopWidth/20.7)*3,y4_left_down);
                                       y4_left_down-=desktopHight/15;
                                       scene->addItem(brick_y_leftdown3[i]);

                               }
                        ///////right down

                               brick * brick_y_rightdown1[40];
                               int y2_rightdown =desktopHight-(((desktopHight/15)*2)-5);
                               for(int i=0;i<number_y_leftbrick;i++){
                               brick_y_rightdown1[i]=new brick(2,desktopHight,desktopWidth);
                               brick_y_rightdown1[i]->setpos_(desktopWidth- ((desktopWidth/20.7)*2),y2_rightdown);
                               y2_rightdown-=desktopHight/15;
                               scene->addItem(brick_y_rightdown1[i]);
                               }

                                   brick * brick_y_rightdown2[40];
                                   int y3_rightdown =desktopHight-(((desktopHight/15)*2)-5);
                                   for(int i=0;i<number_y_leftbrick;i++){
                                   brick_y_rightdown2[i]=new brick(2,desktopHight,desktopWidth);
                                   brick_y_rightdown2[i]->setpos_(desktopWidth- ((desktopWidth/20.7)*3),y3_rightdown);
                                   y3_rightdown-=desktopHight/15;
                                   scene->addItem(brick_y_rightdown2[i]);

                               }

                                       brick * brick_y_rightdown3[40];
                                       int y4_rightdown =desktopHight-(((desktopHight/15)*2)-5);
                                       for(int i=0;i<number_y_leftbrick;i++){
                                       brick_y_rightdown3[i]=new brick(2,desktopHight,desktopWidth);
                                       brick_y_rightdown3[i]->setpos_(desktopWidth- ((desktopWidth/20.7)*4),y4_rightdown);
                                       y4_rightdown-=desktopHight/15;
                                       scene->addItem(brick_y_rightdown3[i]);

                               }

                        //////right up

                                   brick * brick_y_right1[40];
                                   int y2_right =desktopHight/15;
                                   for(int i=0;i<number_y_leftbrick;i++){
                                   brick_y_right1[i]=new brick(2,desktopHight,desktopWidth);
                                   brick_y_right1[i]->setpos_(desktopWidth- ((desktopWidth/20.7)*2),y2_right);
                                   y2_right+=desktopHight/15;
                                   scene->addItem(brick_y_right1[i]);
                                   }

                                       brick * brick_y_right2[40];
                                       int y3_right =desktopHight/15;
                                       for(int i=0;i<number_y_leftbrick;i++){
                                       brick_y_right2[i]=new brick(2,desktopHight,desktopWidth);
                                       brick_y_right2[i]->setpos_(desktopWidth-( (desktopWidth/20.7)*3),y3_right);
                                       y3_right+=desktopHight/15;
                                       scene->addItem(brick_y_right2[i]);

                                   }

                                           brick * brick_y_right3[40];
                                           int y4_right =desktopHight/15;
                                           for(int i=0;i<number_y_leftbrick;i++){
                                           brick_y_right3[i]=new brick(2,desktopHight,desktopWidth);
                                           brick_y_right3[i]->setpos_(desktopWidth- ((desktopWidth/20.7)*4),y4_right);
                                           y4_right+=desktopHight/15;
                                           scene->addItem(brick_y_right3[i]);

                                   }
                        /////betveen up
                                   int y_b_up =desktopHight/15;
                                   int x_brickb=(desktopWidth/2)-(4*(desktopWidth/20.6));
                                   brick * y_brick_b[7];
                                   for(int i=0;i<7;i++){
                                   y_brick_b[i]=new brick(2,desktopHight,desktopWidth);
                                   y_brick_b[i]->setpos_(x_brickb,y_b_up);
                                   x_brickb+=(desktopWidth/20.6);
                                   scene->addItem(y_brick_b[i]);
                                   }

                                   ///1/3 up

                                   int y4_brick =(desktopHight/15)*3.5;
                                   int x4_brickb=(desktopWidth/3)-(desktopWidth/20.6);
                                   brick * up_brick_b[33];
                                   for(int i=0;i<18;i++){
                                   up_brick_b[i]=new brick(2,desktopHight,desktopWidth);

                                   up_brick_b[i]->setpos_(x4_brickb,y4_brick);
                                    scene->addItem(up_brick_b[i]);
                                     x4_brickb+=(desktopWidth/20.6);
                                   if(i==2){
                                       x4_brickb+=2*(desktopWidth/20.6);
                                   }
                                   if(i==5){
                                     x4_brickb= (desktopWidth/3)-(desktopWidth/20.6);
                                      y4_brick+=desktopHight/15;
                                   }
                                   if(i==8){
                                       x4_brickb+=2*(desktopWidth/20.6);
                                   }

                                   if(i==11){
                                       x4_brickb= (desktopWidth/3)-(desktopWidth/20.6);
                                        y4_brick+=desktopHight/15;

                                   }
                                   if(i==14){
                                        x4_brickb+=2*(desktopWidth/20.6);
                                   }
                                   }
                          //////betveen down
                                   int y_b_down =desktopHight/15;
                                   int x2_brickb=(desktopWidth/2)-(4*(desktopWidth/20.6));
                                   brick * y2_brick_b[40];
                                   for(int i=0;i<7;i++){
                                   y2_brick_b[i]=new brick(2,desktopHight,desktopWidth);
                                   y2_brick_b[i]->setpos_(x2_brickb,desktopHight-y_b_down*2);
                                   x2_brickb+=(desktopWidth/20.6);
                                   scene->addItem(y2_brick_b[i]);

                                   }
                                   //////1/3 down
                               int x3_brickb=(desktopWidth/3)-(desktopWidth/20.6);
                               int y3_brickb=desktopHight-y_b_down*5;
                               for(int i=7;i<25;i++){
                               y2_brick_b[i]=new brick(2,desktopHight,desktopWidth);
                               y2_brick_b[i]->setpos_(x3_brickb,y3_brickb);
                               x3_brickb+=(desktopWidth/20.6);
                               scene->addItem(y2_brick_b[i]);
                               if(i==9){
                                 x3_brickb+=2*(desktopWidth/20.6);
                               }
                               if(i==12){
                                  x3_brickb=(desktopWidth/3)-(desktopWidth/20.6) ;
                                  y3_brickb=y3_brickb-y_b_down;
                               }
                               if(i==15){
                                  x3_brickb+=2*(desktopWidth/20.6);
                               }
                               if(i==18){
                                   x3_brickb=(desktopWidth/3)-(desktopWidth/20.6) ;
                                   y3_brickb=y3_brickb-(y_b_down);
                               }
                               if(i==21){
                                   x3_brickb+=2*(desktopWidth/20.6);
                               }
                               }

//add key


                      int w=desktopWidth/20.6;
                      int h=desktopHight/15;
                       key *KEY[30];
                       KEY[1]=new key(2);
                       KEY[1]->setpos_(w+4,desktopHight/1.75);
                       scene->addItem(KEY[1]);
                       KEY[2]=new key(2);
                       KEY[2]->setpos_(w+4,desktopHight/3);
                       scene->addItem(KEY[2]);

                       KEY[3]=new key(2);
                       KEY[3]->setpos_(desktopWidth-(w*2),desktopHight/1.75);
                       scene->addItem(KEY[3]);

                       KEY[4]=new key(2);
                       KEY[4]->setpos_(desktopWidth-(w*2),desktopHight/3);
                       scene->addItem(KEY[4]);

                       KEY[5]=new key(2);
                       KEY[5]->setpos_(desktopWidth/3,2.5*h);
                       scene->addItem(KEY[5]);

                       KEY[6]=new key(2);
                       KEY[6]->setpos_(desktopWidth/1.7,2.5*h);
                       scene->addItem(KEY[6]);

                                                                 KEY[7]=new key(2);
                                                               //  KEY[7]->setpos_(desktopWidth/2.2,4*h);
                                                               //  scene->addItem(KEY[7]);

                                                                KEY[8]=new key(2);
                                                               //  KEY[8]->setpos_(desktopWidth/2.2,6.7*h);
                                                               //  scene->addItem(KEY[8]);

                                                                 KEY[9]=new key(2);
                                                                // KEY[9]->setpos_(desktopWidth/2.2,10*h);
                                                                // scene->addItem(KEY[9]);

                                                                 KEY[10]=new key(2);
                                                                 KEY[10]->setpos_(desktopWidth/1.7,6.7*h);
                                                                 scene->addItem(KEY[10]);

                                                                 KEY[11]=new key(2);
                                                                 KEY[11]->setpos_(desktopWidth/3,6.7*h);
                                                                 scene->addItem(KEY[11]);

                                                                 KEY[12]=new key(2);
                                                                 KEY[12]->setpos_(desktopWidth/3,12*h);
                                                                 scene->addItem(KEY[12]);

                                                                 KEY[13]=new key(2);
                                                                 KEY[13]->setpos_(desktopWidth/1.7,12*h);
                                                                 scene->addItem(KEY[13]);

                                                                 KEY[14]=new key(2);
                                                                 KEY[14]->setpos_(desktopWidth/6,6.7*h);
                                                                 scene->addItem(KEY[14]);

                                                                 KEY[15]=new key(2);
                                                                 KEY[15]->setpos_(desktopWidth/1.3,6.7*h);
                                                                 scene->addItem(KEY[15]);

                                                                 KEY[16]=new key(2);
                                                                 KEY[16]->setpos_(desktopWidth/4.3,1.8*h);
                                                                 scene->addItem(KEY[16]);

                                                                 KEY[17]=new key(2);
                                                                 KEY[17]->setpos_(desktopWidth/1.4,1.8*h);
                                                                 scene->addItem(KEY[17]);

                                                                 KEY[18]=new key(2);
                                                                 KEY[18]->setpos_(desktopWidth/1.4,12.5*h);
                                                                 scene->addItem(KEY[18]);

                                                                 KEY[19]=new key(2);
                                                                 KEY[19]->setpos_(desktopWidth/4.3,12.5*h);
                                                                 scene->addItem(KEY[19]);
                        KEY[20]=new key(2);
                        KEY[20]->setpos_(desktopWidth/3.5,12.5*h);
                        scene->addItem(KEY[20]);
                        KEY[21]=new key(2);
                        KEY[21]->setpos_(desktopWidth/1.5,12.5*h);
                        scene->addItem(KEY[21]);
                        KEY[22]=new key(2);
                        KEY[22]->setpos_(desktopWidth/1.4,4*h);
                        scene->addItem(KEY[22]);
                        KEY[23]=new key(2);
                        KEY[23]->setpos_(desktopWidth/4.3,4*h);
                        scene->addItem(KEY[23]);
                        KEY[24]=new key(2);
                        KEY[24]->setpos_(desktopWidth/4.3,10*h);
                        scene->addItem(KEY[24]);
                        KEY[25]=new key(2);
                        KEY[25]->setpos_(desktopWidth/1.4,10*h);
                        scene->addItem(KEY[25]);
                        KEY[26]=new key(2);
                        KEY[26]->setpos_(desktopWidth/4.3,6*h);
                        scene->addItem(KEY[26]);

                        KEY[27]=new key(2);
                        KEY[27]->setpos_(desktopWidth/9,6.7*h);
                        scene->addItem(KEY[27]);
                        KEY[28]=new key(2);
                        KEY[28]->setpos_(desktopWidth/1.2,6.7*h);
                        scene->addItem(KEY[28]);






//add player
                            player1=new player(2,26,desktopWidth-3*(desktopWidth/10),desktopHight/11);
                            (player1->playerscore).getscore()=0;//;
                            player1->setFlag(QGraphicsItem::ItemIsFocusable);
                            player1->setFocus();
                            scene->addItem(player1);
//add score
                            myscore2=new score();
                            myscore2->setPos(desktopWidth/20,desktopHight/17);
                            myscore2->getscore()=0;//;
                            scene->addItem(myscore2);
                            myhealth2=new Health();
                            myhealth2->setPos(desktopWidth/20,desktopHight/11);
                            scene->addItem(myhealth2);

 //inhabitantdestroyer

                            des_img=new inhabitantdestroyer(1,1,300,300);
                            des_img->setPos(desktopWidth/2-(desktopWidth/10),(desktopHight/2)-2.15*(desktopHight/10));
                            scene->addItem(des_img);
 //add fire
                             timerfire->start(3000);

}
void game::betweenlevel(){

if (level==1){
    scene->clear();
    QImage background(":/img/background0.jpg");
    scene->setBackgroundBrush(background.scaled(desktopWidth,desktopHight));
    Button* play1;
    play1 = new Button(QString(":/img/play-icon.png"));
    play1->setPos((desktopWidth/2)-desktopWidth/10,(desktopHight/2)-desktopHight/10);
    scene->addItem(play1);
    connect(play1,SIGNAL(clicked()),this,SLOT(level1()));
     view->setScene(scene);
}
if(level==2){
     id3=0;
    scene->clear();
    QImage background(":/img/background0.jpg");
    scene->setBackgroundBrush(background.scaled(desktopWidth,desktopHight));
    Button* play1;
    play1 = new Button(QString(":/img/play-icon.png"));
    play1->setPos((desktopWidth/2)-desktopWidth/10,(desktopHight/2)-desktopHight/10);
    scene->addItem(play1);
    connect(play1,SIGNAL(clicked()),this,SLOT(level2()));
     view->setScene(scene);

}

}
void game::setdestroyer()
{
    QDesktopWidget desktop;
    desktopHight=desktop.geometry().height();
    desktopWidth=desktop.geometry().width();
if(id3){
    int randomnumber1=rand()/3000;
    int randomnumber2=rand()/3000;

    int randomnumber3=rand()/3000;
    int randomnumber4=rand()/3000;
    int randomnumber5=rand()/3000;
    int randomnumber6=rand()/3000;

    qDebug()<<"random"<<randomnumber1;

    fire_img1=new fire(randomnumber1,desktopWidth/2-(desktopWidth/20),(desktopHight/2)-((desktopHight)/15)*3);
    scene->addItem(fire_img1);

    fire_img2=new fire(randomnumber2,desktopWidth/2-(desktopWidth/20),(desktopHight/2)-((desktopHight)/15)*3);

    scene->addItem(fire_img2);

    fire_img3=new fire(randomnumber3,desktopWidth/2-(desktopWidth/20),(desktopHight/2)-((desktopHight)/15)*3);

    scene->addItem(fire_img3);
    fire_img4=new fire(randomnumber4,desktopWidth/2-(desktopWidth/20),(desktopHight/2)-((desktopHight)/15)*3);

    scene->addItem(fire_img4);
    fire_img5=new fire(randomnumber5,desktopWidth/2-(desktopWidth/20),(desktopHight/2)-((desktopHight)/15)*3);

    scene->addItem(fire_img5);
    fire_img6=new fire(randomnumber6,desktopWidth/2-(desktopWidth/20),(desktopHight/2)-((desktopHight)/15)*3);

    scene->addItem(fire_img6);
}
}

void game::level3(){
    music2->stop();
    id3=0;
    scene->clear();
    QImage background(":/img/endgame.jpg");
    scene->setBackgroundBrush(background.scaled(desktopWidth,desktopHight));
    view->setScene(scene);

}

void game::senddata()
{
   QString massege;

   massege=QString::number(player1->xplayer);
   massege=" ";
   massege=QString::number(player1->yplayer);
   massege.push_back((QChar(23)));
   socket->write(massege.toLocal8Bit());


}


void game::connected()
{

    qDebug()<<"connected";
       socket->write("every thing i want to send");
}

void game::disconnected()
{

     qDebug()<<"disconnected";
}

void game::bytewriten(qint64 bytes)
{
    qDebug()<<"writing...";
       qDebug()<<bytes;
}

void game::readyread()
{

    qDebug()<<"reading...";
      QString data=socket->readAll();
     // int a=data.





}

void game::readmessage()
{
if(socket->state()!=QAbstractSocket::ConnectedState){
    return;

}
QString reciveData;
//        reciveData.append(socket->readAll());
//        if(!receivedData.contains(QChar(23))){
//           return;
//        }
//        QStringList message=receivedData.split(QChar(23));
//        reciveData  =

}

void game::disconnect_by_server()
{

    socket->close();
}


