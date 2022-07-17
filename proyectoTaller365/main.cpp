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
void menu(BinaryTree* arbol, int time) {
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
                    cout << arbol->cantEntrantes()/time;
                    break;
                case 5:
                    cout << "La velocidad de las personas que han salido es: " << endl;
                    cout << arbol->cantEntrantes()/time;
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

int tiempo_contador() {
    
}

float velocidad_Entrada(BinaryTree* arbol) {
    float vel= (float)arbol->cantEntrantes() / tiempo_contador();
    return vel;
}

float velocidad_Salida(BinaryTree* arbol) {
    float vel = (float)arbol->cantSalientes() / tiempo_contador();
    return vel;
}

void cargarImagenes() {

}

int main(int argc, char** argv)
{    
    BinaryTree* arbol = new BinaryTree();
    vector<string> images;
    /*
    double tiempo = 0;
    clock_t inicio, fin;
    inicio = clock();
    //codigo de ejecucion
    fin = clock();
    double time = (double(fin - inicio) / CLOCKS_PER_SEC);
    tiempo = time;
    return tiempo;
    */

    time_t now= time(0);
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);
    int Tinicio = timeinfo.tm_hour;

    images.push_back("Resources/images0292.png");
    images.push_back("Resources/images0293.png");
    images.push_back("Resources/images1679.png");
    images.push_back("Resources/images1680.png");

    Detector detector;
    Mat imagen;
    
    //detector.toggleMode();

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



    cout << detector.modeName() << endl;
    /*
    vector<Persona> found = detector.detect(imagen);  //persona encontrada  
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
    */
    Point p1(175, 0), p2(175, 300);//Linea

    int time = 1;
    line(imagen, p1, p2, Scalar(255, 0, 0), time, LINE_8);
    imshow("People detector", imagen);

    //cout << "Entraron: " << arbol->cantEntrantes() << endl;
    //cout << "Salieron: " << arbol->cantSalientes() << endl;

    

    //cout << "La velocidad de las personas que entran son :" << veloEntra << " segundos" << endl;
    //cout << "La velocidad de las persona que salen: " << veloSalida << " segundos" << endl;

    //arbol->show(arbol->getRaiz(), 0);
    
    menu(arbol, time);
    waitKey(0);
    return 0; 
}

