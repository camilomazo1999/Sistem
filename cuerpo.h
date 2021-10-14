#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <calculos.h>
#include <QPainter>

class cuerpo: public QGraphicsItem
{
private:
    calculos *particula;
    double escala;


public:
    cuerpo(double pos_x, double pos_y, double v_x, double v_y, double mas, double r);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);


    calculos *getParticula() const;
    void actualizar(double delta);
    void setescala(double esca);
};

#endif // CUERPO_H
