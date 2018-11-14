/* A Bison parser, made by GNU Bison 3.2.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "spl.y" /* yacc.c:338  */


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
SYMTABNODEPTR create_symTabNode(char*, int);

/* create a symbolTable table */
SYMBOLTABLEPTR create_symbolTable(void);

/* add a node to the table */
int symbolTable_add_node(SYMBOLTABLEPTR, char*, int);

/* get the node at a given index */
SYMTABNODEPTR symbolTable_get_node_for_index(SYMBOLTABLEPTR, int);

/* get the index for an node whos identifier  */
int symbolTable_get_index_of_node(SYMBOLTABLEPTR, char*);

void printTree(TERNARY_TREE, int);

void genCode(TERNARY_TREE);

SYMBOLTABLEPTR symbol_table = NULL;



#line 190 "spl.tab.c" /* yacc.c:338  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COLON_T = 258,
    ENDP_T = 259,
    PERIOD_T = 260,
    DECLARATIONS_T = 261,
    CODE_T = 262,
    COMMA_T = 263,
    OF_T = 264,
    TYPE_T = 265,
    SEMICOLON_T = 266,
    CHARACTER_T = 267,
    INTEGER_T = 268,
    REAL_T = 269,
    ASSIGN_T = 270,
    IF_T = 271,
    THEN_T = 272,
    ELSE_T = 273,
    ENDIF_T = 274,
    DO_T = 275,
    WHILE_T = 276,
    ENDDO_T = 277,
    ENDWHILE_T = 278,
    FOR_T = 279,
    IS_T = 280,
    BY_T = 281,
    TO_T = 282,
    ENDFOR_T = 283,
    WRITE_T = 284,
    OPEN_BRAKET_T = 285,
    CLOSE_BRAKET_T = 286,
    NEWLINE_T = 287,
    READ_T = 288,
    NOT_T = 289,
    AND_T = 290,
    OR_T = 291,
    NOT_EQUAL_T = 292,
    LESS_OR_EQUAL_T = 293,
    GREATER_OR_EQUAL_T = 294,
    EQUAL_T = 295,
    LESS_THAN_T = 296,
    GREATER_THAN_T = 297,
    ADD_T = 298,
    SUBTRACT_T = 299,
    MULTIPLY_T = 300,
    DIVIDE_T = 301,
    INTEGER_CONSTANT_T = 302,
    REAL_CONSTANT_T = 303,
    CHARACTER_CONSTANT_T = 304,
    IDENTIFIER_T = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 124 "spl.y" /* yacc.c:353  */

    int iVal;
    TERNARY_TREE tVal;

