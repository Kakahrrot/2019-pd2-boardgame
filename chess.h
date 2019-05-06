#ifndef CHESS_H
#define CHESS_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene> 
#include <QGraphicsView> 
#include <QRectF>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QVector>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QPushButton>

class chess: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    chess(int x, int y, QString ch,QColor my_color,bool status = true);
    chess();
    ~chess();
    void changePos(int x, int y);
	static void setboard(QGraphicsScene* board,QGraphicsView* view);
    static void setrecord(const QVector<chess*>& p);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget );
    QRectF boundingRect()const;
signals:
   void test(int i);
private:
    int x, y, lx, ly;
    QString ch;
    const int paintx, painty;
    QColor my_color;
    const QRectF* rect;
    bool status;
    static double px;
    static double rx;
    static double rc;
    static short position[10][11];
	static QVector<chess*> piece;
	void move1();
	void move2(int mode= 2);
	void move3();
	void move4(int mode = 4);
	void move5();
	void move6();
	void move7();
	bool battle();
	static bool flag;
	void switch_local_coordinate(void);
	static QVector<chess*> temp;
	static QGraphicsScene* board;
	static QGraphicsView * view;
	static void gameover(QColor color);
};
#endif // CHESS_H
