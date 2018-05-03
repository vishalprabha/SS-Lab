%{
int c=0; //Definition
%}

%%
"printf"|"scanf"|"int"|"float" {printf("%s is an keyword\n",yytext);} //Rule for checking if keyword
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s is an identifier\n",yytext); c++;} //Rule for an identifer
.* {printf("%s is not an identifer\n",yytext);} //Rule for other characters not an identifer
\n {;}
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[]) //argv for taking input through arguments from command line
{
    yyin=fopen(argv[1], "r"); // For reading input file
    yylex();
    printf("Number of identifers is : %d\n", c); //Print number of identifers
    return 0;
}
