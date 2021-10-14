#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    delta = 0.1;
    escena = new QGraphicsScene(this);
    escena->setSceneRect(-280,-225,581,481);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);

    timer = new QTimer();
    timer->stop();

    connect(timer, SIGNAL(timeout()),this,SLOT(simulacion()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_1_clicked()
{
    double x = ui->posx_2->text().toDouble();
    double y = ui->posy_2->text().toDouble();
    double r = ui->redio_2->text().toDouble();
    double m = ui->mas_2->text().toDouble();
    double vx = ui->velx_2->text().toDouble();
    double vy = ui->vely_2->text().toDouble();

    planeta = new cuerpo(x,y,vx,vy,m,r);

    sistema.push_back(planeta);
}

void MainWindow::on_btn_2_clicked()
{
    for (int i=0;i<sistema.size() ;i++ ) {
        sistema.at(i)->actualizar(delta);
        escena->addItem(sistema.at(i));
    }
}

void MainWindow::simulacion()
{
    copiar.setFileName("valores.txt");
    copiar.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
    QTextStream stream(&copiar);
    for (int i=0;i<sistema.size() ;i++ )
    {
        for (int j=0; j<sistema.size(); j++ )
        {
            if(i!=j)
            {

                sistema.at(i)->getParticula()->aceleraciones(sistema.at(j)->getParticula()->getPosicion_x(),sistema.at(j)->getParticula()->getPosicion_y(),sistema.at(j)->getParticula()->getMasa());
                sistema.at(i)->actualizar(delta);
            }
        }

    }



    for(int k = 0; k < sistema.size(); k++)
    {
        stream<<sistema.at(k)->getParticula()->getPosicion_x()<<"          "<< sistema.at(k)->getParticula()->getPosicion_y()<<"          ";
    }
    stream<<"\n";
    copiar.close();
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(delta);
}
