#include "Nodo.h"
#include "Persona.h"
#include "Linked.h"

 Nodo::Nodo() {
     next = NULL;
}
 Nodo::Nodo(Persona persona) {
     this->persona = persona;
     this->next = NULL;
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