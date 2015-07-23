#include<iostream>
#include<iomanip>
#include<cmath>
#include <fstream>
#include "Roots.h"



double rootFinders::falsiMethod(std::string fname,double a, double b, Function& f){
    double root, fa,fb,fr,old,err,oa =a,ob = b;
    std::cout<<std::setprecision(7)<<std::endl;
    std::ofstream vOut;
    vOut.open(fname);
    vOut.precision(7);
    vOut.setf(std::ios::fixed);
    vOut.setf(std::ios::showpoint);
    vOut<<"Function f(x)="<<f<<" for ["<<a<<","<<b<<"] using Regula-Falsi\n"<<std::endl;
    int iter = 1;
    while(true){
        fa = f(a);
        fb= f(b);
        root = (a*fb - b*fa)/(fb-fa);

        fr = f(root);
        err =((root-old)/root)*100;

        if(std::abs(fr) < 1e-07){
            std::cout<<"The Falsi method root of the function f(x)="<<f<<" with x0="<<oa<<" and x1="<<ob<<" using regula falsi is "<<root<<std::endl;
            std::cout<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            std::cout<<"Iterations till acceptable root was found was "<<iter<<std::endl;
            vOut<<"\nThe root of the function f(x)="<<f<<" for ["<<oa<<","<<ob<<"] using Regula-Falsi is "<<root<<std::endl;
            vOut<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            vOut<<"Iterations till acceptable root was found was "<<iter<<std::endl;
            break;
        }
        if(fa*fr < 0)
            b = root;
        if(fa*fr > 0)
            a = root;
        if(fa*fr == 0){
            std::cout<<"The Falsi method root of the function f(x)= "<<f<<" with x0="<<oa<<" and x1="<<ob<<" is "<<root<<std::endl;
            std::cout<<"This is an exact zero root at iteration "<<iter<<std::endl;
            vOut<<"\nThe Falsi method root of the function f(x)= "<<f<<" with x0="<<oa<<" and x1="<<ob<<" is "<<root<<std::endl;
            vOut<<"This is an exact zero root at iteration "<<iter<<std::endl;
            break;
        }
        vOut<<"Iteration["<<iter<<"] solution is["<<root<<"]"<<std::endl;
        ++iter;
        old = root;
    }

    vOut.close();
    return root;

}


double rootFinders::bisectionMethod(std::string fname,double a, double b, Function& f){
    double m, l = a, r = b, fm, oa = a , ob = b,old,err;
     std::cout<<std::setprecision(7)<<std::endl;
    std::ofstream vOut;
    vOut.open(fname);
    vOut.precision(7);
    vOut.setf(std::ios::fixed);
    vOut.setf(std::ios::showpoint);
    vOut<<"Function f(x)="<<f<<" for ["<<a<<","<<b<<"] using Bisection\n"<<std::endl;
    int iter = 1;
    while(true){
        m = (l+r) / 2;
        fm = f(m);
        err = std::abs((m-old)/m)*100;
        if(fm > 0){
            r = m;
        }
        if(fm < 0){
            l = m;
        }
        if(fm == 0){
            std::cout<<"The Bisection method root of the function f(x)= "<<f<<" with x0="<<oa<<" and x1="<<ob<<" is "<<m<<std::endl;
            std::cout<<"This is an exact zero root at iteration "<<iter<<std::endl;

            vOut<<"\nThe Bisection method root of the function f(x)= "<<f<<" for ["<<oa<<","<<ob<<"] is "<<m<<std::endl;
            vOut<<"This is an exact zero root at iteration "<<iter<<std::endl;
            break;
        }
        if(std::abs(fm) < 1e-07){
            std::cout<<"Bisection method found the root of f(x)="<<f<<" with intial guesses of x0="<<oa<<" and x1="<<ob<<" to be "<<m<<std::endl;
            std::cout<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            std::cout<<"Iterations till acceptable root was found was "<<iter<<std::endl;

            vOut<<"\nBisection method found the root of f(x)="<<f<<" for ["<<oa<<","<<ob<<"] is "<<m<<std::endl;
            vOut<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            vOut<<"Iterations till acceptable root was found was "<<iter<<std::endl;
            break;
        }
        vOut<<"Iteration["<<iter<<"] solution is["<<m<<"]"<<std::endl;
        ++iter;
        old = m;

    }
    vOut.close();
    return m;
}


