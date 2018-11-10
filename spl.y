%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(char *);

#define SYMTABSIZE      50
#define IDLENGTH        15
#define NOTHING         -1
#define INDENTOFFSET    2l

enum ParseTreeNodeType { PROGRAM, BLOCK, DELCLARATION_BLOCK, IDENTIFIER_LIST, TYPE, STATEMENT_LIST, STATEMENT, ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, WHILE_STATEMENT FOR_STATEMENT, FOR_LOOP, WRITE_STATEMENT, READ_STATEMENT, OUTPUT_LIST, CONDITONAL, COMPARITOR, EXPRESSION, TERM, VALUE, CONSTANT};

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FLASE 0
#endif

#ifndef NULL
#define NULL 0
#endif

struct treeNode {
    int item;
    int nodeIdentifier;
    struct treeNode* first;
    struct treeNode* second;
    struct treeNode* third;
};

typedef struct treeNode TREE_NODE;
typedef TREE_NODE* TERNARY_TREE;

TERNARY_TREE create_node(int, int, TERNARY_TREE, TERNARY_TREE, TERNARY_TREE);
/*
struct symTabNode {
    char identfier[IDLENGTH];
};

typedef struct symTabNode SYMTABNODE;
typedef SYMTABNODE* SYMTABNODEPTR;

SYMTABNODEPTR symTab[SYMTABSIZE];

int currentSymTabSize = 0;
*/

struct symTabNode {
    char* identifier;
    struct symTabNode* prev;
    struct symTabNode next;
};
typedef struct symTabNode SYMTABNODE;
typedef SYMTABNODE* SYMTABNODEPTR;

struct symbolTable {
    SYMTABNODEPTR head;
    SYMTABNODEPTR tail;
    int length;
};
typedef symbolTable SYMBOLTABLE;
typedef SYMBOLTABLE* SYMBOLTABLEPTR

/* create a symbol table node */
SYMTABNODEPTR create_symTabNode(char*);

/* create a symbolTable table */
SYMBOLTABLEPTR create_symbolTable(void);

/* add a node to the table */
int symbolTable_add_node(SYMBOLTABLEPTR, char*);

/* get the node at a given index */
SYMTABNODEPTR symbolTable_get_node_for_index(SYMBOLTABLEPTR, int);

/* get the index for an node whos identifier  */
int symbolTable_get_index_of_node(SYMBOLTABLEPTR, char*);

SYMBOLTABLEPTR symbol_table = NULL;


%}

%start program

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
%token<iVal> IDENTIFIER



%token COLON ENDP PERIOD DECLARATIONS CODE COMMA OF TYPE SEMICOLON CHARACTER INTEGER REAL ASSIGN IF THEN ELSE ENDIF DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE OPEN_BRAKET CLOSE_BRAKET NEWLINE READ NOT AND OR NOT_EQUAL LESS_OR_EQUAL GREATER_OR_EQUAL EQUAL LESS_THAN GREATER_THAN ADD SUBTRACT MULTIPLY DIVIDE


%type<tVal> block declaration_block identifier_list type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparison comparitor constant value expression for_loop term

%%

program                 : IDENTIFIER COLON block ENDP IDENTIFIER PERIOD 
                        {
                            TERNARY_TREE ParseTree;
                            if ($1 == $5)
                                ParseTree = create_node($1, PROGRAM, $3, NULL, NULL);
                            
                        }
                        ;


block                   : DECLARATIONS declaration_block CODE statement_list
                        {
                            $$ = create_node(NOTHING, BLOCK, $2, $4, NULL);
                        }
                        | CODE statement_list
                        {
                            $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL);
                        }
                        ;


declaration_block       : identifier_list OF TYPE type SEMICOLON declaration_block
                        {
                            $$ = create_node(NOTHING, DELCLARATION_BLOCK, $1, $4, NULL);
                        }
                        | identifier_list OF TYPE type SEMICOLON
                        {
                            $$ = create_node(NOTHING, DELCLARATION_BLOCK, $1, $4, NULL);
                        }
                        ;


identifier_list         : IDENTIFIER
                        {
                            $$ = create_node($1, IDENTIFIER_LIST, NULL, NULL, NULL);
                        }
                        | IDENTIFIER COMMA identifier_list
                        {
                            $$ = create_node($1, IDENTIFIER_LIST, $3, NULL, NULL);
                        }
                        ;


type                    : CHARACTER
                        {
                            $$ = create_node(NOTHING, TYPE, NULL, NULL, NULL);
                        }
                        | INTEGER
                        {
                            $$ = create_node(NOTHING, TYPE, NULL, NULL, NULL);
                        }
                        | REAL
                        {
                            $$ = create_node(NOTHING, TYPE, NULL, NULL, NULL);
                        }
                        ;


statement_list          : statement
                        {
                            $$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL ,NULL);
                        }
                        | statement SEMICOLON statement_list
                        {
                            $$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL);
                        }
                        ;

statement               : assignment_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        | if_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        | do_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        | while_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        | for_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        | write_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        | read_statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL);
                        }
                        ;

assignment_statement    : expression ASSIGN IDENTIFIER
                        {
                            $$ = create_node(NOTHING, ASSIGNMENT_STATEMENT, $1, NULL, NULL);
                        }
                        ;

if_statement            : IF conditional THEN statement_list ENDIF
                        {
                            $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL);
                        }
                        | IF conditional THEN statement_list ELSE statement_list ENDIF
                        {
                            $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, $6);
                        }
                        ;

do_statement            : DO statement_list WHILE conditional ENDDO
                        {
                            $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL);
                        }
                        ;

