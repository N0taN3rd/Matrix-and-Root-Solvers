#include "Function.h"

Function::Function(std::vector<Term*>* p){
    poly = p;
}

Function::Function(Function& e){
    poly = new std::vector<Term*>();
    for(Term* t : *e.poly)
        poly->push_back(t->clone());
}

Function::Function(Function* e){
    poly = new std::vector<Term*>();
    for(Term* t : *e->poly)
        poly->push_back(t->clone());
}

Function::~Function(){
    for(Term* t : *poly)
        delete t;
    delete poly;
}

Function* Function::getDerivative(){
    std::vector<Term*>* p = new std::vector<Term*>();
    for(Term* t : *poly){
        //Term* d = t->derivative();
        if(!t->isEnd())
            p->push_back(t->derivative());
    }

    return new  Function(p);
}

double Function::operator()(double x){
    int n = poly->size();
    double result = 0.0;
    Term* t = poly->at(0);
    result += t->evaluate(x);
    //std::cout<<t <<" of "<<x<<" = "<<t->evaluate(x)<<std::endl;
    int c = t->getOp();

    for(int i =1; i < n; ++i){
        t = poly->at(i);

        if(c == '+')
            result += t->evaluate(x);
        else
            result -= t->evaluate(x);

            //std::cout<<t <<" of "<<x<<" = "<<t->evaluate(x)<<std::endl;
            c = t->getOp();
    }
    return result;
}
