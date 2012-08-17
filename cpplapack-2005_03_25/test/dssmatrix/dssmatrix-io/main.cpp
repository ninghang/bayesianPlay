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
  for(int c=0; c<A.vol; c++){
    cout << "A(" << A.indx[c] << "," << A.jndx[c] << ") ="
         << A.array[c] << endl;
  }

  
  //A.put(1,2, 4.5);
  //A.add(1,2, 0.1);
  //A.sub(1,2, 0.1);
  //A.mult(1,2, 10.);
  //A.div(1,2, 10.);
  //A.del(1,2);
  A.fdel(2);
  cout << "A =\n" << A << endl;
  
  const CPPL::dssmatrix B(A);
  //// write/read ////
  B.write( "tmp.txt" );
  
  CPPL::dssmatrix C;
  C.read( "tmp.txt" );
  cout << "C-B =\n" << C-B << "<-Should be zero." << endl;
  
  return 0;
}

/*****************************************************************************/
