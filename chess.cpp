#include "chess.h"
double chess::px = 25;
double chess::rx = px/10;
double chess::rc = rx*5;
short chess::position[10][11] = {{0}};
void chess::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    this->moveBy(0,-px);
    y--;
    static int counter = 0;
    counter++;
    if(counter%3 == 0) hide();
    qDebug() << x << " " << y << ch;
    update(*rect);
}

void chess::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(status)
    {
        QPen pen;
        pen.setColor(my_color);
        pen.setWidth(1);
        QBrush brush(Qt::yellow);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawEllipse(*rect);
        QPointF pf(paintx*px-rc/2, painty*px+3*rc/8);
        painter->drawText(pf,ch);
    }
}

QRectF chess::boundingRect() const
{
    return *rect;
}

chess::chess(int x, int y, QString ch, QColor my_color, bool status):
        x(x), y(y),paintx(x),painty(y), ch(ch), my_color(my_color),status(status)
{
    rect = new QRectF(x*px-rc,y*px-rc,2*rc,2*rc);
}

chess::~chess()
{
}

void chess::changePos(int dx, int dy)
{
    x+=dx;
    y+=dy;
    this->moveBy(dx*px, dy*px);
}

void chess::setrecord(const QVector<chess *>& piece)
{
    for(int i = 0; i < 32; i++)
    {
        if(piece.at(i)->my_color == Qt::red)
            position[piece.at(i)->x][piece.at(i)->y] = 1;
        else
            position[piece.at(i)->x][piece.at(i)->y] = 2;
    }
}
