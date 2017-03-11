#ifndef POLYGON_H
#define POLYGON_H

using namespace std;



class Polygon
{
private:
	int numSide;

public:
	void print()
	{cout << numSide << endl}

}

class Rectangle :public Polygon
{
private:
	int numSide = 4;

public:
	void print();
	{cout << numSide << endl}
}


#endif