#include <iostream>
#include "NodoArbol.hpp"
#include "BinaryTree.hpp"


void BinaryTree::insertar(int centroide) {
	raiz = insertar(raiz,centroide);
}
NodoArbol* BinaryTree::insertar(NodoArbol* nodo, int centroide) {
	if (nodo == nullptr) {
		nodo = new NodoArbol();
		nodo->centroide = centroide;
		nodo->izq = nullptr;
		nodo->der = nullptr;
	}
	else if (centroide < nodo->centroide) {
		nodo->izq = insertar(nodo->izq, centroide);
	}
	else if (centroide > nodo->centroide) {
		nodo->der = insertar(nodo->der, centroide);
	}
	return nodo;
}
