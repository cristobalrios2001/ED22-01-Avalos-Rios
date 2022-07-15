#include <iostream>

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

class BinaryTree {

public:
	struct NodoArbol* raiz;
	NodoArbol* insertar(NodoArbol*nodo,int centroide);
	void insertar(int centroide);
	BinaryTree() {
		raiz = nullptr;
	}
};
