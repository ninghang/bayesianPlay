//====================================================================[include]
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpplapack.h"
using namespace std;

#include "dsysv_check.cpp"
#include "dsyev_check.cpp"
#include "dsygv_check.cpp"

//=======================================================================[main]
/*! main */
int main(int argc, char** argv)
{
  //////// dsysv ////////
  dsysv_check_vector();
  dsysv_check_matrix();
  
  //////// dsyev ////////
  dsyev_check_value();
  dsyev_check_right();
  dsyev_check_left();
  
  //////// dsygv ////////
  dsygv_check_value();
  dsygv_check_both();
  
  return 0;
}
