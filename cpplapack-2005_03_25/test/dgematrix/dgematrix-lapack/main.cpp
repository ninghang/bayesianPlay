//====================================================================[include]
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpplapack.h"
using namespace std;


#include "dgesv_check.cpp"
#include "dgels_check.cpp"
#include "dgelss_check.cpp"
#include "dgeev_check.cpp"
#include "dggev_check.cpp"
#include "dgesvd_check.cpp"

//=======================================================================[main]
/*! main */
int main(int argc, char** argv)
{
  //////// dgesv ////////
  dgesv_check_vector();
  dgesv_check_matrix();
  
  //////// dgels ////////
  dgels_check_vector();
  dgels_check_matrix();
  
  //////// dgelss ////////
  dgelss_check_vector();
  dgelss_check_matrix();
  
  //////// dgeev ////////
  dgeev_check_value();
  dgeev_check_right();
  dgeev_check_left();
  
  //////// dggev ////////
  dggev_check_value();
  dggev_check_right();
  dggev_check_left();
  
  //////// dgesvd ////////
  dgesvd_check();
  
  return 0;
}
