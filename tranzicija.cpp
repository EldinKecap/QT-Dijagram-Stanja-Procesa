#include "tranzicija.h"

Tranzicija::Tranzicija(int duzina, int rotacija, int x, int y)
{
    this->duzina = duzina;
    this->rotacija = rotacija;
    this->x = x;
    this->y = y;
}

void Tranzicija::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget ){
       Q_UNUSED(option);
       Q_UNUSED(widget);
    // Set the pen and brush for the arrow
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(Qt::green);
    //this->setPos(100,100);
    // Define the points for the arrow
    QVector<QPointF> points;
    //points << QPointF(0, 20) << QPointF(0, 0)  << QPointF(100, 0)  << QPointF(100, -10) << QPointF(110, 10)  << QPointF(100, 30) << QPointF(100, 20);
    points << QPointF(0, 15) << QPointF(0, 0)  << QPointF(this->duzina, 0) << QPointF(this->duzina, -10) << QPointF(this->duzina+10, 7 ) << QPointF(this->duzina, 25)<< QPointF(this->duzina, 15) << QPointF(0, 15);
    // Create a QPainterPath object for the arrow
    QPainterPath path;
    path.addPolygon(QPolygonF(points));
    // Rotate the arrow by 45 degrees
    painter->translate(this->x,this->y);
    painter->rotate(this->rotacija);
    // Draw the arrow using the QPainterPath object
    painter->drawPath(path);

   }

