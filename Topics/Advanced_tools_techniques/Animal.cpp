#include "stdafx.h"
#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(){
	cout << "Animal::Animal()"<< endl;
}

Animal::~Animal(){
	cout << "Animal::~Animal()" << endl;
}

void* Animal::operator new(size_t size)
{
	void *storage = malloc(size);
	if (NULL == storage) {
		throw "allocation fail : no free memory";
	}
	cout << storage << endl;
	return storage;
}

void Animal::operator delete(void* p)
{
	cout << p << endl;
	free(p);
}