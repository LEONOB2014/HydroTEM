#include "PERM.h"


PERM::PERM(void)
{
}


PERM::~PERM(void)
{
}
double PERM::UnfrozenWaterContent(double temperature, double depth, double a, double b)
{
double unfrozenwater=0.0;
  unfrozenwater=  a * pow (temperature, b);
 return unfrozenwater;
}
