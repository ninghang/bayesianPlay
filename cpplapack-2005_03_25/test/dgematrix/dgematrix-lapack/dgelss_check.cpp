//=============================================================================
/*! dgelss_check_vector */
void dgelss_check_vector()
{
  cout << "############ check dgelss vector ############" << endl;
  
  srand(time(NULL));
  int M(3), N(4);
  long RANK(0);
  double RCOND(-1.0);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,N);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}

  //// make dcovector b  ////
  CPPL::dcovector b(M);
  for(int i=0; i<b.l; i++){
    b(i) =double( rand() /(RAND_MAX/10) );
  }

  //// make dcovector s  ////
  CPPL::dcovector s;
   
  //// make A_original ////
  CPPL::dgematrix A_original(A);
  
  //// make A_original ////
  CPPL::dcovector b_original(b);
  
  //// dgels ////
  A.dgelss(b,s,RANK,RCOND);
  
  //// print ////
  cout << "A_original=\n" << A_original << endl;
  cout << "b_original=\n" << b_original << endl;
  cout << "A=\n" << A << endl;
  cout << "b=\n" << b << endl;
  cout << "s=\n" << s << endl;
  cout << "A_original*b=\n" << A_original*b << endl;
}


//=============================================================================
/*! dgelss_check_matrix */
void dgelss_check_matrix()
{
  cout << "############ check dgelss matrix ############" << endl;
  
  srand(time(NULL));
  int M(3), N(4);
  long RANK(0);
  double RCOND(-1.0);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,N);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}

  //// make dgematrix B  ////
  CPPL::dgematrix b(M,2);
  for(int i=0; i<b.m; i++){
    for(int j=0; j<b.n; j++){
      b(i,j) =double( rand() /(RAND_MAX/10) );
    }
  }
  
  //// make dcovector s  ////
  CPPL::dcovector s;
   
  //// make A_original ////
  CPPL::dgematrix A_original(A);
  
  //// make b_original ////
  CPPL::dgematrix b_original(b);
  
  //// dgels ////
  A.dgelss(b,s,RANK,RCOND);
  
  //// print ////
  cout << "A_original=\n" << A_original << endl;
  cout << "b_original=\n" << b_original << endl;
  cout << "A=\n" << A << endl;
  cout << "b=\n" << b << endl;
  cout << "s=\n" << s << endl;
  cout << "A_original*b=\n" << A_original*b << endl;
}
