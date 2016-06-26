#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include<QFont>

class score:public QGraphicsTextItem
{
public:
    score(QGraphicsTextItem* parent=0);
    void increase();
    int& getscore();
private:
    int Score;
};

#endif // SCORE_H
