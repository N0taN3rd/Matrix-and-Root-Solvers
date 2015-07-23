#include "FunctionFactor.h"


Term* FunctionFactory::xTerm(){
    std::cout<<"Building your xTerm"<<std::endl;
    int pow,co,op;
    std::cout<<"Use coefiecent? y or n"<<std::endl;
    std::string i;
    std::cin>>i;
    if(i == "y"){
        std::cout<<"Enter coefiecent as integer"<<std::endl;
        std::cin>>i;
        co = std::stoi(i);
    } else {
        co = 1;
    }
    std::cout<<"Use a power y or n"<<std::endl;
     std::cin>>i;
      if(i == "y"){
        std::cout<<"Enter power as integer"<<std::endl;
        std::cin>>i;
        pow = std::stoi(i);
    } else {
        pow = 1;
    }
    std::cout<<"What operator do you want + or - defaults to +"<<std::endl;
    std::cin>>i;
    if(i == "-"){
        op = '-';
    }else{
        op = '+';
    }
    std::cout<<"Your x term is "<<co<<"*x^"<<pow<<" "<<(char)op<<std::endl;
    return new XTerm(co,pow,op);
}

Term* FunctionFactory::eTerm(){
     std::cout<<"Building your constant Term"<<std::endl;
     int e,o;
     std::cout<<"Input your constant term as integer"<<std::endl;
     std::string i;
     std::cin>>i;
     e = std::stoi(i);
     o = '+';
    std::cout<<"Your constant term is "<<e<<std::endl;
    return new EndTerm(e,o);
}

Term* FunctionFactory::mTerm(){
    std::cout<<"Building your math Term"<<std::endl;
    int choice,op;
    std::cout<<"Input 1 for sin, 2 for cos, 3 for tan, 4 for e^x, 5 for ln, and 6 for log"<<std::endl;
    std::string i,m;
    std::cin>>i;
    choice = std::stoi(i);
    switch(choice){
        case 1:
            m = "sin";
            break;
        case 2:
            m = "cos";
            break;
        case 3:
            m = "tan";
            break;
        case 4:
            m = "e^";
            break;
        case 5:
            m = "ln";
            break;
        case 6:
            m = "log";
            break;
        default:
            std::cout<<"Input not reconized using sin"<<std::endl;
            m = "sin";
            break;
    }

    std::cout<<"What operator do you want + or - defaults to +"<<std::endl;
    std::cin>>i;
    if(i == "-"){
        op = '-';
    }else{
        op = '+';
    }

    std::cout<<"Your math terms is "<<m<<"(x) "<<(char)op<<std::endl;
    return new MathTerm(m,op);
}

void FunctionFactory::options(){
    std::cout<<"Your options are x terms, math functions, and constants"<<std::endl;
    std::cout<<"-x terms are in the form coefficient*x^power operator"<<std::endl;
    std::cout<<"-math functions are in the form sin|cos|tan|e^x|ln|log10(x) operator"<<std::endl;
    std::cout<<"-constans are in the form value"<<std::endl;
    std::cout<<"-operators are + or -"<<std::endl;
    std::cout<<"Each term can only go to the first dirivative"<<std::endl;
    std::cout<<"When asked for term choice input \n- 1 for x terms \n- 2 for math functions \n- 3 for constant"<<std::endl;
    std::cout<<"y or yes to continue, o or h for options, any other input will exit the builder"<<std::endl;
    std::cout<<"PLEASE NOTE YOU ARE LIMITED INTEGER VALUES FOR COEFIENTS POWER AND CONSTANT!"<<std::endl;
    std::cout<<"I GENERATE THE DERIVATIVE FOR YOU! :)"<<std::endl;
    std::cout<<"ANY OTHER INPUT YOU WILL GET AN EXCEPTION YOU HAVE BEEN WARNED\nAlso if there is a trailing operator ignore it as it is the cost of having this feature\n\n\n"<<std::endl;
}


Function* FunctionFactory::build(){
   std::vector<Term*>* poly = new std::vector<Term*>();

    /*
    poly->push_back(new XTerm(1,3,'-'));
    poly->push_back(new XTerm(1,1,'-'));
    poly->push_back(new EndTerm(2,'-'));
    */

    bool cont = true;
    std::cout<<"\nBuild your expresion"<<std::endl;
    std::cout<<"You can have as many terms as you want \nbut are limited to certain options for each term.\n"<<std::endl;
    std::cout<<"Your options are x terms, math functions, and constants"<<std::endl;
    std::cout<<"-x terms are in the form coefficient*x^power operator"<<std::endl;
    std::cout<<"-math functions are in the form sin|cos|tan|e^x|ln|log10(x) operator"<<std::endl;
    std::cout<<"-constans are in the form value"<<std::endl;
    std::cout<<"-operators are + or -"<<std::endl;
    std::cout<<"\nEach term can only go to the first dirivative"<<std::endl;
    std::cout<<"When asked for term choice input \n- 1 for x terms \n- 2 for math functions \n- 3 for constant"<<std::endl;
    std::cout<<"y or yes to continue, o or h for options, any other input will exit the builder"<<std::endl;
    std::cout<<"PLEASE NOTE YOU ARE LIMITED INTEGER VALUES FOR COEFIENTS POWER AND CONSTANT!"<<std::endl;
    std::cout<<"I GENERATE THE DERIVATIVE FOR YOU! :)"<<std::endl;
    std::cout<<"ANY OTHER INPUT YOU WILL GET AN EXCEPTION YOU HAVE BEEN WARNED\nAlso if there is a trailing operator ignore it as it is the cost of having this feature\n\n\n"<<std::endl;
    while(cont){
        std::cout<<"When asked for term choice input \n- 1 for x terms\n- 2 for math functions\n- 3 for constant"<<std::endl;
        std::cout<<"Which term"<<std::endl;
        std::string c;
        std::cin>>c;
        if(c == "1"){
            poly->push_back(xTerm());
        }else if(c=="2"){
              poly->push_back(mTerm());
        }else if(c=="3"){
              poly->push_back(eTerm());
        }else if(c == "o" || c=="h"){
            options();
        }

        std::cout<<"Continue? y/n"<<std::endl;
        std::cin>>c;
        if(!(c=="y" | c=="yes")){
            if(poly->size() == 0){
                std::cout<<"You did not create any terms re-try? y or n"<<std::endl;
                std::string c;
                std::cin>>c;
                if(c !="y"){
                    std::cout<<"I am returning you a nullpointer"<<std::endl;
                    delete poly;
                    return nullptr;
                }
            }else{
                break;
            }
        }

    }


    return new Function(poly);

}

Function* FunctionFactory::build6() {
    std::vector<Term*>* poly = new std::vector<Term*>();
    poly->push_back(new XTerm(1,1,'+'));
    poly->push_back(new MathTerm("ln",'+',true));
    return new Function(poly);
}


Function* FunctionFactory::build8() {
    std::vector<Term*>* poly = new std::vector<Term*>();
    poly->push_back(new XTerm(1,4,'+'));
    poly->push_back(new XTerm(2,3,'-'));
    poly->push_back(new XTerm(9,2,'-'));
    poly->push_back(new XTerm(2,1,'+'));
    poly->push_back(new EndTerm(8,'+'));
    return new Function(poly);
}