// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html

#include "Detector.hpp"
#include "Persona.hpp"
#include "Nodo.hpp"
#include "Linked.hpp"
#include "BinaryTree.hpp"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace cv;
using namespace std;

double calcularDistancia(Persona p, int distX, int distY) {
    int distPX = p.getXCentro();
    int distPY = p.getXCentro();

    double distancia = sqrt(pow(distX - distPX, 2) + pow(distY - distPY, 2));
    return distancia;
}
void cargarImg(BinaryTree* arbol) {
    Mat imagen;
    Detector detector;
    imagen = imread("images/images0292.png");
    detector.toggleMode();
    cout << detector.modeName() << endl;
    vector<Persona> found = detector.detect(imagen);
    for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
    {
        Persona& p = *i;
        arbol->insertar(arbol->getRaiz(), p.getXCentro());
        //cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl;
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
    }
    Point p1(175, 0), p2(175, 300);
    int time = 1;
    line(imagen, p1, p2, Scalar(255, 0, 0), time, LINE_8);

    imshow("People detector", imagen);
}

void menu(BinaryTree* arbol, double tiempoT) {
    String resp;
    int opcion;
    String salida = "No";
    bool cierre = true;
    while (salida != "Si") {
        cout << "Bienvenido al Sistema de Vigilancia ACME " << endl;
        cout << "Introduzca el perfil con el cual ingresara al sistema (Guardia) o (Administrador): ";
        cin >> resp;
        while (resp != "Guardia" && resp != "Administrador") {
            cout << "Bienvenido al Sistema de Vigilancia ACME " << endl;
            cout << "Introduzca el perfil con el cual ingresara al sistema (Guardia) o (Administrador): ";
            cin >> resp;
        }
        if (resp == "Administrador") {
            cout << "obteniendo imagenes a analizar" << endl;
            cout << "Saliendo del modo Adminsitrador" << endl;
        }
        else{
            while (cierre) {
                cout << endl;
                cout << "Desplegando opciones desponibles....." << endl;
                cout << "1) Detectar a las personas" << endl;
                cout << "2)Cantidad de personas que han entrado" << endl;
                cout << "3)Cantidad de personas que han salido" << endl;
                cout << "4)Velocidad de las personas que han entrado" << endl;
                cout << "5)Velocidad de las personas que han salido" << endl;
                cout << "6)Salir del menu Guardia" << endl;
                cout << endl;
                cout << "Introduzca la opcion que desee: ";
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    cout << "Detectando personas..." << endl;
                    //cargarImg(arbol);
                    break;
                case 2:
                    cout << "La cantidad de personas que han entrado son: " << endl;
                    cout << arbol->cantEntrantes();
                    break;
                case 3:
                    cout << "La cantidad de personas que han salido son: " << endl;
                    cout <<arbol->cantSalientes();
                    break;
                case 4:
                    cout << "La velocidad de las personas que han entrado es: " << endl;
                    cout << arbol->cantEntrantes()/ tiempoT;
                    break;
                case 5:
                    cout << "La velocidad de las personas que han salido es: " << endl;
                    cout << arbol->cantEntrantes()/ tiempoT;
                    break;
                case 6:
                    cout << "Saliendo del menu Guardia"<<endl;
                    cierre = false;
                    break;
                default:
                    cout << "Ingrese una de las opciones disponible porfavor......" << endl;
                    break;
                }
            } 
            cout << "Desea salir del sistema (Si) o (No)" << endl;
            cin >> salida;
            while (salida != "Si" && salida != "No") {
                cout << "Desea salir del sistema (Si) o (No)" << endl;
                cin >> salida;
            }
        }
    }
    cout << " SALIENDO DEL SISTEMA......" << endl;
}



void cargarImagenes_Personas(BinaryTree* arbol) {
    vector<string> images;

    time_t now = time(0);
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);
    int Tinicio = timeinfo.tm_hour;
   

    images.push_back("images/images0292.png");//proyectoTaller365/images/image0292.png
    images.push_back("images/images0293.png");//proyectoTaller365/images/image0293.png
    images.push_back("images/images1679.png");//proyectoTaller365/images/image1679.png
    images.push_back("images/images1680.png");//proyectoTaller365/images/image1680.png

    Detector detector;
    Mat imagen;

    for (string im : images) {
        imagen = imread(im);
        vector<Persona> found = detector.detect(imagen);
        for (vector<Persona>::iterator i = found.begin(); i != found.end(); i++) {
            Persona& p = *i;
            arbol->insertar(arbol->getRaiz(), p.getXCentro());

            rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 0, 255), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);//centroide
            circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
            circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
        }
    }

    int Tfinal = timeinfo.tm_hour;
    double tiempoT = (double(Tfinal - Tinicio) / CLOCKS_PER_SEC);
}
/*
void seleccionar_cargarImagenes_Personas(BinaryTree* arbol) {
    vector<string> images;

    time_t now = time(0);
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);
    int Tinicio = timeinfo.tm_hour;
    

    opciones(images);

    Detector detector;
    Mat imagen;

    for (string im : images) {
        imagen = imread(im);
        vector<Persona> found = detector.detect(imagen);
        for (vector<Persona>::iterator i = found.begin(); i != found.end(); i++) {
            Persona& p = *i;
            arbol->insertar(arbol->getRaiz(), p.getXCentro());

            rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 0, 255), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);//centroide
            circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
            circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
        }
    }

    int Tfinal = timeinfo.tm_hour;
    double time = (double(Tfinal - Tinicio) / CLOCKS_PER_SEC);
}
void opciones(vector<string> images) {
    int opcion;
    cout << "Seleccione 1, 2 o 3." << endl;
    
    cout << "Introduzca la opcion que desee: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        images.push_back("images/images0292.png");
        images.push_back("images/images0293.png");
        break;
    case 2:
        images.push_back("images/images1679.png");
        images.push_back("images/images1680.png");        
        break;
    case 3:
        images.push_back("images/images0293.png");
        images.push_back("images/images1679.png");
        break;
    
    default:
        cout << "Ingrese una de las opciones disponible porfavor......(1,2 o 3)" << endl;
        break;
    }
}
*/

double tiempoT =0;
int main(int argc, char** argv)
{    
    BinaryTree* arbol = new BinaryTree();
    //cargarImagenes_Personas(arbol);
    //arbol->show(arbol->getRaiz(),0);
    /*
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
        arbol->insertar(arbol->getRaiz(), p.getXCentro());


        //cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl; //coordenadas de las personas(centroides)
        //detector.adjustRect(r);
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 0, 255), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);//centroide
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);


    }
    Point p1(175, 0), p2(175, 300);
    int time = 1;
    line(imagen, p1, p2, Scalar(255, 0, 0), time, LINE_8);

    imshow("People detector", imagen);*/
    menu(arbol, tiempoT);
    waitKey(0);
    return 0; 
}

