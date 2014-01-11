#pragma once
#include "geology.h"
#include "vegetation.h"
class microbe
{
public:
	microbe(void);
	~microbe(void);

	string microbe_f;
	struct microbe_parameter
	{
		double rhq10;
		double kn2;
		double moistmin;
		double moistopt;
		double moistmax;

		// Biome-specific decomposition parameters for function rhxclm

		double kd;
		double kda;
		double kdb;
		double kdc;
		double lcclnc;
		double propftos;

		// Biome-specific microbial nitrogen uptake parameters for function
		//   nminxclm

		double nup;
		double nupa;
		double nupb;
		// Biome-specific N fixation parameter

		double nfixpar;
		double cnsoil;


	} microbe_p[pftnum];

	

	void read_microbe_parameter();
};

