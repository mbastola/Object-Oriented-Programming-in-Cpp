#include "stdafx.h"
#include <iostream>
#include "Grizzly.h"
using namespace std;

Grizzly::Grizzly()
{
	cout << "Grizzly::Grizzly()" << endl;
}


Grizzly::~Grizzly(){
	cout << "Grizzly::~Grizzly()" << endl;
}

int Grizzly::toes()
{
	return 5;
}

void Grizzly::print()
{
	Endangered::print();
	cout << "Grizzly" << endl;
}

void Grizzly::growl()
{
	cout << "Grizzly Growl" << endl;
}
void Grizzly::react()
{
	this->growl();
}