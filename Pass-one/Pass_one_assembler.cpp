/*
**************************
@Author: Vishal P
@Lab: System Software Lab
Version 2.0 Improved from the code of Niranjan-Ananth
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Pass_one_assembler.cpp
*/


#include<iostream> //For Basic I/O operations
#include<cstring> //For string operations
#include<cstdlib> //For stoi
#include<fstream> //For file operations


using namespace std;

int main(){

    ifstream input("Pass_one_input.txt"); //Code input for One Pass
    ifstream optab("Pass_one_optab.txt"); //Optab input (without code values)
    ofstream out("Pass_one_output.txt"); //File with generated output
    ofstream symtab("Pass_one_symtab.txt"); // File with generated symtab
    string label, opcode, operand, code;
    int startAddress = 0, locationPointer;

    input >> label >> opcode >> operand;
    if(opcode == "START"){
        startAddress = stoi(operand,nullptr,16); //stoi returns the integer value in a given string, 16 means HEX value
        out << hex << startAddress << " "<< label << " " << opcode << " " << operand << endl; //hex used to output HEX values
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
               if (operand[0]== 'C') //Checking for whether C or X after BYTE
                 locationPointer += operand.length() - 3;
               else
               {
                 if((operand.length()-3)%2 == 0) //Done incase we have 3HEX Values in input
                 locationPointer += (operand.length()-3)/2;
                 else locationPointer += ((operand.length()-3)/2)+1;
               }
            }
        else if(opcode == "WORD")
            locationPointer += 3;

        input >> label >> opcode >> operand;
    }
    out << hex << locationPointer << " "<< label << " " << opcode << " " << operand << endl; //Added for END line
    return 0;
}
