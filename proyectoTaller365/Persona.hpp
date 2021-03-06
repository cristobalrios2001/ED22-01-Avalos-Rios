#pragma once
#ifndef PERSONA_H
#define PERSONA_H


#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
class Persona
{
private:
    int xComienzo;
    int yComienzo;
    int xFin;
    int yFin;
    int xCentro;
    int yCentro;
    int id;
public:
    Persona();
    Persona(cv::Rect&);

    int getXComienzo();
    int getYComienzo();
    int getXFin();
    int getYFin();
    int getXCentro();
    int getYCentro();
    int getID();
    void setXCentro(int x);
    void setYCentro(int y);
};

#endif