#ifndef MATRIXMETHODS_H_INCLUDED
#define MATRIXMETHODS_H_INCLUDED

#include<vector>


namespace iterativeSolvers{
    std::vector<double>* jacobi(std::vector<std::vector<double>*>*, std::vector<double>*);
    std::vector<double>* gaussSeidel(std::vector<std::vector<double>*>* mat, std::vector<double>* b);
    std::vector<double>* SOR(std::vector<std::vector<double>*>* mat,std::vector<double>* b,double w);
}

namespace nonIterativeSolvers{
    std::vector<double>* gaussianElmination(std::vector<std::vector<double>*>* mat,std::vector<double>* b);
    std::vector<double>* luDecomposition(std::vector<std::vector<double>*>* mat,std::vector<double>* b);
}

#endif // MATRIXMETHODS_H_INCLUDED
