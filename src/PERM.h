#pragma once
#include "Data.h"
class PERM
{
public:
	PERM(void);
	~PERM(void);

	double UnfrozenWaterContent(double temperature, double depth,double a, double b);

};

