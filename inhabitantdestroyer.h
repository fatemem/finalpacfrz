#ifndef INHABITANTDESTROYER_H
#define INHABITANTDESTROYER_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QDesktopWidget>

class inhabitantdestroyer : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit inhabitantdestroyer(int direct,int id,int x,int y,QObject *parent1 = 0, QGraphicsPixmapItem *parent2=0);
private:
     QPixmap * mydestroyerimg;
     int x;
     int y;
     int id;

     QTimer*timer;
     int direct;


signals:

public slots:


};

#endif // INHABITANTDESTROYER_H
