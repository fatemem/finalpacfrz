
#include "health.h"

Health::Health(QGraphicsTextItem *parent):QGraphicsTextItem(parent)
{
    //intiliaze Health to three
    health=1;

    //drow the text
    setPlainText(QString("Health: ")+QString::number(health));//Health:3

    setDefaultTextColor(Qt::white);
    setFont(QFont("times",22));


}

void Health::decrease()
{
    setPlainText(QString("Health: ")+QString::number(health));//Health:3
    health--;
}

int &Health::getHealth()
{
    return health;
}
