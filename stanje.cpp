#include "stanje.h"

Stanje::Stanje(int x, int y, QString naslov)
{
    this->x = x;
    this->y = y;
    this->naslov = naslov;
}

void Stanje :: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush yellowBrush(Qt::yellow);
    QBrush grayBrush(Qt::gray);
    painter->setBrush(yellowBrush);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    painter->setPen(outlinePen);

    QRectF rect(x, y, 100, 100);
    painter->drawEllipse(rect);

    QFont font("Arial", 13, QFont::Bold);
    painter->setFont(font);
    painter->drawText(QPointF(x + 30, y + 35), naslov);

    QPainterPath redCekanja;
    painter->setBrush(grayBrush);
    QRectF processContainer(x + 15, y + 55, 15, 15);
    for (int i = 0; i < 5; i++) {
        redCekanja.addRect(processContainer);
        processContainer.translate(processContainer.width(), 0);
    }
    painter->drawPath(redCekanja);
}

