%{
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(char *);

#define SYMTABSIZE      50
#define IDLENGTH        15
#define NOTHING         -1
#define INDENTOFFSET    2l

enum ParseTreeNodeType { PROGRAM, BLOCK };

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FLASE 0
#endif

#ifndef NULL
#define NULL 0
#endif

struct teeNode {
    int item;
    int nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
};

typedef struct treeNode TREE_NODE;
typedef TREE_NODE *TERNARY_TREE;

TERNARY_TREE create_node(int, int, TERNARY_TREE, TERNARY_TREE, TERNARY_TREE);

struct symTabNode {
    char identfier[IDLENGTH];
};

typedef struct symTabNode SYMTABNODE;
typedef SYMTABNODE* SYMTABNODEPTR;

SYMTABNODEPTR symTab[SYMTABSIZE];

int currentSymTabSize = 0;

*/
%}

%start program
/*
%union {
    int iVal;
    double rVal;
    char cVal;
    char* sVal;
    TERNARY_TREE tVal;

}

%token<iVal> INTEGER_CONSTANT
%token<rVal> REAL_CONSTANT
%token<cVal> CHARACTER_CONSTANT
%token<sVal> IDENTIFIER

*/

%token COLON ENDP PERIOD DECLARATIONS CODE COMMA OF TYPE SEMICOLON CHARACTER INTEGER REAL ASSIGN IF THEN ELSE ENDIF DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE OPEN_BRAKET CLOSE_BRAKET NEWLINE READ NOT AND OR NOT_EQUAL LESS_OR_EQUAL GREATER_OR_EQUAL EQUAL LESS_THAN GREATER_THAN ADD SUBTRACT MULTIPLY DIVIDE IDENTIFIER CHARACTER_CONSTANT REAL_CONSTANT INTEGER_CONSTANT

/*%type<tVal> program block declaration_block identifier_list type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparison comparitor*/

%%

program                 : IDENTIFIER COLON block ENDP IDENTIFIER PERIOD 
                        {
                            /*TERNARY_TREE ParseTree;
                            if (strcmp($1, $5)) {
                                ParseTree = create_node($1, PROGRAM, $3, NULL, NULL);
                            }
                            printf("Done");*/
                            
                        }
                        ;

block                   : DECLARATIONS declaration_block CODE statement_list
                        {
                            /*$$ = create_node(NOTHING, BLOCK, $2, $4, NULL);*/
                        }
                        | CODE statement_list
                        {
                            /*$$ = create_node(NOTHING, BLOCK, $2, NULL, NULL);*/
                        }
                        ;

declaration_block       : identifier_list OF TYPE type SEMICOLON declaration_block
                        {
                            /*$$ = create_node(NOTHING, DELCLARATION_BLOCK, $1, $4, NULL);*/
                        }
                        | identifier_list OF TYPE type SEMICOLON
                        ;

identifier_list         : IDENTIFIER
                        {
                            /*$$ = create_node($1, IDENTIFIER, NULL, NULL, NULL);*/
                        }
                        | IDENTIFIER COMMA identifier_list
                        {
                            /*$$ = create_node(NOTHING, IDENTIFIER, $1, NULL, NULL);*/
                        }
                        ;

type                    : CHARACTER
                        {
                            /*$$ = create_node(NOTHING, CHARACTER, NULL, NULL, NULL);*/
                        }
                        | INTEGER
                        {
                            /*$$ = create_node(NOTHING, INTEGER, NULL, NULL, NULL);*/
                        }
                        | REAL
                        {
                            /*$$ = create_node(NOTHING, REAL, NULL, NULL, NULL);*/
                        }
                        ;

statement_list          : statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL ,NULL);*/
                        }
                        | statement SEMICOLON statement_list
                        {
                            /*$$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL);*/
                        }
                        ;

statement               : assignment_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        | if_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        | do_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        | while_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        | for_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        | write_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        | read_statement
                        {
                            /*$$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);*/
                        }
                        ;

assignment_statement    : expression ASSIGN IDENTIFIER
                        {
                            /*$$ = create_node(NOTHING, ASSIGNMENT_STATEMENT, $1, NULL, NULL);*/
                        }
                        ;

if_statement            : IF conditional THEN statement_list ENDIF
                        | IF conditional THEN statement_list ELSE statement_list ENDIF
                        ;

do_statement            : DO statement_list WHILE conditional ENDDO
                        ;

while_statement         : WHILE conditional DO statement_list ENDWHILE
                        ;

for_statement           : FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR
                        ;

write_statement         : WRITE OPEN_BRAKET output_list CLOSE_BRAKET
                        | NEWLINE
                        ;

read_statement          : READ OPEN_BRAKET IDENTIFIER CLOSE_BRAKET
                        ;

output_list             : expression
                        | expression COMMA output_list
                        ;

conditional             : NOT conditional
                        | comparison
                        | comparison AND conditional
                        | comparison OR conditional
                        ;

comparison              : expression comparitor expression
                        ;

comparitor              : EQUAL
                        | NOT_EQUAL
                        | LESS_THAN
                        | GREATER_THAN
                        | LESS_OR_EQUAL
                        | GREATER_OR_EQUAL
                        ;

expression              : expression ADD term
                        | expression SUBTRACT term
                        | term
                        ;

term                    : term MULTIPLY value
                        | term DIVIDE value
                        | value
                        ;

value                   : IDENTIFIER
                        | constant
                        | OPEN_BRAKET expression CLOSE_BRAKET
                        ;

constant                : SUBTRACT REAL_CONSTANT
                        | SUBTRACT INTEGER_CONSTANT
                        | REAL_CONSTANT
                        | INTEGER_CONSTANT
                        | CHARACTER_CONSTANT
                        ;
%%
#include "lex.yy.c"
