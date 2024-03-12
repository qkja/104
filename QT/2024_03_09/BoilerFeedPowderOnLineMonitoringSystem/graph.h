#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "util.hpp"
namespace Ui
{
    class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

private:
    Ui::Graph *ui;
};

#endif // GRAPH_H
