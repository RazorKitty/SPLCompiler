%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTHING         -1

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FLASE 0
#endif

#ifndef NULL
#define NULL 0
#endif

int yylex(void);
void yyerror(char *);

enum ParseTreeNodeType {
    PROGRAM,
    BLOCK,
    DECLARATION,
    IDENTIFIER,
    CHARACTER,
    INTEGER,
    REAL,
    STATEMENT_LIST,
    STATEMENT,
    ASSIGNMENT_STATEMENT,
    IF_STATEMENT,
    DO_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    FOR_LOOP,
    WRITE_STATEMENT,
    READ_STATEMENT,
    OUTPUT_LIST,
    COMPARISION,
    NOT,
    CONDITONAL,
    AND,
    OR,
    COMPARITOR,
    EQUAL,
    NOT_EQUAL,
    LESS_THAN,
    GREATER_THAN,
    LESS_OR_EQUAL,
    GREATER_OR_EQUAL,
    ADD,
    SUBTRACT,
    TERM,
    MULTIPLY,
    DIVIDE,
    VALUE,
    CONSTANT,
    EXPRESSION,
    NEGATIVE_REAL_CONSTANT,
    POSITIVE_REAL_CONSTANT,
    NEGATIVE_INTEGER_CONSTANT,
    POSITIVE_INTEGER_CONSTANT,
    CHARACTER_CONSTANT
};
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

struct symTabNode {
    char* symbol;
    int type;
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

void genCode(TERNARY_TREE);

SYMBOLTABLEPTR symbol_table = NULL;


%}

%start program

%union {
    int iVal;
    TERNARY_TREE tVal;
}



%token COLON_T ENDP_T PERIOD_T DECLARATIONS_T CODE_T COMMA_T OF_T TYPE_T SEMICOLON_T CHARACTER_T INTEGER_T REAL_T ASSIGN_T IF_T THEN_T ELSE_T ENDIF_T DO_T WHILE_T ENDDO_T ENDWHILE_T FOR_T IS_T BY_T TO_T ENDFOR_T WRITE_T OPEN_BRAKET_T CLOSE_BRAKET_T NEWLINE_T READ_T NOT_T AND_T OR_T NOT_EQUAL_T LESS_OR_EQUAL_T GREATER_OR_EQUAL_T EQUAL_T LESS_THAN_T GREATER_THAN_T ADD_T SUBTRACT_T MULTIPLY_T DIVIDE_T

%token<iVal> INTEGER_CONSTANT_T REAL_CONSTANT_T CHARACTER_CONSTANT_T IDENTIFIER_T

%type<tVal> block declaration_block identifier_list type statement_list statement output_list conditional comparison comparitor constant value expression term assignment_statement if_statement do_statement while_statement for_statement for_loop write_statement read_statement      

%%



program                 : IDENTIFIER_T COLON_T block ENDP_T IDENTIFIER_T PERIOD_T 
                        {
                            TERNARY_TREE ParseTree;
                            if ($1 == $5)
                                ParseTree = create_node($1, PROGRAM, $3, NULL, NULL);
                                #ifdef DEBUG
                                /*printTree(ParseTree, 0);*/
                                #endif
                                genCode(ParseTree);
                        }
                        ;


block                   : CODE_T statement_list
                        {
                            $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL);
                        }
                        |DECLARATIONS_T declaration_block CODE_T statement_list
                        {
                            $$ = create_node(NOTHING, BLOCK, $2, $4, NULL);
                        }
                        ;


declaration_block       : identifier_list OF_T TYPE_T type SEMICOLON_T declaration_block
                        {
                            $$ = create_node(NOTHING, DECLARATION, $1, $4, $6);
                        }
                        | identifier_list OF_T TYPE_T type SEMICOLON_T
                        {
                            $$ = create_node(NOTHING, DECLARATION, $1, $4, NULL);
                        }
                        ;


identifier_list         : IDENTIFIER_T
                        {
                            $$ = create_node($1, IDENTIFIER, NULL, NULL, NULL);
                        }
                        | identifier_list COMMA_T IDENTIFIER_T
                        {
                            $$ = create_node($3, IDENTIFIER, $1, NULL, NULL);
                        }
                        ;


