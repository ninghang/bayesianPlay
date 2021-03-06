//=============================================================================
/*! _zrovector*_zgematrix operator */
inline _zrovector operator*(const _zrovector& vec, const _zgematrix& mat)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator*(const _zrovector&, const _zgematrix&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(vec.L!=mat.M){
    std::cerr << "[ERROR] operator*(const _zrovector&, const _zgematrix&)"
              << std::endl
              << "These vector and matrix can not make a product."
              << std::endl
              << "Your input was (" << vec.L << ") * ("
              << mat.M << "x" << mat.N << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zrovector newvec(mat.N);
  zgemv_( 'T', mat.M, mat.N, std::complex<double>(1.0,0.0), mat.Array, mat.M,
          vec.Array, 1, std::complex<double>(0.0,0.0), newvec.array, 1 );
  
  vec.destroy();
  mat.destroy();
  return _(newvec);
}
