#include "Nodo.h"
#include "Persona.h"

Nodo::Nodo() {
    Nodo* nodo = new Nodo();

}

Nodo::Nodo(Persona persona) {
    Nodo* n = new Nodo();
    n->persona = persona;

}
void Nodo::setNext(Nodo* nodo) {
    this->next = nodo;
}
Nodo* Nodo::getNext() {
    return this->next;
}
Persona Nodo::getPersona() {
    return this->persona;
}
Nodo :: ~Nodo() {

}

void Nodo::setPersona(Persona persona) {
    this->persona = persona;
}