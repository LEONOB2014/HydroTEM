#include "vegetation.h"


vegetation::vegetation(void)
{	
	//the plant function type could be prepared another way.
	string pft_t[]=	{"ice" ,
		"alpine_tundra_&_polar_desert" ,
		"wet_tundra" ,
		"boreal_forest",
		"temperate_coniferous_forests", 
		"temperate_deciduous_forests" ,  
		"grasslands",
		"xeric_shrublands"  ,
		"tropical_forests"  ,
		"xeric_woodlands"   ,
		"temperate_evergreen_broadleaf"
		"croplands"};
	for (int i=0;i<pftnum;i++)
	{
		pft.push_back(pft_t[i]);
	}
}
vegetation::~vegetation(void)
{
}
float ** vegetation::read_vegetation_type()
{
	float ** pftname= DataIO::Read_Binary(vegetation_f,global_row,global_col);
	return pftname;
}
void vegetation::read_pft_parameter()
{
	for (int i=0;i< pftnum;++i)
	{		 
		string pft_f=workspace_p+pft[i] +".ini";
		char header[12];
		char sitename[80];
		float sitecol;
		float siterow;
		long updated;
		double temp;
		ifstream ifs;
		ifs.open(pft_f.c_str(),ios::in);
		if (!ifs)
		{
			cerr << endl << "Cannot open " << pft_f << " for data input" << endl;
			exit(-1);
		}
		else
		{
			ifs >> header >> pft_p[i].id;
			ifs >> header >> pft_p[i].name;
			ifs >> header >> sitename;
			ifs >> header >> sitecol;
			ifs >> header >> siterow;
			ifs >> header >> updated;

			ifs >> header >> pft_p[i].ca;
			ifs >> header >> pft_p[i].cb;
			ifs >> header >> pft_p[i].strna;
			ifs >> header >> pft_p[i].strnb;
			ifs >> header >> pft_p[i].solca;
			ifs >> header >> pft_p[i].solcb;
			ifs >> header >> pft_p[i].solna;
			ifs >> header >> pft_p[i].solnb;
			ifs >> header >> pft_p[i].avlna;
			ifs >> header >> pft_p[i].avlnb;
			ifs >> header >> pft_p[i].stona;
			ifs >> header >> pft_p[i].stonb;

			ifs >> header >>  pft_p[i].unleaf12;

			ifs >> header >> pft_p[i].initleafmx;

			ifs >> header >>  pft_p[i].cmaxcut;
			ifs >> header >>  pft_p[i].cmax1a;
			ifs >> header >>  pft_p[i].cmax1b;
			ifs >> header >>  pft_p[i].cmax2a;
			ifs >> header >>  pft_p[i].cmax2b;
			ifs >> header >>  pft_p[i].cfall;
			ifs >> header >>  pft_p[i].kra;
			ifs >> header >>  pft_p[i].krb;
			ifs >> header >> temp;//microbe.kda;
			ifs >> header >> temp;//microbe.kdb[veg.cmnt];
			ifs >> header >> temp;//microbe.lcclnc[veg.cmnt];
			ifs >> header >> temp;//microbe.propftos[veg.cmnt];
			ifs >> header >>  pft_p[i].nmaxcut;
			ifs >> header >>  pft_p[i].nmax1a;
			ifs >> header >>  pft_p[i].nmax1b;
			ifs >> header >>  pft_p[i].nmax2a;
			ifs >> header >>  pft_p[i].nmax2b;
			ifs >> header >>  pft_p[i].nfall;
			ifs >> header >> temp;//microbe.nupa[veg.cmnt];
			ifs >> header >> temp;//microbe.nupb[veg.cmnt];
			ifs >> header >> temp;//soil.nloss[veg.cmnt];
			ifs >> header >> temp;//microbe.nfixpar[veg.cmnt];
			ifs >> header >>  pft_p[i].initcneven;
			ifs >> header >>  pft_p[i].cnmin;
			ifs >> header >>  pft_p[i].c2na;
			ifs >> header >>  pft_p[i].c2nb;
			ifs >> header >>  pft_p[i].c2nmin;
			ifs >> header >> temp; //microbe.cnsoil[veg.cmnt];
		}
		ifs.close();
	}
}
void vegetation::read_vegetation_parameter()
{	
	const int varnum = 21;
	char header[varnum][10];
	int pftid[pftnum];
	char pftname[pftnum][31];
	long update[pftnum];
	ifstream ifs;
	ifs.open(vegetation_f, ios::in);
	if (!ifs)
	{
		cerr << "\nThe vegetation file:  " << vegetation_f << " is invalid" << endl;
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
			ifs >> pftid[j] >> pftname[j];
			ifs >> vegetation_p.kc[j];
			ifs >> vegetation_p.ki[j];
			ifs >> vegetation_p.gva[j];
			ifs >> vegetation_p.tmin[j];
			ifs >> vegetation_p.toptmin[j];
			ifs >> vegetation_p.toptmax[j];
			ifs >> vegetation_p.tmax[j];
			ifs >> vegetation_p.raq10a0[j];
			ifs >> vegetation_p.raq10a1[j];
			ifs >> vegetation_p.raq10a2[j];
			ifs >> vegetation_p.raq10a3[j];
			ifs >> vegetation_p.kn1[j];
			ifs >> vegetation_p.labncon[j];
			ifs >> vegetation_p.leafmxc[j];
			ifs >> vegetation_p.kleafc[j];
			ifs >> vegetation_p.sla[j];
			ifs >> vegetation_p.cov[j];
			ifs >> vegetation_p.fpcmax[j];
			ifs >> update[j];
		}
	}
	ifs.close();
}
void vegetation::read_root_depth_parameter()
{
	const int varnum = 7;
	char header[varnum][10];	
	int  pftid[pftnum];
	char pftname[pftnum][32];
	long update[pftnum];
	ifstream ifs;
	ifs.open(root_depth_f, ios::in);
	if (!ifs)
	{
		cerr << "\nCannot open " << root_depth_f << " for data input" << endl;
		exit(-1);
	}
	else
	{
		for (int i = 0; i < varnum; i++)
		{
			ifs >> header[i]; 
		}
		for (int j = 1; j < pftnum; j++)
		{
			ifs >> pftid[j] >> pftname[j];
			ifs >> root_depth_p.rootza[j] >> root_depth_p.rootzb[j] >> root_depth_p.rootzc[j];
			ifs >> root_depth_p.minrootz[j] >> update[j];
		}
	}
	ifs.close();
}
void vegetation::read_leaf_parameter()
{	
	const int varnum = 7;
	char header[varnum][8];	
	int pftid[pftnum];
	char pftname[pftnum][32];
	int update[pftnum];
	ifstream ifs;
	ifs.open(leaf_f, ios::in);
	if (!ifs)
	{
		cerr << "\nCannot open " << leaf_f << " for data input" << endl;
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
			ifs >> pftid[j] >> pftname[j];
			ifs >> leaf_p.minleaf[j];
			ifs >> leaf_p.aleaf[j];
			ifs >> leaf_p.bleaf[j];
			ifs >> leaf_p.cleaf[j];
			ifs >> update[j];	
		}
	}
	ifs.close();
}