#ifndef MATVECUTIL_H_INCLUDED
#define MATVECUTIL_H_INCLUDED

#include<vector>

namespace MatVecUtil{
    double relativeError(std::vector<std::vector<double>*>* mat, std::vector<double>* x, std::vector<double>* b);
    double relativeError2(std::vector<std::vector<double>*>* mat, std::vector<double>* x, std::vector<double>* b);
    double sqrtOfSumSqrs(std::vector<double>* a);
    double dotProduct(std::vector<double>* a, std::vector<double>* b);
    std::vector<double>* matTimesVect(std::vector<std::vector<double>*>* mat, std::vector<double>* vec);
    std::vector<double>* vectorMinus(std::vector<double>* a, std::vector<double>* b);
    std::vector<double>* vectorPlus(std::vector<double>* a, std::vector<double>* b);
    void print(std::vector<std::vector<double>*>* mat);
    void print(std::vector<double>* vec);
}

#endif // MATVECUTIL_H_INCLUDED
