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
		//cout<<nodo->dato;printf(":\tsumando hoja, \n");//se puede borrar esta linea
	}
	if (nodo->izq != nullptr) {
		//printf("izq\n");
		contador = cuentaNodos(nodo->izq, contador);
		//cout<<nodo->dato;printf(":\tfin izq\n\n");//se puede borrar esta linea

	}
	if (nodo->der != nullptr) {
		//printf("der\n");
		contador = cuentaNodos(nodo->der, contador);
		//cout<<nodo->dato;printf(":\tsumando raiz\n");//se puede borrar esta linea
		contador++;
	}
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