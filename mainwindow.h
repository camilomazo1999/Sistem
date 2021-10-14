#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QVector>
#include <calculos.h>
#include <cuerpo.h>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <iostream>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_1_clicked();
    void simulacion();
    void on_btn_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    QTimer *timer;
    cuerpo *planeta;

    QVector<cuerpo*>sistema;

    double delta;

    QFile copiar;

};
#endif // MAINWINDOW_H
