#include <iostream>
#include "NodoArbol.hpp"
#include "BinaryTree.hpp"


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
void BinaryTree::setRaiz(int centroide) {
	raiz->centroide = centroide;
}

int BinaryTree::cantEntrantes() {
	int contador = 0;
	if (raiz != nullptr) {
		NodoArbol* n = raiz->izq;
		contador = cuentaNodos(n, contador);
	}
	return contador;
}

int BinaryTree::cantSalientes() {
	int contador = 0;
	if (raiz != nullptr) {
		NodoArbol* n = raiz->der;
		contador = cuentaNodos(n, contador);
	}
	return contador;
}



int  BinaryTree::cuentaNodos(struct NodoArbol* nodo, int contador) {
	if (isLeaf(nodo)) {
		contador++;
	}
	if (nodo->izq != nullptr) {		
		contador = cuentaNodos(nodo->izq, contador);	

	}
	if (nodo->der != nullptr) {
		contador = cuentaNodos(nodo->der, contador);		
		contador++;
	}
	return contador;
}

bool  BinaryTree::isLeaf(NodoArbol* nodo) {
	if (nodo->der == nullptr && nodo->izq == nullptr)
		return true;
	return false;
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
