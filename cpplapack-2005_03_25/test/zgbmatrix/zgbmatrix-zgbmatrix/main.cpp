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
  int M(4), N(3), KL(2), KU(1);
  
  CPPL::zgbmatrix A(M,N,KL,KU);
  for(int i=0; i<A.m; i++){
    for(int j=CPPL::max(0,i-A.kl); j<CPPL::min(A.n,i+A.ku+1); j++){
      A(i,j) =complex<double>(rand()/(RAND_MAX/10), rand()/(RAND_MAX/10));
    }
  }
  cout << "A =\n" << A << endl;
  
  CPPL::zgbmatrix B;
  cout << "#### B=A; ####" << endl;
  B=A;
  cout << "B =\n" << B << endl;
  
  cout << "#### B+=A; ####" << endl;
  B+=A;
  cout << "B =\n" << B << endl;

  cout << "#### B-=A; ####" << endl;
  B-=A;
  cout << "B =\n" << B << endl;
  
  cout << "A+B =\n" << A+B << endl;
  cout << "A-B =\n" << A-B << endl;
  
  CPPL::zgbmatrix P(8,10,2,3), Q(10,9,1,3), R;
  for(int i=0; i<P.m; i++){
    for(int j=CPPL::max(0,i-P.kl); j<CPPL::min(P.n,i+P.ku+1); j++){
      P(i,j) =complex<double>(rand()/(RAND_MAX/10), rand()/(RAND_MAX/10));
    }
  }
  for(int i=0; i<Q.m; i++){
    for(int j=CPPL::max(0,i-Q.kl); j<CPPL::min(Q.n,i+Q.ku+1); j++){
      Q(i,j) =complex<double>(rand()/(RAND_MAX/10), rand()/(RAND_MAX/10));
    }
  }
  CPPL::zgematrix P2(P), Q2(Q);
  cout << "P =\n" << P << endl;
  cout << "P2 =\n" << P2 << endl;
  cout << "Q =\n" << Q << endl;
  cout << "Q2 =\n" << Q2 << endl;
  cout << "P*Q =\n" << P*Q << endl;
  cout << "P2*Q2 =\n" << P2*Q2 << endl;
  cout << "P*Q - P2*Q2 =\n" << P*Q-P2*Q2 << endl;
  
  cout << "#### P*=Q; ####" << endl;
  P*=Q;
  cout << "P =\n" << P << endl;
  
  return 0;
}

/*****************************************************************************/
