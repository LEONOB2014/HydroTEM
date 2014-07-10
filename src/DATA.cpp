#include "Data.h"

Data::Data(void)
{
}

Data::~Data(void)
{

}

float * Data::Read_Binary(string filename)
{		
  ifstream  ifs;
  ifs.open (filename.c_str(), ios::in | ios::binary);
  ifs.seekg(0,ios::end);
  long length=ifs.tellg();
  ifs.seekg(0,ios::beg);
  long length2 = length /sizeof(float);	
  float * data = new float[length2];	
  float temp;
  for (long i=0;i< length2;++i)
    {
      ifs.read( reinterpret_cast<char*>( &temp ), sizeof temp );
      data[i]=temp;
    }	
  return data;
}

float ** Data::Read_Binary(string filename,int m,int n)
{		
  float temp;
  ifstream  ifs;
  ifs.open (filename.c_str(), ios::in | ios::binary);
  float * data_temp = new float[m*n];	
  for (long i=0;i< m*n-1;++i)
    {
      ifs.read( reinterpret_cast<char*>( &temp ), sizeof temp );
      data_temp[i]=temp;
    }
  ifs.close();
  float ** data=new float *[m];
  for (int i=0;i < m;++i )
    {
      data[i]=data_temp + n * i ;
    }
  return data;
}


