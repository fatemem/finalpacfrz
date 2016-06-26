#include "button.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "game.h"
Button::Button(QString pic)

{
    setPixmap(QPixmap(pic));
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    emit clicked();
}
