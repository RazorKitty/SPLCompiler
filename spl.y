%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(char *);
#define NOTHING         -1
#define INDENTOFFSET    2l

enum ParseTreeNodeType { PROGRAM, BLOCK, DECLARATION, CHARACTER_TYPE, INTEGER_TYPE, REAL_TYPE, ID, STATEMENT_LIST, STATEMENT, ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, WHILE_STATEMENT, FOR_STATEMENT, FOR_LOOP, WRITE_STATEMENT, READ_STATEMENT, OUTPUT_LIST, COMPARISION, NOT_CONDITONAL, CONDITONAL, AND_CONDITONAL, OR_CONDITONAL, COMPARITOR, EXPRESSION, TERM, VALUE, CONSTANT, NEGATIVE_REAL_CONSTANT, POSITIVE_REAL_CONSTANT, NEGATIVE_INTEGER_CONSTANT, POSITIVE_INTEGER_CONSTANT, USIGNED_CHARACTER_CONSTANT};

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

void printTree(TERNARY_TREE, int);

SYMBOLTABLEPTR symbol_table = NULL;


%}

%start program

%union {
    int iVal;
    TERNARY_TREE tVal;

}



%token COLON ENDP PERIOD DECLARATIONS CODE COMMA OF TYPE SEMICOLON CHARACTER INTEGER REAL ASSIGN IF THEN ELSE ENDIF DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE OPEN_BRAKET CLOSE_BRAKET NEWLINE READ NOT AND OR NOT_EQUAL LESS_OR_EQUAL GREATER_OR_EQUAL EQUAL LESS_THAN GREATER_THAN ADD SUBTRACT MULTIPLY DIVIDE

%token<iVal> INTEGER_CONSTANT REAL_CONSTANT CHARACTER_CONSTANT IDENTIFIER

%type<tVal> block declaration_block identifier_list type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparison comparitor constant value expression for_loop term

%%



program                 : IDENTIFIER COLON block ENDP IDENTIFIER PERIOD 
                        {
                            TERNARY_TREE ParseTree;
                            if ($1 == $5)
                                ParseTree = create_node($1, PROGRAM, $3, NULL, NULL);
                                printTree(ParseTree, 0); 
                        }
                        ;


block                   : CODE statement_list
                        {
                            $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL);
                        }
                        |DECLARATIONS declaration_block CODE statement_list
                        {
                            $$ = create_node(NOTHING, BLOCK, $2, $4, NULL);
                        }
                        ;


declaration_block       : identifier_list OF TYPE type SEMICOLON declaration_block
                        {
                            $$ = create_node(NOTHING, DECLARATION, $1, $4, $6);
                        }
                        | identifier_list OF TYPE type SEMICOLON
                        {
                            $$ = create_node(NOTHING, DECLARATION, $1, $4, NULL);
                        }
                        ;


identifier_list         : IDENTIFIER
                        {
                            $$ = create_node($1, ID, NULL, NULL, NULL);
                        }
                        | IDENTIFIER COMMA identifier_list
                        {
                            $$ = create_node($1, ID, $3, NULL, NULL);
                        }
                        ;


type                    : CHARACTER
                        {
                            $$ = create_node(NOTHING, CHARACTER_TYPE, NULL, NULL, NULL);
                        }
                        | INTEGER
                        {
                            $$ = create_node(NOTHING, INTEGER_TYPE, NULL, NULL, NULL);
                        }
                        | REAL
                        {
                            $$ = create_node(NOTHING, REAL_TYPE, NULL, NULL, NULL);
                        }
                        ;


statement_list          : statement
                        {
                            $$ = create_node(NOTHING, STATEMENT, $1, NULL ,NULL);
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
                            $$ = create_node($3, ASSIGNMENT_STATEMENT, $1, NULL, NULL);
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
                            $$ = create_node($1, FOR_LOOP, $3, $7, $5);
                        }
                        ;

