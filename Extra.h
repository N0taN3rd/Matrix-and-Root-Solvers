//
// Created by Johns on 4/25/2015.
//

#ifndef JOHNBERLIN_CS417_SOLVERS__1__EXTRA_H
#define JOHNBERLIN_CS417_SOLVERS__1__EXTRA_H
#include <boost/tokenizer.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace Extra{
    typedef boost::char_separator<char> separator;
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

    void fill(std::string fname,std::vector<std::vector<double>*>* mat,std::vector<double>* b) {
        if (!mat->empty()) {
            for (auto v : *mat)
                delete v;
            mat->clear();
        }
        if (!b->empty())
            b->clear();

        separator sep(" ");

        std::ifstream in(fname, std::ios::in);
        std::string line;
        int linecount = 0;
        int m = 0, n = 0, cnt = 0, vcnt = 0;
        mat->push_back(new std::vector<double>());
        while (std::getline(in, line)) {
            if (linecount == 0) {
                auto fSpace = line.find_first_of(" ");
                m = std::stoi(line.substr(0, fSpace)), n = std::stoi(line.substr(fSpace + 1));

            } else {
                tokenizer tok(line, sep);
                int tokenCount = 0;
                for (auto iter = tok.begin(); iter != tok.end(); ++iter) {

                    //std::cout << *iter << std::endl;
                    ++tokenCount;
                    ++cnt;
                    if (vcnt >= m){

                    }else{
                        if (cnt <= m){

                        }else{
                            vcnt++;
                            cnt = 1;
                            if (vcnt < m) {
                                std::cout<<"Creating new vector and adding it"<<std::endl;
                            }else{

                            }
                        }
                    }
                    /*
                    auto val = std::stod(*iter);
                    ++cnt;

                    if (vcnt >= m)
                        b->push_back(val);
                    else {
                        if (cnt <= m)
                            mat->at(vcnt)->push_back(val);
                        else {
                            vcnt++;
                            cnt = 1;
                            if (vcnt < m) {
                                mat->push_back(new std::vector<double>());
                                mat->at(vcnt)->push_back(val);
                            } else
                                b->push_back(val);
                        }


                    }
                     */

                }
                std::cout<<"m= "<<m<<" n= "<<n<<" tokencount = "<<tokenCount<<" "<<" n*n = N "<<m*n<<" tokenCount-(m*n)= "<<tokenCount-(m*n)<<std::endl;
            }
            ++linecount;
        }
    }

    void sanatize(std::string fname){
        separator sep(" ");
        std::cout<<"FUCK!"<<std::endl;
        std::ifstream in(fname, std::ios::in);
        std::ofstream out;
        out.open(fname.substr(0,fname.find("."))+"fixed.txt");
        std::string line;
        int linecount = 0;
        int m = 0, n = 0, cnt = 0;

        if(in.is_open() && out.is_open()){
            while (std::getline(in, line)) {
                if (linecount == 0) {
                    auto fSpace = line.find_first_of(" ");
                    m = std::stoi(line.substr(0, fSpace)), n = std::stoi(line.substr(fSpace + 1));
                    out<<m<<" "<<n<<std::endl;
                    std::cout<<m<<" "<<n<<std::endl;
                }else{
                    tokenizer tok(line, sep);
                    for (auto iter = tok.begin(); iter != tok.end(); ++iter) {

                        if(cnt < m)
                            out<<*iter<<" ";
                        else{
                            std::cout<<cnt<<std::endl;
                            out<<std::endl<<*iter<<" ";
                            cnt = 0;
                            std::cout<<cnt<<std::endl;

                        }
                        ++cnt;

                    }
                }
                ++linecount;
            }
        }else{
            std::cout<<"Fuck its not open"<<std::endl;
        }
        in.close();
        out.close();
    }

    void count(std::string fname){
        separator sep(" ");
        std::ifstream in(fname, std::ios::in);
        int rowCount = 0;
        std::string line;
        int m = 0, n = 0, cnt = 0;
        std::getline(in, line);
        auto fSpace = line.find_first_of(" ");
        m = std::stoi(line.substr(0, fSpace)), n = std::stoi(line.substr(fSpace + 1));
        std::cout<<fname+" "<<m<<" "<<n<<std::endl;
        if(in.is_open()){
            while (std::getline(in, line)) {

                tokenizer tok(line, sep);
                for (auto iter = tok.begin(); iter != tok.end(); ++iter) {
                    if(cnt == m){
                        std::cout<<"just got row= "<<rowCount<<" with total elements of "<<cnt-1<<" m ="<<m<<std::endl;
                        rowCount += 1;
                        cnt = 0;
                    }

                    ++cnt;
                }
            }

        }
        std::cout<<"\n"<<std::endl;
    }

    void loadFile(std::string fname,std::vector<std::vector<double>*>* mat,std::vector<double>* b){
        if (!mat->empty()) {
            for (auto v : *mat)
                delete v;
            mat->clear();
        }
        if (!b->empty())
            b->clear();

        separator sep(" ");

        std::ifstream in(fname, std::ios::in);
        std::string line;
        int linecount = 0;
        int m = 0, n = 0, count = 1,rowCount = 1,vcnt = 0;
        if(in.is_open()){
            std::getline(in, line);
            auto fSpace = line.find_first_of(" ");
            m = std::stoi(line.substr(0, fSpace)), n = std::stoi(line.substr(fSpace + 1));
            m = m*n;
            n = m;
            std::cout<<fname+" M "<<m<<" N "<<n<<std::endl;
            for(int i = 0; i < m; ++i)
                mat->push_back(new std::vector<double>());

            while (std::getline(in, line)) {
                tokenizer tok(line, sep);
                for (auto iter = tok.begin(); iter != tok.end(); ++iter) {
                    if(vcnt < m){
                        if(count <= m){
                            mat->at(vcnt)->push_back(std::stod(*iter));
                        }else{
                            rowCount += 1;
                            count = 1;
                            vcnt += 1;
                            mat->at(vcnt)->push_back(std::stod(*iter));
                        }
                    }else{
                        b->push_back(std::stod(*iter));
                    }
                    count += 1;

                }
            }

        }

    }


}

#endif //JOHNBERLIN_CS417_SOLVERS__1__EXTRA_H
