// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Animal.h"
#include "Endangered.h"
#include "Bear.h"
#include "Panda.h"
#include "Grizzly.h"

int main(int argc, char* argv[])
{
	//Endangered bear1;
	//Animal bear2;
	Panda Pu("PuThePanda");
	//Grizzly G;
	//G.growl();
	//G.print();
	//G.toes();
	//G.cuddle();
	//Pu.print();
	//Pu.cuddle();
	//Pu.toes();
	//Pu.growl();
	//Pu.react();
	//G.react();
	Animal* a = &Pu;
	//Animal* b = &G;
	//a->growl();
	a->cuddle();
	//b->growl();
	//b->cuddle();
	return 0;
}

