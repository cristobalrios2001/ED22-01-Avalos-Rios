// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html

#include "Detector.h"
#include "Persona.h"
#include "Nodo.h"
#include "Linked.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    Linked *listaEntrada = new Linked();
    Linked *listaSalida = new Linked();
    
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
        cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl;
        //detector.adjustRect(r);
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 0, 255), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);//centroide
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
        if (p.getXCentro() > 175) {
            contadorEntrada++;
        }
        else {
            contadorSalida++;
        }
    }
    Point p1(175, 0), p2(175, 300);//Linea
    int time = 1;
    line(imagen, p1, p2, Scalar(255, 0,0), time, LINE_8);
    imshow("People detector", imagen);
    cout << "Entraron: "<<contadorEntrada<<endl;
    cout << "Salieron: " << contadorSalida<<endl;
    float veloEntra = (float) contadorEntrada / 3600;
    float veloSalida = (float)contadorSalida / 3600;
    cout << "La velocidad de las personas que entran son :" << veloEntra<<" segundos" << endl;
    cout << "La velocidad de las persona que salen: " << veloSalida<< " segundos" << endl;
    waitKey(0);
    
    Persona* p = new Persona();
    Nodo* n = new Nodo();
    listaEntrada->addNodo(*p);
    listaEntrada->show();
    cout << p->getID();

   

    return 0;

    
}