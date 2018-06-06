%{
int c=0;
%}
%%
"/*"[^("*/")]+"*/" {c++;}
"//" {c++;}
. {;}
[\n] {;}
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[])
{
    yyin=fopen(argv[1], "r");
    yylex();
    printf("The number of comments is : %d\n", c); 
    return 0;
}
