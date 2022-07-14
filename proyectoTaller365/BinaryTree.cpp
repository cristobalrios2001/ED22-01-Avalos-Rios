#include <iostream>
#include "NodoArbol.hpp"
#include "BinaryTree.hpp"


void BinaryTree::insertar(int centroide) {
	raiz = insertar(centroide);
}
NodoArbol* BinaryTree::insertar(NodoArbol* nodo, int centroide) {
	if (nodo == nullptr) {
		nodo = new NodoArbol();
		nodo->centroide = centroide;
		nodo->izq = nullptr;
		nodo->der = nullptr;
	}
	else if (centroide < raiz) {
		insertar(raiz->izq, centroide);
	}
	else if (centroide > raiz) {
		insertar(raiz->der, centroide);
	}

	return nodo;
}
