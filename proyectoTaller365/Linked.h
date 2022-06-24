#pragma once
#ifndef LINKED_H
#define LINKED_H
#include "Nodo.h"
#include "Persona.h"

#include <iostream>
#include <string>
using namespace std;

class Linked {
	Nodo* header;
public:
	Linked();
	void addNodo(Persona persona);
	int getSize();
	void show();
	~Linked();

};
#endif