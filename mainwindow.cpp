#include "mainwindow.h"
#include "ui_mainwindow.h"
#define px 75.0
#define rx px/12

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setboard();
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
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    for(int i = 0; i < L.size();i++)
        board->addLine(L.at(i),pen);
    pen.setWidth(6);
    board->addRect(0*px, 0*px, 10*px, 11*px, pen);
    pen.setWidth(3);
    //for circles
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    board->addEllipse(2*px-rx, 3*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(2*px-rx, 8*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(8*px-rx, 3*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(8*px-rx, 8*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(1*px-rx, 4*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(3*px-rx, 4*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(5*px-rx, 4*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(7*px-rx, 4*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(9*px-rx, 4*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(1*px-rx, 7*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(3*px-rx, 7*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(5*px-rx, 7*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(7*px-rx, 7*px-rx, rx*2, rx*2, pen, brush);
    board->addEllipse(9*px-rx, 7*px-rx, rx*2, rx*2, pen, brush);

    ui->view->centerOn(5*px,5.5*px);
    //qDebug() << L.size();
}
MainWindow::~MainWindow()
{
    delete ui;
}
