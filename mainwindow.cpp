#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->view->scale(3,3);
    ui->view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->view->centerOn(5*px,5.5*px);
    ng = new QPushButton("new game",this);
    ng->setGeometry(10*px,10*px,px*2,px*2);
    edit = new QPushButton("edit", this);
    edit->setGeometry(100,200,100,100);
    connect(ng,SIGNAL(clicked()), this, SLOT(ngclicked()));
    connect(edit, SIGNAL(clicked()), this, SLOT(editclicked()));
    setboard();
    ui->view->setScene(board);
    //my_view = new QGraphicsView(board);
    //my_view->setScene(board);
    //my_view->show();
}
void QWidget::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
{
    qDebug() <<"mainwindow" << mouseEvent->pos();
}


void MainWindow::test()
{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    QRectF rec(5*px-rc,1*px-rc,2*rc,2*rc);
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(rec);
    circle->setBrush(brush);
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem("帥",circle);
    circle->setPen(pen);
    text->setPen(pen);
    text->setPos(5*px-rc/2,1*px-15*rc/16);
    board->addItem(circle);
    ui->view->setScene(board);
}

void MainWindow::setboard()
{
    board = new QGraphicsScene();
    //for lines
    QVector<QLineF> L ;
    QLineF l;
    for(int i = 1; i <= 10;i++)
    {
        l.setLine(1*px, i*px, 9*px, i*px);
        L.append(l);
    }
    for(int i = 1; i <= 9;i++)
    {
        l.setLine(i*px, 1*px, i*px, 5*px);
        L.append(l);
        l.setLine(i*px, 6*px, i*px, 10*px);
        L.append(l);
    }
    l.setLine(4*px, 1*px, 6*px, 3*px);
    L.append(l);
    l.setLine(6*px, 1*px, 4*px, 3*px);
    L.append(l);
    l.setLine(4*px, 10*px, 6*px, 8*px);
    L.append(l);
    l.setLine(6*px, 10*px, 4*px, 8*px);
    L.append(l);
    QPen boardpen(QBrush(),3);
    boardpen.setColor(Qt::black);
    for(int i = 0; i < L.size();i++)
        board->addLine(L.at(i),boardpen);
    boardpen.setWidth(6);
    board->addRect(0*px, 0*px, 10*px, 11*px, boardpen);
    boardpen.setWidth(3);
    //for circles
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    board->addEllipse(2*px-rx, 3*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(2*px-rx, 8*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(8*px-rx, 3*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(8*px-rx, 8*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(1*px-rx, 4*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(3*px-rx, 4*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(5*px-rx, 4*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(7*px-rx, 4*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(9*px-rx, 4*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(1*px-rx, 7*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(3*px-rx, 7*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(5*px-rx, 7*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(7*px-rx, 7*px-rx, rx*2, rx*2, boardpen, brush);
    board->addEllipse(9*px-rx, 7*px-rx, rx*2, rx*2, boardpen, brush);

    //qDebug() << L.size();
}

void MainWindow::newgame()
{
    QVector<int>x = {5,6,4,3,7,2,8,1,9,2,8,1,3,5,7,9,5,6,4,3,7,2,8,1,9,2,8,1,3,5,7,9};
    QVector<int>y = {10,10,10,10,10,10,10,10,10,8,8,7,7,7,7,7,1,1,1,1,1,1,1,1,1,3,3,4,4,4,4,4};
    QVector<QString> ch ={"帥","仕","仕","相","相","傌","傌","俥","俥","炮","炮","兵","兵","兵","兵","兵","將","士","士","象","象","馬","馬","車","車","砲","砲","卒","卒","卒","卒","卒"};
    QColor my_color(Qt::red);
    for(int i = 0; i < 32; i++)
    {
        chess* p = new chess(x[i],y[i],ch[i],my_color);
        piece.push_back(p);
        board->addItem(piece.at(i));
        if(i == 15)
            my_color = Qt::black;
    }
}

    /*
    帥0   (將)16
    仕1 2 (士)17 18
    相3 4 (象)19 20
    俥5 6 (車)21 22
    傌7 8 (馬)23 24
    炮9 10(砲)25 26
    兵11 15 (卒)27 31
    */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ngclicked()
{
   newgame();
   delete ng;
   delete edit;
   chess::setrecord(piece);
}

void MainWindow::editclicked()
{
   delete edit;
   delete ng;


}
