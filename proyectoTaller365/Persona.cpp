#include "Persona.h"
#include <ctime>
#include <cstdlib>

Persona::Persona() {
    srand((unsigned)time(0));
    id = rand();
}

Persona::Persona(cv::Rect& r) {//Persona recive un rectangulo
    xComienzo = r.x;
    yComienzo = r.y;
    xFin = r.x + r.width;
    yFin = r.y + r.height;
    xCentro = r.x + ((float)r.width / 2.0);//calculo centroides
    yCentro = r.y + ((float)r.height / 2.0);
}
int Persona::getXComienzo() {
    return xComienzo;
}

int Persona::getYComienzo() {
    return yComienzo;
}

int Persona::getXFin() {
    return xFin;
}

int Persona::getYFin() {
    return yFin;
}

int Persona::getXCentro() {
    return xCentro;
}
int Persona::getYCentro() {
    return yCentro;
}
int Persona :: getID() {
    return id;
}