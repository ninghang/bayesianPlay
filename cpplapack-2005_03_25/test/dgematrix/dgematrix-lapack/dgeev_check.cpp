//=============================================================================
void dgeev_check_value()
{
  cout << "############ check dgeev value ############" << endl;
  
  srand(time(NULL));
  int M(3);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,M);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}
  
  //// make wr wi vr ////
  vector<double> wr, wi;
  
  //// make A_original ////
  CPPL::dgematrix A_original(A);
  
  //// dgeev ////
  A.dgeev(wr, wi);
  
  //// print ////
  cout << "A_original=\n" << A_original << endl;
  for(int i=0; i<A.m; i++){
    cout << "#### " << i << "th eigen ####" << endl;
    cout << "wr=" << wr[i] <<endl;
    cout << "wi=" << wi[i] <<endl;
  }
}

//=============================================================================
void dgeev_check_right()
{
  cout << "############ check dgeev right ############" << endl;
  
  srand(time(NULL));
  int M(3);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,M);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}
  
  //// make wr wi vr ////
  vector<double> wr, wi;
  vector<CPPL::dcovector> vrr, vri;
  
  //// make A_original ////
  CPPL::dgematrix A_original(A);
  
  //// dgeev ////
  A.dgeev(wr, wi ,vrr, vri);
  
  //// print ////
  cout << "A_original=\n" << A_original << endl;
  for(int i=0; i<A.m; i++){
    cout << "#### " << i << "th eigen ####" << endl;
    cout << "wr=" << wr[i] <<endl;
    cout << "wi=" << wi[i] <<endl;
    cout << "vrr=\n" << vrr[i] <<endl;
    cout << "vri=\n" << vri[i] <<endl;
    cout << "Real[ [A]*{x} -lambda*{x} ] = (Should be zeros)\n"
         << A_original*vrr[i] -(wr[i]*vrr[i] - wi[i]*vri[i]) 
         << endl;
    cout << "Imag[ [A]*{x} -lambda*{x} ] = (Should be zeros)\n"
         << A_original*vri[i] -(wr[i]*vri[i] + wi[i]*vrr[i]) 
         << endl;
  }
}

//=============================================================================
void dgeev_check_left()
{
  cout << "############ check dgeev left ############" << endl;
  
  srand(time(NULL));
  int M(3);
  
  //// make dgematrix A  ////
  CPPL::dgematrix A(M,M);
  for(int i=0; i<A.m; i++){ for(int j=0; j<A.n; j++){
    A(i,j) =double( rand() /(RAND_MAX/10) );
  }}
  
  //// make wr wi vl ////
  vector<double> wr, wi;
  vector<CPPL::drovector> vlr, vli;
  
  //// make A_original ////
  CPPL::dgematrix A_original(A);
  
  //// dgeev ////
  A.dgeev(wr, wi ,vlr, vli);
  
  //// print ////
  cout << "A_original=\n" << A_original << endl;
  for(int i=0; i<A.m; i++){
    cout << "#### " << i << "th eigen ####" << endl;
    cout << "wr = " << wr[i] << endl;
    cout << "wi = " << wi[i] << endl;
    cout << "vlr = " << vlr[i];
    cout << "vli = " << vli[i] << endl;
    cout << "Real[ {x}*[A] -{x}*lambda ] = (Should be zeros)\n"
         << vlr[i]*A_original -(vlr[i]*wr[i] - vli[i]*wi[i]) 
         << endl;
    cout << "Imag[ {x}*[A] -{x}*lambda ] = (Should be zeros)\n"
         << vli[i]*A_original -(vli[i]*wr[i] + vlr[i]*wi[i]) 
         << endl;
  }
}
