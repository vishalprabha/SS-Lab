/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a yacc program to recognize a valid arithmetic expression that uses operators + ,- ,* and /.
*/


%{
#include "y.tab.c"  //Definition
%}
%% //Rules
[0-9]+ {return NUMBER;} //Return if number
[_a-zA-Z][_a-zA-Z0-9]* {return ID;} //Return if identifier
[\n] {return NL;} //Return if newline
. {return yytext[0];} //Return text otherwise
%%
int yywrap(void)
{
return 1;
}
