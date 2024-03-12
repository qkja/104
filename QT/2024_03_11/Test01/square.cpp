#include "square.h"
#include "ui_square.h"

Square::Square(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Square)
{
    ui->setupUi(this);
    // 创建场景和正方形项
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(0, 0, 100, 100);
    QGraphicsEllipseItem *circle = scene->addEllipse(75, 75, 50, 50, QPen(Qt::black), QBrush(Qt::blue));
    // 设置正方形项的位置
    rectItem->setPos(50, 50);

    // 将正方形项添加到场景中
    scene->addItem(rectItem);

    // 将场景设置给QGraphicsView
    ui->graphicsView->setScene(scene);

    // 添加对角线
    QPen pen(Qt::red, 2, Qt::SolidLine);
    scene->addLine(rectItem->pos().x(), rectItem->pos().y(),
                   rectItem->pos().x() + rectItem->rect().width(),
                   rectItem->pos().y() + rectItem->rect().height(), pen);
    scene->addLine(rectItem->pos().x() + rectItem->rect().width(),
                   rectItem->pos().y(),
                   rectItem->pos().x(),
                   rectItem->pos().y() + rectItem->rect().height(), pen);
}

Square::~Square()
{
    delete ui;
}
