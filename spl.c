#include <stdio.h>

extern int yyparse(void);

#if YYDEBUG
    extern int yydebug;
    yydebug = 1;
    
#endif

int main(void)
{
    return(yyparse());
}

void yyerror(char *s)
{
    fprintf(stderr, "Error : Exiting %s\n", s);
}
