#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Bear:public Animal {
public:
	Bear();
	virtual ~Bear();
	virtual int toes() = 0;
};



#endif // !BEAR_H
