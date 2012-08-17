//=============================================================================
/*! dgels_check */
void dgels_check_vector()
{
  cout << "############ check dgels vector ############" << endl;
  
  srand(time(NULL));
  int M(3), N(2);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,N);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}
  
  //// make dcovector y  ////
  CPPL::dcovector y(M);
  for(int i=0; i<y.l; i++){
    y(i) =double( rand() /(RAND_MAX/10) );
  }
  
  //// make originals ////
  CPPL::dgematrix A_original(A);
  CPPL::dcovector y_original(y);
  
  //// dgels ////
  A.dgels(y);
  
  //// print ////
  cout << "######## dgels(vec) ########" << endl;
  cout << "A_original=\n" << A_original << endl;
  cout << "y_original=\n" << y_original << endl;
  cout << "A=\n" << A << endl;
  cout << "y=\n" << y << endl;
  cout << "A_original*y=\n" << A_original*y << endl;
  
  //// reset ////
  A =A_original;
  y =y_original;
  double r; //residual square
  
  //// dgels ////
  A.dgels(y,r);
  
  //// print ////
  cout << "######## dgels(vec, residual) ########" << endl;
  cout << "A_original=\n" << A_original << endl;
  cout << "y_original=\n" << y_original << endl;
  cout << "A=\n" << A << endl;
  cout << "y=\n" << y << endl;
  cout << "residual=" << r << endl;
  cout << "A_original*y=\n" << A_original*y << endl;
}

//==============================================================================
void dgels_check_matrix()
{
  cout << "############ check dgels matrix ############" << endl;
  
  srand(time(NULL));
  int M(3), N(2);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,N);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}

  //// make dgematrix Y  ////
  CPPL::dgematrix Y(M,M);
  for(int i=0; i<Y.m; i++){ for(int j=0; j<Y.n; j++){
    Y(i,j) =double( rand() /(RAND_MAX/10) );
  }}
   
  //// make originals ////
  CPPL::dgematrix A_original(A);
  CPPL::dgematrix Y_original(Y);
  
  //// dgels ////
  A.dgels(Y);
  
  //// print ////
  cout << "######## dgels(mat) ########" << endl;
  cout << "A_original=\n" << A_original << endl;
  cout << "Y_original=\n" << Y_original << endl;
  cout << "A=\n" << A << endl;
  cout << "Y=\n" << Y << endl;
  cout << "A_original*Y=\n" << A_original*Y << endl;
  
  //// reset ////
  A =A_original;
  Y =Y_original;
  CPPL::drovector R; //residual square
  
  //// dgels ////
  A.dgels(Y,R);
  
  //// print ////
  cout << "######## dgels(mat, residual) ########" << endl;
  cout << "A_original=\n" << A_original << endl;
  cout << "Y_original=\n" << Y_original << endl;
  cout << "A=\n" << A << endl;
  cout << "Y=\n" << Y << endl;
  cout << "residual=" << R << endl;
  cout << "A_original*Y=\n" << A_original*Y << endl;  
}
