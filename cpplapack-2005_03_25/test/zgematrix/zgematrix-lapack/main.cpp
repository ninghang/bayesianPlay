//====================================================================[include]
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpplapack.h"
using namespace std;


#include "zgesv_check.cpp"
#include "zgels_check.cpp"
#include "zgelss_check.cpp"
#include "zgeev_check.cpp"
//#include "zggev_check.cpp"
#include "zgesvd_check.cpp"

//=======================================================================[main]
/*! main */
int main(int argc, char** argv)
{
  zgesv_check_vector();
  zgesv_check_matrix();
  
  zgels_check_vector();
  zgels_check_matrix();
  
  zgelss_check();
  
  zgeev_check_value();
  zgeev_check_right();
  zgeev_check_left();
  
  //zggev_check_value();
  //zggev_check_right();
  //zggev_check_left();
  
  zgesvd_check();
  
  return 0;
}
