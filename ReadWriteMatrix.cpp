#include "ReadWriteMatrix.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <chrono>
#include <functional>

#define round(x) std::floor(x*100.) / 100.

double domSum(std::vector<double>* sumMe){
    int size = sumMe->size();
    double sum = 0.0;
    for(int i = 0; i < size; ++i)
        sum += std::abs(sumMe->at(i));
    return (double)sum;
}


void readWriteMatrix::getFromFile(std::string fName, std::vector<std::vector<double>*>* mat,std::vector<double>* b){
    if(!mat->empty()){
        for(auto v : *mat)
            delete v;
        mat->clear();
    }
    if(!b->empty())
        b->clear();
     std::string line;
     std::ifstream in(fName,std::ios::in);
     std::vector<std::string> lines;
     if(in.is_open())
        while(std::getline(in,line))
            lines.emplace_back(line);
     auto fl = lines[0];
     auto fSpace = fl.find_first_of(" ");
     int m = std::stoi(fl.substr(0,fSpace)), n = std::stoi(fl.substr(fSpace+1)), cnt = 0, vcnt = 0;
    std::cout<<fName<<" m= "<<m<<" n="<<n<<" N="<<m*n<<std::endl;
    m = m*n;
     lines.erase(lines.begin());
     mat->push_back(new std::vector<double>());
     for(auto l : lines){
        if(l.find(".") != std::string::npos){
            auto lastPos = l.find_first_not_of(" ", 0);
            auto pos =     l.find_first_of(" ", lastPos);
            while(pos != std::string::npos || lastPos != std::string::npos){
                auto mvar = l.substr(lastPos, pos - lastPos);
                auto  val = std::stod(mvar);
                ++cnt;
                if(vcnt >= m)
                    b->push_back(val);
                else{
                    if(cnt <= m)
                        mat->at(vcnt)->push_back(val);
                    else{
                        vcnt++;
                        cnt = 1;
                        if(vcnt < m){
                             mat->push_back(new std::vector<double>());
                             mat->at(vcnt)->push_back(val);
                        }else
                            b->push_back(val);
                    }
                }
                lastPos = l.find_first_not_of(" ", pos);
                pos = l.find_first_of(" ", lastPos);
            }
        }
     }
}

void readWriteMatrix::getRandom(std::vector<std::vector<double>*>* mat,std::vector<double>* b,int m, int n, double low, double high){
     if(!mat->empty()){
        for(auto v : *mat)
            delete v;
        mat->clear();
    }
    if(!b->empty())
        b->clear();

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //64 bit word length mersenne twister has always given the best rands for me
    std::mt19937_64 generator (seed);
    std::uniform_real_distribution<double> distribution(low,high);
    auto rand = std::bind(distribution,generator);
    std::vector<double> _tt;
    bool tt = true;
    for(int i =0; i < m; ++i){
        mat->push_back(new std::vector<double>());
        for(int j = 0; j < n; ++j){
            mat->at(i)->push_back(round(rand()));
            if(tt)
                _tt.push_back(round(rand()));
        }
        tt = false;
        (*mat->at(i))[i] = domSum(mat->at(i));
    }

    std::cout<<"Saving random x to file called randX.txt"<<std::endl;
    writeVector("randX.txt",&_tt);


    for(auto v : *mat){
        double d = 0.0;
        for(int j = 0; j < n; ++j)
            d += v->at(j) * _tt[j];
        b->push_back(d);
    }

}

void readWriteMatrix::writeMat(std::string fname,std::vector<std::vector<double>*>* m){
    std::fstream matOut(fname,std::ios::out | std::ios::trunc);
    int n = m->size();
    matOut<<n<<" "<<n<<std::endl;
    matOut<<std::endl;
    for(auto vv : *m){
        for(auto d : *vv)
         matOut<<d<<" ";
        matOut<<std::endl;
    }
}

void readWriteMatrix::writeMatVec(std::string fname,std::vector<std::vector<double>*>* m,std::vector<double>* v){
    std::fstream matOut(fname,std::ios::out | std::ios::trunc);
    int n = v->size();
    matOut<<n<<" "<<n<<std::endl;
    matOut<<std::endl;
    for(auto vv : *m){
        for(auto d : *vv)
         matOut<<d<<" ";
        matOut<<std::endl;
    }
    matOut<<std::endl;
    for(auto   d : *v)
        matOut<<d<<" ";
    matOut<<std::endl;

}
void readWriteMatrix::writeVector(std::string fname,std::vector<double>* v){
    std::fstream vOut(fname,std::ios::out | std::ios::trunc);
    for(auto d : *v)
        vOut<<d<<" ";
    vOut<<std::endl;
}

void readWriteMatrix::writeFinalVector(std::string fname, std::vector<double> *v) {
    auto outSize = std::sqrt(v->size());
    int size = v->size();
    std::cout<<v->size()<<" "<<outSize<<std::endl;
    std::ofstream vOut;
    vOut.open(fname);
    int count = 1,rowCount = 1;
    for(auto elem : *v){
        if(count <= outSize){
            vOut<<elem << " ";
        }else{
            rowCount+=1;
            count = 1;
            vOut<<std::endl<<elem<<" ";
        }
        count += 1;
    }
    vOut.close();
}

void readWriteMatrix::writeFinalVectorCSV(std::string fname, std::vector<double> *v) {
    auto outSize = std::sqrt(v->size());
    int size = v->size();
    std::cout<<v->size()<<" "<<outSize<<std::endl;
    std::ofstream vOut;
    vOut.open(fname);
    int count = 1,rowCount = 1;
    for(auto elem : *v){
        if(count <= outSize){
            if(count == outSize)
                vOut<<elem;
            else
                vOut<<elem<<",";
        }else{
            rowCount+=1;
            count = 1;
            vOut<<std::endl<<elem<<",";
        }
        count += 1;
    }
    vOut.close();
}

