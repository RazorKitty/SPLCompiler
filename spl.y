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
                        /*{
                            TERNARY_TREE ParseTree;
                            if (strcmp($1, $5))
                                ParseTree = create_node($1, PROGRAM, $3, NULL, NULL);
                            
                        }*/
                        ;


block                   : DECLARATIONS declaration_block CODE statement_list
                        /*{
                            $$ = create_node(NOTHING, BLOCK, $2, $4, NULL);
                        }*/
                        | CODE statement_list
                        /*{
                            $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL);
                        }*/
                        ;


declaration_block       : identifier_list OF TYPE type SEMICOLON declaration_block
                        /*{
                            $$ = create_node(NOTHING, DELCLARATION_BLOCK, $1, $4, NULL);
                        }*/
                        | identifier_list OF TYPE type SEMICOLON
                        /*{
                            $$ = create_node(NOTHING, DELCLARATION_BLOCK, $1, $4, NULL);
                        }*/
                        ;


identifier_list         : IDENTIFIER
                        /*{
                            $$ = create_node($1, IDENTIFIER, NULL, NULL, NULL);
                        }*/
                        | IDENTIFIER COMMA identifier_list
                        /*{
                            $$ = create_node($1, IDENTIFIER, $3, NULL, NULL);
                        }*/
                        ;


type                    : CHARACTER
                        /*{
                            $$ = create_node(NOTHING, CHARACTER, NULL, NULL, NULL);
                        }*/
                        | INTEGER
                        /*{
                            $$ = create_node(NOTHING, INTEGER, NULL, NULL, NULL);
                        }*/
                        | REAL
                        /*{
                            $$ = create_node(NOTHING, REAL, NULL, NULL, NULL);
                        }*/
                        ;


statement_list          : statement
                        /*{
                            $$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL ,NULL);
                        }*/
                        | statement SEMICOLON statement_list
                        /*{
                            $$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL);
                        }*/
                        ;


statement               : expression ASSIGN IDENTIFIER
                        /*{
                            $$ = create_node(NOTHING, ASSIGNMENT_STATEMENT, $1, NULL, NULL);
                        }*/
                        | IF conditional THEN statement_list ENDIF
                        /*{
                            $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL);
                        }*/
                        | IF conditional THEN statement_list ELSE statement_list ENDIF
                        /*{
                            $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, $6);
                        }*/
                        | DO statement_list WHILE conditional ENDDO
                        /*{
                            $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL);
                        }*/
                        | WHILE conditional DO statement_list ENDWHILE
                        /*{
                            $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL);
                        }*/
                        | FOR for_loop statement_list ENDFOR
                        /*{
                            $$ = create_node(NOTHING, FOR_STATEMENT, $2, $3, NULL);
                        }*/
                        | WRITE OPEN_BRAKET output_list CLOSE_BRAKET
                        /*{
                            $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL);
                        }*/
                        | NEWLINE
                        /*{
                            //may want to come back to thins... 
                            $$ = create_node(NOTHING, WRITE_STATEMENT, NULL, NULL, NULL);
                        }*/
                        | READ OPEN_BRAKET IDENTIFIER CLOSE_BRAKET
                        /*{
                            $$ = create_node(NOTHING, READ_STATEMENT, $3, NULL, NULL);
                        }*/
                        ;


for_loop                : IDENTIFIER IS expression BY expression TO expression DO
                        /*{
                            $$ = create_node($1, FOR_LOOP, $3, $5, $7);
                        }*/
                        ;

output_list             : value
                        /*{
                            $$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL);
                        }*/
                        | value COMMA output_list
                        /*{
                            $$ = create_node(NOTHING, OUTPUT_LIST, $1, $3, NULL);
                        }*/
                        ;

conditional             : NOT conditional
                        /*{
                           $$ = create_node(NOTHING, CONDITONAL, $2, NULL, NULL); 
                        }*/
                        | comparison
                        /*{
                            $$ = create_node(NOTHING, CONDITONAL, $1, NULL, NULL);
                        }*/
                        | comparison AND conditional
                        /*{
                            $$ = create_node(NOTHING, CONDITONAL, $1, $3, NULL);
                        }*/
                        | comparison OR conditional
                        /*{
                            $$ = create_node(NOTHING, CONDITONAL, $1, $3, NULL);
                        }*/
                        ;

comparison              : expression comparitor expression
                        /*{
                            $$ = create_node(NOTHING, COMPARISION, $1, $2, $3);
                        }*/
                        ;

comparitor              : EQUAL
                        /*{
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }*/
                        | NOT_EQUAL
                        /*{
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }*/
                        | LESS_THAN
                        /*{
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }*/
                        | GREATER_THAN
                        /*{
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }*/
                        | LESS_OR_EQUAL
                        /*{
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }*/
                        | GREATER_OR_EQUAL
                        /*{
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }*/
                        ;

expression              : value
                        /*{
                            $$ = create_node(NOTHING, EXPRESSION, $1, NULL, NULL);
                        }*/
                        | value operator expression
                        /*{
                            $$ = create_node(NOTHING, EXPRESSION, $1, $2, $3);
                        }*/
                        ;

operator                : ADD
                        /*{
                            $$ = create_node(NOTHING, OPERATOR, NULL, NULL, NULL);
                        }*/
                        | SUBTRACT
                        /*{
                            $$ = create_node(NOTHING, OPERATOR, NULL, NULL, NULL);
                        }*/
                        | MULTIPLY
                        /*{
                            $$ = create_node(NOTHING, OPERATOR, NULL, NULL, NULL);
                        }*/
                        | DIVIDE
                        /*{
                            $$ = create_node(NOTHING, OPERATOR, NULL, NULL, NULL);
                        }*/
                        ;

value                   : IDENTIFIER
                        /*{
                            $$ = create_node(NOTHING, VALUE, NULL, NULL, NULL);
                        }*/
                        | constant
                        /*{
                            $$ = create_node(NOTHING, VALUE, $1, NULL, NULL);
                        }*/
                        | SUBTRACT constant
                        /*{
                            $$ = create_node(NOTHING, VALUE, $2, NULL, NULL);
                        }*/
                        | OPEN_BRAKET expression CLOSE_BRAKET
                        /*{
                            $$ = create_node(NOTHING, VALUE, $1, NULL, NULL);
                        }*/
                        ;

constant                : REAL_CONSTANT
                        /*{
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }*/
                        | INTEGER_CONSTANT
                        /*{
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }*/
                        | CHARACTER_CONSTANT
                        /*{
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }*/
                        ;
%%
#include "lex.yy.c"
