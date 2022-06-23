// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html

#include "Detector.h"
#include "Persona.h"

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include <string>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    Detector detector;
    Mat imagen;
    imagen = imread("images/image0292.png");
    detector.toggleMode();
    cout << detector.modeName() << endl;

    vector<Persona> found = detector.detect(imagen);
    for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
    {
        Persona& p = *i;
        cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ")" << endl;
        //detector.adjustRect(r);
        rectangle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
        circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 3);
        circle(imagen, cv::Point(p.getXComienzo(), p.getYComienzo()), 3, cv::Scalar(255, 0, 255), 2);
        circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
    }

    imshow("People detector", imagen);
    waitKey(0);

    return 0;
}