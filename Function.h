#ifndef EXPERSION_H_INCLUDED
#define EXPERSION_H_INCLUDED

#include "Term.h"
#include <iostream>
#include <vector>

class Function{
public:
     Function(std::vector<Term*>*);
     Function(Function&);
     Function(Function*);
    ~Function();
     Function* getDerivative();
     double operator()(double);
    friend std::ostream& operator<<(std::ostream&, Function&);
    friend std::ostream& operator<<(std::ostream&, Function*);
private:
    std::vector<Term*>* poly;

};

inline std::ostream& operator<<(std::ostream& out, Function& p){
    for(Term* t : (*p.poly)){
        out<<t;
    }
    out<<std::endl;
    return out;
}


inline std::ostream& operator<<(std::ostream& out , Function* p){
    for(Term* t : (*p->poly)){
        out<<t;
    }
    out<<std::endl;
    return out;
}

#endif // EXPERSION_H_INCLUDED
