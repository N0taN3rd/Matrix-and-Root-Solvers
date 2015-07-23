#ifndef TERM_H_INCLUDED
#define TERM_H_INCLUDED
#include <iostream>
class Term{
public:
    virtual ~Term(){};
    virtual double evaluate(double) = 0;
    virtual void print(std::ostream&) = 0;
    virtual int getOp() = 0;
    virtual bool isEnd() = 0;
    virtual Term* clone() const = 0;
    virtual Term* derivative() = 0;
    friend std::ostream& operator<<(std::ostream&, Term*);
    friend std::ostream& operator<<(std::ostream&, Term&);
};


inline std::ostream& operator<<(std::ostream& out, Term* t){
    t->print(out);
    return out;
}

inline std::ostream& operator<<(std::ostream& out, Term& t){
    t.print(out);
    return out;
}


#endif // TERM_H_INCLUDED
