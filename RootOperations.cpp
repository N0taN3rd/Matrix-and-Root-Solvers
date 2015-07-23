#include "RootOperations.h"


RootOperations::RootOperations()
    :x0(0.0), x1(0.0) {
    f = nullptr;
}

RootOperations::~RootOperations() {
    if(f != nullptr)
        delete f;
}

void RootOperations::getxs() {
    std::cout<<"Please input two double values to use as intial guess to find the root of\n"<<std::endl;
    std::cout<<"If you plan on using sin|cos|tan please input the values in radians as the cmath says radians not degrees\n"<<std::endl;
    std::cout<<"Input x0"<<std::endl;
    x0 = getInputDouble();
    std::cout<<"Input x1"<<std::endl;
    x1 = getInputDouble();
}

bool RootOperations::validxs() {
    if(x0 > x1 || x0 == x1)
        return false;
    else
        return true;
}

void RootOperations::operations() {
    build();
    if(f==nullptr) {
        std::cout<<"You did not create a vaild function please try again"<<std::endl;
        build();
    }
    rootMenu();
    c = getInput();
    if(c == "b" || c == "f") {
        if(x0 == 0.0 && x1 == 0.0)
            getxs();
        else {
            std::cout<<"Do you wish to use the previous values of x0= "<<x0<<" and x1= "<<x1<<" y/n?"<<std::endl;
            c = getInput();
            if(c == "n")
                getxs();
        }
        while(!validxs()){
            std::cout<<"Invalid guesses try again? y/n "<<std::endl;
            c = getInput();
            if(c != "y")
                return;
            getxs();
        }
        std::cout<<"The function f(x)="<<f<<" will be used to find the root between intial guess of ["<<x0<<","<<x1<<"]\n"<<std::endl;
        if(c == "b") {
            std::cout<<"Bisection method choosen the root is\n"<<rootFinders::bisectionMethod(x0,x1,*f)<<std::endl;
        } else {
            std::cout<<"False position method choose the root is\n"<<rootFinders::falsiMethod(x0,x1,*f)<<std::endl;
        }
    } else {
        std::cout<<"Please input one double to use as intial guess to find the root of\n"<<std::endl;
        x0 = getInputDouble();
        std::cout<<"The function f(x)="<<f<<" will be used to find the root between intial guess of "<<x0<<"\n"<<std::endl;
        std::cout<<"Newtons method choose the root is\n"<<rootFinders::newtonMethod(x0,*f)<<std::endl;
    }
}

void RootOperations::build() {
    if(f == nullptr)
        f = ff.build();
    else {
        std::cout<<"Do you still wish to use the function "<<f<<"? y/n \n"<<std::endl;
        c = getInput();
        if(c != "y") {
            delete f;
            f = ff.build();
        }
    }
}
