%{ 
#ifdef PRINT
#define RETURN(argtype, token) printf(#argtype " " #token "\n");
#else
#define RETURN(argtype, token) return(token)
#endif

#include <string.h>
/*
#include "spl.tab.c"


extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char*);
*/

int installId(char*);
/*
struct symTabNode {
    char* symbol;
    struct symTabNode* prev;
    struct symTabNode* next;
};
typedef struct symTabNode SYMTABNODE;
typedef SYMTABNODE* SYMTABNODEPTR;

struct symbolTable {
    SYMTABNODEPTR head;
    SYMTABNODEPTR tail;
    int length;
};
typedef struct symbolTable SYMBOLTABLE;
typedef SYMBOLTABLE* SYMBOLTABLEPTR;
*/

#ifndef PRINT
    extern SYMBOLTABLEPTR symbol_table;
#endif
%}

delim       [ \t\n\r]
ws          {delim}+

integer_constant     [0-9]+
real_constant        [0-9]+\.[0-9]+
character_constant   '[a-zA-Z]'

identifer           [a-zA-Z][a-zA-Z0-9]*

%%

{ws}                    ;/* ignore white space */
"<>"                    RETURN(binary_operator, NOT_EQUAL);
"<="                    RETURN(binary_operator, LESS_OR_EQUAL);
">="                    RETURN(binary_operator, GREATER_OR_EQUAL);
"="                     RETURN(binary_operator, EQUAL);
"<"                     RETURN(binary_operator, LESS_THAN);
">"                     RETURN(binary_operator, GREATER_THAN);
"+"                     RETURN(binary_operator, ADD);
"-"                     RETURN(binary_operator, SUBTRACT);
"*"                     RETURN(binary_operator, MULTIPLY);
"/"                     RETURN(binary_operator, DIVIDE);
":"                     RETURN(seperator, COLON);
ENDP                    RETURN(keyword, ENDP);
"."                     RETURN(seperator, PERIOD);
DECLARATIONS            RETURN(keyword, DECLARATIONS);
CODE                    RETURN(keyword, CODE);
","                     RETURN(seperator, COMMA);
OF                      RETURN(keyword, OF);
TYPE                    RETURN(keyword, TYPE);
";"                     RETURN(seperator,  SEMICOLON);
CHARACTER               RETURN(type, CHARACTER);
INTEGER                 RETURN(type, INTEGER);
REAL                    RETURN(type, REAL);
"->"                    RETURN(binary_operator, ASSIGN);
IF                      RETURN(keyword, IF);
THEN                    RETURN(keyword, THEN);
ELSE                    RETURN(keyword, ELSE);
ENDIF                   RETURN(keyword, ENDIF);
DO                      RETURN(keyword, DO);
WHILE                   RETURN(keyword, WHILE);
ENDDO                   RETURN(keyword, ENDDO);
ENDWHILE                RETURN(keyword, ENDWHILE);
FOR                     RETURN(keyword, FOR);
IS                      RETURN(keyword, IS);
BY                      RETURN(keyword, BY);
TO                      RETURN(keyword, TO);
ENDFOR                  RETURN(keyword, ENDFOR);
WRITE                   RETURN(keyword, WRITE);
"("                     RETURN(braket, OPEN_BRAKET);
")"                     RETURN(braket, CLOSE_BRAKET);
NEWLINE                 RETURN(keyword, NEWLINE);
READ                    RETURN(keyword, READ);
NOT                     RETURN(keyword, NOT);
AND                     RETURN(keyword, AND);
OR                      RETURN(keyword, OR);

{identifer}             { 
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(identifier, IDENTIFIER);
                        }


{character_constant}    {
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(character_constant,CHARACTER_CONSTANT);
                        }   

{real_constant}         {
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(real_constant, REAL_CONSTANT);
                        }

{integer_constant}      {
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(integer_constant, INTEGER_CONSTANT);
                        }
                        
%%
#ifndef PRINT
    int installId(char* sym) {
        extern SYMBOLTABLEPTR symbol_table;
        if (!symbol_table) {
            symbol_table = create_symbolTable();
        }
        int index = symbolTable_get_index_of_node(symbol_table, sym);
        return (index > -1) ? index : symbolTable_add_node(symbol_table, sym);
    }
#endif

