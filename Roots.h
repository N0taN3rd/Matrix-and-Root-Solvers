#ifndef ROOTS_H_INCLUDED
#define ROOTS_H_INCLUDED
#include "Function.h"
#include <string>

namespace rootFinders{
    double bisectionMethod(std::string fname,double a, double b, Function& f);
    double falsiMethod(std::string fname,double a, double b, Function& f);
    double newtonMethod(std::string fname,double a, Function& f);
    double bisectionMethod(double a, double b, Function& f);
    double falsiMethod(double a, double b, Function& f);
    double newtonMethod(double a, Function& f);
}

#endif // ROOTS_H_INCLUDED
