#include "chess.h"
#define specialcolor Qt::green
#define rednum 1
#define blacknum 2
#define blackdir 1
#define reddir -1 
double chess::px = 25;
double chess::rx = px/10;
double chess::rc = rx*5;
short chess::position[10][11] = {{0}};
QGraphicsScene* chess::board = nullptr;
QGraphicsView * chess::view = nullptr;
//  1 ~ 9  1 ~ 10
bool chess::flag = false;
QVector<chess*> chess::piece;
QVector<chess*> chess::temp;

void chess::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{	
	int i;
	static chess* ptr = nullptr;
	if(!flag)	
	{
		ptr = this;
		if(ch == "帥" || ch ==  "將")
			move1();
		else if(ch == "仕" || ch == "士")
			move2();
		else if(ch == "相" || ch == "象")
			move3();
		else if(ch == "俥" || ch == "車") 
			move4();
		else if(ch == "傌" || ch == "馬") 
			move5();
		else if(ch == "炮" || ch == "砲") 
			move6();
		else if(ch == "兵" || ch == "卒") 
			move7();
		flag = true;
		for(i = 0; i < temp.size(); i++)
			board->addItem(temp.at(i));
		view->setScene(board);
	}
	else
	{
		if(ptr != this && this->my_color == specialcolor)
		{
			battle();
			position[ptr->x][ptr->y] = 0;
			ptr->changePos(this->x, this->y);
			ptr->my_color == Qt::red ? position[this->x][this->y] = rednum:position[this->x][this->y] = blacknum;
		}
		qDebug() << "delete " << temp.size();
		while(!temp.isEmpty())
		{
			delete temp[0];
		 	temp.removeFirst();
		}
		flag = false;
		ptr = nullptr;
	}
}

void chess::move1()
{
	qDebug() << "move1 called";
	int i;
	int me = 0;
	int dir = 0;
	chess*p;
	if(my_color == Qt::red)
	{
		me = rednum;
		dir = reddir;
		for(i = 0; i < piece.size();i++)
			if(piece.at(i)->ch == "將")
				break;
		if(piece.at(i)->ch == "將" && piece.at(i)->x == x)
		{
			bool wangjianwang = true;
			for(int j = piece.at(i)->y + 1; j < this->y;j++)
				if(position[x][j] != 0)
					wangjianwang = false;
			if(wangjianwang)
			{
				p = new chess(piece.at(i)->x, piece.at(i)->y, ch, specialcolor);
				temp.append(p);
			}
		}
	}
	else
	{
		me = blacknum;
		dir = blackdir;
		for(i = 0; i < piece.size();i++)
			if(piece.at(i)->ch == "帥")
				break;
		if(piece.at(i)->ch == "帥" && piece.at(i)->x == x)
		{
			bool wangjianwang = true;
			for(int j = piece.at(i)->y - 1; j > this->y;j--)
				if(position[x][j] != 0)
					wangjianwang = false;
			if(wangjianwang)
			{
				p = new chess(piece.at(i)->x, piece.at(i)->y, ch, specialcolor);
				temp.append(p);
			}
		}
	}
		if(ly + 1 <= 3 && position[x][y+dir] != me)
		{
			p = new chess(x, y+dir, ch, specialcolor);
			temp.append(p);
		}
		if(ly - 1 >= 1 && position[x][y-dir] != me)
		{
			p = new chess(x, y-dir, ch, specialcolor);
			temp.append(p);
		}
		if(lx + 1 <= 6 && position[x+dir][y] != me)
		{
			p = new chess(x+dir, y, ch, specialcolor);
			temp.append(p);
		}
		if(lx - 1 >= 4 && position[x-dir][y] != me)
		{
			p = new chess(x-dir, y, ch, specialcolor);
			temp.append(p);
		}
}

void chess::move2()
{
	qDebug() << "move2 called";

}
void chess::move3()
{
	qDebug() << "move3 called";

}
void chess::move4()
{
	qDebug() << "move4 called";

}
void chess::move5()
{
	qDebug() << "move5 called";

}
void chess::move6()
{
	qDebug() << "move6 called";

}
void chess::move7()
{
	qDebug() << "move7 called";

}

void chess::battle()
{
 	int i;
	for(i = 0; i < piece.size();i++)
		if(this->x == piece.at(i)->x && this->y == piece.at(i)->y)
		{
			qDebug() << piece.at(i)->ch;
			piece.at(i)->changePos(0,0);
			update(*piece.at(i)->rect);
			//piece[i]->status = false;
			//piece[i]->hide();
			if(piece.at(i)->ch == "帥" || piece.at(i)->ch ==  "將")
				gameover(piece.at(i)->my_color);//lose color
		}
}

void chess::gameover(QColor color)
{
 	qDebug() << color << "lose";
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
	x(x), y(y),ch(ch),paintx(x),painty(y), my_color(my_color),status(status)
{
	rect = new QRectF(x*px-rc,y*px-rc,2*rc,2*rc);
	switch_local_coordinate();
}

chess::~chess()
{
}

void chess::changePos(int newx, int newy)
{
	int dx = newx - x;
	int dy = newy - y;
	this->moveBy(dx*px, dy*px);
	x = newx;
	y = newy;
	switch_local_coordinate();
}

void chess::setrecord(const QVector<chess *>& p)
{
	for(int i = 0; i < p.size(); i++)
	{
		piece.push_back(p.at(i));
		if(piece.at(i)->my_color == Qt::red)
			position[piece.at(i)->x][piece.at(i)->y] = rednum;//1
		else
			position[piece.at(i)->x][piece.at(i)->y] = blacknum;//2
	}
}

void chess::switch_local_coordinate()
{
	if(my_color == Qt::red)
	{
		lx = 10 - x;
		ly = 11 - y;
	}
	else
	{
		lx = x;
		ly = y;
	}
}

void chess::setboard(QGraphicsScene* board, QGraphicsView *view)
{
 	chess::board = board;
	chess::view = view;
}
