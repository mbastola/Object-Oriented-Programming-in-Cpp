// simple_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
	blah2 testStruct = blah2();
	cout << testStruct.mem1 << ',' << testStruct.mem2 << endl;
	blah3 testClass(4, 5);
	cout << testClass.get_mem1() << endl;
	cout << testClass.get_mem2() << endl;
	cout << testClass.get_mem3() << endl;
//	cout << testClass.set_mem1(3)<<endl;
//	cout << testClass.set_mem2(3)<< endl;
	//cout << testClass.set_mem3(3) << endl;
	blah3 m;
	cout << "m.x = " << m.get_mem1() << " and m.y = " << m.get_mem2() << endl;
	m.set_mem1(7).set_mem2(3); // chained use of mutator functions
	cout << "m.x = " << m.get_mem1() << " and m.y = " << m.get_mem2() << endl;
	blah3 n(m); // copy construction
	cout << "n.x = " << n.get_mem1() << " and n.y = " << n.get_mem2() << endl;
	return 0;
}

