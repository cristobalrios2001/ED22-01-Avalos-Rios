#include <iostream>

class BinaryTree {
private: 
	struct NodoArbol* raiz;
	NodoArbol* insertar(NodoArbol*nodo);
	double distancia();
public:
	BinaryTree() {
		raiz = nullptr;
	}
};