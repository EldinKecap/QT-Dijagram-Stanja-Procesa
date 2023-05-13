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

    void animationStart(int indexOfProcess,int limitX, int limitY , QVector<QGraphicsEllipseItem*> arrayToAnimate, bool forward, bool down);
    int processArrayIndex ;
    float xAnimationPositionIncrement;
    float yAnimationPositionIncrement;
    float animationLimitX;
    float animationLimitY;
    bool incrementSet;
    bool forward;
    bool down;

    QVector<QGraphicsEllipseItem*> animatingArray;

    QGraphicsEllipseItem* drawProcess(int x, int y);
    QTimer *timer;
private slots:
    void moveCircle()
    {

        float limitX = animationLimitX + (15 * processArrayIndex);
        float limitY = animationLimitY;

        if(!incrementSet){
            if(forward && down){
                xAnimationPositionIncrement = (1.0/100)*(limitX - animatingArray[processArrayIndex]->pos().x());
                yAnimationPositionIncrement = (1.0/100)*(limitY - animatingArray[processArrayIndex]->pos().y());
            }else if(!forward && !down){
                xAnimationPositionIncrement = (1.0/100)*(animatingArray[processArrayIndex]->pos().x() - limitX);
                yAnimationPositionIncrement = (1.0/100)*(animatingArray[processArrayIndex]->pos().y() - limitY);
            }else if(!forward && down){
                xAnimationPositionIncrement = (1.0/100)*(animatingArray[processArrayIndex]->pos().x() - limitX);
                yAnimationPositionIncrement = (1.0/100)*(limitY - animatingArray[processArrayIndex]->pos().y());
            }else if(forward && !down){
                xAnimationPositionIncrement = (1.0/100)*(limitX -animatingArray[processArrayIndex]->pos().x() );
                yAnimationPositionIncrement = (1.0/100)*(animatingArray[processArrayIndex]->pos().y() - limitY);
            }

            incrementSet = true;
        }

        qreal x;
        qreal y;

        if(forward && down){
            x = animatingArray[processArrayIndex]->pos().x() + xAnimationPositionIncrement;
            y = animatingArray[processArrayIndex]->pos().y() + yAnimationPositionIncrement;
        }else if(!forward && !down){
            x = animatingArray[processArrayIndex]->pos().x() - xAnimationPositionIncrement;
            y = animatingArray[processArrayIndex]->pos().y() - yAnimationPositionIncrement;
        }else if(!forward && down){
            x = animatingArray[processArrayIndex]->pos().x() - xAnimationPositionIncrement;
            y = animatingArray[processArrayIndex]->pos().y() + yAnimationPositionIncrement;
        }else if(forward && !down){
            x = animatingArray[processArrayIndex]->pos().x() + xAnimationPositionIncrement;
            y = animatingArray[processArrayIndex]->pos().y() - yAnimationPositionIncrement;
        }

//        qDebug()<< x<<' '<<y;

        if(forward && down){
            if(x > limitX ){
                x = limitX;
            }
            if(y > limitY ){
                y = limitY;
            }
        }else if(!forward && !down){
            if(x < limitX ){
                x = limitX;
            }
            if(y < limitY ){
                y = limitY;
            }
        } else if(!forward && down){
            if(x < limitX ){
                x = limitX;
            }
            if(y > limitY ){
                y = limitY;
            }
        } else if(forward && !down){
            if(x > limitX ){
                x = limitX;
            }
            if(y < limitY ){
                y = limitY;
            }
    }

        // set the new position
        this->animatingArray[processArrayIndex]->setPos(x, y);
//        this->processReadyArray[0]->boundingRect().setX(x);
//        this->processReadyArray[0]->boundingRect().setY(y);
        // check if the circle has reached the destination
        if (x == limitX  && y == limitY) {
            // stop the timer
            incrementSet = false;
            startReady->setEnabled(true);
            readyRun->setEnabled(true);
            runReady->setEnabled(true);
            runWait->setEnabled(true);
            waitReady->setEnabled(true);
            runStop->setEnabled(true);
            timer->stop();
        }
        scene->update();
    }
    void on_unistiProces_clicked();
};
#endif // DIALOG_H
