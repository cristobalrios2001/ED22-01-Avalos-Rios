// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html

#include "Detector.hpp"
#include "Persona.hpp"
#include "Nodo.hpp"
#include "Linked.hpp"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace cv;
using namespace std;

struct nodoArbol {
    float dato;
    nodoArbol* der;
    nodoArbol* izq;
};
typedef struct nodoArbol nodo;



double calcularDistancia(Persona p, int distX, int distY) {
    int distPX = p.getXCentro();
    int distPY = p.getXCentro();

    double distancia = sqrt(pow(distX - distPX, 2) + pow(distY - distPY, 2));
    return distancia;
}

int main(int argc, char** argv)
{
    Linked* listaEntrada = new Linked();
    Linked* listaSalida = new Linked();

    Detector detector;
    Mat imagen;
    imagen = imread("images/image0292.png");
    detector.toggleMode();
    cout << detector.modeName() << endl;

    vector<Persona> found = detector.detect(imagen);
    int contadorEntrada = 0;
    int contadorSalida = 0;
    for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
    {
        Persona& p = *i;
        if (p.getXCentro() > 175) {
            listaEntrada->addNodo(p); // Personas Entrando
        }
        else {
            listaSalida->addNodo(p); // Personas Saliendo
        }

        //cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl; //coordenadas de las personas(centroides)
        //detector.adjustRect(r);
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 0, 255), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);//centroide
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);

        for (int i = 0; i < listaEntrada->getSize(); i++) {
            Persona personaI = listaEntrada->getI(i);
            double distancia = calcularDistancia(personaI, p.getXCentro(), p.getYCentro());//esta comparando la misma persona
            if (distancia < 0.1) { //ver distancia
                personaI.setXCentro(p.getXCentro());
                personaI.setYCentro(p.getYCentro());
            }
        }
        for (int i = 0; i < listaSalida->getSize(); i++) {
            Persona personaI = listaSalida->getI(i);
            double distancia = calcularDistancia(personaI, p.getXCentro(), p.getYCentro());
            if (distancia < -0.1) {
                personaI.setXCentro(p.getXCentro());
                personaI.setYCentro(p.getYCentro());
            }
        }


        if (p.getXCentro() > 175) {
            contadorEntrada++;
        }
        else {
            contadorSalida++;
        }
    }

    Point p1(175, 0), p2(175, 300);//Linea

    int time = 1;
    line(imagen, p1, p2, Scalar(255, 0, 0), time, LINE_8);
    imshow("People detector", imagen);

    cout << "Entraron: " << contadorEntrada << endl;
    cout << "Salieron: " << contadorSalida << endl;

    float veloEntra = (float)contadorEntrada / 3600;
    float veloSalida = (float)contadorSalida / 3600;

    cout << "La velocidad de las personas que entran son :" << veloEntra << " segundos" << endl;
    cout << "La velocidad de las persona que salen: " << veloSalida << " segundos" << endl;

    waitKey(0);
    
    return 0; 
}



void menu() {
    cout << "Bienvenido a las historias de usuario " << endl;
    cout << "Ingrese la opcion que desea realizar: ";
    cout << "1) Detectar a las personas" << endl;
    cout << "2)Cantidad de personas que han entrado" << endl;
    cout << "3)Cantidad de personas que han salido" << endl;
    cout << "4)Velocidad de las personas que han entrado" << endl;
    cout << "5)Velocidad de las personas que han salido" << endl;
}