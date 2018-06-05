/*
**************************
@Author: Vishal P
@Lab: System Software Lab
Version 2.0 Improved from code Given by Mam
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Macro_one_pass1.cpp
*/

//Create empty Macro_deftab.txt file before executing the program
// Create empty Arg_tab.txt file before executing the program
#include<iostream>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include<fstream>
using namespace std;
int main()
  {
    string label,opcode,operand,newlabel,newoperand,newopcode,macroname,ex;
    int i,lines;
    ifstream f1("Macro_input.txt");
    ofstream f2("Macro_output.txt");
    fstream f3("Macro_deftab.txt");

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
          f1>>label>>opcode>>operand;
          lines++;
        }
      }
      else if(opcode == macroname)
      {
        fstream f4("Arg_tab.txt");
        if(label != "-")
        f2<<label;
        int n = operand.length();
        char arr[n+1];
        strcpy(arr, operand.c_str());
        char * ar = strtok(arr,",");
        while (ar != NULL)
        {
          f4<<ar<<endl;
          ar = strtok(NULL, ",");
        }
        f4.seekg(0,ios::beg);
        f3.seekg(0,ios::beg);
        f4>>ex;
        f3>>newlabel>>newopcode>>newoperand;
        for(i=0;i<lines;i++)
        {
          if(newoperand[0]=='&')
          {
          f2<<newlabel<<" "<<newopcode<<" "<<ex<<endl;
          f4>>ex;
          f3>>newlabel>>newopcode>>newoperand;
          }
          else
          f2<<newlabel<<" "<<newopcode<<" "<<newoperand<<endl;
          f3>>newlabel>>newopcode>>newoperand;
        }
      }
      else
        f2<<label<<" "<<opcode<<" "<<operand<<endl;
        f1>>label>>opcode>>operand;
    }
    f2<<label<<" "<<opcode<<" "<<operand<<endl;
    return 0;
  }
