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
  int M(5), N(5), CAP(4);
  
  CPPL::dssmatrix A(M,N,CAP);
  A.fput(0,0, 1.);
  A.fput(3,2, 2.);
  A.fput(1,2, 3.);
  A.fput(4,1, 4.);
  cout << "A =\n" << A << endl;
  
  CPPL::dsymatrix B(N);
  for(int i=0; i<A.n; i++){ for(int j=0; j<=i; j++){
    B(i,j) =double( rand() /(RAND_MAX/10) );
  }}
  cout << "B =\n" << B << endl;
  
  //cout << "A+B =\n" << A+B << endl;
  cout << "A-B =\n" << A-B << endl;
  cout << "A*B =\n" << A*B << endl;
  
  return 0;
}

/*****************************************************************************/
