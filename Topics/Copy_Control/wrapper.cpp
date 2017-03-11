#include "stdafx.h"
#include "wrapper.h"
#include <iostream>
#include <string>

using namespace std;

Wrapper::Wrapper()
{
	this->myDetector = new Detector();
	this->member = true;
	cout << "Constructor of wrapper :" << this << " " << &this->myDetector << endl;
}

Wrapper::Wrapper(const Wrapper& other) 
{
	this->member = false;

}

Wrapper::~Wrapper()
{
	if (this->member)
		delete myDetector;
	cout << "Destructor of Wrapper :" << this << " " << &this->myDetector << endl;
}