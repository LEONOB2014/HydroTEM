#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <iterator>
#include "atmosphere.h"
#include "soil.h"
#include "vegetation.h"
#include "snow.h"
#include "geology.h"




using namespace std;

const int variable_count=20;

class TEM
{
public:
	TEM(void);
	TEM(string sConfig_file);
	~TEM(void);
	atmosphere cAtmosphere;
	soil cSoil;
	vegetation cVegetation;
	snow cSnow;
	geology cGeology;
	

	//ifstream  f_soil;

	string configuration_f;
	struct config_parameter
	{
		//workspace
		string workspace;
		//parameters
		int spin_num;
		int year_per_spin;
		int transient_year;	
		int equilirium_checkpoint;
		int start_year;
		int end_year;
		int year_intervel;
		double water_tolerance;
		double carbon_tolerance;
		double equlibrium_tolerance;
		double proportional_tolerance;	
		int interation_num;
		int pft_num;

	}config_p;




	void read_configuration();
	void deploy_component();
	void run();

};

