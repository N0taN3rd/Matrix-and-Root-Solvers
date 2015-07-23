#ifndef READWRITEMATRIX_H_INCLUDED
#define READWRITEMATRIX_H_INCLUDED
#include <string>
#include <vector>

namespace readWriteMatrix{
    void getFromFile(std::string fName, std::vector<std::vector<double>*>* mat, std::vector<double>* b);
    void getRandom(std::vector<std::vector<double>*>* mat,std::vector<double>* b,int m, int n, double low, double high);
    void writeMat(std::string fname,std::vector<std::vector<double>*>* m);
    void writeMatVec(std::string fname,std::vector<std::vector<double>*>* m,std::vector<double>* v);
    void writeVector(std::string fname,std::vector<double>* v);
    void writeFinalVector(std::string fname,std::vector<double>*v);
    void writeFinalVectorCSV(std::string fname, std::vector<double> *v);
}


#endif // READWRITEMATRIX_H_INCLUDED
