#include <iostream>
#include "NodoArbol.hpp"
#include "BinaryTree.hpp"


void BinaryTree::insertar(int centroide) {
	if (raiz == nullptr) {
		raiz->centroide = centroide;
	}
}

void BinaryTree::insertarNodo(NodoArbol* nodo, int centroide) {
	if (nodo == nullptr) {
		nodo = new NodoArbol();
		nodo->centroide = centroide;
		nodo->izq = nullptr;
		nodo->der = nullptr;
	}
	else if (centroide < nodo->centroide) {
		if (nodo->izq == NULL) {
			nodo->izq = new NodoArbol();
			nodo->izq->centroide = centroide;
		}
		else {
			insertarNodo(nodo->izq, centroide);
		}
	}
	else if (centroide > nodo->centroide) {
		if (nodo->der == NULL) {
			nodo->der = new NodoArbol();
			nodo->der->centroide = centroide;
		}
		else {
			insertarNodo(nodo->der, centroide);
		}
	}
}
int BinaryTree:: cantEntrantes() {
	if (raiz != nullptr) {
		NodoArbol* n = raiz->izq;
		

		
	}
}

void BinaryTree :: inorden(NodoArbol*nodo) {
	if (nodo != NULL) {
		inorden(nodo->izq);
		printf("%d,", nodo->centroide);
		inorden(nodo->der);
	}
}

void BinaryTree::show(NodoArbol* raiz,int cont) {
	if (raiz == NULL) {
		return;
	}
	else {
		show(raiz->der, cont + 1);
		for (int i = 0; i < cont; i++) {
			cout << "     ";
		}
		cout << raiz->centroide << endl;
		show(raiz->izq, cont + 1);
	}
}