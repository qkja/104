#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <QObject>

class DataProcessing : public QObject
{
    Q_OBJECT
public:
    explicit DataProcessing(QObject *parent = nullptr);

signals:

};

#endif // DATAPROCESSING_H
