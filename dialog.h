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

    QVector<int> processStartArray;

    void drawProcess(int x, int y);
};
#endif // DIALOG_H
