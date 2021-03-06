//=============================================================================
/*! zgematrix+_zssmatrix operator */
inline _zgematrix operator+(const zgematrix& matA, const _zssmatrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator+(const zgematrix&, const _zssmatrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.M!=matB.M || matA.N!=matB.N){
    std::cerr << "[ERROR] operator+(const zgematrix&, const _zssmatrix&)"
              << std::endl
              << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.M << "x" << matA.N << ") + ("
              << matB.M << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat(matA);
  for(long c=0; c<matB.VOL; c++){
    newmat(matB.Indx[c],matB.Jndx[c]) += matB.Array[c];
  }
  
  matB.destroy();
  return _(newmat);
}

//=============================================================================
/*! zgematrix-_zssmatrix operator */
inline _zgematrix operator-(const zgematrix& matA, const _zssmatrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator-(const zgematrix&, const _zssmatrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.M!=matB.M || matA.N!=matB.N){
    std::cerr << "[ERROR] operator-(const zgematrix&, const _zssmatrix&)"
              << std::endl
              << "These two matrises can not make a subtraction." << std::endl
              << "Your input was (" << matA.M << "x" << matA.N << ") - ("
              << matB.N << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG

  zgematrix newmat(matA);
  for(long c=0; c<matB.VOL; c++){
    newmat(matB.Indx[c],matB.Jndx[c]) -= matB.Array[c];
  }
  
  matB.destroy();
  return _(newmat);
}

//=============================================================================
/*! zgematrix*_zssmatrix operator */
inline _zgematrix operator*(const zgematrix& matA, const _zssmatrix& matB)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator*(const zgematrix&, const _zssmatrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(matA.N!=matB.M){
    std::cerr << "[ERROR] operator*(const zgematrix&, const _zssmatrix&)"
              << std::endl
              << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.M << "x" << matA.N << ") * ("
              << matB.N << "x" << matB.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat(matA.M, matB.N);
  newmat.zero();
  
  for(long c=0; c<matB.VOL; c++){
    for(long i=0; i<matA.M; i++){
      newmat(i,matB.Jndx[c]) += matA(i,matB.Indx[c])*matB.Array[c];
    }
  }
  
  matB.destroy();
  return _(newmat);
}
