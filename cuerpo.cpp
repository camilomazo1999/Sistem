#include "cuerpo.h"
cuerpo::cuerpo(double pos_x, double pos_y, double v_x, double v_y, double mas, double r):escala(0.035)
{
    particula = new calculos(pos_x,pos_y,v_x, v_y,mas,r);
}

void cuerpo::actualizar(double delta)
{
    particula->actualizar_variables(delta);
    setPos(particula->getPosicion_x()*escala,-particula->getPosicion_y()*escala);

}

void cuerpo::setescala(double esca)
{
    escala = esca;
}

calculos *cuerpo::getParticula() const
{
    return particula;
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-1*escala*particula->getRadio(),-1*escala*particula->getRadio(),2*escala*particula->getRadio(),2*escala*particula->getRadio());
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(particula->getMasa()>10000)
    {
        painter->setBrush(Qt::red);
        painter->drawEllipse(boundingRect());
    }
    else if(particula->getMasa()<1000)
    {
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());
    }
}
