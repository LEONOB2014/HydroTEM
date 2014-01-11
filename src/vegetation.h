#pragma once
#include "geology.h"

const int vegnum = 35;
const int mosnum = 5;
const int pftnum=12;

class vegetation
{
public:
	vegetation(void);
	~vegetation(void);	
	/*int vegetation_code;
	int community_type_count;
	double CN_factor;
	string source;	
	string variable_name;	
	string land_use;*/
	string workspace_p;
	string vegetation_f;
	string root_depth_f;
	string leaf_f;

	vector<string>pft;	

	struct root_depth_parameter
	{
		double rootza[pftnum];
		double rootzb[pftnum];
		double rootzc[pftnum];
		double minrootz[pftnum];
	}root_depth_p;
	struct vegetation_parameter
	{
		double kc[pftnum];
		double ki[pftnum];
		double gva[pftnum];
		double tmin[pftnum];
		double toptmin[pftnum];
		double toptmax[pftnum];
		double tmax[pftnum];
		double raq10a0[pftnum];
		double raq10a1[pftnum];
		double raq10a2[pftnum];
		double raq10a3[pftnum];
		double kn1[pftnum];
		double labncon[pftnum];
		double leafmxc[pftnum];
		double kleafc[pftnum];
		double sla[pftnum];
		double cov[pftnum];
		double fpcmax[pftnum];
	}vegetation_p;
	struct leaf_parameter
	{
		double minleaf[pftnum];
		double aleaf[pftnum];
		double bleaf[pftnum];
		double cleaf[pftnum];
	} leaf_p;
	struct pft_paramter
	{
		int id;
		string name;
		double ca;
		double cb;
		double strna;
     double strnb;
     double solca;
     double solcb;
     double solna;
     double solnb;
     double avlna;
     double avlnb;
     double stona;
     double stonb;
	 double initleafmx;
	 double unleaf12;
	    // Biome-specific carbon uptake parameters for function gppxclm

     double cmax;
     double cmaxcut;
     double cmax1a;
     double cmax1b;
     double cmax2a;
     double cmax2b;
	  // Biome-specific proportion of vegetation lost as litterfall

     double cfall;  // proportion of vegetation carbon
     double nfall;  // proportion of vegetation nitrogen
	   // Biome-specific respiration parameters for function rmxclm

     double kr;
     double kra;
     double krb;
	   // Biome-specific nitrogen uptake parameters for function nupxclm

     double nmax;
     double nmaxcut;
     double nmax1a;
     double nmax1b;
     double nmax2a;
     double nmax2b;
	 //double nfall;

	  // Biome-specific vegetation C/N parameters

     double cneven;
     double cnmin;
     double c2n;
     double c2na;
     double c2nb;
     double c2nmin;
     double initcneven;
     double dc2n;
     double adjc2n;

	}pft_p[pftnum];

	/*community_paramter community_p[pftnum];
	vector<int> community_type_number;
	vector<int> subtype;
	vector<double> type_percentage;*/
	//string continent;
	float ** read_vegetation_type();
	void read_pft_parameter();
	void read_root_depth_parameter();
	void read_vegetation_parameter();
	void read_leaf_parameter();
	void calculate_radiation();
};

