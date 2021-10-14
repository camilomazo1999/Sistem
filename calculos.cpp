#include "calculos.h"


calculos::calculos(double pos_x, double pos_y, double vel_x, double vel_y, double mass, double redio)
{
    posicion_x = pos_x;
    posicion_y = pos_y;

    velocidad_x = vel_x;
    velocidad_y = vel_y;

    aceleracion_x = 0;
    aceleracion_y = 0;

    masa = mass;
    radio = redio;

    fuerza_gravitacion =  6.67384*(pow(10,-11));
}

double calculos::getMasa() const
{
    return masa;
}

double calculos::getRadio() const
{
    return radio;
}
double calculos::getPosicion_y() const
{
    return posicion_y;
}

double calculos::getPosicion_x() const
{
    return posicion_x;
}

void calculos::aceleraciones(double pos_x_2,double pos_y_2,double masa_2)
{

    distancia = pow(pow((pos_y_2-posicion_y),2)+pow((pos_x_2-posicion_x),2),1/2);

    aceleracion_x = fuerza_gravitacion*masa_2*(pos_x_2-posicion_x)/pow(distancia,2);
    aceleracion_y = fuerza_gravitacion*masa_2*(pos_y_2-posicion_y)/pow(distancia,2);

}

void calculos::actualizar_variables(double delta)
{

    velocidad_x = velocidad_x + (aceleracion_x*delta);
    velocidad_y = velocidad_y +(aceleracion_y*delta);
    posicion_x = posicion_x + (velocidad_x*delta);
    posicion_y = posicion_y + (velocidad_y*delta);

}
