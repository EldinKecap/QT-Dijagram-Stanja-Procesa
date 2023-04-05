#ifndef STANJE_H
#define STANJE_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsEllipseItem>
#include <QFont>
#include <QString>

class Stanje : public QGraphicsEllipseItem
{
public:
    Stanje(int x,int y, QString naslov);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int x;
    int y;
    QString naslov;
};

#endif // STANJE_H
