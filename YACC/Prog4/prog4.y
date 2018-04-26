/*
**************************
@Author: Vishal P
@Lab: System Software Lab
**************************
Question: Develop a yacc program to recognize the strings of the form ambn, where m>=0,n>=0.
*/

%token A B NL
%%
stmt : C D NL {printf("Valid\n"); exit(0); }
     ;
C : A C
  |A
  | ;

D : B D
  |B
  | ;
%%
int yyerror(char*msg){
    printf("Invalid\n");
    exit(0);
}
int main(){
    yyparse();
    return 0;
}
