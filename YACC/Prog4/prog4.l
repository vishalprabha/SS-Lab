/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a yacc program to recognize the strings of the form ambn, where m>=0,n>=0.
*/

%{
#include "y.tab.c"
%}
%%
[aA] {return A;}
[bB] {return B;}
[\n] {return NL;}
. {return yytext[0];}
%%
