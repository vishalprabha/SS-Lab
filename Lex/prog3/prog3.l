%{
int stack=0, opd=0, opt=0, valid=1;
%}

%%
"(" {stack++;}
")" {stack--; if(stack < 0) {valid=0;}}
[a-zA-Z][a-zA-Z0-9]* {opd++; printf("%s is an operand\n",yytext);}
[+\-*/] {opt++; printf("%s is an operator\n",yytext);}
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[])
{
    yyin=fopen(argv[1], "r");
    yylex();
    if(stack==0 && valid==1 && opd - opt == 1)
    {
        printf("Valid\n");
    }
    else{
        printf("Invalid\n"); 
    }
    return 0;
}
