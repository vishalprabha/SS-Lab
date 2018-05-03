%{
int l=0, c=0, w=0, s=0; //Definitions
%}
%%
[^ \t\n,."'/]+ {w++; c+=yyleng;} //Rule for words
[ ] {s++;} // Rule for spaces
[\n] {l++;} // Rule for new line character
. {c++;} //Rule for every other character
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[]) //argv for taking input through arguments from command line
{
    yyin=fopen(argv[1], "r"); // For reading input file
    yylex();
    printf("Lines: %d\nSpaces: %d\nWords: %d\nCharacters: %d\n", l, s, w, c); //Print characters
    return 0;
}
