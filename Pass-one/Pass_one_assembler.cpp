/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Pass_one_assembler.cpp
*/


#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>


using namespace std;

int main(){

    ifstream input("input.txt");
    ifstream optab("Pass_one_optab.txt");
    ofstream out("Pass_one_output.txt");
    ofstream symtab("Pass_one_symtab.txt");
    string label, opcode, operand, code;
    int startAddress = 0, locationPointer;

    input >> label >> opcode >> operand;
    if(opcode == "START"){
        startAddress = stoi(operand,nullptr,16);
        out << hex << startAddress << " "<< label << " " << opcode << " " << operand << endl;
        input >> label >> opcode >> operand;
    }

    locationPointer = startAddress;

    while(opcode != "END"){
        out << hex << locationPointer << " "<< label << " " << opcode << " " << operand << endl;
        if(label != "-"){
            symtab << label << " " << hex << locationPointer << endl;
        }
        optab.clear();
        optab.seekg(0, ios::beg);
        optab >> code;
        while(code!="END"){
            if(opcode == code){
                locationPointer += 3;
                break;
            }
            optab >> code;
        }
        if(opcode == "RESB")
            locationPointer += stoi(operand);
        else if(opcode == "RESW")
            locationPointer += 3*stoi(operand);
        else if(opcode == "BYTE")
            {
               if (operand[0]== 'C')
                 locationPointer += operand.length() - 3;
               else
               {
                 if((operand.length()-3)%2 == 0)
                 locationPointer += (operand.length()-3)/2;
                 else locationPointer += ((operand.length()-3)/2)+1;
               }
            }
        else if(opcode == "WORD")
            locationPointer += 3;

        input >> label >> opcode >> operand;
    }
    out << hex << locationPointer << " "<< label << " " << opcode << " " << operand << endl;
    return 0;
}
