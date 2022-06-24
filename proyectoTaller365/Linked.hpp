#pragma once
#ifndef LINKED_H
#define LINKED_H

#include "Nodo.hpp"
#include "Persona.hpp"
#include <iostream>
#include <string>
using namespace std;

class Linked {
private:
	Nodo* header;
	int size = 0;
public:
	Linked();
	void addNodo(Persona persona);
	int getSize();
	void show();
	~Linked();
};
#endif