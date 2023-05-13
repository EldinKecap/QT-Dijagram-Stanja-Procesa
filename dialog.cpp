#include "dialog.h"
#include "ui_dialog.h"

void logaj(){
    qDebug() << "Polygon item pomjeri_proces!";
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

    connect(startReady,SIGNAL(pomjeri_proces()),this,SLOT(moveProcessStartToReady()));
    connect(readyRun,SIGNAL(pomjeri_proces()),this,SLOT(moveProcessReadyToRun()));
    connect(runReady,SIGNAL(pomjeri_proces()),this,SLOT(moveProcessRunToReady()));
    connect(runWait,SIGNAL(pomjeri_proces()),this,SLOT(moveProcessRunToWait()));
    connect(waitReady,SIGNAL(pomjeri_proces()),this,SLOT(moveProcessWaitToReady()));
    connect(runStop,SIGNAL(pomjeri_proces()),this,SLOT(moveProcessRunToStop()));

}



Dialog::~Dialog()
{
    delete ui;
}

QGraphicsEllipseItem *Dialog::drawProcess(int x, int y)
{
    QBrush redBrush(Qt::red);
    QPen pen(Qt::black);
    pen.setWidth(1);
    QGraphicsEllipseItem *proces = new QGraphicsEllipseItem(0,0,10,10);
    proces->setBrush(redBrush);
    proces->setPen(pen);
    proces->setPos(x,y);
    scene->addItem(proces);

    scene->update();

    return proces;
}

void Dialog::on_kreirajProces_clicked()
{

    if(this->processStartArray.size() < 5)
    {

        this->processStartArray.push_back(this->drawProcess(68 + (15*this->processStartArray.size()) ,108));
        this->processStartArray.push_back(NULL);
        this->processStartArray.push_back(NULL);
        this->processStartArray.push_back(NULL);
        this->processStartArray.push_back(NULL);

    }else{

        for(int i=0; i < this->processStartArray.size(); i++)
        {
        if(this->processStartArray[i]==NULL){
            this->processStartArray[i]=this->drawProcess(68 + (15*i) ,108);
            break;
        }
        }
    }
}

bool isEmpty(QVector<QGraphicsEllipseItem*> processVector ){
    int counter = 0;
    for(int i=0; i < processVector.size(); i++)
    {

    if(processVector[i]==NULL){
        counter++;
    }

    }
    if(counter == 5){
        return true;
    }else{
        return false;
    }
}

int findArrayIndex(QVector<QGraphicsEllipseItem*> processVector){
    for(int i=0; i < processVector.size(); i++)
    {

    if(!processVector[i]==NULL){
        return i;
    }

    }

}

void Dialog::moveProcessStartToReady()
{
    qDebug() << "startReady";
//  this->processStartArray[0]->setPos(300,300);
    scene->update();
    //POPULATE THE ARRAY WITH NULLS
    if(this->processReadyArray.size()<5){
        this->processReadyArray.push_back(NULL);
        this->processReadyArray.push_back(NULL);
        this->processReadyArray.push_back(NULL);
        this->processReadyArray.push_back(NULL);
        this->processReadyArray.push_back(NULL);
    }

    if(isEmpty(this->processStartArray) || this->processStartArray.empty()){

        qDebug()<<"Empty Start Array";

    }else{

        int indexOfNextInLine = findArrayIndex(processStartArray);

        for(int i = 0 ; i < this->processReadyArray.size(); i++ ){
            if(this->processReadyArray[i] == NULL){
                this->processReadyArray[i] = this->processStartArray[indexOfNextInLine];
                this->processStartArray[indexOfNextInLine] = NULL;
                this->animationStart(i,218,308,processReadyArray,true,true);
                break;
            }


        }


    }

}

void Dialog::moveProcessReadyToRun()
{
    qDebug() << "readyRun";

    scene->update();
    //POPULATE THE ARRAY WITH NULLS
    if(this->processRunArray.size()<5){
        this->processRunArray.push_back(NULL);
        this->processRunArray.push_back(NULL);
        this->processRunArray.push_back(NULL);
        this->processRunArray.push_back(NULL);
        this->processRunArray.push_back(NULL);
    }

    if(isEmpty(this->processReadyArray) || this->processReadyArray.empty()){

        qDebug()<<"Empty Ready Array";

    }else{

        int indexOfNextInLine = findArrayIndex(processReadyArray);
                qDebug()<<this->processReadyArray;
                for(int i = 0 ; i < this->processRunArray.size(); i++ ){
                    if(this->processRunArray[i] == NULL){
                        this->processRunArray[i] = this->processReadyArray[indexOfNextInLine];
                        this->processReadyArray[indexOfNextInLine] = NULL;
                        this->animationStart(i,518,308,processRunArray,true,true);
                        break;
                        }
                    }
    }
}

