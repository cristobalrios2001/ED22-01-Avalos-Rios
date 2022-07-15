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
	void insertar(int centroide);
	void insertarNodo(NodoArbol*nodo,int centroide);	
	int cantEntrantes();
	int cuentaNodos(NodoArbol* nodo, int contador);
	bool isLeaf(NodoArbol* nodo);
	int cantSalientes();

	void show(NodoArbol*raiz,int cont);
	BinaryTree() {
		raiz = nullptr;
	}
};
