#ifndef INHABTHREAD_H
#define INHABTHREAD_H

#include <iostream>
#include <QThread>
#include <QTimer>
#include <QObject>
#include <QDebug>
using namespace std;

class inhabthread : public QThread
{
    Q_OBJECT
    QTimer* thr;
public:
    inhabthread(QObject *parent=0);
    void run(int);
    public slots:
    void myslot();

signals:
    void mysignal();

};


#endif // INHABTHREAD_H
