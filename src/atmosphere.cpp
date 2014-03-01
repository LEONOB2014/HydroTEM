#include "atmosphere.h"


atmosphere::atmosphere(void)
{
}


atmosphere::~atmosphere(void)
{
}

void atmosphere::read_carbon_dioxide()
{	
	int year;
	double concenstration;
	ifstream ifs(carbon_dioxide_f.c_str(),ios::in);
	if(ifs.good())
	{
		while(!ifs.eof())
		{
			ifs >> year >> concenstration;
			carbon_dioxide.push_back(concenstration);
		}		
	}
	
}


void atmosphere::calculate_radiance(int year, double latitude)
{
	int sumday=0;
	for(int i=0;i<mon_num;i++)
	{
		int DayOfMonth=Date::DayOfMonth(year,i+1);		
		double sumd;
		double sig;
		double eta;
		double sinbeta;
		double sb;
		double sotd;
		int day;
		int hour;			
		double lambda = latitude * pi / 180.0;	
		double total = 0.0;
		for (day = 0; day < DayOfMonth; day++)
		{
			++sumday;
			sumd = 0;
			sig = -23.4856*cos(2 * pi * (sumday + 10.0)/365.25);
			sig *= pi / 180.0;
			for (hour = 0; hour < 24; hour++)
			{
				eta = (double) ((hour+1) - 12) * pi / 12.0;
				sinbeta = sin(lambda)*sin(sig) + cos(lambda)*cos(sig)*cos(eta);
				sotd = 1 - (0.016729 * cos(0.9856 * (sumday - 4.0) * pi / 180.0));
				sb = sp * sinbeta / pow(sotd,2.0);
				if (sb >= 0.0) { sumd += sb; }
			}
			total += sumd;
		}
		total /= (double)DayOfMonth;

		tot_ra[i] = total;
		
	}
}