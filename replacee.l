%{
#include <stdio.h>
#include <string.h>
%}

%%
"saveetha"   { printf("sse"); }
.|\n        { putchar(yytext[0]); }
%%

int yywrap() {
    return 1;  // Indicate end of input
}

int main(int argc, char *argv[]) {
    FILE *input_file = fopen(argv[1], "r");
   yyin = input_file;
    yylex();

    fclose(input_file);
    return 0;
}