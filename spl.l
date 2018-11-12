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
"<>"                    RETURN(binary_operator, NOT_EQUAL_T);
"<="                    RETURN(binary_operator, LESS_OR_EQUAL_T);
">="                    RETURN(binary_operator, GREATER_OR_EQUAL_T);
"="                     RETURN(binary_operator, EQUAL_T);
"<"                     RETURN(binary_operator, LESS_THAN_T);
">"                     RETURN(binary_operator, GREATER_THAN_T);
"+"                     RETURN(binary_operator, ADD_T);
"-"                     RETURN(binary_operator, SUBTRACT_T);
"*"                     RETURN(binary_operator, MULTIPLY_T);
"/"                     RETURN(binary_operator, DIVIDE_T);
":"                     RETURN(seperator, COLON_T);
ENDP                    RETURN(keyword, ENDP_T);
"."                     RETURN(seperator, PERIOD_T);
DECLARATIONS            RETURN(keyword, DECLARATIONS_T);
CODE                    RETURN(keyword, CODE_T);
","                     RETURN(seperator, COMMA_T);
OF                      RETURN(keyword, OF_T);
TYPE                    RETURN(keyword, TYPE_T);
";"                     RETURN(seperator,  SEMICOLON_T);
CHARACTER               RETURN(type, CHARACTER_T);
INTEGER                 RETURN(type, INTEGER_T);
REAL                    RETURN(type, REAL_T);
"->"                    RETURN(binary_operator, ASSIGN_T);
IF                      RETURN(keyword, IF_T);
THEN                    RETURN(keyword, THEN_T);
ELSE                    RETURN(keyword, ELSE_T);
ENDIF                   RETURN(keyword, ENDIF_T);
DO                      RETURN(keyword, DO_T);
WHILE                   RETURN(keyword, WHILE_T);
ENDDO                   RETURN(keyword, ENDDO_T);
ENDWHILE                RETURN(keyword, ENDWHILE_T);
FOR                     RETURN(keyword, FOR_T);
IS                      RETURN(keyword, IS_T);
BY                      RETURN(keyword, BY_T);
TO                      RETURN(keyword, TO_T);
ENDFOR                  RETURN(keyword, ENDFOR_T);
WRITE                   RETURN(keyword, WRITE_T);
"("                     RETURN(braket, OPEN_BRAKET_T);
")"                     RETURN(braket, CLOSE_BRAKET_T);
NEWLINE                 RETURN(keyword, NEWLINE_T);
READ                    RETURN(keyword, READ_T);
NOT                     RETURN(keyword, NOT_T);
AND                     RETURN(keyword, AND_T);
OR                      RETURN(keyword, OR_T);

{identifer}             { 
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(identifier, IDENTIFIER_T);
                        }


{character_constant}    {
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(character_constant,CHARACTER_CONSTANT_T);
                        }   

{real_constant}         {
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(real_constant, REAL_CONSTANT_T);
                        }

{integer_constant}      {
                            #ifndef PRINT
                                yylval.iVal = installId(yytext);
                            #endif
                            RETURN(integer_constant, INTEGER_CONSTANT_T);
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

