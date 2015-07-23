#include "MatrixOperations.h"

MatrixOperations::MatrixOperations()
:l(-100.0),h(100.0),omega(1.0) {
    mat = new std::vector<std::vector<double> *>();
    b = new std::vector<double>();
    x = nullptr;
    userFileArg = false;
    first = true;
}

MatrixOperations::~MatrixOperations() {
    delete b;
    if(x != nullptr)
        delete x;
    if(!mat->empty())
        for(auto v : *mat)
            delete v;
    delete mat;
}

std::string MatrixOperations::getFileName(){
    std::string c;
    std::cin>>c;
    return c;
}


void MatrixOperations::createBuild(std::string& c) {
    std::cout<<"\nIf a previous matrix A and vector b have been created they will be replaced now"<<std::endl;
    if(c=="c") {
        std::cout<<"\nPlease input size n a int for matrix A and vector b"<<std::endl;
        n = getInputInt();
        std::cout<<"\nDo you wish to input the lower and upper bounds of the random number generator? y/n"<<std::endl;
        if(getInput() == "y") {
            std::cout<<"\bPlease input the lower bounds"<<std::endl;
            l = getInputDouble();
            std::cout<<"\nPlease input the upper bounds"<<std::endl;
            h = getInputDouble();
            std::cout<<"\bThe values that will be used ar["<<l<<","<<h<<"]"<<std::endl;
        } else {
            std::cout<<"\nDefault values will be used which are [-100.0,100.0]"<<std::endl;
        }
        readWriteMatrix::getRandom(mat,b,n,n,l,h);
    } else {
        if(userFileArg){
            if(first){
                std::cout<<"\nUsing provided input file "<<file<<" to load matrix A and vector B"<<std::endl;
                first = false;
            }else{
                std::cout<<"Use the file "<<file<<" to load the matrix A and vector B? y/n"<<std::endl;
                c = getInput();
                if(c != "y"){
                    std::cout<<"\nPlease input the name of the file to be used to load the matrix"<<std::endl;
                    file = getFileName();
                }
            }
        }else{
            if(first){
                first = false;
                std::cout<<"\nPlease input the name of the file to be used to load the matrix"<<std::endl;
                file = getFileName();
            }else{
                std::cout<<"Use the file "<<file<<" to load matrix A and vector B? y/n"<<std::endl;
                c = getInput();
                if(c != "y"){
                    std::cout<<"\nPlease input the name of the file to be used to load the matrix"<<std::endl;
                    file = getFileName();
                }
            }

        }
        readWriteMatrix::getFromFile(file,mat,b);

    }
    std::cout<<"\nDo you wish to see the matrix A and vector b? y/n"<<std::endl;
    c = getInput();
    if(c == "y") {
        std::cout<<"\nMatrix A:"<<std::endl;
        MatVecUtil::print(mat);
        std::cout<<"\nVector b:"<<std::endl;
        MatVecUtil::print(b);
    }

    std::cout<<"\nDo you wish to save matrix A and vector b to disk? y/n \n"<<std::endl;
    c = getInput();
    if(c == "y") {
        std::cout<<"The name of the file is matVec.txt"<<std::endl;
        readWriteMatrix::writeMatVec("matVec.txt",mat,b);
    }
}

bool MatrixOperations::operations(std::string& c) {
    bool goToMatSolver = false;
    if(c == "c" || c == "i"){
        createBuild(c);
        return goToMatSolver;
    }

    if(mat->empty() || b->empty()){
        std::cout<<"\nYou have not created or imported a matrix yet please choose i for import or c for create random"<<std::endl;
        c = getInput();
         createBuild(c);
        return true;
    }

    matrixMenu();
    if(x != nullptr && !x->empty()) {
        std::cout<<"The previous solution is now being erased\n"<<std::endl;
        delete x;
    }

    switch(getMatrixMethodChoice()) {
    case 1:
        std::cout<<"Using Jacobi to solve Ax=b\n"<<std::endl;
        meth = "JacobiSol";
        x = iterativeSolvers::jacobi(mat,b);
        break;
    case 2:
        std::cout<<"Using Gauss Seidel to solve Ax=b\n"<<std::endl;
        meth = "GaussSeidelSol";
        x = iterativeSolvers::gaussSeidel(mat,b);
        break;
    case 3:
        meth = "SORSol";
        std::cout<<"Using SOR to solve Ax=b"<<std::endl;
        std::cout<<"Do you wish to use a custom omega value? y/n\n"<<std::endl;
        c = getInput();
        if(c == "y")
            omega = getInputDouble();
        std::cout<<"The value for omega is "<<omega<<"\n"<<std::endl;
        x = iterativeSolvers::SOR(mat,b,omega);
        break;
    case 4:
        meth = "GaussianElimSol";
        std::cout<<"Using Gaussian Elimination to solve Ax=b\n"<<std::endl;
        x = nonIterativeSolvers::gaussianElmination(mat,b);
        break;
    case 5:
        meth = "LUSol";
        std::cout<<"Using LU Decomposition to solve Ax=b\n"<<std::endl;
        x = nonIterativeSolvers::luDecomposition(mat,b);
        break;
    case -1:
        std::cout<<"The input was not valid please choose again\n"<<std::endl;
        goToMatSolver = true;
        break;
    }
    if(goToMatSolver)
        return goToMatSolver;
    std::cout<<"Do you wish to view the solution x? y/n \n"<<std::endl;
    c = getInput();
    if(c == "y") {
        std::cout<<"Vector x: "<<std::endl;
        MatVecUtil::print(x);
    }

    std::cout<<"Do you wish to save vector x to disk? y/n \n"<<std::endl;
    c = getInput();
    if(c == "y") {
        std::cout<<"The name of the file is "+meth+".txt\n"<<std::endl;
        readWriteMatrix::writeVector(meth+".txt",x);
    }

    return goToMatSolver;

}
