#include "microbe.h"


microbe::microbe(void)
{
}


microbe::~microbe(void)
{
}
void microbe::read_microbe_parameter()
{
	const int varnum = 8;
	char header[varnum][12];	
	int pftid[pftnum];
	char pftname[pftnum][40];
	long update[pftnum];
	ifstream ifs;
	ifs.open(microbe_f, ios::in);
	if (!ifs)
	{
		cerr << "\nCannot open " << microbe_f << " for data input" << endl;
		exit(-1);
	}
	else
	{
		for (int i = 0; i < varnum; i++)
		{
			ifs >> header[i]; 
		}
		for (int j = 0; j < pftnum; j++)
		{
			/*ifs >> pftid[j] >> pftname[j];
			ifs >> microbe_p.rhq10[j];
			ifs >> microbe_p.kn2[j];
			ifs >> microbe_p.moistmin[j] >> microbe_p.moistopt[j] >> microbe_p.moistmax[j];
			ifs >> update[j];*/
		}
	}
	ifs.close();
}