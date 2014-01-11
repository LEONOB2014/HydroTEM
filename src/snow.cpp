#include "snow.h"


snow::snow(void)
{
}


snow::~snow(void)
{
}

void snow::read_snow_parameter()
{
	
	const int varnum = 52;
	char header[varnum][15];
	int pftid[vegnum], update[vegnum];
	char pftname[vegnum][40];
	ifstream ifs;
	ifs.open(snow_pf.c_str(), ios::in);
	if (!ifs) 
	{
		cerr << "\nThe Snow parameter file:  " << snow_pf << " is invalid" << endl;
		exit(-1);
	}
	else
	{
		for (int i = 0; i < varnum; i++) 
		{
			ifs >> header[i];
		}
		for (int i = 0; i < pftnum; i++)
		{
			/*ifs >>pftid[i] >> pftname  >> snow_p[i].MAX >> snow_p[i].NST  >> snow_p[i].KALLYR  >>
				snow_p[i].KNODES   >> snow_p[i].KISO  >> snow_p[i].KTEMP   >> snow_p[i].KSNOW   >> snow_p[i].KENVL  >> snow_p[i].KFLUX  
			>> snow_p[i].LISO  >> snow_p[i].TISO  >> snow_p[i].LMAX  >> snow_p[i].VDEPTH  >> snow_p[i].DEPTEM1  >>
				snow_p[i].DEPTEM2  >> snow_p[i].DEPTEM3  >> snow_p[i].DEPTEM4  >> snow_p[i].DEPTEM5  >> snow_p[i].NDEPF  >>
				snow_p[i].VDEP  >> snow_p[i].DEPFLX1  >> snow_p[i].DEPFLX2  >> snow_p[i].DEPFLX3  >> snow_p[i].DEPFLX4  >>
				snow_p[i].DEPFLX5  >> snow_p[i].HLAT  >>snow_p[i].TF  >> snow_p[i].gflux  >> snow_p[i].cdsnow  >> snow_p[i].FIRST  >>
				snow_p[i].FINAL  >> snow_p[i].PER  >> snow_p[i].DTDAY  >> snow_p[i].THETA  >> snow_p[i].TOP  >> snow_p[i].IG  >>snow_p[i].EPSMIN  
			>> snow_p[i].VSPACE  >> snow_p[i].VDEN  >>snow_p[i].kint  >>snow_p[i].VDEP1  >>snow_p[i].DEPHET  >> snow_p[i].SNOFAL  >>
				snow_p[i].EPSSNO  >> snow_p[i].CONVRT  >> snow_p[i].ETAO  >>snow_p[i].DENFAC  >> snow_p[i].FCMELT  >>
				snow_p[i].DENMAX  >>update  ;*/
		}
		ifs.close();
	}
}