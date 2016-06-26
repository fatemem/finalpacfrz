#ifndef DESTROYERTHREAD_H
#define DESTROYERTHREAD_H

#include <QObject>
#include <QObject>
#include<QGraphicsScene>
#include<QThread>
#include"horizontaldestroyer.h"
#include"verticaldestroyer.h"
class destroyerthread : public QObject
{
    Q_OBJECT
public:
    explicit destroyerthread(QObject *parent = 0);
    void dowork(QThread & cthread);


public slots:
     void adddestroyer();


private:
verticaldestroyer vdes;
horizontaldestroyer hdes;


};

#endif // DESTROYERTHREAD_H
