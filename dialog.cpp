#include "dialog.h"
#include "ui_dialog.h"

void logaj(){
    qDebug() << "Polygon item clicked!";
}

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
    run = new Stanje(500,250,"Run");
    scene->addItem(run);
    wait = new Stanje(350,450,"Wait");
    scene->addItem(wait);
    stop = new Stanje(650,50,"Stop");
    scene->addItem(stop);

    startReady = new Tranzicija(120,50,140,150);
    scene->addItem(startReady);
    readyRun = new Tranzicija(150,0,320,270);
    scene->addItem(readyRun);
    runReady = new Tranzicija(150,180,480,330);
    scene->addItem(runReady);
    runWait = new Tranzicija(120,130,520,360);
    scene->addItem(runWait);
    waitReady = new Tranzicija(120,230,350,460);
    scene->addItem(waitReady);
    runStop = new Tranzicija(120,310,580,250);
    scene->addItem(runStop);
}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::drawProcess(int x, int y)
{
    QBrush redBrush(Qt::red);
    QPen pen(Qt::black);
    pen.setWidth(1);
    QGraphicsEllipseItem *proces = new QGraphicsEllipseItem(x,y,10,10);
    proces->setBrush(redBrush);
    proces->setPen(pen);
    scene->addItem(proces);

    scene->update();
}

void Dialog::on_kreirajProces_clicked()
{
    qDebug() << this->processStartArray.size();
    if(this->processStartArray.size() < 5)
    {
    this->processStartArray.push_back(1);
    for(int i=0; i < this->processStartArray.size(); i++)
    {
    this->drawProcess(68 + (15*i) ,108);
    }
    }
}
