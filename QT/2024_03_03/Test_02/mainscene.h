#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Mainscene; }
QT_END_NAMESPACE

class Mainscene : public QMainWindow
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);
    ~Mainscene();

private:
    ChooseLevelScene* choose = nullptr;
    Ui::Mainscene *ui;
};
#endif // MAINSCENE_H
