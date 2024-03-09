#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew_2->setIcon(QIcon("C:\\Users\\qkj12\\AppData\\Roaming\\qq_guild\\undefined\\nt_data\\Emoji\\emoji-resource\\__MACOSX\\emoji_res\\._emoji_014.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

