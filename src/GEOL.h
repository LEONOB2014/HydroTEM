#pragma once
#include "Data.h"

//the global matrix dimensions, which is determined by the resolution
const long global_row=360;
const long global_col=720;
using namespace std;
class GEOL
{
public:
	GEOL(void);
	~GEOL(void);	
	string elevation_f;
	float ** ReadElevation();

};

