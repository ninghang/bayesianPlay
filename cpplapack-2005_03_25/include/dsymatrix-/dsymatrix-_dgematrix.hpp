//=============================================================================
/*! _dgematrix+dsymatrix operator */
inline _dgematrix operator+(const dsymatrix& matA, const _dgematrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator+(const dsymatrix&, const _dgematrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.N || matA.N!=matB.M){
    std::cerr << "[ERROR] operator+(_dsymatrix&, dgematrix&)" << std::endl
              << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.N << "x" << matA.N << ") + ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  for(long i=0; i<matA.N; i++) {
    for(long j=0; j<matA.N; j++) {
      matB(i,j)+=matA(i,j);
    }
  }
  
  return matB;
}

//=============================================================================
/*! _dgematrix-dgematrix operator */
inline _dgematrix operator-(const dsymatrix& matA, const _dgematrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator-(const dsymatrix&, const _dgematrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.N || matA.N!=matB.M){
    std::cerr << "[ERROR] operator-(_dsymatrix&, dgematrix&)" << std::endl
              << "These two matrises can not make a subtraction." << std::endl
              << "Your input was (" << matA.N << "x" << matA.N << ") - ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG

  for(long i=0; i<matA.N; i++){
    for(long j=0; j<matA.N; j++){
      matB(i,j) =matA(i,j)-matB(i,j);
    }
  }
  
  return matB;
}

//=============================================================================
/*! _dgematrix*dgematrix operator */
inline _dgematrix operator*(const dsymatrix& matA, const _dgematrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator*(const dsymatrix&, const _dgematrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.M){
    std::cerr << "[ERROR] operator*(_dsymatrix&, dgematrix&)" << std::endl
              << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.N << "x" << matA.N << ") * ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat( matA.N, matB.N );
  dsymm_( 'L', 'L', matA.N, matB.N, 1.0, matA.Array, matA.N, 
          matB.Array, matB.M, 0.0, newmat.array, newmat.m );
  
  matB.destroy();
  return _(newmat);
}