type                    : CHARACTER_T
                        {
                            $$ = create_node(NOTHING, CHARACTER, NULL, NULL, NULL);
                        }
                        | INTEGER_T
                        {
                            $$ = create_node(NOTHING, INTEGER, NULL, NULL, NULL);
                        }
                        | REAL_T
                        {
                            $$ = create_node(NOTHING, REAL, NULL, NULL, NULL);
                        }
                        ;


statement_list          : statement
                        {
                            $$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL ,NULL);
                        }
                        | statement SEMICOLON_T statement_list
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


assignment_statement    : expression ASSIGN_T IDENTIFIER_T
                        {
                            $$ = create_node($3, ASSIGNMENT_STATEMENT, $1, NULL, NULL);
                        }
                        ;

if_statement            : IF_T conditional THEN_T statement_list ENDIF_T
                        {
                            $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL);
                        }
                        | IF_T conditional THEN_T statement_list ELSE_T statement_list ENDIF_T
                        {
                            $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, $6);
                        }
                        ;

do_statement            : DO_T statement_list WHILE_T conditional ENDDO_T
                        {
                            $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL);
                        }
                        ; 

while_statement         : WHILE_T conditional DO_T statement_list ENDWHILE_T
                        {
                            $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL);
                        }
                        ;

for_statement           : FOR_T for_loop statement_list ENDFOR_T
                        {
                            $$ = create_node(NOTHING, FOR_STATEMENT, $2, $3, NULL);
                        }
                        ;


for_loop                : IDENTIFIER_T IS_T expression BY_T expression TO_T expression DO_T
                        {
                            $$ = create_node($1, FOR_LOOP, $3, $5, $7);
                        }
                        ;

write_statement         : WRITE_T OPEN_BRAKET_T output_list CLOSE_BRAKET_T
                        {
                            $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL);
                        }
                        | NEWLINE_T
                        {
                            $$ = create_node(NOTHING, WRITE_STATEMENT, NULL, NULL, NULL);
                        }
                        ;

read_statement          : READ_T OPEN_BRAKET_T IDENTIFIER_T CLOSE_BRAKET_T
                        {
                            $$ = create_node($3, READ_STATEMENT, NULL, NULL, NULL);
                        }
                        ;



output_list             : value
                        {
                            $$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL);
                        }
                        | value COMMA_T output_list
                        {
                            $$ = create_node(NOTHING, OUTPUT_LIST, $1, $3, NULL);
                        }
                        ;

conditional             : NOT_T conditional
                        {
                           $$ = create_node(NOTHING, NOT, $2, NULL, NULL); 
                        }
                        | comparison
                        {
                            $$ = create_node(NOTHING, CONDITONAL, $1, NULL, NULL);
                        }
                        | comparison AND_T conditional
                        {
                            $$ = create_node(NOTHING, AND, $1, $3, NULL);
                        }
                        | comparison OR_T conditional
                        {
                            $$ = create_node(NOTHING, OR, $1, $3, NULL);
                        }
                        ;

comparison              : expression comparitor expression
                        {
                            $$ = create_node(NOTHING, COMPARISION, $1, $2, $3);
                        }
                        ;

comparitor              : EQUAL_T
                        {
                            $$ = create_node(NOTHING, EQUAL, NULL ,NULL, NULL);
                        }
                        | NOT_EQUAL_T
                        {
                            $$ = create_node(NOTHING, NOT_EQUAL, NULL ,NULL, NULL);
                        }
                        | LESS_THAN_T
                        {
                            $$ = create_node(NOTHING, LESS_THAN, NULL ,NULL, NULL);
                        }
                        | GREATER_THAN_T
                        {
                            $$ = create_node(NOTHING, GREATER_THAN, NULL ,NULL, NULL);
                        }
                        | LESS_OR_EQUAL_T
                        {
                            $$ = create_node(NOTHING, LESS_OR_EQUAL, NULL ,NULL, NULL);
                        }
                        | GREATER_OR_EQUAL_T
                        {
                            $$ = create_node(NOTHING, GREATER_OR_EQUAL, NULL ,NULL, NULL);
                        }
                        ;

expression              : expression ADD_T term
                        {
                            $$ = create_node(NOTHING, ADD, $1, $3, NULL);
                        }
                        | expression SUBTRACT_T term
                        {
                            $$ = create_node(NOTHING, SUBTRACT, $1, $3, NULL);
                        }
                        | term
                        {
                            $$ = create_node(NOTHING, TERM, $1, NULL, NULL);
                        }
                        ;

