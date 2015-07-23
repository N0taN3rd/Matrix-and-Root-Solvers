#ifndef MATHTERM_H_INCLUDED
#define MATHTERM_H_INCLUDED
#include <iostream>
#include <string>
#include <cmath>
#include "Term.h"

class MathTerm : public Term{
public:
     MathTerm();
     MathTerm(bool,std::string,int);
     MathTerm(std::string,int);
     MathTerm(std::string,int,bool);
     MathTerm(const MathTerm&);
     ~MathTerm();

     Term* clone() const;
     Term* derivative();
     bool isEnd();
     int getOp();
     void print(std::ostream&);
     double evaluate(double);
private:
    bool derived;
    bool end;
    std::string math;
    int op;
    std::string derive();
};

#endif // MATHTERM_H_INCLUDED
