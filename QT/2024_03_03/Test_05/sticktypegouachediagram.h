#ifndef STICKTYPEGOUACHEDIAGRAM_H
#define STICKTYPEGOUACHEDIAGRAM_H

#include <QMainWindow>

namespace Ui {
class StickTypeGouacheDiagram;
}

class StickTypeGouacheDiagram : public QMainWindow
{
    Q_OBJECT

public:
    explicit StickTypeGouacheDiagram(QWidget *parent = nullptr);
    ~StickTypeGouacheDiagram();
signals:
    void back();
private:
    Ui::StickTypeGouacheDiagram *ui;
};

#endif // STICKTYPEGOUACHEDIAGRAM_H
