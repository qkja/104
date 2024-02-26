#include "mylabel.h"
#include <iostream>
#include <QDebug>
MyLabel::MyLabel(QWidget* parent)
    :QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    //    std::cout << "MyLabel已经被销毁" << std::endl;
    qDebug()<< "MyLabel已经被销毁" ;
}

