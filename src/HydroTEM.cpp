#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "DataIO.h"
#include "parameter.h"
#include "TEM.h"

using namespace std;

int main(int argc, char** arguments)
{
	string config_file(arguments[1]);
	TEM tem(config_file);
	tem.read_configuration();
	tem.deploy_component();
	tem.run();
	return 1;
}

