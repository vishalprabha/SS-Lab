%{
#include "y.tab.h"
%}
%% //Rules
[0-9]+(\.[0-9]+)? {return NUMBER;} //Return if number
[_a-zA-Z][_a-zA-Z0-9]* {return ID;} //Return if identifier
[\n] {return NL;} //Return if newline
. {return yytext[0];} //Return text otherwise
%%
