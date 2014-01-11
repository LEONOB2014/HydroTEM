#pragma once
#include "vegetation.h"

using namespace std;

class soil
{
public:
	soil(void);
	~soil(void);


	string soil_texture_f;
	string soil_layer_pf;
	string soil_temperature_pf;
	string soil_pf;


	struct soil_layer_parameter
	{
		long MAT1 ,MAT2 ,MAT3 ,MAT4 ,MAT5 ,MAT6 ;
		double THICK1 ,DXA1 ,DXB1 ,DENSE1 ,
			WATER1 ,vcond1 ,vsph1 , cond1 ,spht1 ,
			condf1 ,sphf1 ;
		double THICK2 ,DXA2 ,DXB2 ,DENSE2 ,
			WATER2 ,vcond2 ,vsph2 , cond2 ,spht2 ,
			condf2 ,sphf2 ;
		double THICK3 ,DXA3 ,DXB3 ,DENSE3 ,
			WATER3 ,vcond3 ,vsph3 , cond3 ,spht3 ,
			condf3 ,sphf3 ;
		double THICK4 ,DXA4 ,DXB4 ,DENSE4 ,
			WATER4 ,vcond4 ,vsph4 , cond4 ,spht4 ,
			condf4 ,sphf4 ;
		double THICK5 ,DXA5 ,DXB5 ,DENSE5 ,
			WATER5 ,vcond5 ,vsph5 , cond5 ,spht5 ,
			condf5 ,sphf5 ;
		double THICK6 ,DXA6 ,DXB6 ,DENSE6 ,WATER6 ;
	}soil_layer_p[pftnum];
	struct soil_temperature_parameter
	{
		long NP ;
		double INDEX ,VDEP ; 
		double DEPTH [25],TEMP [25];
	}soil_temperature_p[pftnum];

	struct soil_parameter
	{
		double pctpora;
		double pctporb;
		double fldcapa;
		double fldcapb;
		double wiltpta;
		double wiltptb;
	}soil_p;
	struct soil_pft_parameter
	{
		//total nitrogen input into soil (g N / (square meter * month))
		double nintot;
		//proportion of available nitrogen lost (g N / (square meter * month))
		double nloss;
	}soil_pft_p[pftnum];


	float ** read_soil_texture();
	void read_soil_layer_parameter();
	void read_soil_temperature_parameter();
	void read_soil_parameter();

};

