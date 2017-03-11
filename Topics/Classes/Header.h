#ifndef HEADER_H
#define HEADER_H

struct blah
{
	int mem1;
	int mem2;
};


class blah2
{
public:	
	int mem1;
	int mem2;
};

class blah3
{
private:
	int mem1 = 4;
	int mem2 = 5;
	const int mem3= 0;
public:
	blah3();
	blah3(int m1,int m2);
	int get_mem1() const;
	int get_mem2() const;
	int get_mem3() const;
	blah3 & set_mem1(int val);
	blah3 & set_mem2(int val);
	blah3 & set_mem3(int val);
};

#endif