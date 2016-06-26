#ifndef GAME_H
#define GAME_H
#include<QObject>
#include<QGraphicsScene>
#include<QGraphicsView>
#include"player.h"
#include"score.h"
#include"health.h"
#include"inhabitantdestroyer.h"
#include"fire.h"
#include<QtMultimedia/QMediaPlayer>
#include<QTcpSocket>
#include<QAbstractSocket>
#include<QTcpSocket>
#include<QString>
class game:public QObject {
    Q_OBJECT
public:
//behavere:
game(QWidget*parent=0);
void level0();
void betweenlevel();
void senddata();
//field
QMediaPlayer *music;
QMediaPlayer *music2;
QGraphicsScene* scene;
static QGraphicsView* view;
score* myscore1;
score*myscore2;
score*myscore3;
Health *myhealth1;
Health *myhealth2;
Health *myhealth3;
int id3;
private:
QTimer * timerfire;
QTimer *middlepagetimer;
inhabitantdestroyer *des_img;
fire *fire_img1;
fire *fire_img2;
fire *fire_img3;
fire *fire_img4;
fire *fire_img5;
fire *fire_img6;

player* player1;
int desktopHight;
int desktopWidth;
int level;
QTcpSocket* socket;
public slots:


    void connected();
    void disconnected();
    void bytewriten(qint64 bytes);
    void readyread();
    void readmessage();
    void disconnect_by_server();

void level1();
void level2();
void checkend();
void setdestroyer();
void level3();
};

#endif // GAME_H
