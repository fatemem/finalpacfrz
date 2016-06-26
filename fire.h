#ifndef FIRE_H
#define FIRE_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include"inhabthread.h"
#include<QDesktopWidget>


class fire : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit fire(int direct,int x,int y,QObject *parent1 = 0, QGraphicsPixmapItem *parent2=0);
     QPixmap* fire_img;
     int x;
     int y;
     int id;
     int direct;


signals:

public slots:
     void moving();

};

#endif // FIRE_H
