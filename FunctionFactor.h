#ifndef FUNCTIONFACTOR_H_INCLUDED
#define FUNCTIONFACTOR_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "Function.h"
#include "Term.h"
#include "XTerm.h"
#include "EndTerm.h"
#include "MathTerm.h"

class FunctionFactory{
public:
        Function* build();
        Function* build6();
        Function* build8();
private:
     Term* xTerm();
     Term* eTerm();
     Term* mTerm();
     void options();
     void mTerms();
     void xTerms();
};


#endif // FUNCTIONFACTOR_H_INCLUDED
