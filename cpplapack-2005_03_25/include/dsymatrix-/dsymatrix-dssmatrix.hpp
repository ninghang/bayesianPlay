//=============================================================================
/*! dsymatrix+dssmatrix operator */
inline _dgematrix operator+(const dsymatrix& matA, const dssmatrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator+(const dsymatrix&, const dssmatrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.M || matA.N!=matB.N){
    std::cerr << "[ERROR] operator+(const dsymatrix&, const dssmatrix&)"
              << std::endl
              << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.N << "x" << matA.N << ") + ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(matA);
  for(long c=0; c<matB.VOL; c++){
    newmat(matB.Indx[c],matB.Jndx[c]) += matB.Array[c];
  }
  
  return _(newmat);
}

//=============================================================================
/*! dsymatrix-dssmatrix operator */
inline _dgematrix operator-(const dsymatrix& matA, const dssmatrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator-(const dsymatrix&, const dssmatrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.M || matA.N!=matB.N){
    std::cerr << "[ERROR] operator-(const dsymatrix&, const dssmatrix&)"
              << std::endl
              << "These two matrises can not make a subtraction." << std::endl
              << "Your input was (" << matA.N << "x" << matA.N << ") - ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG

  dgematrix newmat(matA);
  for(long c=0; c<matB.VOL; c++){
    newmat(matB.Indx[c],matB.Jndx[c]) -= matB.Array[c];
  }
  
  return _(newmat);
}

//=============================================================================
/*! dsymatrix*dssmatrix operator */
inline _dgematrix operator*(const dsymatrix& matA, const dssmatrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator*(const dsymatrix&, const dssmatrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.M){
    std::cerr << "[ERROR] operator*(const dsymatrix&, const dssmatrix&)"
              << std::endl
              << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.N << "x" << matA.N << ") * ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dgematrix newmat(matA.N, matB.N);
  newmat.zero();
  
  for(long c=0; c<matB.VOL; c++){
    for(long i=0; i<matA.N; i++){
      newmat(i,matB.Jndx[c]) += matA(i,matB.Indx[c])*matB.Array[c];
    }
  }
  
  return _(newmat);
}
