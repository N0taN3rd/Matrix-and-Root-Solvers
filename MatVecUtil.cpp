#include <cmath>
#include <iostream>
#include "MatVecUtil.h"


double MatVecUtil::relativeError(std::vector<std::vector<double>*>* mat, std::vector<double>* x, std::vector<double>* b){
    std::vector<double>* bp = MatVecUtil::matTimesVect(mat,x);
    std::vector<double>* m = MatVecUtil::vectorMinus(b,bp);
    double mm = MatVecUtil::sqrtOfSumSqrs(m), bb = MatVecUtil::sqrtOfSumSqrs(b);
    delete bp;
    delete m;
    return (mm / bb) * 100;
}

double MatVecUtil::relativeError2(std::vector<std::vector<double>*>* mat, std::vector<double>* x, std::vector<double>* b){
    std::vector<double>* bp = MatVecUtil::matTimesVect(mat,x);
    std::vector<double>* m = MatVecUtil::vectorMinus(b,bp);
    double error = 0.0;
    int len = bp->size();
    for(int i = 0; i < len; ++i){
        double er = sqrt((m->at(i)*m->at(i))/(b->at(i) * b->at(i)));
        std::cout<<"Error of b-approximate["<<i<<"]= "<<bp->at(i)<<" and b["<<i<<"]= "<<b->at(i)<<" is "<<er<<std::endl;
        error += er;
    }

    return error * 100;
}

double MatVecUtil::sqrtOfSumSqrs(std::vector<double>* a){
    double d = 0.0;
    for(auto dd : *a)
        d += dd * dd;
    return sqrt(d);
}

double MatVecUtil::dotProduct(std::vector<double>* a, std::vector<double>* b){
    double dp = 0.0;
    int len = a->size();
    for(int i = 0; i < len; ++i)
        dp += a->at(i) * b->at(i);
    return dp;
}

std::vector<double>* MatVecUtil::matTimesVect(std::vector<std::vector<double>*>* mat, std::vector<double>* vec){
    std::vector<double>* v = new std::vector<double>();
    int len = vec->size();
    for(int i = 0; i < len; ++i){
        double d = 0.0;
        for(int j = 0; j < len; ++j)
            d += mat->at(i)->at(j) * vec->at(j);
        v->push_back(d);
    }
    return v;
}

std::vector<double>* MatVecUtil::vectorMinus(std::vector<double>* a, std::vector<double>* b){
    std::vector<double>* v = new std::vector<double>();
    int len = b->size();
    for(int i = 0; i < len; ++i)
        v->push_back(a->at(i) - b->at(i));
    return v;
}


std::vector<double>* MatVecUtil::vectorPlus(std::vector<double>* a, std::vector<double>* b){
    std::vector<double>* v = new std::vector<double>();
    int len = b->size();
    for(int i = 0; i < len; ++i)
        v->push_back(a->at(i) + b->at(i));
    return v;
}

void MatVecUtil::print(std::vector<std::vector<double>*>* mat){
   for(auto v : *mat){
     for(auto d : *v){
        std::cout<<d<< " ";
     }
     std::cout<<std::endl;
   }
}


void MatVecUtil::print(std::vector<double>* vec){
    for(auto d : *vec)
        std::cout<<d<<" ";
    std::cout<<std::endl;
}

