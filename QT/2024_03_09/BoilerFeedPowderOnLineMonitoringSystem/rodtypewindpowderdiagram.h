#ifndef RODTYPEWINDPOWDERDIAGRAM_H
#define RODTYPEWINDPOWDERDIAGRAM_H

#include <QWidget>

namespace Ui {
class RodTypeWindPowderDiagram;
}

class RodTypeWindPowderDiagram : public QWidget
{
    Q_OBJECT

public:
    explicit RodTypeWindPowderDiagram(QWidget *parent = nullptr);
    ~RodTypeWindPowderDiagram();

private:
    Ui::RodTypeWindPowderDiagram *ui;
};

#endif // RODTYPEWINDPOWDERDIAGRAM_H
