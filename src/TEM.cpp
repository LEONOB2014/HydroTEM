#include "TEM.h"

string backslash ="\\";

TEM::TEM(void)
{
}


TEM::~TEM(void)
{
}
TEM::TEM(string config_file)
{
	configuration_f=config_file;
}
void TEM::read_configuration()
{
	//verify the configuration file
	ifstream ifs;	
	ifs.open(configuration_f.c_str(), ios::in);
	if(ifs.good())
	{
		string variable;
		string value;
		while(!ifs.eof())
		{
			//workspace
			ifs >> variable >> config_p.workspace;
			//parameters

		}
	}
	else
	{

	}
}

void TEM::deploy_component()
{
	//........................................................................................................
	//parameter files
	//........................................................................................................

	//..........................................................................................................
	//for deatils of how parameter files are placed under the workspace, see the workspace instruction paper.
	cGeology.elevation_f=config_p.workspace+backslash+"parameter"+backslash+"elevation_file.flt";

	cVegetation.workspace_p=config_p.workspace+backslash+"parameter"+backslash;
	cVegetation.vegetation_f=config_p.workspace+backslash+"parameter"+backslash+"vegetation_file.flt";
	cSoil.soil_texture_f=config_p.workspace+backslash+"parameter"+backslash+"soil_texture.flt";


	//........................................................................................................

}
void TEM::run()
{
	//the main idea of the gTEM is to calculate the pixel by pixel under the same time domain. 
	//and this design is potenially good for interaction between pixels in further development.
	//to seperate the spin up period and transient period, more attention need to be paid for time control
	//some variables, e.g. elevation is time independent and also need special attention.

	//.....................................................................................
	//read parameter files
	cSnow.read_snow_parameter();
	//......................................................................................


	//..............................................................................................
	//read all time independent data into memory first, 
	//in reality these data set changes with time as well, need to be addressed in future development
	//moreover these data could be read directly into memory if possible

	cGeology.read_elevation();	
	cSoil.read_soil_texture();	
	cVegetation.read_vegetation_type();
	//...............................................................................................

	//TEM_model
	//equilirium simulation 
	//set all the flag outside loop to improve efficiency
	//the common sense is to reduce unnecessary loop as to improve the efficience
	//the case or switch option may be applied in coming development
	//int spinup_year = config_p.spin_num *  config_p.year_per_spin;

	/*for(int iyear=0;iyear < spinup_year;iyear++)
	{

		for(int month=1;month<=12;month++)
		{
			cAtmosphere.calculate_radiance(iyear,23);
		}

	}*/

	//start transient simulation






	//
}