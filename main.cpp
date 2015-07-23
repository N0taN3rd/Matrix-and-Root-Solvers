/*
    John Berlin
*/

#include <iostream>
#include <string>
#include <exception>
#include "MatrixOperations.h"
#include "MenuSelections.h"
#include "MatrixMethods.h"
#include "Extra.h"
#include "Function.h"
#include "FunctionFactor.h"
#include "Roots.h"
#include "RootOperations.h"

int main(int argc, char **argv) {
    std::string c;
    bool goToMatSolver = false;
    MatrixOperations matOp;
    if(argc >= 2)
        matOp.setFile(std::string(argv[1]));
    RootOperations rOp;
    while(true) {
        if(goToMatSolver)
            c = "m";
        else {
            mainMenu();
            c = getInput();
        }
        if(c == "q") {
            std::cout<<"\nThank you for using this program have a nice day"<<std::endl;
            break;
        } else if(c == "c" || c == "i" || c == "m"){
            try{
                goToMatSolver = matOp.operations(c);
            }catch (std::exception& e){
                std::cerr<<"An exception was thrown "<<e.what()<<std::endl;
                std::cerr<<"It was non fatal you can try again(correct last input)\nOtherwise exit the program"<<std::endl;
            }
        }else if(c == "r"){
            try{
                rOp.operations();
            }catch (std::exception& e){
               std::cerr<<"An exception was thrown "<<e.what()<<std::endl;
               std::cerr<<"It was non fatal you can try again(correct last input)\nOtherwise exit the program"<<std::endl;
            }
        }else
            std::cout<<"\nThe input choice is not valid please try again"<<std::endl;
    }
     
    return 0;
}
