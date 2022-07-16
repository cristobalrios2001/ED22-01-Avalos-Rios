#include <iostream>
#include "NodoArbol.hpp"
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

class BinaryTree {
	NodoArbol* raiz;
public:
	BinaryTree();
	void insertar(NodoArbol* nodo, int centroide);
	NodoArbol* getRaiz();
	int cuentaNodos(NodoArbol* nodo, int contador);
	bool isLeaf(NodoArbol* nodo);
	int cantEntrantes();
	int cantSalientes();
	void show(NodoArbol* raiz, int cont);
};
