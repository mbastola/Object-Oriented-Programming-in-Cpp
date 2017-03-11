#include "stdafx.h"
#include <iostream>
#include "Panda.h"
using namespace std;

Panda::Panda(const string& name)
{
	this->name = name;
	cout << "Panda::Panda()" << endl;
}


Panda::~Panda(){
	cout << "Panda::~Panda()" << endl;
}

int Panda::toes()
{
	return 6;
}

void Panda::print()
{
	Endangered::print();
	cout << "Panda: " << this->name << endl;
}
void Panda::cuddle()
{
	cout << "Panda Cuddle" << endl;
}

void Panda::react()
{
	this->cuddle();
}