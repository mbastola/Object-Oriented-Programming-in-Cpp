#include "stdafx.h"
#include <iostream>
#include "Header.h"

using namespace std;

ostream & operator<< (ostream &o,
	const Rectangle &p) {
	o << p.length << " " << p.width; // space delimited
	return o;
}

istream & operator>> (istream &i, Rectangle &p) {
	i >> p.length >> p.width; // extract both variables
	return i;
}
