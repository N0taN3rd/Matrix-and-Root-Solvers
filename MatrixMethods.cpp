#include <algorithm>
#include <utility>
#include <iostream>
#include <cmath>

#include "MatrixMethods.h"
#include "MatVecUtil.h"

std::vector<double>* iterativeSolvers::jacobi(std::vector<std::vector<double>*>* mat, std::vector<double>* b){
    int n = b->size();
    int iterations = 0;
    double tNorm = 0.0, tNormThresh = 0.000001;
    std::vector<double>* xOld = new std::vector<double>(n,0.0);
    std::vector<double>* xNew = new std::vector<double>();
    std::cout<<"Jacobi Start "<<std::endl;
    while(true){

         for(int i = 0; i < n; ++i){
            double d = 0.0;
            //LU[i][j] * xOld[j]
            for(int j = 0; j < n; ++j)
               if(i != j)
                 d += mat->at(i)->at(j)*xOld->at(j);
            //xNew[i] = 1/A[i][i] * (b[i] - xOld[i])
            xNew->push_back((1 / mat->at(i)->at(i)) * (b->at(i) - d));
        }
        double nSum = 0.0;
        //two norm
        for(int ii = 0; ii < n; ++ii){
            double d = 0.0, t = 0.0;
            //bAprox[i] = A[i][j]*xNew[j]
            for(int jj = 0; jj < n; ++jj)
                d += mat->at(ii)->at(jj) * xNew->at(jj);
            //bReal[i] - bAprox[i]
            t = b->at(ii) - d;
            nSum += t * t;
        } tNorm = sqrt(nSum);

        if(tNorm < tNormThresh)
            break;
        //make xOld = xNew
        std::move(xNew->begin(),xNew->end(),xOld->begin());
        xNew->clear();
        ++iterations;
    }

    std::cout<<"Jacobi solution after "<<iterations<<" iterations"<<std::endl;
    std::cout<<"The relative error of the solution is "<<MatVecUtil::relativeError(mat,xNew,b)<<std::endl;

    delete xOld;

    return xNew;
}



std::vector<double>* iterativeSolvers::gaussSeidel(std::vector<std::vector<double>*>* mat, std::vector<double>* b){

    int n = b->size();
    int iterations = 0;
    double tNorm = 1.0, tNormThresh = 0.000001;
    std::vector<double>* x = new std::vector<double>(n,0.0);
    std::cout<<"Gauss Siedel Start "<<std::endl;
    while(true){
         for(int i = 0; i < n; ++i){
            double d = 0.0;
            //LU[i,j] * x[j]
            for(int j = 0; j < n; ++j)
                if(i != j)
                    d += mat->at(i)->at(j) * x->at(j);

             //x[i] = 1/A[i,i] * [b[i]  - (LU[i,j] * x[j])]
            (*x)[i] = (1/mat->at(i)->at(i)) * (b->at(i) - d);
        }
       // std::cout<<"After first loop"<<std::endl;
        //determine two norm
        double sum = 0.0;
        for(int i=0; i < n; ++i){
            double d = 0.0,  t = 0.0;
            //std::cout<<i<<std::endl;
            //bProx[i] = sum(A[i][j] * x[j]) for i,j = [0,(n-1)]
            for(int j =0; j < n; ++j){
                d += mat->at(i)->at(j) * x->at(j);
                //std::cout<<j<<std::endl;
            }
             //bReal[i] - baprox[i]
            t = b->at(i) - d;
            //std::cout<<"after t="<<std::endl;

            //two norm of (bReal[i] - bProx[i])
            sum += t * t;
        } tNorm = sqrt(sum);

       //convergance test tNorm < 10^-5
        if(tNorm < tNormThresh)
            break;
       ++iterations;
    }
    std::cout<<"Gauss Seidel solution after "<<iterations<<" iterations"<<std::endl;
    std::cout<<"The relative error of the solution is "<<MatVecUtil::relativeError(mat,x,b)<<std::endl;

    return x;
}


