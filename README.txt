***************************
*  SPL Compiler ACW 2018  *
***************************

*********************
*  Folder contents  *
*********************
├── README.txt
├── spl.bnf
├── spl.c
├── spl.l
├── spl.y
└── test-results.txt

spl.bnf contains the Backus-Naur form notation denoting the spl language.
spl.c is a harness that runs the code generate from the bison file.
spl.l is the lexer file, this file contains code that detects lexical tokens from an input file stream
spl.y is the parser file, this file contains code for the parser that consumes tokens from the lexer and builds a tree representing the inputted file.
test-results.txt contains the results of testing.

**************************
*  Language assumptions  *
**************************

Condtionals
the SPL conditional statement is ambiguous e.g. NOT a = 6 AND a <> 8 
it is not clear whether the NOT token negates only the left hand lide of the AND or if it should negate the rest of the conditional statement.
In this implementation of the spl compiler the NOT will negate the entire statement.

For Loops
the SPL for loop statement is also ambiguous e.g FOR a IS 1 BY 1 TO 13 DO
it is not clear whether the loop condtion should evaluate to a < 13 or a <= 13
In this implementation loop conditions will be inclusive of the TO value.

******************
*  Symbol Table  *
******************
The give symbol table structure can only handle a maximum of 50 symbol and each symbol can only be upto 15 characters in length.
the symbol tables has been extended to support as many symbols and as long a symbol as you computer has ram.

*********************
*  Print statement  *
*********************
during code generation when the compiler find a write statement it will look ahead at the output list determine the types for each argument and produce a format string to display all arguments. e.g WRITE('H','E','L'.'L','O',42,3.14);
will evaluate to printf("%c%c%c%c%c%d%lf",'H','E','L','L','O',42,3.14);
it also supports this look ahead functionality for evaluating the type returned by an expression.

*****************
*  C key words  *
*****************
the compiler supports using keywords from the C language as identifiers (as long as they are not also not key words in SPL)

*********************
*  Type converison  *
*********************
the compiler follows the same rules as C for type coversion, this is convention for most programming languages and it seems fit follow this rule.
