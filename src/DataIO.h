#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
using namespace std;

class DataIO
{
public:
	DataIO(void);
	~DataIO(void);
	static	float * Read_Binary(string filename);
	static float ** Read_Binary(string filename,  int m, int n);
};

