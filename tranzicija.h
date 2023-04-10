#ifndef TRANZICIJA_H
#define TRANZICIJA_H
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QRect>

class Tranzicija: public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    Tranzicija(int duzina, int rotacija, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget );

signals:
    void pomjeri_proces();

private:
    int duzina;
    int rotacija;
    int x;
    int y;
    QRect *okvir;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // TRANZICIJA_H
