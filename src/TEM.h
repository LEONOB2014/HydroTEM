#pragma once

//The C/C++ library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <iterator>

//PARA
#include "PARA.h"
//SHAR memory and data
#include "SHAR.h"

//Packages library
#include "ATMO.h"
#include "EVAP.h"
#include "GEOL.h"
#include "LAKE.h"
#include "MICR.h"
#include "PERM.h"
#include "RECH.h"
#include "RIVE.h"
#include "SNOW.h"
#include "SOIL.h"
#include "STRE.h"
#include "VEGE.h"

using namespace std;

class TEM
{
 public:
  TEM(void);
  TEM(string sConfig_file);
  ~TEM(void);

  //declare package classes
  ATMO cATMO;	
  EVAP cEVAP;
  GEOL cGEOL;
  LAKE cLAKE;
  MICR cMICR;
  PERM cPERM;
  RECH cRECH;
  RIVE cRIVE;
  SNOW cSNOW;
  SOIL cSOIL;
  STRE cSTRE;
  VEGE cVEGE;
	

  //ifstream  f_soil;

  string configuration_f;
  struct config_parameter
  {
    //workspace
    string workspace;
    //parameters
    string parameter_file;

    //package list
    string ATMO_file;

		
  }config_p;




  void ReadConfiguration();
  void Deploy();
  void Run();

};

