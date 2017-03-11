// Dynamic_Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "detector.h"
#include <memory>
#include <vector>

using namespace std;
shared_ptr<Detector> createAndInit();

int main(int argc, char* argv[])
{
	cout << endl;
	//Detector D;
	int* i = new int(3);
	int *k = new int[*i];
	for (int j = 0; j < *i; j++)
	{
		k[j] = j;
	}
	for (int j = 0; j < *i; j++)
	{
		cout << k[j] << endl;
	}
	cout << *i << endl;
	vector<shared_ptr<Detector>> V;
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		V.push_back(make_shared<Detector>());
	}
	auto sp = createAndInit();
	shared_ptr<Detector> sp1 = make_shared<Detector>();
	cout << endl;
	auto p = make_shared<int>(3);
	auto r = make_shared<int>(5);
	auto m(r);
	cout << r.use_count() << endl;
	auto q(p);
	p = r;
	cout << p.use_count() << endl;
	cout << r.use_count() << endl;
	void f(vector<int>);
	f(vector<int>(10));
	cout << f.size() << endl;
	return 0;
}

shared_ptr<Detector> createAndInit()
{
	shared_ptr<Detector> p(new Detector);
	cout << "First pointer"<< p << endl;
	return p;
}


