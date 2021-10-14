#ifndef CALCULOS_H
#define CALCULOS_H
#include <math.h>

class calculos
{
private:
    double posicion_x;
    double posicion_y;
    double velocidad_x;
    double velocidad_y;

    double distancia;
    double masa;
    double radio;

    double aceleracion_x;
    double aceleracion_y;

    double fuerza_gravitacion;


public:
    calculos(double pos_x, double pos_y, double vel_x, double vel_y, double mass, double redio);


    double getPosicion_x() const;
    double getPosicion_y() const;
    double getMasa() const;
    double getRadio() const;

    void aceleraciones(double pos_x_2,double pos_y_2,double masa_2);
    void actualizar_variables(double delta);


};

#endif // CALCULOS_H
