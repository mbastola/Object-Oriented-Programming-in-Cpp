// overload_IO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	Rectangle r1;
	r1.length = 31;
	r1.width = 27;
	cout << r1 << endl;
	/*while (1){
		cout << "Please enter 2 coordinates(or hit Ctrl - C to quit) :";
		cin >> r1;
		cout << r1 << endl;
	}*/
	ifstream myfileIn(argv[1]);
	ofstream myfileOut(argv[2]);
	if (myfileIn.is_open())
	{
		while (myfileIn.good())
		{
			myfileIn >> r1;
			if (myfileOut.is_open())
				myfileOut << r1 << endl;
			else
			{
				cout << "Unable to open output file" << endl;
				return 1;
			}
		}
	}
	else
	{
		cout << "Unable to open input file" << endl;
		return 1;
	}
	return 0;
}

