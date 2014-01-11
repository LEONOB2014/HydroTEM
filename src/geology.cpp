#include "geology.h"


geology::geology(void)
{
}


geology::~geology(void)
{
}

float ** geology::read_elevation()
{	
	float ** elevation= DataIO::Read_Binary(elevation_f,global_row,global_col);
	return elevation;
}
