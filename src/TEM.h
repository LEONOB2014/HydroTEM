#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <iterator>


#include "atmosphere.h"
#include "geology.h"
#include "permafrost.h"
#include "shared.h"
#include "snow.h"
#include "soil.h"
#include "vegetation.h"



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
		
	}config_p;




	void read_configuration();
	void deploy_component();
	void run();

};

