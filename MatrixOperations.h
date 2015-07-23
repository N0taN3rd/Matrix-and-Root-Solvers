#ifndef MATRIXOPERATIONS_H_INCLUDED
#define MATRIXOPERATIONS_H_INCLUDED
#include<vector>
#include<string>
#include<iostream>

#include "ReadWriteMatrix.h"
#include "MatrixMethods.h"
#include "MatVecUtil.h"
#include "MenuSelections.h"

class MatrixOperations{
public:
    MatrixOperations();
    ~MatrixOperations();
    bool operations(std::string& c);
    void setFile(std::string file){this->file = file; userFileArg = true;}
private:
    void createBuild(std::string& c);
    std::string getFileName();
    std::vector<std::vector<double>*>* mat;
    std::vector<double>* b;
    std::vector<double>* x;
    double l,h,omega;
    int n;
    std::string meth,file;
    bool userFileArg,first;
};


#endif // MATRIXOPERATIONS_H_INCLUDED
