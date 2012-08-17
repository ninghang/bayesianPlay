/*****************************************************************************/
/*                                 noname                                    */
/*****************************************************************************/

//====================================================================[include]
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpplapack.h"

//=======================================================================[main]
/*! main */
int main(int argc, char** argv)
{
  srand(time(NULL));
  int M(5), N(5), CAP(4);
  int KL(1), KU(2);
  
  CPPL::dssmatrix A(M,N,CAP);
  A.fput(0,0, 1.);
  A.fput(3,2, 2.);
  A.fput(1,2, 3.);
  A.fput(4,1, 4.);
  std::cout << "A =\n" << A << std::endl;
  
  CPPL::dgbmatrix B(M,N,KL,KU);
  for(int i=0; i<B.m; i++){
    for(int j=CPPL::max(0,i-B.kl); j<CPPL::min(B.n,i+B.ku+1); j++){
      B(i,j) =double( rand() /(RAND_MAX/10) );
    }
  }
  std::cout << "B =\n" << B << std::endl;
  
  std::cout << "A+B =\n" << A+B << std::endl;
  std::cout << "A-B =\n" << A-B << std::endl;
  std::cout << "A*B =\n" << A*B << std::endl;
  
  return 0;
}

/*****************************************************************************/
