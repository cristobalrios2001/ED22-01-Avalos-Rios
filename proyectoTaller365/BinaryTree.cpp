#include <iostream>
#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
	this->raiz = new NodoArbol(175);
}

NodoArbol* BinaryTree::getRaiz() {
	return this->raiz;
}

void BinaryTree::insertar(NodoArbol* nodo, int centroide) {
	if (centroide < nodo->centroide) {
		if (nodo->izq == nullptr) {
			nodo->izq = new NodoArbol(centroide);
		}
		else {
			insertar(nodo->izq, centroide);
		}
	}
	else if (centroide > nodo->centroide) {
		if (nodo->der == NULL) {
			nodo->der = new NodoArbol(centroide);

		}
		else {
			insertar(nodo->der, centroide);
		}
	}
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



int  BinaryTree::cuentaNodos(NodoArbol* nodo, int contador) {
	if (isLeaf(nodo)) {
		contador++;
	}
	if (nodo->izq != nullptr) {		
		contador = cuentaNodos(nodo->izq, contador);
		contador++;

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

void BinaryTree::eliminarBinaryTree(NodoArbol* raiz)
{
	
	if (raiz == nullptr) {
		return;
	}

	
	eliminarBinaryTree(raiz->izq);
	eliminarBinaryTree(raiz->der);

	
	delete raiz;

	
	raiz = nullptr;
}
