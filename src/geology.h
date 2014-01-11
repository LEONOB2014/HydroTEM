#pragma once
#include "DataIO.h"

//the global matrix dimensions, which is determined by the resolution
const long global_row=360;
const long global_col=720;
using namespace std;
class geology
{
public:
	geology(void);
	~geology(void);	
	string elevation_f;
	float ** read_elevation();

};

