#include "Nodo.hpp"

 Nodo::Nodo() {
     next = nullptr;
}
 Nodo::Nodo(Persona persona) {
     this->persona = persona;
     this->next = nullptr;
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