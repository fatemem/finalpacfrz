#ifndef HORIZONTALDESTROYER_H
#define HORIZONTALDESTROYER_H

#include <QObject>
#include"destroyer.h"

class horizontaldestroyer:public destroyer
{
    Q_OBJECT
public:
    explicit horizontaldestroyer(int id,int firstx,int firsty,QGraphicsPixmapItem *parent=0);


public slots:
void move();
private:
 int flag=1;
 int flag1;

};



#endif // HORIZONTALDESTROYER_H
