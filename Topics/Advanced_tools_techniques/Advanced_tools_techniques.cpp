// Advanced_tools_techniques.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "Animal.h"
#include "Endangered.h"
#include "Grizzly.h"
#include "Panda.h"
#include "Bear.h"

bool same_cage(Animal * a, Animal * b) {
	// only ok if both are Pandas
	return dynamic_cast<Panda *>(a) &&
		dynamic_cast<Panda *>(b);
}


int main(int argc, char* argv[])
{
	Animal *a = new Grizzly();
	Grizzly *a1= new Grizzly();
	Bear *a2 = new Grizzly();
	Animal *b = new Panda("PuThePanda1");
	Panda *b1 = new Panda("PuThePanda2");
	Bear *b2 = new Panda("PuThePanda3");
	/*
	cout << "we have a "
		<< typeid(*a).name() << endl << "and a "
		<< typeid(*a1).name() << endl << endl
	<< typeid(*a2).name() << endl << endl
	<< typeid(*b).name() << endl << endl
	<< typeid(*b1).name() << endl << endl
	<< typeid(*b2).name() << endl << endl;*/
	/*
	if (!same_cage(a, b)) {
		cout << "Don’t put in same cage!" << endl;
	}
	*/
	//Panda *P1 = dynamic_cast<Panda *>(a); /*Animal Grizzy to panda*/
	Panda *P2 = dynamic_cast<Panda *>(b); /*Animal Panda to panda*/
	Grizzly *G1 = dynamic_cast<Grizzly *>(a); /*Animal Grizzy to grizzly*/
	//Grizzly *G2 = dynamic_cast<Grizzly *>(b); /*Animal Panda to grizzly*/
	cout << "we have a "
		//<< typeid(*P1).name() << endl << "and a "
		<< typeid(*P2).name() << endl << "and a "
		<< typeid(*G1).name() << endl << "and a "
		//<< typeid(*G2).name() << endl 
		<< endl;
	G1->growl();
	P2->cuddle();
	auto growl_ptr = &Grizzly::growl; // fxn
	auto cuddle_ptr = &Panda::cuddle; // fxn
	(G1->*growl_ptr)();
	(P2->*cuddle_ptr)();
	delete a; delete b;
	delete a1; delete b1;
	delete a2; delete b2;
	cout << endl << endl;
	Panda *k = new Panda("Overloaded New Panda");
	delete k;
	return 0;
}

