#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include <QBrush>
#include <QtMath>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->redSlider->setRange(0,255);
    ui->greenSlider->setRange(0,255);
    ui->blueSlider->setRange(0,255);

    connect(ui->redSlider,&QSlider::valueChanged,this,&MainWindow::onRedChanged);
    connect(ui->greenSlider,&QSlider::valueChanged,this,&MainWindow::onGreenChanged);
    connect(ui->blueSlider,&QSlider::valueChanged,this,&MainWindow::onBlueChanged);

    updateColorCode();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateColorCode(){
    int r=ui->redSlider->value();
    int g=ui->greenSlider->value();
    int b=ui->blueSlider->value();

    QString  rString=QString::number(r,16).count()>1?QString::number(r,16):QString::number(r,16).prepend("0");
    QString  gString=QString::number(g,16).count()>1?QString::number(g,16):QString::number(g,16).prepend("0");
    QString  bString=QString::number(b,16).count()>1?QString::number(b,16):QString::number(b,16).prepend("0");

    QString s=(rString.append(gString).append(bString)).prepend("#");
    ui->colorCode->setText(s);
}

void MainWindow::onRedChanged(int r){
    updateColorCode();
    update();
}

void MainWindow::onBlueChanged(int r){
    updateColorCode();
    update();
}

void MainWindow::onGreenChanged(int r){
    updateColorCode();
    update();
}

void MainWindow::paintEvent(QPaintEvent *event){
    int red=ui->redSlider->value();
    int green=ui->greenSlider->value();
    int blue=ui->blueSlider->value();
    draw(red,green,blue);
}

void MainWindow::draw(int R, int G,int B){

    QPainter paintr(this);
    toDisplay.setWidth(this->width());
    toDisplay.setHeight(this->height()-170);

    QColor colr;
    colr.setRed(R);
    colr.setGreen(G);
    colr.setBlue(B);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(colr);

    paintr.setBrush(brush);
    paintr.drawRect(toDisplay);
}