#line 286 "spl.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   154,   158,   165,   169,   176,   180,   187,
     191,   195,   202,   206,   212,   216,   220,   224,   228,   232,
     236,   242,   248,   252,   258,   264,   270,   277,   283,   287,
     293,   301,   305,   311,   315,   319,   323,   329,   335,   339,
     343,   347,   351,   355,   361,   365,   369,   375,   379,   383,
     389,   393,   397,   403,   407,   411,   415,   419
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON_T", "ENDP_T", "PERIOD_T",
  "DECLARATIONS_T", "CODE_T", "COMMA_T", "OF_T", "TYPE_T", "SEMICOLON_T",
  "CHARACTER_T", "INTEGER_T", "REAL_T", "ASSIGN_T", "IF_T", "THEN_T",
  "ELSE_T", "ENDIF_T", "DO_T", "WHILE_T", "ENDDO_T", "ENDWHILE_T", "FOR_T",
  "IS_T", "BY_T", "TO_T", "ENDFOR_T", "WRITE_T", "OPEN_BRAKET_T",
  "CLOSE_BRAKET_T", "NEWLINE_T", "READ_T", "NOT_T", "AND_T", "OR_T",
  "NOT_EQUAL_T", "LESS_OR_EQUAL_T", "GREATER_OR_EQUAL_T", "EQUAL_T",
  "LESS_THAN_T", "GREATER_THAN_T", "ADD_T", "SUBTRACT_T", "MULTIPLY_T",
  "DIVIDE_T", "INTEGER_CONSTANT_T", "REAL_CONSTANT_T",
  "CHARACTER_CONSTANT_T", "IDENTIFIER_T", "$accept", "program", "block",
  "declaration_block", "identifier_list", "type", "statement_list",
  "statement", "assignment_statement", "if_statement", "do_statement",
  "while_statement", "for_statement", "for_loop", "write_statement",
  "read_statement", "output_list", "conditional", "comparison",
  "comparitor", "expression", "term", "value", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -39,    16,    14,    11,   -47,   -27,    59,    22,   -47,    51,
      43,    -3,    59,    -3,    12,    35,   -10,   -47,    37,    13,
     -47,   -47,   -47,   -47,   -47,    65,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,    -8,     8,   -47,   -47,    40,    59,    44,
      68,    -3,    69,    36,    73,    66,    75,    71,    59,   -10,
     -15,    47,   -47,   -47,    59,    48,   -10,   -10,   -10,   -10,
      88,   -47,   -47,    -4,   -47,    59,    -3,    -3,   -47,   -47,
     -47,   -47,   -47,   -47,   -10,    -3,    59,   -10,    74,    70,
      96,   -47,    87,   -47,   -47,     8,     8,   -47,   -47,   -47,
     -47,   -47,   -47,   108,    55,   -47,   -47,    38,    98,    99,
     -22,   -47,   -47,   -10,   -47,   -27,    59,   -47,   -47,   -47,
     -10,   -47,   -47,   102,     6,   -47,   -10,   -19,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      56,    54,    57,    50,     4,    12,    14,    15,    16,    17,
      18,    19,    20,     0,    46,    49,    51,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    53,     0,     0,     0,     0,     0,     0,
       0,     3,     8,     0,    33,     0,     0,     0,    39,    42,
      43,    38,    40,    41,     0,     0,     0,     0,     0,     0,
      31,    52,     0,    13,    21,    44,    45,    47,    48,     2,
       9,    10,    11,     0,     0,    35,    36,    37,     0,     0,
       0,    26,    28,     0,    30,     6,     0,    22,    24,    25,
       0,    32,     5,     0,     0,    23,     0,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,    18,   -47,   -47,    -6,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,    21,     2,   -47,   -47,
     -11,    28,   -46,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    93,    24,    25,    26,    27,
      28,    29,    30,    48,    31,    32,    79,    42,    43,    74,
      33,    34,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,   118,    44,    80,   110,    50,    45,    55,    90,    91,
      92,     1,    87,    88,     4,    46,    81,     5,     6,     3,
      16,    56,    57,     8,    56,    57,    37,    16,    56,    57,
      44,    41,    61,   116,    19,    56,    57,    20,    21,    22,
      23,    19,    78,    64,    20,    21,    22,    23,    83,    56,
      57,    39,    40,    58,    59,    44,    44,    80,    38,    94,
      52,    53,    47,    97,    44,    49,   100,    51,    95,    96,
      99,    66,    67,   106,   107,    11,    54,    98,    63,    12,
      13,    56,    57,    14,    85,    86,    65,    75,    15,    16,
      60,    17,    18,    89,    62,    76,    77,    82,    84,   114,
     113,   102,   101,    19,   103,   117,    20,    21,    22,    23,
      68,    69,    70,    71,    72,    73,    56,    57,   104,   105,
     108,   115,   109,   112,   111
};