void Dialog::moveProcessRunToReady()
{
    qDebug() << "runReady";
    scene->update();
    //POPULATE THE ARRAY WITH NULLS


    if(isEmpty(this->processRunArray) || this->processRunArray.empty()){

        qDebug()<<"Empty Run Array";

    }else{

        int indexOfNextInLine = findArrayIndex(processRunArray);
                qDebug()<<this->processRunArray;
                for(int i = 0 ; i < this->processRunArray.size(); i++ ){
                    if(this->processReadyArray[i] == NULL){
                        this->processReadyArray[i] = this->processRunArray[indexOfNextInLine];
                        this->animationStart(i,218,308,processReadyArray,false,false);
                        this->processRunArray[indexOfNextInLine] = NULL;
                        break;
                    }
                }
            }
//            qDebug()<<this->processReadyArray;
}

void Dialog::moveProcessRunToWait()
{
    qDebug() << "runWait";
    scene->update();
    //POPULATE THE ARRAY WITH NULLS
    if(this->processWaitArray.size()<5){
        this->processWaitArray.push_back(NULL);
        this->processWaitArray.push_back(NULL);
        this->processWaitArray.push_back(NULL);
        this->processWaitArray.push_back(NULL);
        this->processWaitArray.push_back(NULL);
    }

    if(isEmpty(this->processRunArray) || this->processRunArray.empty()){

        qDebug()<<"Empty Run Array";

    }else{

        int indexOfNextInLine = findArrayIndex(processRunArray);
                qDebug()<<this->processRunArray;
                for(int i = 0 ; i < this->processWaitArray.size(); i++ ){
                    if(this->processWaitArray[i] == NULL){
                        this->processWaitArray[i] = this->processRunArray[indexOfNextInLine];
                        this->processRunArray[indexOfNextInLine] = NULL;
                        this->animationStart(i,368,508,processWaitArray,false,true);
                        break;
                    }
        }
    }


}

void Dialog::moveProcessWaitToReady()
{
    qDebug() << "waitReady";

    scene->update();

    if(isEmpty(this->processWaitArray) || this->processWaitArray.empty()){

        qDebug()<<"Empty Wait Array";

    }else{

        int indexOfNextInLine = findArrayIndex(processWaitArray);
                qDebug()<<this->processWaitArray;
                for(int i = 0 ; i < this->processWaitArray.size(); i++ ){
                    if(this->processReadyArray[i] == NULL){
                        this->processReadyArray[i] = this->processWaitArray[indexOfNextInLine];
                        this->processWaitArray[indexOfNextInLine] = NULL;
                        this->animationStart(i,218,308,processReadyArray,false,false);
                        break;
                    }
                }
            }
}

void Dialog::moveProcessRunToStop()
{
    qDebug() << "runStop";

    scene->update();
    //POPULATE THE ARRAY WITH NULLS
    if(this->processStopArray.size()<5){
        this->processStopArray.push_back(NULL);
        this->processStopArray.push_back(NULL);
        this->processStopArray.push_back(NULL);
        this->processStopArray.push_back(NULL);
        this->processStopArray.push_back(NULL);
    }

    if(isEmpty(this->processRunArray) || this->processRunArray.empty()){

        qDebug()<<"Empty Run Array";

    }else{

        int indexOfNextInLine = findArrayIndex(processRunArray);
                qDebug()<<this->processRunArray;
                for(int i = 0 ; i < this->processStopArray.size(); i++ ){
                    if(this->processStopArray[i] == NULL){
                        this->processStopArray[i] = this->processRunArray[indexOfNextInLine] ;
                        this->processRunArray[indexOfNextInLine] = NULL;
                        this->animationStart(i,668,108,processStopArray,true,false);
                        break;
                    }
        }
    }
}

void Dialog::animationStart(int indexOfProcess, int limitX, int limitY, QVector<QGraphicsEllipseItem *> arrayToAnimate, bool forward, bool down)
{
    processArrayIndex = indexOfProcess;
    animationLimitX = limitX;
    animationLimitY = limitY;
    animatingArray = arrayToAnimate;
    startReady->setEnabled(false);
    readyRun->setEnabled(false);
    runReady->setEnabled(false);
    runWait->setEnabled(false);
    waitReady->setEnabled(false);
    runStop->setEnabled(false);
    timer = new QTimer(this);
    this->forward = forward;
    this->down = down;
    connect(timer, SIGNAL(timeout()), this, SLOT(moveCircle()));
    timer->start(1);
}

void Dialog::on_unistiProces_clicked()
{
    for(int i = 0; i < this->processStopArray.size() ; i++ ){
        if(this->processStopArray[i] != NULL){
            scene->removeItem(this->processStopArray[i]);
            this->processStopArray[i] = NULL ;
            scene->update();
            break;
        }
    }
}
