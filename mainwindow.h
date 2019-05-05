#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chess.h"
#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QLine>
#include <QRectF>
#include <QGraphicsSimpleTextItem>
#include <QBrush>
#include <QPen>
#include <QVector>
#include <QPushButton>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <fstream>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void ngclicked();
    void editclicked();
private:
    QGraphicsScene *board;
    double px = 25.0;
    double rx = px/10;
    double rc = rx*5;
    Ui::MainWindow *ui;
    void setboard();
    void setpiece();
    void newgame();
    void test(QVector<int>&);
    chess *p, *p2;
    QVector<chess*>piece;
    QPushButton *ng,*edit;
    QGraphicsView *my_view;
};

#endif // MAINWINDOW_H
