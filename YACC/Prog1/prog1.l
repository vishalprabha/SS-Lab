%{
#include "y.tab.h"
%}
%%
[0-9]+(\.[0-9]+)? {return NUMBER;}
[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
[\n] {return NL;}
. {return yytext[0];} 
%%
