#include "assist.h"
#include "qdebug.h"
Assist::Assist(QWidget *parent) : QWidget(parent)
{
     qDebug() << "Assist()";
}

Assist::~Assist()
{
     qDebug() << "~Assist()";
}
