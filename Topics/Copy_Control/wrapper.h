#ifndef WARPPER_H
#define WRAPPER_H

#include "detector.h"
class Wrapper
{
private:
	Detector* myDetector = nullptr;
	bool member;

public:
	Wrapper();
	~Wrapper();
};

#endif


