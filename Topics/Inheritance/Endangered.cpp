#include "stdafx.h"
#include <iostream>
#include "Endangered.h"
using namespace std;


Endangered::Endangered(){
	cout << "Endangered::Endangered()" << endl;
}

Endangered::~Endangered(){
	cout << "Endangered::~Endangered()" << endl;
}

void Endangered::print()
{
	cout << "ENDANGERED!" << endl;
}