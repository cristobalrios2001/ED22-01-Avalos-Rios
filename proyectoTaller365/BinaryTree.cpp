#include <iostream>
#include "NodoArbol.hpp"
#include "BinaryTree.hpp"



void BinaryTree::insertar(float centroide) {
	raiz = insertar(raiz, centroide);
}
NodoArbol* BinaryTree::insertar(NodoArbol* nodo, float centroide) {
	if (nodo == nullptr) {
		nodo = new NodoArbol();
		nodo->centroide = centroide;
		nodo->izq = nullptr;
		nodo->der = nullptr;
	}

	return nodo;
}
