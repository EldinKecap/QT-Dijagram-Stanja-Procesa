#include "tranzicija.h"

Tranzicija::Tranzicija(int duzina, int rotacija, int x, int y)
{
    this->duzina = duzina;
    this->rotacija = rotacija;
    this->x = x;
    this->y = y;
    //setAcceptHoverEvents(true);
}

QRectF Tranzicija::boundingRect() const
{
    QRectF okvir;
    switch(this->rotacija){
    case 50:
        okvir = QRectF(this->x - 10, this->y, 90, 105);
        break;
    case 0:
        okvir = QRectF(this->x , this->y-10, 160, 40);
        break;
    case 180:
        okvir = QRectF(this->x - 160 , this->y-25, 160, 40);
        break;
    case 130:
        okvir = QRectF(this->x-90  , this->y-5 , 90, 100);
        break;
    case 230:
        okvir = QRectF(this->x-90  , this->y-5 , 90, 100);
        break;
    case 310:
        okvir = QRectF(this->x-90  , this->y-5 , 90, 100);
        break;
    }

    return okvir;
}

void Tranzicija::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget ){
       Q_UNUSED(option);
       Q_UNUSED(widget);
    // Set the pen and brush for the arrow
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(Qt::green);
    //HELPER FRAME FOR DRAWING OUT BOUNDING RECT
    QRectF okvir = boundingRect();
    painter->fillRect(okvir,Qt::green);
    // Define the points for the arrow
    QPolygon  points;

    points << QPoint(0, 15) << QPoint(0, 0)  << QPoint(this->duzina, 0) << QPoint(this->duzina, -10) << QPoint(this->duzina+10, 7 ) << QPoint(this->duzina, 25)<< QPoint(this->duzina, 15) << QPoint(0, 15);
    // Create a QPainterPath object for the arrow
    QPainterPath path;
    path.addPolygon(QPolygonF(points));
    // Rotate the arrow by 45 degrees
    painter->translate(this->x,this->y);
    painter->rotate(this->rotacija);
    // Draw the arrow using the QPainterPath object
    painter->drawPath(path);
    painter->setBackground(Qt::red);
    update();
}

void Tranzicija::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  qDebug()<<"awesome";
  QGraphicsItem::mousePressEvent(event);
}


