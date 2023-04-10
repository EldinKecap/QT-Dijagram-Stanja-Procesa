// dialog.h

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "stanje.h"
#include <QDebug>
#include "tranzicija.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_kreirajProces_clicked();
    void moveProcessStartToReady();
    void moveProcessReadyToRun();
    void moveProcessRunToReady();
    void moveProcessRunToWait();
    void moveProcessWaitToReady();
    void moveProcessRunToStop();

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
    QGraphicsView *view;

    Stanje *start;
    Stanje *ready;
    Stanje *wait;
    Stanje *run;
    Stanje *stop;
    Tranzicija *startReady;
    Tranzicija *readyRun;
    Tranzicija *runReady;
    Tranzicija *runWait;
    Tranzicija *waitReady;
    Tranzicija *runStop;

    QVector<QGraphicsEllipseItem*> processStartArray;
    QVector<QGraphicsEllipseItem*> processReadyArray;
    QVector<QGraphicsEllipseItem*> processRunArray;
    QVector<QGraphicsEllipseItem*> processWaitArray;
    QVector<QGraphicsEllipseItem*> processStopArray;

    int processReadyArrayIndex ;

    QGraphicsEllipseItem* drawProcess(int x, int y);
    QTimer *timer;
private slots:
    void moveCircle()
    {
        // get the current position of the circle item
         processReadyArray[processReadyArrayIndex]->x();

        int limitX = 100;
        int limitY = 100;
        switch(processReadyArrayIndex){
            case 0:
            limitX = 218;
            limitY = 308;
            break;
        }
        // calculate the new position
        qreal x = processReadyArray[processReadyArrayIndex]->boundingRect().x() + 1;

        qreal y = processReadyArray[processReadyArrayIndex]->boundingRect().y() + 1;
        //

        qDebug()<< x <<' '<<y;
//        timer->stop();

        //
        if(y > limitY ){
            y = limitY;
        }
        if(x > limitX ){
            x = limitX;
        }
        // set the new position
        this->processReadyArray[processReadyArrayIndex]->setPos(x, y);
        this->processReadyArray[processReadyArrayIndex]->boundingRect().setX(x);
        this->processReadyArray[processReadyArrayIndex]->boundingRect().setY(y);
        // check if the circle has reached the destination
        if (x >= limitX  && y >= limitY) {
            // stop the timer
            timer->stop();
        }
        scene->update();
    }
    void on_unistiProces_clicked();
};
#endif // DIALOG_H
