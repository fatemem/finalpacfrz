#include <QApplication>
#include"game.h"
game* mygame;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mygame=new game();
    mygame->level0();
    mygame->view->show();

    return a.exec();
}
