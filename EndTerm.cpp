#include "EndTerm.h"

EndTerm::EndTerm()
:Term(),val(0),op(0)
{}


EndTerm::EndTerm(int v ,int o)
:Term(),val(v),op(o)
{}

EndTerm::EndTerm(const EndTerm& et)
:Term(),val(et.val),op(et.val)
{}

EndTerm::~EndTerm()
{}

Term* EndTerm::clone() const{
    return new EndTerm(*this);
}

Term* EndTerm::derivative(){
    return new EndTerm(0,op);
}

int EndTerm::getOp(){
    return op;
}

void EndTerm::print(std::ostream& out){
    out<<val<<" ";
}

double EndTerm::evaluate(double x){
    return val;
}

bool EndTerm::isEnd(){
    return true;
}
