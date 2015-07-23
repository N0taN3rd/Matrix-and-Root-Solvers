#ifndef ENDTERM_H_INCLUDED
#define ENDTERM_H_INCLUDED

#include <iostream>
#include "Term.h"

class EndTerm : public Term {
public:
     EndTerm();
     EndTerm(int,int);
     EndTerm(const EndTerm&);
     ~EndTerm();

     Term* clone() const;
     Term* derivative();
     bool isEnd();
     int getOp();
     void print(std::ostream&);
     double evaluate(double);

private:
    int val;
    int op;
};


#endif // ENDTERM_H_INCLUDED
