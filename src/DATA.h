#pragma once

//C header

#include <stdio.h>
#include <math.h>

//C++ header
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>





using namespace std;

class Data
{
 public:
  Data(void);
  ~Data(void);
  //Traditional Data IO
  static	float * Read_Binary(string filename);
  static float ** Read_Binary(string filename,  int m, int n);
  //Data IO using PETSc
  //Mat Read_Binary(string filename,int m,int n);




};