while_statement         : WHILE conditional DO statement_list ENDWHILE
                        {
                            $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL);
                        }
                        ;

for_statement           : FOR for_loop statement_list ENDFOR
                        {
                            $$ = create_node(NOTHING, FOR_STATEMENT, $2, $3, NULL);
                        }
                        ;

for_loop                : IDENTIFIER IS expression BY expression TO expression DO
                        {
                            $$ = create_node($1, FOR_LOOP, $3, $5, $7);
                        }
                        ;

write_statement         : WRITE OPEN_BRAKET output_list CLOSE_BRAKET
                        {
                            $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL);
                        }
                        ;

read_statement          : READ OPEN_BRAKET IDENTIFIER CLOSE_BRAKET
                        {
                            $$ = create_node($3, READ_STATEMENT, NULL, NULL, NULL)
                        }

output_list             : value
                        {
                            $$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL);
                        }
                        | value COMMA output_list
                        {
                            $$ = create_node(NOTHING, OUTPUT_LIST, $1, $3, NULL);
                        }
                        ;

conditional             : NOT conditional
                        {
                           $$ = create_node(NOTHING, CONDITONAL, $2, NULL, NULL); 
                        }
                        | comparison
                        {
                            $$ = create_node(NOTHING, CONDITONAL, $1, NULL, NULL);
                        }
                        | comparison AND conditional
                        {
                            $$ = create_node(NOTHING, CONDITONAL, $1, $3, NULL);
                        }
                        | comparison OR conditional
                        {
                            $$ = create_node(NOTHING, CONDITONAL, $1, $3, NULL);
                        }
                        ;

comparison              : expression comparitor expression
                        {
                            $$ = create_node(NOTHING, COMPARISION, $1, $2, $3);
                        }
                        ;

comparitor              : EQUAL
                        {
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }
                        | NOT_EQUAL
                        {
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }
                        | LESS_THAN
                        {
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }
                        | GREATER_THAN
                        {
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }
                        | LESS_OR_EQUAL
                        {
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }
                        | GREATER_OR_EQUAL
                        {
                            $$ = create_node(NOTHING, COMPARITOR, NULL ,NULL, NULL);
                        }
                        ;

expression              : term ADD term
                        {
                            $$ = create_node(NOTHING, EXPRESSION, $1, $3, NULL);
                        }
                        | term SUBTRACT term
                        {
                            $$ = create_node(NOTHING, EXPRESSION, $1, $3, NULL);
                        }
                        | term
                        {
                            $$ = create_node(NOTHING, EXPRESSION, $1, NULL, NULL);
                        }
                        ;

term                    : value MULTIPLY value
                        {
                            $$ = create_node(NOTHING, TERM, $1, $3, NULL);
                        }
                        | value DIVIDE value
                        {
                            $$ = create_node(NOTHING, TERM, $1, $3, NULL);
                        }
                        | value
                        {
                            $$ = create_node(NOTHING, TERM, $1, NULL, NULL);
                        }
                        ;

value                   : IDENTIFIER
                        {
                            $$ = create_node($1, VALUE, NULL, NULL, NULL);
                        }
                        | constant
                        {
                            $$ = create_node(NOTHING, VALUE, $1, NULL, NULL);
                        }
                        | OPEN_BRAKET expression CLOSE_BRAKET
                        {
                            $$ = create_node(NOTHING, VALUE, $2, NULL, NULL);
                        }
                        ;

constant                : SUBTRACT REAL_CONSTANT
                        {
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }
                        | REAL_CONSTANT
                        {
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }
                        | SUBTRACT INTEGER_CONSTANT
                        {
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }
                        | INTEGER_CONSTANT
                        {
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }
                        | CHARACTER_CONSTANT
                        {
                            $$ = create_node(NOTHING, CONSTANT, NULL, NULL, NULL);
                        }
                        ;
%%

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1, TERNARY_TREE p2, TERNARY_TREE p3) {
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return(t)
}



/* create a symbol table node */
SYMTABNODEPTR create_symTabNode(char* id) {
    SYMTABNODEPTR node = (SYMTABNODEPTR)malloc(sizeof(SYMTABNODE));
    strcpy(node->identifier, id);
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/* create a symbolTable table */
SYMBOLTABLEPTR create_symbolTable(void) {
    SYMBOLTABLEPTR table = (SYMBOLTABLEPTR)malloc(sizeof(SYMBOLTABLE));
    table->head = NULL;
    table-tail = NULL;
    table->length = 0;
    return table;
}

/* add a node to the table */
int symbolTable_add_node(SYMBOLTABLEPTR table, char* id) {
    SYMTABNODEPTR new_node = create_symTabNode(id);
    if (table->head == NULL) {
        table->head = table->tail = new_node;
    }
    table->tail->next = new_node;
    new_node->prev = talbe->tail;
    table->tail = new_node;
    return list-length++;
}

/* get the node at a given index */
SYMTABNODEPTR symbolTable_get_node_for_index(SYMBOLTABLEPTR table, int index) {
    if (index > list->length) {
        return NULL;
    }
    SYMTABNODEPTR current_node = table-head;
    int i;
    for (i = 0; i < index; ++i) {
        current_node = current_node->next;
    }
    return current_node;
}

/* get the index for an node whos identifier  */
int symbolTable_get_index_of_node(SYMBOLTABLEPTR table, char* id) {
    SYMTABNODEPTR current_node = table->head;
    int i;
    for (i = 0; i < table->length; ++i) {
        if (strcmp(current_node->identifier, id) == 0) {
            return i;
        }
        current_node = current_node->next;
    }
    return -1;
}



#include "lex.yy.c"
