#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew, &QAction::triggered, this,[=](){
        //        QDialog dlg(this);// 模态的
        //        dlg.resize(200,200);

        //        dlg.exec(); // 弹出对话框

        //        QDialog* dlg = new QDialog(this);// 非模态的
        //        dlg->resize(200,200);

        //        dlg->show();// 弹出对话框
        //        dlg->setAttribute(Qt::WA_DeleteOnClose); // 防止内存泄露
        // 消息对话框
        QMessageBox::critical(this, "critical", "错误");
        QMessageBox::me
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

