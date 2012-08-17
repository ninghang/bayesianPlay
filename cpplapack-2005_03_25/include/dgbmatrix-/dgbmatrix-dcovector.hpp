//=============================================================================
/*! dgbmatrix*dcovector operator */
inline _dcovector operator*(const dgbmatrix& mat, const dcovector& vec)
{
#ifdef  CPPL_VERBOSE
  std::cerr << "# [MARK] operator*(const dgbmatrix&, const dcovector&)"
            << std::endl;
#endif//CPPL_VERBOSE
  
#ifdef  CPPL_DEBUG
  if(mat.N!=vec.L){
    std::cerr << "[ERROR] operator*(const dgbmatrix&, const dcovector&)"
              << std::endl
              << "These matrix and vector can not make a product." << std::endl
              << "Your input was (" << mat.M << "x" << mat.N << ") * ("
              << vec.L << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  dcovector newvec(mat.M);
  dgbmv_( 'N', mat.M, mat.N, mat.KL, mat.KU, 1.0, mat.Array,
          mat.KL+mat.KU+1, vec.Array, 1, 0.0, newvec.Array, 1 );
  
  return _(newvec);
}
