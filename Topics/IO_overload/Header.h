#ifndef HEADER_H
#define HEADER_H
#include <iostream>

using namespace std;
struct Rectangle{
	int length;
	int width;
};

ostream & operator<<(ostream &, const Rectangle &);
istream & operator>> (istream &, Rectangle &);
#endif