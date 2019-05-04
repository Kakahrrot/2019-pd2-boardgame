#ifndef CHESS_H
#define CHESS_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QVector>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>

class chess: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    chess(int x, int y, QString ch,QColor my_color,bool status = true);
    chess();
    ~chess();
    void changePos(int x, int y);
    static void setrecord(const QVector<chess*>&);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget );
    QRectF boundingRect()const;
signals:
   void test(int i);
private:
    int x, y;
    const int paintx, painty;
    QString ch;
    QColor my_color;
    const QRectF* rect;
    bool status;
    static double px;
    static double rx;
    static double rc;
    static short position[10][11];
};
#endif // CHESS_H
