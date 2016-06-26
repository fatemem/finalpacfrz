#ifndef VERTICALDESTROYER_H
#define VERTICALDESTROYER_H
#include <QObject>
#include"destroyer.h"

class verticaldestroyer:public destroyer
{
    Q_OBJECT
public:
    explicit verticaldestroyer(int id,int firstx,int firsty,QGraphicsPixmapItem *parent=0);


public slots:
 void move();
 private:
  int flag2=1;
  int flag3;

};
#endif // VERTICALDESTROYER1_H
