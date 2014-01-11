#pragma once
#include "vegetation.h"

class snow
{
public:
	snow(void);
	~snow(void);
	struct snow_parameter
	{
		long MAX ,NST ,KALLYR ,KNODES ,KISO ;
		long KTEMP ,KSNOW ,KENVL ,KFLUX ,LISO ;
		long LMAX , NDEPF ,IG ;
		long kint ,SNOFAL  ;// for index;
		double TISO ,VDEPTH ,DEPTEM1 ,DEPTEM2 ,DEPTEM3 ,DEPTEM4 ,DEPTEM5 ,VDEP ;
		double VDEPTH1 ,DEPFLX1 ,DEPFLX2 ,DEPFLX3 ,DEPFLX4 ,DEPFLX5 ;
		double HLAT ,TF ,gflux ,cdsnow ,FIRST ,FINAL ;
		double PER ,DTDAY ,THETA ,TOP ,EPSMIN ;
		double VSPACE ,VDEN ,VDEP1 ,DEPHET ,EPSSNO ;
		double CONVRT ,ETAO ,DENFAC ,FCMELT ,DENMAX ;
	}snow_p[pftnum];

	string snow_pf;
	void read_snow_parameter();

};