static const yytype_uint8 yycheck[] =
{
      11,    20,    13,    49,    26,    16,    12,    15,    12,    13,
      14,    50,    58,    59,     0,    13,    31,     6,     7,     3,
      30,    43,    44,    50,    43,    44,     4,    30,    43,    44,
      41,    34,    38,    27,    44,    43,    44,    47,    48,    49,
      50,    44,    48,    41,    47,    48,    49,    50,    54,    43,
      44,     8,     9,    45,    46,    66,    67,   103,     7,    65,
      47,    48,    50,    74,    75,    30,    77,    30,    66,    67,
      76,    35,    36,    18,    19,    16,    11,    75,    10,    20,
      21,    43,    44,    24,    56,    57,    17,    21,    29,    30,
      50,    32,    33,     5,    50,    20,    25,    50,    50,   110,
     106,    31,    28,    44,     8,   116,    47,    48,    49,    50,
      37,    38,    39,    40,    41,    42,    43,    44,    31,    11,
      22,    19,    23,   105,   103
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,     3,     0,     6,     7,    53,    50,    54,
      55,    16,    20,    21,    24,    29,    30,    32,    33,    44,
      47,    48,    49,    50,    57,    58,    59,    60,    61,    62,
      63,    65,    66,    71,    72,    73,    74,     4,     7,     8,
       9,    34,    68,    69,    71,    57,    68,    50,    64,    30,
      71,    30,    47,    48,    11,    15,    43,    44,    45,    46,
      50,    57,    50,    10,    68,    17,    35,    36,    37,    38,
      39,    40,    41,    42,    70,    21,    20,    25,    57,    67,
      73,    31,    50,    57,    50,    72,    72,    73,    73,     5,
      12,    13,    14,    56,    57,    68,    68,    71,    68,    57,
      71,    28,    31,     8,    31,    11,    18,    19,    22,    23,
      26,    67,    54,    57,    71,    19,    27,    71,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    59,    60,    60,    61,    62,    63,    64,    65,    65,
      66,    67,    67,    68,    68,    68,    68,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     6,     5,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     7,     5,     5,     4,     8,     4,     1,
       4,     1,     3,     2,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       1,     1,     3,     2,     1,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 142 "spl.y" /* yacc.c:1645  */
    {
                            TERNARY_TREE ParseTree;
                            if ((yyvsp[-5].iVal) == (yyvsp[-1].iVal))
                                ParseTree = create_node((yyvsp[-5].iVal), PROGRAM, (yyvsp[-3].tVal), NULL, NULL);
                                #ifdef DEBUG
                                printTree(ParseTree, 0);
                                #endif
                                genCode(ParseTree);
                        }
#line 1464 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 3:
#line 155 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1472 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 4:
#line 159 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1480 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 5:
#line 166 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, DECLARATION, (yyvsp[-5].tVal), (yyvsp[-2].tVal), (yyvsp[0].tVal));
                        }
#line 1488 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 6:
#line 170 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, DECLARATION, (yyvsp[-4].tVal), (yyvsp[-1].tVal), NULL);
                        }
#line 1496 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 7:
#line 177 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), IDENTIFIER, NULL, NULL, NULL);
                        }
#line 1504 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 8:
#line 181 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), IDENTIFIER, (yyvsp[-2].tVal), NULL, NULL);
                        }
#line 1512 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 9:
#line 188 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, CHARACTER, NULL, NULL, NULL);
                        }
#line 1520 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 10:
#line 192 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, INTEGER, NULL, NULL, NULL);
                        }
#line 1528 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 11:
#line 196 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, REAL, NULL, NULL, NULL);
                        }
#line 1536 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 12:
#line 203 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[0].tVal), NULL ,NULL);
                        }
#line 1544 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 13:
#line 207 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1552 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 14:
#line 213 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1560 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 15:
#line 217 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1568 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 16:
#line 221 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1576 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 17:
#line 225 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1584 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 18:
#line 229 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1592 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 19:
#line 233 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1600 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 20:
#line 237 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1608 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 21:
#line 243 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), ASSIGNMENT_STATEMENT, (yyvsp[-2].tVal), NULL, NULL);
                        }
#line 1616 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 22:
#line 249 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL);
                        }
#line 1624 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 23:
#line 253 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal));
                        }
#line 1632 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 24:
#line 259 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL);
                        }
#line 1640 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 25:
#line 265 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL);
                        }
#line 1648 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 26:
#line 271 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, FOR_STATEMENT, (yyvsp[-2].tVal), (yyvsp[-1].tVal), NULL);
                        }
#line 1656 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 27:
#line 278 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[-7].iVal), FOR_LOOP, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal));
                        }
#line 1664 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 28:
#line 284 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, (yyvsp[-1].tVal), NULL, NULL);
                        }
#line 1672 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 29:
#line 288 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, NULL, NULL, NULL);
                        }
