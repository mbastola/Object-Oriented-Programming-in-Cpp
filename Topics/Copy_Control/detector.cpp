#include "stdafx.h"
#include "detector.h"
#include <iostream>
#include <string>

using namespace std;
unsigned Detector::member2 = 0;

Detector::Detector()
{
	this->member1 = this->member2;
	++(this->member2);
	cout << "Constructor of Detector :" << this << " " << this->member1 << endl;
}


Detector::~Detector()
{
	cout << "Destructor of Detector:" << this << " " << this->member1 << endl;
}