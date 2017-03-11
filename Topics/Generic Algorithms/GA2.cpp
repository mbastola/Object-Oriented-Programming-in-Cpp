// GA2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;

int main(int argc, char* argv[])
{
	set<string> s;
	multiset<string> ms;
	multimap<string, int> mapp;
	char *states[] = { "California", "Oregon", "California", "Washington", "Texas", "Texas" };
	for (int i = 0; i < 6; ++i){
		auto it = s.insert(states[i]);
		auto it2 = ms.insert(states[i]);
		pair<string, int> p(states[i], i);
		auto it3 = mapp.insert(p);
	}
	cout << "The multiset contains: ";
	for (auto it = ms.begin(); it != ms.end(); ++it)
		cout << *it << " ";
	std::cout << endl;
	ostream_iterator<string> out_it(cout, ", ");
	auto it = ms.begin();
	/*while(it != ms.end())
	{
	auto it2 = ms.equal_range(*it);
	while (it2.first != it2.second){
	copy(it2.first, it2.second, out_it);
	ms.erase(it2.first, ++it2.first);
	cout << endl;
	}
	it = it2.second;
	++it;
	}*/
	ostream_iterator<string> out_itmapKey(cout, "-> ");
	ostream_iterator<int> out_itmapVal(cout, ", ");
	auto itmap = mapp.begin();
	while (itmap != mapp.end())
	{
		auto it2 = mapp.equal_range((*itmap).first);
		while (it2.first->first != it2.second->first){
			//copy(it2.first->first, it2.second->first, out_itmapKey);
			cout << it2.first->first << "->" << it2.first->second <<  " ";
			//copy(it2.first->second, it2.second->second, out_itmapVal);
			mapp.erase(it2.first, ++it2.first);
			cout << endl;
		}
		itmap = it2.second;
		++itmap;
	}
	return 0;
}

