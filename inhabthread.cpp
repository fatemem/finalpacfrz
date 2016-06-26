#include "inhabthread.h"

inhabthread::inhabthread(QObject *parent) :
    QThread(parent)
{
}
void  inhabthread::run(int mytime){
    thr =new QTimer();
    thr->setInterval(mytime);
     connect(thr,SIGNAL(timeout()),this,SLOT(myslot()));
     thr->start(mytime);

};
void inhabthread::myslot()
{
    emit mysignal();
}
