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


//int atmosphere::read_cloudiness(FILE *in_file)
//{
//	int result=0;
	/*double longitude,latitude,area;
	string continent;

	if(in_file)
	{
		result = fscanf(in_file, "%lf,%lf, %s ,%lf,%l,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf, %s",
			&longitude, &latitude, s_cloudiness.variable_name, &area, &s_cloudiness.year, &s_cloudiness.total, &s_cloudiness.max,
			&s_cloudiness.average, &s_cloudiness.min,
			s_cloudiness.month+0, s_cloudiness.month+1, s_cloudiness.month+2, s_cloudiness.month+3, s_cloudiness.month+4, s_cloudiness.month+5,
			s_cloudiness.month+6, s_cloudiness.month+7, s_cloudiness.month+8, s_cloudiness.month+9, s_cloudiness.month+10, s_cloudiness.month+11, continent);
	}*/
//	return result;
//}


//int atmosphere::read_air_temperature(FILE *in_file)
//{
//	int result=0;
//	/*double longitude,latitude,area;
	//string continent;

	//if(in_file)
	//{
	//	result = fscanf(in_file, "%lf,%lf, %s ,%lf,%l,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf, %s",
	//		&longitude, &latitude, s_air_temperature.variable_name, &area, &s_air_temperature.year, &s_air_temperature.total, &s_air_temperature.max,
	//		&s_air_temperature.average, &s_air_temperature.min,
	//		s_air_temperature.month+0, s_air_temperature.month+1, s_air_temperature.month+2, s_air_temperature.month+3, s_air_temperature.month+4, s_air_temperature.month+5,
	//		s_air_temperature.month+6, s_air_temperature.month+7, s_air_temperature.month+8, s_air_temperature.month+9, s_air_temperature.month+10, s_air_temperature.month+11, continent);

//	}*/
//	return result;
//}
//int atmosphere::read_precipitation(FILE *in_file)
//{
	//int result=0;
	/*double longitude,latitude,area;
	string continent;

	if(in_file)
	{
		result = fscanf(in_file, "%lf,%lf, %s ,%lf,%l,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf, %s",
			&longitude, &latitude, s_precipitation.variable_name, &area, &s_precipitation.year, &s_precipitation.total, &s_precipitation.max,
			&s_precipitation.average, &s_precipitation.min,
			s_precipitation.month+0, s_precipitation.month+1, s_precipitation.month+2, s_precipitation.month+3, s_precipitation.month+4, s_precipitation.month+5,
			s_precipitation.month+6, s_precipitation.month+7, s_precipitation.month+8, s_precipitation.month+9, s_precipitation.month+10, s_precipitation.month+11, continent);
	}*/
	/*return result;
}*/


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