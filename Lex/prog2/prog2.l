/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a lex program to count the number of comment lines in a given C program.
Note: Execute the following way:
1. lex prog2.l
2. gcc lex.yy.c
3. ./a.out test.txt
*/

%{
int c=0; //Definitions
%}
%%
"/*"[^("*/")]+"*/" {c++;} //Rule to increment comment line when "/*-----*/" encountered
"//" {c++;} //Rule to increment comment line when "//" encountered
. {;} //Rule to ignore other characters
[\n] {;} //Rule to ignore newline
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[]) //argv for taking input through arguments from command line
{
    yyin=fopen(argv[1], "r"); // For reading input file
    yylex();
    printf("The number of comments is : %d\n", c); //Print number of comments 
    return 0;
}