term                    : term MULTIPLY_T value
                        {
                            $$ = create_node(NOTHING, MULTIPLY, $1, $3, NULL);
                        }
                        | term DIVIDE_T value
                        {
                            $$ = create_node(NOTHING, DIVIDE, $1, $3, NULL);
                        }
                        | value
                        {
                            $$ = create_node(NOTHING, VALUE, $1, NULL, NULL);
                        }
                        ;

value                   : IDENTIFIER_T
                        {
                            $$ = create_node($1, IDENTIFIER, NULL, NULL, NULL);
                        }
                        | constant
                        {
                            $$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL);
                        }
                        | OPEN_BRAKET_T expression CLOSE_BRAKET_T
                        {
                            $$ = create_node(NOTHING, EXPRESSION, $2, NULL, NULL);
                        }
                        ;

constant                : SUBTRACT_T REAL_CONSTANT_T
                        {
                            $$ = create_node($2, NEGATIVE_REAL_CONSTANT, NULL, NULL, NULL);
                        }
                        | REAL_CONSTANT_T
                        {
                            $$ = create_node($1, POSITIVE_REAL_CONSTANT, NULL, NULL, NULL);
                        }
                        | SUBTRACT_T INTEGER_CONSTANT_T
                        {
                            $$ = create_node($2, NEGATIVE_INTEGER_CONSTANT, NULL, NULL, NULL);
                        }
                        | INTEGER_CONSTANT_T
                        {
                            $$ = create_node($1, POSITIVE_INTEGER_CONSTANT, NULL, NULL, NULL);
                        }
                        | CHARACTER_CONSTANT_T
                        {
                            $$ = create_node($1, CHARACTER_CONSTANT, NULL, NULL, NULL);
                        }
                        ;
%%

