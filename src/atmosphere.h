#pragma once
#include "Date.h"
#include "DataIO.h"

const double pi = 3.141592654;                // Greek "pi"
const double sp = 1368.0 * 3600.0 / 41860.0;  // solar constant

class atmosphere
{
public:
	atmosphere(void);
	~atmosphere(void);
	vector<double> carbon_dioxide;


	//  Radiation Variables
	double tot_ra[mon_num];        // Gross Irradiance (cal/(sq. cm * day))
	double net_ra[mon_num];        // Net Irradiance   (cal/(sq. cm * day))
	double par[mon_num];         // Photosynthetically Active Radiation	// (cal/(sq.cm * day))
	string carbon_dioxide_f;


	struct cloudiness
	{
		string var_name;
		long year;
		double total;
		double max;
		double mean;
		double min;
		double  month[12];
	}cloud;


	struct air_temperature
	{
		string var_name;
		long year;
		double total;
		double max;
		double mean;
		double min;
		double  month[12];
	}air_temp;



	struct precipitation
	{
		string var_name;
		long year;
		double total;
		double max;
		double mean;
		double min;
		double  month[12];
	}prec;


	struct radiation
	{
		string var_name;
		long year;
		double total;
		double max;
		double mean;
		double min;
		double  month[12];
	}rad;


	string cloudiness_f;
	string precipitation_f;
	string airtemperature_f;

	//the carbon dioxide is annual average in this version
	void read_carbon_dioxide();
	//double ** read_carbon_dioxide(string filename);
	//int read_cloudiness();
	//int read_air_temperature(FILE *in_file);
	//int read_precipitation(FILE *in_file);
	void calculate_radiance(int year, double latitude);
};

