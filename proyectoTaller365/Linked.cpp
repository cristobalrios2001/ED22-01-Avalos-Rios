#include "Nodo.h"
#include "Persona.h"
#include "Linked.h"

#include <iostream>
#include <string>

using namespace std;

Linked:: Linked() {
    header = NULL;
}
void Linked::addNodo(Persona persona) {
    Nodo* nodo = new Nodo();
    nodo->setPersona(persona);
    if (header == NULL) {
        header = nodo;
    }
    else {
        Nodo* current = header;
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        current->setNext(nodo);
    }
}
int Linked::getSize() {
    Nodo* aux = header;
    int cont = 0;
    while (aux->getNext() != NULL) {
        cont++;
        aux = aux->getNext();
    }
    return cont;
}
void Linked::show() {
    if (header == NULL) {
        cout << "Lista Vacia" << endl;
    }
    else {
        Nodo* temp = header;
        while (header != NULL) {
            cout << header->getPersona().getID() << endl;
            header = header->getNext();
        }
    }
}