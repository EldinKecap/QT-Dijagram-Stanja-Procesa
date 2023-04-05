#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QBrush blueBrush(Qt::blue);
    scene->setBackgroundBrush(blueBrush);

    start = new Stanje(50,50,"Start");
    scene->addItem(start);
    ready = new Stanje(200,250,"Ready");
    scene->addItem(ready);
    wait = new Stanje(500,250,"Wait");
    scene->addItem(wait);
    run = new Stanje(350,450,"Run");
    scene->addItem(run);
    stop = new Stanje(650,50,"Stop");
    scene->addItem(stop);
}

Dialog::~Dialog()
{
    delete ui;
}
