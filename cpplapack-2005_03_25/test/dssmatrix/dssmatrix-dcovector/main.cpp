/*****************************************************************************/
/*                                 noname                                    */
/*****************************************************************************/

//====================================================================[include]
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpplapack.h"
using namespace std;

//=======================================================================[main]
/*! main */
int main(int argc, char** argv)
{
  srand(time(NULL));
  int M(5), N(3), CAP(4);
  
  CPPL::dssmatrix A(M,N,CAP);
  A.fput(0,0, 1.);
  A.fput(3,2, 2.);
  A.fput(1,2, 3.);
  A.fput(4,1, 4.);
  cout << "A =\n" << A << endl;
  
  CPPL::dcovector x(N);
  for(int i=0; i<x.l; i++){
    x(i) =double( rand() /(RAND_MAX/10) );
  }
  cout << "x =\n" << x << endl;
  
  cout << "A*x =\n" << A*x << endl;
  
  return 0;
}

/*****************************************************************************/
