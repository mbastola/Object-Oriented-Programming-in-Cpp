#ifndef PANDA_H
#define PANDA_H

#include <iostream>
#include "Bear.h"
#include "Endangered.h"
#include <string>
using namespace std;

class Panda :public Bear, public Endangered {
private:
	string name;
public:
	Panda(const string& name);
	virtual ~Panda();
	virtual int toes();
	virtual void print();
	void cuddle();
	virtual void react();
};



#endif //