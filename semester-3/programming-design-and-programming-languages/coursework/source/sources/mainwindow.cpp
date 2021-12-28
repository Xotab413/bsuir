#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(TimerSlot()));
    timer->start(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerSlot(){
    time++;
    ui->label->setText(QString::number(time));
}
