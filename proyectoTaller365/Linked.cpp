#include "Nodo.h"
#include "Persona.h"


#include <iostream>
#include <string>

using namespace std;

class LinkedList {
private:
    Nodo* first;
public:
    LinkedList() {
        first = NULL;
    }

    void addNode(Persona persona) {
        Nodo* nuevo = new Nodo;
        nuevo->setPersona(persona);
        nuevo->setNext(NULL);

        if (first == NULL) {
            first = nuevo;
        }


    }

};