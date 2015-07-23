#ifndef XTERM_H_INCLUDED
#define XTERM_H_INCLUDED

#include <iostream>
#include <cmath>
#include "Term.h"
#include "EndTerm.h"


class XTerm : public Term{
public:
    XTerm();
    XTerm(int,int,int);
    XTerm(const XTerm&);
    ~XTerm();

    Term* clone() const;
    Term* derivative();
    bool isEnd();
    int getOp();
    void print(std::ostream&);
    double evaluate(double);
private:
    int coefficient;
    int power;
    int op;
};


#endif // XTERM_H_INCLUDED
