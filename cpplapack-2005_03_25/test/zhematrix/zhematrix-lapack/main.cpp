//====================================================================[include]
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpplapack.h"
using namespace std;

#include "zhesv_check.cpp"
#include "zheev_check.cpp"
//#include "zhegv_check.cpp"

//=======================================================================[main]
/*! main */
int main(int argc, char** argv)
{
  zhesv_check_vector();
  zhesv_check_matrix();
  
  zheev_check_value();
  zheev_check_right();
  zheev_check_left();
  
  //zhegv_check_value();
  //zhegv_check_right();
  //zhegv_check_left();
  
  return 0;
}
