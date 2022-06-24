#include "Nodo.h"
#include "Persona.h"
#include "Linked.h"

 Nodo::Nodo(Persona persona) {
    this->persona = persona;

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
void Nodo::setPersona(Persona persona) {
    this->persona = persona;
}
Nodo :: ~Nodo() {
}