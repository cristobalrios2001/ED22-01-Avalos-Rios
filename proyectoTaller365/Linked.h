#pragma once
#include "Nodo.h"
#include "Persona.h"

#include <iostream>
#include <string>
using namespace std;

class Linked {
private:
	Nodo* header;
public:
	Linked();
	void addNodo(Persona persona);
	int getSize();
	void show();

};