#ifndef DESTROYER_H
#define DESTROYER_H

#include <QObject>
#include<QGraphicsPixmapItem>

class destroyer : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit destroyer(int id,int firstx,int firsty, QGraphicsPixmapItem *parent=0);


public slots:


protected:
    QPixmap * mydestroyer;
    int img_id;
    int height;
    int width;
    int x;
    int y;
    int x0;
    int y0;


};

#endif // DESTROYER1_H
