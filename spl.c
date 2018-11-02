#include <stdio.h>

int yyparse(void);

int main(void)
{
    return(yyparse());
}

void yyerror(char *s)
{
    fprintf(stderr, "Error : Exiting %s\n", s);
}
