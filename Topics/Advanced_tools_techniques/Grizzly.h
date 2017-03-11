#ifndef GRIZZLY_H
#define GRIZZLY_H

#include <iostream>
#include "Bear.h"
#include "Endangered.h"
#include <string>
using namespace std;

class Grizzly :public Bear, public Endangered {

public:
	Grizzly();
	virtual ~Grizzly();
	virtual int toes();
	virtual void print();
	void growl();
	virtual void react();
};


#endif //