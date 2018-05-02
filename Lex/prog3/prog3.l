%{
int stack=0, opd=0, opt=0, valid=1; //Definitions
%}

%%
"(" {stack++;}
")" {stack--; if(stack < 0) {valid=0;}} //Check for opening and closing brackets
[a-zA-Z][a-zA-Z0-9]* {opd++; printf("%s is an operand\n",yytext);} //Rule for operand
[+\-*/] {opt++; printf("%s is an operator\n",yytext);} //Rule for operator
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[]) //argv for taking input through arguments from command line
{
    yyin=fopen(argv[1], "r"); // For reading input file
    yylex();
    if(stack==0 && valid==1 && opd - opt == 1) //Print valid if true
    {
        printf("Valid\n");
    }
    else{
        printf("Invalid\n"); //Print false else
    }
    return 0;
}
