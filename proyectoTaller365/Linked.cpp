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
        Nodo* nodo = new Nodo();
        nodo->setPersona(persona);
        nodo->setNext(NULL);
        if (this->first == NULL) {
            this->first = nodo;
        }
        else {
            Nodo* current = this->first;
            while (current->getNext() != NULL) {
                current = current->getNext();
            }
            current->setNext(nodo);
        }
    }
    int getSize() {
        Nodo* aux = this->first;
        int cont = 0;
        while (aux->getNext() != NULL) {
            cont++;
            aux = aux->getNext();
        }
        return cont; 
    }

    void show() {
        Nodo* aux = this->first;
        if (this->first == NULL) {
            cout << "Lista Vacia" << endl;
        }
        else {
            while (aux != NULL) {
               // cout << aux->getPersona() << endl; variable
                aux = aux->getNext();
            }
        }
    }


};