write_statement         : WRITE OPEN_BRAKET output_list CLOSE_BRAKET
                        {
                            $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL);
                        }
                        | NEWLINE
                        {
                            $$ = create_node(NOTHING, WRITE_STATEMENT, NULL, NULL, NULL);
                        }
                        ;

read_statement          : READ OPEN_BRAKET IDENTIFIER CLOSE_BRAKET
                        {
                            $$ = create_node($3, READ_STATEMENT, NULL, NULL, NULL);
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
                           $$ = create_node(NOTHING, NOT_CONDITONAL, $2, NULL, NULL); 
                        }
                        | comparison
                        {
                            $$ = create_node(NOTHING, CONDITONAL, $1, NULL, NULL);
                        }
                        | comparison AND conditional
                        {
                            $$ = create_node(NOTHING, AND_CONDITONAL, $1, $3, NULL);
                        }
                        | comparison OR conditional
                        {
                            $$ = create_node(NOTHING, OR_CONDITONAL, $1, $3, NULL);
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

expression              : expression ADD term
                        {
                            $$ = create_node(NOTHING, ADD, $1, $3, NULL);
                        }
                        | expression SUBTRACT term
                        {
                            $$ = create_node(NOTHING, SUBTRACT, $1, $3, NULL);
                        }
                        | term
                        {
                            $$ = create_node(NOTHING, TERM, $1, NULL, NULL);
                        }
                        ;

term                    : term MULTIPLY value
                        {
                            $$ = create_node(NOTHING, MULTIPLY, $1, $3, NULL);
                        }
                        | term DIVIDE value
                        {
                            $$ = create_node(NOTHING, DIVIDE, $1, $3, NULL);
                        }
                        | value
                        {
                            $$ = create_node(NOTHING, VALUE, $1, NULL, NULL);
                        }
                        ;

value                   : IDENTIFIER
                        {
                            $$ = create_node($1, ID, NULL, NULL, NULL);
                        }
                        | constant
                        {
                            $$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL);
                        }
                        | OPEN_BRAKET expression CLOSE_BRAKET
                        {
                            $$ = create_node(NOTHING, EXPRESSION, $2, NULL, NULL);
                        }
                        ;

constant                : SUBTRACT REAL_CONSTANT
                        {
                            $$ = create_node($2, NEGATIVE_REAL_CONSTANT, NULL, NULL, NULL);
                        }
                        | REAL_CONSTANT
                        {
                            $$ = create_node($1, POSITIVE_REAL_CONSTANT, NULL, NULL, NULL);
                        }
                        | SUBTRACT INTEGER_CONSTANT
                        {
                            $$ = create_node($2, NEGATIVE_INTEGER_CONSTANT, NULL, NULL, NULL);
                        }
                        | INTEGER_CONSTANT
                        {
                            $$ = create_node($1, POSITIVE_INTEGER_CONSTANT, NULL, NULL, NULL);
                        }
                        | CHARACTER_CONSTANT
                        {
                            $$ = create_node($1, USIGNED_CHARACTER_CONSTANT, NULL, NULL, NULL);
                        }
                        ;
%%

