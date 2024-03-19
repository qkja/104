#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H
#include <QApplication>
#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QChartView>
#include <QHBoxLayout>
#include <QThread>
#include <QObject>

class LineChartWidget : public QObject
{
    Q_OBJECT
public:
    explicit LineChartWidget(QObject *parent = nullptr)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);
        setLayout(layout);

        chartView = new QChartView(this);
        layout->addWidget(chartView);

        series = new QLineSeries();
        chartView->chart()->addSeries(series);
        chartView->chart()->createDefaultAxes();
        chartView->setRenderHint(QPainter::Antialiasing);

        // 创建消费者对象
        consumer = new Consumer();

        // 创建一个新的线程，并将消费者对象移动到该线程中
        thread = new QThread();
        consumer->moveToThread(thread);

        // 在线程启动时连接消费者的槽函数
        connect(thread, &QThread::started, consumer, &Consumer::consumeData);

        // 启动线程
        thread->start();
    }

signals:
private:
    QChartView *chartView;
    QLineSeries *series;
    Consumer *consumer;
    QThread *thread;
};

#endif // LINECHARTWIDGET_H
