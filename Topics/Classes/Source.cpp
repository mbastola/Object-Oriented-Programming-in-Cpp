#include "stdafx.h"
#include "Header.h"

using namespace std;

blah3::blah3(int m1,int m2)
{
	mem1 = m1;
	mem2=m2;
}

int blah3::get_mem1() const
{
	return mem1;
}

int blah3::get_mem2() const
{
	return mem2;
}

int blah3::get_mem3() const
{
	return mem3;
}

blah3 & blah3::set_mem1(int val)
{
	mem1 = val;
	return this;
}

blah3 & blah3::set_mem2(int val)
{
	mem2 = val;
	return blah3;
}

blah3 & blah3::set_mem3(int val)
{
	mem3 = val;
	return blah3;
}