/* create a symbol table node */
SYMTABNODEPTR create_symTabNode(char* sym) {
    SYMTABNODEPTR node = (SYMTABNODEPTR)malloc(sizeof(SYMTABNODE));
    node->symbol = (char*)malloc(strlen(sym));
    strcpy(node->symbol, sym);
    node->type = 0;
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

/*

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
            case(IDENTIFIER):
                printf("Identifier: %s\n", node->symbol);
            break;
            case(CHARACTER):
                printf("Character\n");
            break;
            case(INTEGER):
                printf("Integer\n");
            break;
            case(REAL):
                printf("Real\n");
            break;
            case(STATEMENT_LIST):
                printf("Statement list\n");
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
            case(COMPARISION):
                printf("Comparison\n");
            break;
            case(NOT):
                printf("Not\n");
            break;
            case(CONDITONAL):
                printf("Conditonal\n");
            break;
            case(AND):
                printf("And\n");
            break;
            case(OR):
                printf("Or\n");
            break;
            case(COMPARITOR):
                printf("Comparitor\n");
            break;
            case(EQUAL):
                printf("Equal\n");
            break;
            case(NOT_EQUAL):
                printf("Not Equal\n");
            break;
            case(LESS_THAN):
                printf("Less than\n");
            break;
            case(GREATER_THAN):
                printf("Greater than\n");
            break;
            case(LESS_OR_EQUAL):
                printf("Less or equal\n");
            break;
            case(GREATER_OR_EQUAL):
                printf("Greater or equal\n");
            break;
            case(ADD):
                printf("Add\n");
            break;
            case(SUBTRACT):
                printf("Subtract\n");
            break;
            case(TERM):
                printf("Term\n");
            break;
            case(MULTIPLY):
                printf("Multiply\n");
            break;
            case(DIVIDE):
                printf("Divide\n");
            break;
            case(VALUE):
                printf("Value\n");
            break;
            case(CONSTANT):
                printf("Constant\n");
            break;
            case(EXPRESSION):
                printf("Expression\n");
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
            case(CHARACTER_CONSTANT):
                printf("Character constant: %s\n", node->symbol);
            break;

        }
    printTree(tree->first, depth+2);
    printTree(tree->second, depth+2);
    printTree(tree->third, depth+2);
    }
}

void genCode(TERNARY_TREE tree, int* datum) {
    if(!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    switch(tree->nodeIdentifier) {
        case(PROGRAM):
            printf("#include<stdio.h>\nint main(int argc, char** argv) {\n",node->symbol);
            genCode(tree->first, datum);
            printf("}\n");
        break;
        case(BLOCK):
            genCode(tree->first, datum);
            genCode(tree->second, datum);
        break;
        case(DECLARATION):
            genCode(tree->second, datum);
            genCode(tree->first, datum);
            printf(";\n");
            datum = NULL;
            genCode(tree->third, datum);
        break;
        case(IDENTIFIER_DECLARATION):
            printf("%s", node->symbol);
            node->type = datum;
            if (tree->first) {
                printf(", ");
                genCode(tree->first, datum);
            }
        break;
        case(CHARACTER):
            printf("char ");
            *datum = CHARACTER;
        break;
        case(INTEGER):
            printf("int ");
            *datum = INTEGER;
        break;
        case(REAL):
            printf("double ");
            *datum = REAL;
        break;
        case(STATEMENT_LIST):
            genCode(tree->first, datum);
            printf(";\n");
            genCode(tree->second, datum);
        break;
        case(ASSIGNMENT_STATEMENT):
            printf("%s = ", node->symbol);
            genCode(tree->first, datum);
        break;
        case(IF_STATEMENT):
            printf("if (");
            genCode(tree->first, datum);
            printf(") {\n");
            genCode(tree->second, datum);
            printf("}");
            if (tree->third) {
                printf(" else {\n");
                genCode(tree->third, datum);
                printf("}\n");
            }
        break;
        case(DO_STATEMENT):
            printf("do {\n");
            genCode(tree->first, datum);
            printf("}\n while (");
            genCode(tree->second, datum);
            printf("}\n");
        break;
        case(WHILE_STATEMENT):
            printf("while (");
            genCode(tree->first, datum);
            printf(") {\n");
            genCode(tree->second, datum);
            printf("}\n");
        break;
        case(FOR_STATEMENT):
            printf("for (");
            genCode(tree->first, datum);
            printf(") {\n");
            genCode(tree->second, datum);
            printf("}\n");
        break;
        case(FOR_LOOP):
            printf("%s = ", node->symbol);
            genCode(tree->first, datum);
            printf("; ");
            genCode(tree->third, datum);
            printf("; ");
            genCode(tree->second, datum);
        break;
        case(WRITE_STATEMENT):
        break;
        case(READ_STATEMENT):
        break;
        case(OUTPUT_LIST):
        break;
        case(COMPARISION):
        break;
        case(NOT):
        break;
        case(CONDITONAL):
        break;
        case(AND):
        break;
        case(OR):
        break;
        case(COMPARITOR):
        break;
        case(EQUAL):
        break;
        case(NOT_EQUAL):
        break;
        case(LESS_THAN):
        break;
        case(GREATER_THAN):
        break;
        case(LESS_OR_EQUAL):
        break;
        case(GREATER_OR_EQUAL):
        break;
        case(ADD):
        break;
        case(SUBTRACT):
        break;
        case(TERM):
        break;
        case(MULTIPLY):
        break;
        case(DIVIDE):
        break;
        case(VALUE):
        break;
        case(CONSTANT):
        break;
        case(EXPRESSION):
        break;
        case(NEGATIVE_REAL_CONSTANT):
        break;
        case(POSITIVE_REAL_CONSTANT):
        break;
        case(NEGATIVE_INTEGER_CONSTANT):
        break;
        case(POSITIVE_INTEGER_CONSTANT):
        break;
        case(CHARACTER_CONSTANT):
        break;
    }
}
*/

int declareType(TERNARY_TREE tree) {
    if (!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    switch(tree->nodeIdentifier) {
        case (CHARACTER):
            printf("char ");
        break;
        case (INTEGER):
            printf("int ");
        break;
        case (REAL):
            printf("double ");
        break;
    }
    return tree->nodeIdentifier;
}

void declareIdentifiers(TERNARY_TREE tree, int t) {
    if (!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    node->type = t;
    printf("%s", node->symbol);
    if (tree->first) {
        printf(", ");
        declareIdentifiers(tree->first, t);
    }
}

void genWriteStat(TERNARY_TREE tree);

void genCode(TERNARY_TREE tree) {
    if (!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    int t;
    switch (tree->nodeIdentifier) {
        case (PROGRAM):
            printf("#include<stdio.h>\n//%s\nint main() {\n", node->symbol);
            genCode(tree->first);
            printf("}\n");
        break;
        case (BLOCK):
            genCode(tree->first);
            genCode(tree->second);
        break;
        case (DECLARATION):
            t = declareType(tree->second);
            declareIdentifiers(tree->first, t);
            printf(";\n");
            genCode(tree->third);
        break;
        case (STATEMENT_LIST):
            genCode(tree->first);
            genCode(tree->second);
        break;
        case (STATEMENT):
            genCode(tree->first);
            printf(";\n");
        break;
        case (ASSIGNMENT_STATEMENT):
            printf("%s = ", node->symbol);
            genCode(tree->first);
        break;
        case (IF_STATEMENT):
            printf("if (");
            genCode(tree->first);
            printf(") {\n");
            genCode(tree->second);
            if (tree->third) {
                printf("} else {\n");
                genCode(tree->third);
            }
            printf("}");
        break;
        case (DO_STATEMENT):
            printf("do {\n");
            genCode(tree->first);
            printf("} while (");
            genCode(tree->second);
            printf(")");
        break;
        case (WHILE_STATEMENT):
            printf("while (");
            genCode(tree->first);
            printf(") {");
            genCode(tree->second);
            printf("}");
        break;
        case (FOR_STATEMENT):
            printf("for (");
            genCode(tree->first);
            printf(") {\n");
            genCode(tree->second);
            printf("}");
        break;
        case (FOR_LOOP):
            printf("%s = ", node->symbol);
            genCode(tree->first);
            printf("; %s != ", node->symbol);
            genCode(tree->third);
            printf("; %s += ", node->symbol);
            genCode(tree->second);
        break;
        case (NOT):
            printf("!");
            genCode(tree->first);
        break;
        case (CONDITONAL):
            genCode(tree->first);
        break;
        case (AND):
            genCode(tree->first);
            printf(" && ");
            genCode(tree->second);
        break;
        case (OR):
            genCode(tree->first);
            printf(" || ");
            genCode(tree->second);
        break;
        case (COMPARISION):
            genCode(tree->first);
            genCode(tree->second);
            genCode(tree->third);
        break;
        case (EQUAL):
            printf(" == ");
        break;
        case (NOT_EQUAL):
            printf(" != ");
        break;
        case (LESS_THAN):
            printf(" < ");
        break;
        case (GREATER_THAN):
            printf(" > ");
        break;
        case (LESS_OR_EQUAL):
            printf(" <= ");
        break;
        case (GREATER_OR_EQUAL):
            printf(" >= ");
        break;
        case (ADD):
            genCode(tree->first);
            printf(" + ");
            genCode(tree->second);
        break; 
        case (SUBTRACT):
            genCode(tree->first);
            printf(" - ");
            genCode(tree->second);
        break;
        case (TERM):
            genCode(tree->first);
        break;
        case (MULTIPLY):
            genCode(tree->first);
            printf(" * ");
            genCode(tree->second);
        break; 
        case (DIVIDE):
            genCode(tree->first);
            printf(" / ");
            genCode(tree->second);
        break;
        case (VALUE):
            genCode(tree->first);
        break;
        case (IDENTIFIER):
            printf("%s", node->symbol);
        break;
        case (CONSTANT):
            genCode(tree->first);
        break;
        case (EXPRESSION):
            printf("(");
            genCode(tree->first);
            printf(")");
        break;
        case (NEGATIVE_REAL_CONSTANT):
            printf("-%s", node->symbol);
        break;
        case (POSITIVE_REAL_CONSTANT):
            printf("%s", node->symbol);
        break;
        case (NEGATIVE_INTEGER_CONSTANT):
            printf("-%s", node->symbol);
        break;
        case (POSITIVE_INTEGER_CONSTANT):
            printf("%s", node->symbol);
        break;
        case (CHARACTER_CONSTANT):
            printf("%s", node->symbol);
        break;
        case (WRITE_STATEMENT):
            if(tree->first) {
                
            } else {
                printf("printf(\"\\n\")");
            }
        break;
    }
}

#include "lex.yy.c"
