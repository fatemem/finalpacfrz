#include "destroyerthread.h"
#include<QDebug>

destroyerthread::destroyerthread(QObject *parent) :vdes(3,100,100,0),hdes(3,100,100,0),
    QObject(parent)
{
}
void destroyerthread::adddestroyer(){

   hdes.move();
   vdes.move();
   qDebug()<<"in thread";
}
void destroyerthread::dowork(QThread &cthread){
    connect(&cthread,SIGNAL(started()),this,SLOT(adddestroyer()));
}

