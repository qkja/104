#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "qdebug.h"
#include "changepassword.h"
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    pass = new MyPassword; // 这里是我们的口令
    pass->set("123456");
    pass_view = new password(this->pass); // 这个是显示我们的是否密码正确的页面
    //////////////////////////////////////////////////


    // 设定界限
    alarm = new Alarm;
    connect(ui->actionaction_01, &QAction::triggered,[=](){
        // 这是界限的界面
        this->hide();
        alarm->show();
    });


    // 设定喷口
    this->pout = new SetSpout;
    connect(ui->actionaction_02, &QAction::triggered,[=](){

        pass_view->show();
        connect(this->pass_view, &password::back_true,[=](){
            qDebug()<<"修改系数";
            pass_view->close();
            this->hide();

            pout->show();
        });
        connect(this->pass_view, &password::back_false,[=](){
            qDebug()<<"密码错误";
            pass_view->close();
        });

    });
    // 修订背靠管系数
    tube = new BackToTube;
    connect(ui->actionaction_03, &QAction::triggered,[=](){
        pass_view->show();
        connect(this->pass_view, &password::back_true,[=](){
            qDebug()<<"修改系数";
            this->hide();
            pass_view->close();
            tube->show();
        });
        connect(this->pass_view, &password::back_false,[=](){
            qDebug()<<"密码错误";
            pass_view->close();
        });

    });

    // 修改口令
    myPass = new ChangePassword(this->pass);
    connect(ui->actionaction_04, &QAction::triggered,[=](){
        // 这是界限的界面
        this->hide();
        myPass->show();
    });


    // 修改时间
    time_set = new RevisionTime;

    connect(ui->actionaction_05, &QAction::triggered,[=](){
        // 这是界限的界面
        this->hide();
        time_set->show();
    });

    // 退出
    connect(ui->actionaction_06, &QAction::triggered,[=](){
        emit this->back();
    });



    s = new StickTypeGouacheDiagram;
    a = new AWindcutCircleChart;
    t = new TrendCharts;

    connect(ui->actionfig_01, &QAction::triggered,[=](){
        this->hide();
        s->show();
    });

    connect(ui->actionfig_02, &QAction::triggered,[=](){
        this->hide();
        a->show();
    });
    connect(ui->actionfig_03, &QAction::triggered,[=](){
        this->hide();
        t->show();
    });




    // 返回信号
    //    StickTypeGouacheDiagram* s;// 第一张图
    //    AWindcutCircleChart a; // 第二张图
    //    TrendCharts* t; // 第三张图
    connect(this->s, &StickTypeGouacheDiagram::back,[=](){
        qDebug()<<"来及1";
        s->close();
        this->show();
    });
    connect(this->a, &AWindcutCircleChart::back,[=](){
        qDebug()<<"来及1";
        a->close();
        this->show();
    });
    connect(this->t, &TrendCharts::back,[=](){
        qDebug()<<"来及1";
        t->close();
        this->show();
    });

    connect(this->time_set, &RevisionTime::back,[=](){
        qDebug()<<"来及1";
        time_set->close();
        this->show();
    });

    connect(this->pout, &SetSpout::back,[=](){
        qDebug()<<"来及1";
        pout->close();
        this->show();
    });

    connect(this->tube, &BackToTube::back,[=](){
        qDebug()<<"来及1";
        tube->close();
        this->show();
    });

    connect(this->alarm, &Alarm::back,[=](){
        qDebug()<<"来及1";
        alarm->close();
        this->show();
    });

    connect(this->myPass, &ChangePassword::back, [=](){
        qDebug()<<"来及2";
        myPass->close();
        this->show();
    });

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
