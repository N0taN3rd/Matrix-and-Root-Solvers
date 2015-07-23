#include "XTerm.h"

XTerm::XTerm()
:Term(),coefficient(0),power(0),op(0)
{}

XTerm::XTerm(int co,int p, int o)
:Term(),coefficient(co),power(p),op(o)
{}

XTerm::XTerm(const XTerm& other)
:Term(),coefficient(other.coefficient),power(other.power),op(other.op)
{}

XTerm::~XTerm(){}

Term* XTerm::clone() const{
    return new XTerm(*this);
}

Term* XTerm::derivative(){
    int n = power - 1;
    if(n == 0)
        return new EndTerm(coefficient*power,op);
     else
        return new XTerm(coefficient*power,n,op);

}

int XTerm::getOp(){
    return op;
}

void XTerm::print(std::ostream& out){
    out<<coefficient<<"x^"<<power<<" "<<(char)op<<" ";
}

double XTerm::evaluate(double x){
    return coefficient * pow(x,power);
}

bool XTerm::isEnd(){
    return false;
}
