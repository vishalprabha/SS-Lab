/*
**************************
@Author: Vishal P
@Lab: System Software Lab
Version 2.0 Improved from code Given by Mam
**************************
Note: Incase of error in lab execute : $ g++ --std=c++11 Macro_one_pass1.cpp
*/


// Create Arg_tab.txt file before executing the program 
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
    string label,opcode,operand,newlabel,newoperand,macroname,ex;
    int i,lines;
    ifstream f1("Macro_input.txt");
    ofstream f2("Macro_output.txt");
    ofstream f3("Macro_deftab.txt");

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
        f4>>ex;
        for(i=0;i<lines;i++)
        {
          if(d[i].operand[0]=='&')
          {
          f2<<d[i].label<<" "<<d[i].opcode<<" "<<ex<<endl;
          f4>>ex;
          }
          else
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
