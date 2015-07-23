#ifndef ROOTOPERATIONS_H_INCLUDED
#define ROOTOPERATIONS_H_INCLUDED
#include <iostream>
#include <string>
#include "FunctionFactor.h"
#include "Function.h"
#include "MenuSelections.h"
#include "Roots.h"

class RootOperations{
public:
    RootOperations();
    ~RootOperations();
    void operations();
private:
    void build();
    void getxs();
    bool validxs();
    FunctionFactory ff;
    Function* f = nullptr;
    double x0, x1;
    std::string c;
};

#endif // ROOTOPERATIONS_H_INCLUDED
