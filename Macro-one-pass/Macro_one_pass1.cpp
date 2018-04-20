/*
**************************
@Author: Vishal P
@Lab: System Software Lab
Version 2.0 Improved from code Given by Mam
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Macro_one_pass1.cpp
*/

#include<iostream>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include<fstream>
using namespace std;
struct deftab
  {
    string label;
    string opcode;
    string operand;
  }d[10];

int main()
  {
    string label,opcode,operand,newlabel,newoperand,macroname;
    int i,lines;
    ifstream f1("Macro_input.txt"); //input file
    ofstream f2("Macro_output.txt"); // generated output file
    ofstream f3("Macro_deftab.txt"); // generated output file
    f1>>label>>opcode>>operand;
    while(opcode != "END")
    {
      if(opcode == "MACRO")
      {
        macroname = label;
        f1>>label>>opcode>>operand;
        lines=0;
        while(opcode != "MEND")
        {
          f3<<label<<" "<<opcode<<" "<<operand<<endl;
          d[lines].label =label;
          d[lines].opcode = opcode;
          d[lines].operand = operand;
          f1>>label>>opcode>>operand;
          lines++;
        }
      }
      else if(opcode == macroname)
      {
        if(label != "-")
        f2<<label;
        for(i=0;i<lines;i++)
        {
          f2<<d[i].label<<" "<<d[i].opcode<<" "<<d[i].operand<<endl;
        }
      }
      else
        f2<<label<<" "<<opcode<<" "<<operand<<endl;
        f1>>label>>opcode>>operand;
    }
    f2<<label<<" "<<opcode<<" "<<operand<<endl;
    return 0;
  }
