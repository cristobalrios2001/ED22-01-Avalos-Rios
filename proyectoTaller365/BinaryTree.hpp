#include <iostream>

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

class BinaryTree {
private: 
	struct NodoArbol* raiz;
	NodoArbol* insertar(NodoArbol*nodo,float centroide);
	double distancia();
	void insertar(float centroide);
public:
	BinaryTree() {
		raiz = nullptr;
	}
};