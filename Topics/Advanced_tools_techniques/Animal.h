#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal 
{
public:
	Animal();
	virtual ~Animal();
	virtual void print() = 0;
	virtual void react() = 0;
	void* operator new(size_t size);
	void operator delete(void*);

};



#endif //