/* create a symbol table node */
SYMTABNODEPTR create_symTabNode(char* sym) {
    SYMTABNODEPTR node = (SYMTABNODEPTR)malloc(sizeof(SYMTABNODE));
    node->symbol = (char*)malloc(strlen(sym));
    strcpy(node->symbol, sym);
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/* create a symbolTable table */
SYMBOLTABLEPTR create_symbolTable(void) {
    SYMBOLTABLEPTR table = (SYMBOLTABLEPTR)malloc(sizeof(SYMBOLTABLE));
    table->head = NULL;
    table->tail = NULL;
    table->length = 0;
    return table;
}

/* add a node to the table */
int symbolTable_add_node(SYMBOLTABLEPTR table, char* sym) {
    SYMTABNODEPTR new_node = create_symTabNode(sym);
    if (table->head == NULL) {
        table->head = table->tail = new_node;
    }
    table->tail->next = new_node;
    new_node->prev = table->tail;
    table->tail = new_node;
    return table->length++;
}

/* get the node at a given index */
SYMTABNODEPTR symbolTable_get_node_for_index(SYMBOLTABLEPTR table, int index) {
    if (index > table->length) {
        return NULL;
    }
    SYMTABNODEPTR current_node = table->head;
    int i;
    for (i = 0; i < index; ++i) {
        current_node = current_node->next;
    }
    return current_node;
}

/* get the index for an node whos identifier  */
int symbolTable_get_index_of_node(SYMBOLTABLEPTR table, char* sym) {
    SYMTABNODEPTR current_node = table->head;
    int i;
    for (i = 0; i < table->length; ++i) {
        if (strcmp(current_node->symbol, sym) == 0) {
            return i;
        }
        current_node = current_node->next;
    }
    return -1;
}

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1, TERNARY_TREE p2, TERNARY_TREE p3) {
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return t;
}

 void printTree(TERNARY_TREE tree, int depth) {
    if (tree != NULL) {
        int i;
        for (i = 0; i < depth; ++i) {
            printf(" ");
        }
        SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
        switch(tree->nodeIdentifier) {
            case(PROGRAM):
                printf("Program: %s\n",node->symbol);
            break;
            case(BLOCK):
                printf("Block\n");
            break;
            case(DECLARATION):
                printf("Declaration\n");
            break;
            case(ID):
                printf("Identifier: %s\n", node->symbol);
            break;
            case(STATEMENT_LIST):
                printf("Statement list\n");
            break;
            case(STATEMENT):
                printf("Statement\n");
            break;
            case(ASSIGNMENT_STATEMENT):
                printf("Assignment statement: %s\n", node->symbol);
            break;
            case(IF_STATEMENT):
                printf("If statement\n");
            break;
            case(DO_STATEMENT):
                printf("Do statement\n");
            break;
            case(WHILE_STATEMENT):
                printf("While statement\n");
            break;
            case(FOR_STATEMENT):
                printf("For statement\n");
            break;
            case(FOR_LOOP):
                printf("For loop: %s\n", node->symbol);
            break;
            case(WRITE_STATEMENT):
                printf("Write statement\n");
            break;
            case(READ_STATEMENT):
                printf("Read statement %s\n", node->symbol);
            break;
            case(OUTPUT_LIST):
                printf("Output list\n");
            break;
            case(CHARACTER_TYPE):
                printf("Character type\n");
            break;
            case(INTEGER_TYPE):
                printf("Integer type\n");
            break;
            case(REAL_TYPE):
                printf("Real type\n");
            break;
            case(COMPARISION):
                printf("Comparison\n");
            break;
            case(NOT_CONDITONAL):
                printf("Not conditional\n");
            break;
            case(CONDITONAL):
                printf("Conditonal\n");
            break;
            case(AND_CONDITONAL):
                printf("And conditional\n");
            break;
            case(OR_CONDITONAL):
                printf("Or conditional\n");
            break;
            case(COMPARITOR):
                printf("Comparitor\n");
            break;
            case(EXPRESSION):
                printf("Expression\n");
            break;
            case(TERM):
                printf("Term\n");
            break;
            case(VALUE):
                printf("Value\n");
            break;
            case(CONSTANT):
                printf("Constant\n");
            break;
            case(NEGATIVE_REAL_CONSTANT):
                printf("Negative real constant: -%s\n", node->symbol);
            break;
            case(POSITIVE_REAL_CONSTANT):
                printf("Positive real constant: %s\n", node->symbol);
            break;
            case(NEGATIVE_INTEGER_CONSTANT):
                printf("Negative integer constant: -%s\n", node->symbol);
            break;
            case(POSITIVE_INTEGER_CONSTANT):
                printf("Positive integer constant: %s\n", node->symbol);
            break;
            case(USIGNED_CHARACTER_CONSTANT):
                printf("Character constant: %s\n", node->symbol);
            break;

        }
    printTree(tree->first, depth+2);
    printTree(tree->second, depth+2);
    printTree(tree->third, depth+2);
    }
}


#include "lex.yy.c"
