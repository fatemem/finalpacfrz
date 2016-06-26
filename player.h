#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include"score.h"
#include"health.h"
class player:public QObject ,public QGraphicsPixmapItem{
public:
player(int,int ,int , int);
public slots:
void keyPressEvent(QKeyEvent* event);
public:
void keyaccident();
void destroyeraccident();
bool brickaccident();
score playerscore;
Health playerhealth;
QPixmap * playerimg;
int imgid;
int xplayer;
int yplayer;
int keynumber;
int flagup;
int flagdown;
int flagright;
int flagleft;
int _x;
int _y;
};
#endif // PLAYER_H
