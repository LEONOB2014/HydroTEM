#include "soil.h"


soil::soil(void)
{
}


soil::~soil(void)
{
}

float ** soil::read_soil_texture()
{
	float ** soil_texture= DataIO::Read_Binary(soil_texture_f,global_row,global_col);
	return soil_texture;
}
void soil::read_soil_layer_parameter()
{
	const int varnum = 69;
	char header[pftnum][15];
	int pftid[pftnum], update[pftnum];
	char pftname[pftnum][40];
	ifstream ifs;
	ifs.open(soil_layer_pf.c_str(), ios::in);
	if (!ifs) 
	{
		cerr << "\nThe Soil layer file:  " << soil_layer_pf << " is invalid" << endl;
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

			/*ifs >> pftid[i] >> pftname[i]>> soil_layer_p.THICK1[i]>> soil_layer_p.DXA1[i]>>
				soil_layer_p.DXB1[i]>> soil_layer_p.MAT1[i]>> soil_layer_p.DENSE1[i]>> soil_layer_p.WATER1[i]>>
				soil_layer_p.vcond1[i]>> soil_layer_p.vsph1[i]>> soil_layer_p.cond1[i]>> soil_layer_p.spht1[i]>>
				soil_layer_p.condf1[i]>> soil_layer_p.sphf1[i]>> soil_layer_p.THICK2[i]>>soil_layer_p.DXA2[i]>>
				soil_layer_p.DXB2[i]>> soil_layer_p.MAT2[i]>>soil_layer_p.DENSE2[i]>>soil_layer_p.WATER2[i]>>
				soil_layer_p.vcond2[i]>>soil_layer_p.vsph2[i]>>soil_layer_p.cond2[i]>>soil_layer_p.spht2[i]>>
				soil_layer_p.condf2[i]>> soil_layer_p.sphf2[i]>> soil_layer_p.THICK3[i]>> soil_layer_p.DXA3[i]>>
				soil_layer_p.DXB3[i]>> soil_layer_p.MAT3[i]>> soil_layer_p.DENSE3[i]>>soil_layer_p.WATER3[i]>>
				soil_layer_p.vcond3[i]>> soil_layer_p.vsph3[i]>> soil_layer_p.cond3[i]>> soil_layer_p.spht3[i]>>
				soil_layer_p.condf3[i]>> soil_layer_p.sphf3[i]>>soil_layer_p.THICK4[i]>>soil_layer_p.DXA4[i]>>
				soil_layer_p.DXB4[i]>> soil_layer_p.MAT4[i]>> soil_layer_p.DENSE4[i]>>soil_layer_p.WATER4[i]>>
				soil_layer_p.vcond4[i]>> soil_layer_p.vsph4[i]>>soil_layer_p.cond4[i]>> soil_layer_p.spht4[i]>>
				soil_layer_p.condf4[i]>> soil_layer_p.sphf4[i]>> soil_layer_p.THICK5[i]>>soil_layer_p.DXA5[i]>>
				soil_layer_p.DXB5[i]>>soil_layer_p.MAT5[i]>>soil_layer_p.DENSE5[i]>>soil_layer_p.WATER5[i]>>
				soil_layer_p.vcond5[i]>>soil_layer_p.vsph5[i]>> soil_layer_p.cond5[i]>>soil_layer_p.spht5[i]>>
				soil_layer_p.condf5[i]>>soil_layer_p.sphf5[i]>>soil_layer_p.THICK6[i]>>soil_layer_p.DXA6[i]>>
				soil_layer_p.DXB6[i]>>soil_layer_p.MAT6[i]>>soil_layer_p.DENSE6[i]>>soil_layer_p.WATER6[i]>>update[i];*/
		}
		ifs.close();
	}
}
void soil::read_soil_temperature_parameter()
{
	const int varnum = 56;
	char header[varnum][10];
	int pftid[pftnum], update[pftnum];
	char pftname[pftnum][31];
	ifstream ifs;
	ifs.open(soil_temperature_pf, ios::in);
	if (!ifs) {
		cerr << "\nThe Soil temperature file:  " << soil_temperature_pf << " is invalid" << endl;
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

			/*ifs >>pftid[i] >> pftname[i]>> soil_temperature_p.INDEX[i]>> soil_temperature_p.VDEP[i]>> soil_temperature_p.NP[i];
			for (int j=0;j<25; j++)
			{
				ifs >> soil_temperature_p.DEPTH[i][j] >> soil_temperature_p.TEMP[i][j];
			}
			ifs >>update[i];*/
		}
		
	}
	ifs.close();
}
void soil::read_soil_parameter()
{
	long update;
	char header[12];
	ifstream ifs(soil_pf.c_str(), ios::in);
	if (!ifs)
	{
		cerr << "\nThe Soil file:  " << soil_pf << " is invalid" << endl;
		exit(-1);
	}
	else
	{
		ifs >> header >> header >> header;
		ifs >> header >> soil_p.pctpora >> update;
		ifs >> header >> soil_p.pctporb >> update;
		ifs >> header >> soil_p.fldcapa >> update;
		ifs >> header >> soil_p.fldcapb >> update;
		ifs >> header >> soil_p.wiltpta >> update;
		ifs >> header >> soil_p.wiltptb >> update;
		
	}
	ifs.close();
}