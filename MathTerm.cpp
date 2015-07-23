#include "MathTerm.h"


MathTerm::MathTerm()
:Term(),derived(false), math(" "),op(0),end(false)
{
}


MathTerm::MathTerm(bool b ,std::string m ,int o)
:Term(),derived(b),math(m),op(o),end(false)
{

}

MathTerm::MathTerm(std::string m ,int o)
:Term(),derived(false), math(m),op(o),end(false)
{

}

MathTerm::MathTerm(std::string m,int o ,bool end)
:Term(),derived(false), math(m),op(o),end(end)
{

}

MathTerm::MathTerm(const MathTerm& other)
:Term(),derived(other.derived), math(other.math),op(other.op)
{

}
MathTerm::~MathTerm(){
}

Term* MathTerm::clone() const{
    return new MathTerm(*this);
}

Term* MathTerm::derivative() {
    return new MathTerm(derive(),op);
}

int MathTerm::getOp(){
    return op;
}
void MathTerm::print(std::ostream& out){
    out<<math<<"(x)"<<(char)op<<" ";
}

std::string MathTerm::derive(){
    std::string d;
    if(math == "sin")
        d = "cos";
    else if(math == "cos")
        d = "-sin";
     else if(math == "tan")
        d = "sec^2";
     else if(math == "log")
       d = "1/x*ln10";
     else if(math == "ln")
         d = "1/x";
     else if(math == "e^")
         d = "e^";
     else
        d = math;
     return d;
 }

double MathTerm::evaluate(double x){
      double m;
    if(math == "sin")
        m = sin(x);
    else if(math == "cos")
        m = cos(x);
     else if(math == "tan")
        m = tan(x);
     else if(math == "log")
        m  = log10(x);
     else if(math == "ln")
        m = log(x);
     else if(math == "-sin")
         m = -sin(x);
     else if(math == "sec^2"){
        m = pow(1/cos(x),2);
     } else if(math == "1/x"){
        m = 1/x;
     } else if(math == "1/x*ln10"){
        m = 1/(x*log(10));
     } else if(math == "e^")
        m = exp(x);
    return m;
}

bool MathTerm::isEnd(){
    return end;
}
