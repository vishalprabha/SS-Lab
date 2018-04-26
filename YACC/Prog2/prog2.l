/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a yacc program to recognize a valid variable, which starts with a letter, followed by any number of
letters or digits.
*/

%{
  #include "y.tab.c"
  #include<stdio.h>
  #include<stdlib.h>
%}
%%
[0-9]+ {return DIGIT;}
[a-zA-Z] {return LETTER;}
[_] {return UND;}
[\n] {return NL;}
      . {return yytext[0];}
%%
