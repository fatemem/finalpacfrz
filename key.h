#ifndef KEY_H
#define KEY_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QTimer>
#include<QMovie>
#include"inhabthread.h"
class key : public  QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    key(int ,QGraphicsPixmapItem *parent = 0);

     void setpos_(int,int);
private:
     QPixmap* keyimg;
     int flag;

     inhabthread * timer;

public slots:
     void moveimg();



};

#endif // KEY_H