#line 1680 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 30:
#line 294 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[-1].iVal), READ_STATEMENT, NULL, NULL, NULL);
                        }
#line 1688 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 31:
#line 302 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1696 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 32:
#line 306 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1704 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 33:
#line 312 "spl.y" /* yacc.c:1645  */
    {
                           (yyval.tVal) = create_node(NOTHING, NOT, (yyvsp[0].tVal), NULL, NULL); 
                        }
#line 1712 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 34:
#line 316 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, CONDITONAL, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1720 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 35:
#line 320 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, AND, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1728 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 36:
#line 324 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, OR, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1736 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 37:
#line 330 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, COMPARISION, (yyvsp[-2].tVal), (yyvsp[-1].tVal), (yyvsp[0].tVal));
                        }
#line 1744 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 38:
#line 336 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, EQUAL, NULL ,NULL, NULL);
                        }
#line 1752 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 39:
#line 340 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, NOT_EQUAL, NULL ,NULL, NULL);
                        }
#line 1760 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 40:
#line 344 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, LESS_THAN, NULL ,NULL, NULL);
                        }
#line 1768 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 41:
#line 348 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, GREATER_THAN, NULL ,NULL, NULL);
                        }
#line 1776 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 42:
#line 352 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, LESS_OR_EQUAL, NULL ,NULL, NULL);
                        }
#line 1784 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 43:
#line 356 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, GREATER_OR_EQUAL, NULL ,NULL, NULL);
                        }
#line 1792 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 44:
#line 362 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, ADD, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1800 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 45:
#line 366 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, SUBTRACT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1808 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 46:
#line 370 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, TERM, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1816 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 47:
#line 376 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, MULTIPLY, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1824 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 48:
#line 380 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, DIVIDE, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
                        }
#line 1832 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 49:
#line 384 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, VALUE, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1840 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 50:
#line 390 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), IDENTIFIER, NULL, NULL, NULL);
                        }
#line 1848 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 51:
#line 394 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[0].tVal), NULL, NULL);
                        }
#line 1856 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 52:
#line 398 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[-1].tVal), NULL, NULL);
                        }
#line 1864 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 53:
#line 404 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), NEGATIVE_REAL_CONSTANT, NULL, NULL, NULL);
                        }
#line 1872 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 54:
#line 408 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), POSITIVE_REAL_CONSTANT, NULL, NULL, NULL);
                        }
#line 1880 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 55:
#line 412 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), NEGATIVE_INTEGER_CONSTANT, NULL, NULL, NULL);
                        }
#line 1888 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 56:
#line 416 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), POSITIVE_INTEGER_CONSTANT, NULL, NULL, NULL);
                        }
#line 1896 "spl.tab.c" /* yacc.c:1645  */
    break;

  case 57:
#line 420 "spl.y" /* yacc.c:1645  */
    {
                            (yyval.tVal) = create_node((yyvsp[0].iVal), CHARACTER_CONSTANT, NULL, NULL, NULL);
                        }
#line 1904 "spl.tab.c" /* yacc.c:1645  */
    break;


#line 1908 "spl.tab.c" /* yacc.c:1645  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 424 "spl.y" /* yacc.c:1903  */


