// GA1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric> 
using namespace std;	

int main(int argc, char* argv[])
{
	int arr[] = { -2, 19, 80, -47, 80, 80, -2 };
	int* final = arr + 7;	/*right after the end of array*/
	ostream_iterator<int> o(cout, " ");
	//copy(arr, final, o);
	sort(arr, final);
	vector<int> V;
	back_insert_iterator< vector<int> > iter(V);
	vector<int>::iterator it;
	vector<int>::iterator found;
	copy(arr, final, iter);
	copy(V.begin(), V.end(), o);
	cout << endl;	
	for (it = V.begin(); it != V.end()-2; ++it){
		found = adjacent_find(it, V.end());
		cout << *found << " ";  
		if (*found == *it)
			cout << endl;
	}
	auto total = accumulate(V.begin(), V.end(), 0.0);
	auto mean = total / V.size();
	cout << "Mean: " << mean << endl;
	int median;
	if (V.size() % 2)
		median = arr[V.size() / 2];
	else
		median = arr[(V.size() + 1) / 2];
	cout << "Median: " << median << endl;
	int oldfreq = 0;
	vector<int>::iterator pos;
	for (it = V.begin()+1; it != V.end(); ++it){
		if (*(it-1) != *it)
		{
			auto freq = count(V.begin(), V.end(), *it);
			if (freq > oldfreq){
				oldfreq = freq;
				pos = it;
			}
		}
	}
	int mode = *pos;
	cout << "Mode: " << mode << endl;
	return 0;
}

