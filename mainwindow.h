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
#include <QBrush>
#include <QPen>
#include <QVector>
#include <QPushButton>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <fstream>
#include <QLabel>



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
    void stop();
	void testbtclicked();
	void showresult(int);
private:
    QGraphicsScene *board;
    double px = 25.0;
    double rx = px/10;
    double rc = rx*5;
    Ui::MainWindow *ui;
    void setboard();
    void setpiece();
    void newgame();
	void launch();
    QVector<chess*>piece;
    QPushButton *ng,*edit,*testbt, *closebt;
    QGraphicsView *my_view;
};

#endif // MAINWINDOW_H
