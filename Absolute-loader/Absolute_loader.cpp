/*
**************************
@Author: Vishal P
@Lab: System Software Lab
Version 2.0 Improved from the code of Niranjan-Ananth
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Absolute_loader.cpp
*/


#include<iostream> //For Basic I/O operations
#include<fstream> //For file operations
#include<cstdlib> //For stoi
using namespace std;

int main(){
    ifstream input("Absolute_input.txt");
    ofstream out("Absolute_output.txt");
    string x;
    int address;
    input >> x;
    if(x=="H"){
        input >> x >> x >> x >>x;
    }
    while(x!="E"){

            if(x=="T"){
              input >> x;
              address = stoi(x,nullptr,16);
              input >> x >> x;

            while(!(x=="T" || x=="E")){
                out<< hex << address << " " << x[0] << x[1] << endl;
                out<< hex << address + 1 << " " << x[2] << x[3] << endl;
                out<< hex << address + 2 << " " << x[4] << x[5] << endl;
                address += x.length()/2;
                input >> x;
            }
        }
    }
    return 0;
}
