#ifndef TREASURE_H
#define TREASURE_H
#include <QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QTimer>
#include<QMovie>
#include<QPair>
#include<QVector>

#include<QDesktopWidget>

class treasure : public  QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit treasure(QGraphicsPixmapItem *parent = 0);
     void setpos_(int,int);
     float randRange(float,float);
     float rand01();

signals:

public slots:
     void hiden_img();
private:
     QTimer *treasure_timer;
     QPixmap *treasureimg;
     QVector<QPair<int,int> > vec;
     int flag;




};

#endif // TREASURE_H