std::vector<double>* iterativeSolvers::SOR(std::vector<std::vector<double>*>* mat,std::vector<double>* b,double w = 1.0){
    int n = b->size();
    int iterations = 0;
    double tNorm = 1.0, tNormThresh = 0.000001;
    std::vector<double>* x = new std::vector<double>(n,0.0);
    std::cout<<"SOR Start "<<std::endl;
    while(true){

         for(int i = 0; i < n; ++i){
            double d = 0.0;
            //LU[i,j] * x[j]
            for(int j = 0; j < n; ++j)
                if(i != j)
                    d += mat->at(i)->at(j) * x->at(j);

            //x[current iteration] = x[current iteration] + omega * (answere[current iteration] - sum(mat[i][0-(n-1)]) * diagInv) - x[current iteration]
            (*x)[i] = (*x)[i] + w * ( ( (b->at(i) - d ) * 1/mat->at(i)->at(i) ) - (*x)[i]);
        }
        //determine two norm
        double sum = 0.0;
        for(int i=0; i < n; ++i){
            double d = 0.0,  t = 0.0;
            //bProx[i] = sum(A[i][j] * x[j]) for i,j = [0,(n-1)]
            for(int j =0; j < n; ++j)
                d += mat->at(i)->at(j) * x->at(j);

            //bReal[i] - baprox[i]
            t = b->at(i) - d;

            //two norm of (bReal[i] - bProx[i])
            sum += t * t;
        } tNorm = sqrt(sum);

        //convergance test tNorm < 10^-5
        if(tNorm < tNormThresh)
            break;
        ++iterations;
    }
    std::cout<<"SOR solution after "<<iterations<<" iterations"<<std::endl;
    std::cout<<"The relative error of the solution is "<<MatVecUtil::relativeError(mat,x,b)<<std::endl;
    return x;
}



//correct
std::vector<double>* nonIterativeSolvers::gaussianElmination(std::vector<std::vector<double>*>* mat,std::vector<double>* b){
    std::cout<<"Starting GE"<<std::endl;
    int n = b->size();
    int nn = n - 1;
    std::vector<double>* x = new std::vector<double>(n,0.0);

    for(int i = 0; i < n; ++i){
        double diagonal = mat->at(i)->at(i);
        //make diagonal 1
        for(int j = 0; j < n; ++j)
            (*mat->at(i))[j] /= diagonal;
         //update b
        (*b)[i] /= diagonal;
        //update below the diagonal
        for(int k = i+1; k <n; ++k){
            double scale = -1.0 * mat->at(k)->at(i);
            for(int l = i; l < n; ++l)
                (*mat->at(k))[l] += scale * mat->at(i)->at(l);
            (*b)[k] += scale * b->at(i);
        }
    }
    std::cout<<"BackSub"<<std::endl;
    //back sub
    for(int i = nn; i >= 0; --i){
        double d = 0.0;
        for(int j = i + 1; j < n; ++j)
            d += mat->at(i)->at(j) * x->at(j);
        (*x)[i] = b->at(i) - d;

    }
    std::cout<<"The Gaussian Elmination relative error of the solution is "<<MatVecUtil::relativeError(mat,x,b)<<std::endl;
    return x;
}


//correct
std::vector<double>* nonIterativeSolvers::luDecomposition(std::vector<std::vector<double>*>* mat,std::vector<double>* b){
    int n = b->size();
    int nn = n - 1;

    std::cout<<"Starting LU"<<std::endl;
    std::vector<double>* x = new std::vector<double>(*b);

    std::vector<std::vector<double>*>* l = new std::vector<std::vector<double>*>();
    std::vector<std::vector<double>*>* u = new std::vector<std::vector<double>*>();
    for(int i = 0; i < n; ++i){
        l->push_back(new std::vector<double>(n,0.0));
        u->push_back(new std::vector<double>(n,0.0));
    }
    std::cout<<"LU making ut lt"<<std::endl;
    for(int i = 0; i < n; ++i){
        (*l->at(i))[i] = 1.0;
        //loop for the upper triag
        for(int j = i; j < n; ++j){
            (*u->at(i))[j] = mat->at(i)->at(j);
            if(i > 0)
                for(int k = 0; k < i; ++k)
                   (*u->at(i))[j] -= l->at(i)->at(k) * u->at(k)->at(j);
        }
         //loop for the lower triag
        for(int j = i+1; j < n; ++j){
            (*l->at(j))[i] = mat->at(j)->at(i);
            if(i > 0)
                for(int k = 0; k < i; ++k)
                    (*l->at(j))[i] -= l->at(j)->at(k) * u->at(k)->at(i);
            (*l->at(j))[i] /= u->at(i)->at(i);
        }
    }
    std::cout<<"LU forward sub"<<std::endl;
    //forward sub
    for(int i = 1; i < n; ++i){
        //double d = x->at(i);
        for(int j = 0; j < i; ++j)
           (*x)[i] -= l->at(i)->at(j) * x->at(j);
        //(*x)[i] = d;
    }
    std::cout<<"Lu backsub"<<std::endl;
    //back sub
    for(int i = nn; i >= 0; --i){
        double d = 0.0;
        for(int j = i + 1; j < n; ++j)
            d += u->at(i)->at(j) * x->at(j);
        (*x)[i] = ((*x)[i] - d) / u->at(i)->at(i);
    }

    std::cout<<"The LU Decomposition relative error of the solution is "<<MatVecUtil::relativeError(mat,x,b)<<std::endl;
     for(int i = 0; i < n; ++i){
        delete l->at(i);
        delete u->at(i);
     }

     delete l;
     delete u;

    return x;

}

