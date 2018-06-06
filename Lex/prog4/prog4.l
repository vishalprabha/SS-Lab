%{
int c=0;
%}

%%
"printf"|"scanf"|"int"|"float" {printf("%s is an keyword\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s is an identifier\n",yytext); c++;}
.* {printf("%s is not an identifer\n",yytext);}
\n {;}
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[])
{
    yyin=fopen(argv[1], "r");
    yylex();
    printf("Number of identifers is : %d\n", c); 
    return 0;
}
