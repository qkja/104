#include "dataprocessing.h"
#include "QDebug"
DataProcessing::DataProcessing(QObject *parent) : QObject(parent)
{
     qDebug() << "DataProcessing()";
}

DataProcessing::~DataProcessing()
{
      qDebug() << "~DataProcessing()";
}
