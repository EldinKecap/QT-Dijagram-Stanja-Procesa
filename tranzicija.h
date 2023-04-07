#ifndef TRANZICIJA_H
#define TRANZICIJA_H
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QPainter>

class Tranzicija: public QObject, public QGraphicsPolygonItem
{
public:
    Tranzicija(int duzina, int rotacija, int x, int y);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget );

private:
    int duzina;
    int rotacija;
    int x;
    int y;
};

#endif // TRANZICIJA_H
