#include "NodoArbol.hpp"

NodoArbol::NodoArbol(int dato) {
	this->centroide = dato;
	this->izq = nullptr;
	this->der = nullptr;
}