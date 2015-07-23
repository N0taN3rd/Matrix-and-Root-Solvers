#include "MenuSelections.h"

void mainMenu(){
    std::cout<<"\nWhen selecting your choice from the following option use \nthe character inside the () eg (R)andom you will input r or R when asked for choice"<<std::endl;
    std::cout<<"(C)reate random matrix A and vector B"<<std::endl;
    std::cout<<"(I)mport matrix A and vector B from a file"<<std::endl;
    std::cout<<"(M)atrix methods to solve equations Ax=b"<<std::endl;
    std::cout<<"(R)oot finding methods for polynomials"<<std::endl;
    std::cout<<"(Q)uit"<<std::endl;
    std::cout<<"Please input your choice now "<<std::endl;
}

void matrixMenu(){
    std::cout<<"\nMatrix solver choices"<<std::endl;
    std::cout<<"(J)acobi"<<std::endl;
    std::cout<<"(GS) Gauss-Seidel"<<std::endl;
    std::cout<<"(SOR) Successive Over Relaxation"<<std::endl;
    std::cout<<"(GE) Gaussian Elimination"<<std::endl;
    std::cout<<"(LU) LU Decomposition"<<std::endl;
    std::cout<<"Please input your choice now "<<std::endl;
}


void rootMenu(){
    std::cout<<"\nRoot solver choices"<<std::endl;
    std::cout<<"(B)isection"<<std::endl;
    std::cout<<"(F)alse position"<<std::endl;
    std::cout<<"(N)ewtons method"<<std::endl;
}

std::string getInput(){
    std::string c;
    std::cin>>c;
    std::transform(c.begin(),c.end(),c.begin(), ::tolower);
    return c;
}

double getInputDouble(){
    std::string c;
    std::cin>>c;
    return std::stod(c);
}

int getInputInt(){
    std::string c;
    std::cin>>c;
    return std::stoi(c);
}

int getMatrixMethodChoice(){
    std::string c = getInput();
    int ret = 0;
    if(c == "j"){
        ret = 1;
    }else if(c == "gs"){
        ret = 2;
    }else if(c == "sor"){
        ret = 3;
    }else if(c == "ge"){
        ret = 4;
    }else if(c == "lu"){
        ret = 5;
    }else{
        ret = -1;
    }
    return ret;
}
