#include "GEOL.h"


GEOL::GEOL(void)
{
}


GEOL::~GEOL(void)
{
}

float ** GEOL::ReadElevation()
{	
	float ** elevation= Data::Read_Binary(elevation_f,global_row,global_col);
	return elevation;
}
