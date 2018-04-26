/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a yacc program to recognize a valid arithmetic expression that uses operators + ,- ,* and /.
*/

%{
  int yylex();
  int yyerror(char *);
  #include<stdlib.h>
  #include<stdio.h>
%}
%token ID NUMBER NL //Declarations
%left '+' '-'
%left '*' '/'
%% //Rules
  stmt : exp NL {printf("Valid\n"); exit(0);}
  ;
  exp : exp '+' exp
  |exp '-' exp
  |exp '*' exp
  |exp '/' exp
  |'(' exp ')'
  |NUMBER
  |ID
  ;
%%
int yyerror(char * msg){
    printf("Invalid\n");
    exit(0);
}

int main(){
    int yylex();
    yyparse();
    return 0;
}
