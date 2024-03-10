#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barchart.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    BarChart* bar_chart = new BarChart(this);
//bar_chart->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

