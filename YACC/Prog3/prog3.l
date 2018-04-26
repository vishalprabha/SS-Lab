/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a yacc program to evaluate an arithmetic expression involving operators +,-,* and /.
*/

%{
#include "y.tab.c"
%}
%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}
\n {return NL;}
. {return yytext[0];}
%%