/* create a symbol table node */
SYMTABNODEPTR create_symTabNode(char* sym, int type) {
    SYMTABNODEPTR node = (SYMTABNODEPTR)malloc(sizeof(SYMTABNODE));
    node->symbol = (char*)malloc(strlen(sym));
    strcpy(node->symbol, sym);
    node->type = type;
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
int symbolTable_add_node(SYMBOLTABLEPTR table, char* sym, int type) {
    SYMTABNODEPTR new_node = create_symTabNode(sym, type);
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

int getType(TERNARY_TREE tree) {
    if (!tree) {
        return NOTHING;
    }
    int left, right;
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    switch (tree->nodeIdentifier) {
        case (ADD):
        case (SUBTRACT):
        case (TERM):
        case (MULTIPLY):
        case (DIVIDE):
        case (VALUE):
        case (CONSTANT):
            left = getType(tree->first);
            right = getType(tree->second);
            return (left > right) ? left : right;
        break;
        case (IDENTIFIER):
        case (NEGATIVE_REAL_CONSTANT):
        case (POSITIVE_REAL_CONSTANT):
        case (NEGATIVE_INTEGER_CONSTANT):
        case (POSITIVE_INTEGER_CONSTANT):
        case (CHARACTER_CONSTANT):
            return node->type;
        break;
    }
}

void genPrintFormat(TERNARY_TREE tree) {
    if (!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    int type;
    switch(tree->nodeIdentifier) {
        case (OUTPUT_LIST):
           genPrintFormat(tree->first);
            if (tree->second) {
                genPrintFormat(tree->second);
            }
        break;
        case (IDENTIFIER):
            if (node->type == CHARACTER) {
                printf("%%c");
            } else if (node->type == REAL) {
                printf("%%lf");
            } else if (node->type == INTEGER) {
                printf("%%d");
            }
        break;
        case (CONSTANT):
            genPrintFormat(tree->first);
        break;
        case (NEGATIVE_REAL_CONSTANT):
            printf("%%f");
        break;
        case (POSITIVE_REAL_CONSTANT):
            printf("%%f");
        break;
        case (NEGATIVE_INTEGER_CONSTANT):
            printf("%%d");
        break;
        case (POSITIVE_INTEGER_CONSTANT):
            printf("%%d");
        break;
        case (CHARACTER_CONSTANT):
            printf("%%c");
        break;
        case (EXPRESSION):
            type = getType(tree->first);
            if (type == CHARACTER) {
                printf("%%c");
            } else if (type == REAL) {
                printf("%%lf");
            } else if (type == INTEGER) {
                printf("%%d");
            }
        break;
    }
}



void genCode(TERNARY_TREE tree) {
    if (!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    int t;
    switch (tree->nodeIdentifier) {
        case (PROGRAM):
            printf("#include<stdio.h>\n/*%s*/\nint _Hey_Brian_;\nint main() {\n", node->symbol);
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
            printf("; _Hey_Brian_ =(");
            genCode(tree->second);
            printf("), (%s-(", node->symbol);
            genCode(tree->third);
            printf("))*((_Hey_Brian_ > 0) - (_Hey_Brian_ < 0)) <= 0; %s += _Hey_Brian_", node->symbol, node->symbol);
        break;
        case (NOT):
            printf("!");
            printf("(");
            genCode(tree->first);
            printf(")");
        break;
        case (CONDITONAL):
            genCode(tree->first);
        break;
        case (AND):
            printf("(");
            genCode(tree->first);
            printf(" && ");
            genCode(tree->second);
            printf(")");
        break;
        case (OR):
            printf("(");
            genCode(tree->first);
            printf(" || ");
            genCode(tree->second);
            printf(")");
        break;
        case (COMPARISION):
            printf("(");
            genCode(tree->first);
            genCode(tree->second);
            genCode(tree->third);
            printf(")");
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
            printf("(");
            genCode(tree->first);
            printf(" + ");
            genCode(tree->second);
            printf(")");
        break; 
        case (SUBTRACT):
            printf("(");
            genCode(tree->first);
            printf(" - ");
            genCode(tree->second);
            printf(")");
        break;
        case (TERM):
            genCode(tree->first);
        break;
        case (MULTIPLY):
            printf("(");
            genCode(tree->first);
            printf(" * ");
            genCode(tree->second);
            printf(")");
        break; 
        case (DIVIDE):
            printf("(");
            genCode(tree->first);
            printf(" / ");
            genCode(tree->second);
            printf(")");
        break;
        case (VALUE):
            genCode(tree->first);
        break;
        case (IDENTIFIER):
            printf("%s", node->symbol);
            if (tree->first) {
                printf(", ");
                genCode(tree->first);
            }
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
            printf("printf(\"");
            if(tree->first) {
                genPrintFormat(tree->first);
                printf("\", ");
                genCode(tree->first);
            } else {
                printf("\\n\"");
            }
            printf(")");
        break;
        case (OUTPUT_LIST):
            genCode(tree->first);
            if (tree->second) {
                printf(", ");
                genCode(tree->second);
            }
        break;
        case (READ_STATEMENT):
            printf("scanf(\"");
            if (node->type == CHARACTER) {
                printf(" %%c");
            } else if (node->type == REAL) {
                printf(" %%lf");
            } else if (node->type == INTEGER) {
                printf(" %%d");
            }
            printf("\", &%s)", node->symbol);
        break;
    }
}

void printTree(TERNARY_TREE tree, int depth) {
    int i;
    if (!tree) {
        return;
    }
    SYMTABNODEPTR node = symbolTable_get_node_for_index(symbol_table, tree->item);
    switch(tree->nodeIdentifier) {
        case (PROGRAM):
            printf("Program: %s\n", node->symbol);
        break;
        case (BLOCK):
            printf("Block\n");
        break;
        case (DECLARATION):
            printf("Declaration\n");
        break;
        case (IDENTIFIER):
            printf("Identifier: %s\n", node->symbol);
        break;
        case (CHARACTER):
            printf("Type: Character\n");
        break;
        case (INTEGER):
            printf("Type: Integer\n");
        break;
        case (REAL):
            printf("Type: Real\n");
        break;
        case (STATEMENT_LIST):
            printf("Statement list\n");
        break;
        case (STATEMENT):
            printf("Statement\n");
        break;
        case (ASSIGNMENT_STATEMENT):
            printf("Assignment statement: %s\n", node->symbol);
        break;
        case (IF_STATEMENT):
            printf("If statement\n");
        break;
        case (DO_STATEMENT):
            printf("Do statement\n");
        break;
        case (WHILE_STATEMENT):
            printf("While statement\n");
        break;
        case (FOR_STATEMENT):
            printf("For statement\n");
        break;
        case (FOR_LOOP):
            printf("For loop\n");
        break;
        case (WRITE_STATEMENT):
            printf("Write statement\n");
        break;
        case (READ_STATEMENT):
            printf("Read statement\n");
        break;
        case (OUTPUT_LIST):
            printf("Output list\n");
        break;
        case (NOT):
            printf("Conditional not\n");
        break;
        case (CONDITONAL):
            printf("Conditional\n");
        break;
        case (AND):
            printf("Condtional and\n");
        break;
        case (OR):
            printf("Condtional or\n");
        break;
        case (COMPARISION):
            printf("Comparison\n");
        break;
        case (EQUAL):
            printf("Equal\n");
        break;
        case (NOT_EQUAL):
            printf("Not equal\n");
        break;
        case (LESS_THAN):
            printf("Less than\n");
        break;
        case (GREATER_THAN):
            printf("Greater than\n");
        break;
        case (LESS_OR_EQUAL):
            printf("Less or equal\n");
        break;
        case (GREATER_OR_EQUAL):
            printf("Greater than or equal\n");
        break;
        case (ADD):
            printf("Add\n");
        break;
        case (SUBTRACT):
            printf("Subtract\n");
        break;
        case (TERM):
            printf("Tern\n");
        break;
        case (MULTIPLY):
            printf("Multiply\n");
        break;
        case (DIVIDE):
            printf("Divide\n");
        break;
        case (VALUE):
            printf("Value\n");
        break;
        case (CONSTANT):
            printf("Constant\n");
        break;
        case (EXPRESSION):
            printf("Expression\n");
        break;
        case (NEGATIVE_REAL_CONSTANT):
            printf("Negative real constant: -%s\n", node->symbol);
        break;
        case (POSITIVE_REAL_CONSTANT):
            printf("Positive real constant: -%s\n", node->symbol);
        break;
        case (NEGATIVE_INTEGER_CONSTANT):
            printf("Negative integer constant: -%s\n", node->symbol);
        break;
        case (POSITIVE_INTEGER_CONSTANT):
            printf("Positive integer constant: -%s\n", node->symbol);
        break;
        case (CHARACTER_CONSTANT):
            printf("Character constant: -%s\n", node->symbol);
        break;
    }
    for (i = 0; i < depth; ++i) {
        printf(" ");
    }
    depth+=4;
    printTree(tree->first, depth);
    printTree(tree->second, depth);
    printTree(tree->third, depth);
}

#include "lex.yy.c"
