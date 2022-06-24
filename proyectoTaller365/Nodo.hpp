#pragma once
#ifndef NODO_H
#define NODO_H

#include "Persona.hpp"
#include "Linked.hpp"

class Nodo {
    Persona persona;
    Nodo* next;

public:
    Nodo();
    Nodo(Persona persona);
    void setNext(Nodo* nodo);
    Nodo* getNext();
    Persona getPersona();
    void setPersona(Persona persona);
    ~Nodo();
};
#endif