double rootFinders::newtonMethod(std::string fname,double a, Function& f){
    double  x = a, xx = 0.0,err;
    std::cout<<std::setprecision(7)<<std::endl;
    std::ofstream vOut;
    vOut.open(fname);
    vOut.precision(7);
    vOut.setf(std::ios::fixed);
    vOut.setf(std::ios::showpoint);

    Function* fd = f.getDerivative();
    vOut<<"Function f(x)="<<f<<" and f'(x)= "<<fd<<" for "<<a<<" using Newtons Methods\n"<<std::endl;
    int iter = 0;
    while(true){
        xx = x - (f(x)/(*fd)(x));
        err = std::abs((xx-x)/xx);

        if(err < 1e-05){
            std::cout<<"Newtons Methods root of the function f(x)="<<f<<" and f'(x)="<<fd<<" with x="<<a<<" is "<<xx<<std::endl;
            std::cout<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            std::cout<<"Iterations till acceptable root was found was "<<iter<<std::endl;
            vOut<<"\nNewtons Methods root of the function f(x)="<<f<<" and f'(x)="<<fd<<" with x="<<a<<" is "<<xx<<std::endl;
            vOut<<"\nThe absolute relative approximate error of the root is "<<err<<std::endl;
            vOut<<"Iterations till acceptable root was found was "<<iter<<std::endl;
            break;
        }
        vOut<<"Iteration["<<iter<<"] solution is["<<xx<<"]"<<std::endl;
        x = xx;
        ++iter;
    }
    delete fd;
    vOut.close();
    return xx;
}


double rootFinders::falsiMethod(double a, double b, Function& f){
    double root, fa,fb,fr,old,err,oa =a,ob = b;
    std::cout<<std::setprecision(7)<<std::endl;
    int iter = 1;
    while(true){
        fa = f(a);
        fb= f(b);
        root = (a*fb - b*fa)/(fb-fa);

        fr = f(root);
        err =((root-old)/root)*100;

        if(std::abs(fr) < 1e-07){
            std::cout<<"The Falsi method root of the function f(x)="<<f<<" with x0="<<oa<<" and x1="<<ob<<" using regula falsi is "<<root<<std::endl;
            std::cout<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            std::cout<<"Iterations till acceptable root was found was "<<iter<<std::endl;

            break;
        }
        if(fa*fr < 0)
            b = root;
        if(fa*fr > 0)
            a = root;
        if(fa*fr == 0){
            std::cout<<"The Falsi method root of the function f(x)= "<<f<<" with x0="<<oa<<" and x1="<<ob<<" is "<<root<<std::endl;
            std::cout<<"This is an exact zero root at iteration "<<iter<<std::endl;

            break;
        }

        ++iter;
        old = root;
    }


    return root;

}


double rootFinders::bisectionMethod(double a, double b, Function& f){
    double m, l = a, r = b, fm, oa = a , ob = b,old,err;
    std::cout<<std::setprecision(7)<<std::endl;
    std::ofstream vOut;

    int iter = 1;
    while(true){
        m = (l+r) / 2;
        fm = f(m);
        err = std::abs((m-old)/m)*100;
        if(fm > 0){
            r = m;
        }
        if(fm < 0){
            l = m;
        }
        if(fm == 0){
            std::cout<<"The Bisection method root of the function f(x)= "<<f<<" with x0="<<oa<<" and x1="<<ob<<" is "<<m<<std::endl;
            std::cout<<"This is an exact zero root at iteration "<<iter<<std::endl;


            break;
        }
        if(std::abs(fm) < 1e-07){
            std::cout<<"Bisection method found the root of f(x)="<<f<<" with intial guesses of x0="<<oa<<" and x1="<<ob<<" to be "<<m<<std::endl;
            std::cout<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            std::cout<<"Iterations till acceptable root was found was "<<iter<<std::endl;


            break;
        }

        ++iter;
        old = m;

    }
    return m;
}


double rootFinders::newtonMethod(double a, Function& f){
    double  x = a, xx = 0.0,err;
    std::cout<<std::setprecision(7)<<std::endl;



    Function* fd = f.getDerivative();

    int iter = 0;
    while(true){
        xx = x - (f(x)/(*fd)(x));
        err = std::abs((xx-x)/xx);

        if(f(xx) < 1e-07){
            std::cout<<"Newtons Methods root of the function f(x)="<<f<<" and f'(x)="<<fd<<" with x="<<a<<" is "<<xx<<std::endl;
            std::cout<<"The absolute relative approximate error of the root is "<<err<<std::endl;
            std::cout<<"Iterations till acceptable root was found was "<<iter<<std::endl;

            break;
        }

        x = xx;
        ++iter;
    }
    delete fd;
    return xx;
}