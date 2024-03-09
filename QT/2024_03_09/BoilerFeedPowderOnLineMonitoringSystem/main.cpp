#include "welcomescreen.h"

#include <QApplication>
#include "qdebug.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WelcomeScreen w;
    w.show();

    a.exec();
    qDebug()<<"进程已经结束";

    return 0;
}
