%{
#ifdef PRINT
#define RETURN(argtype, token) printf(#argtype " " #token "\n");
#else
#define RETURN(argtype, token) return(token)
#endif

%}

delim       [ \t\n\r]
ws          {delim}+
letter      [A-Za-z]
digit       [0-9]

integer_constant     [0-9]+
real_constant        [0-9]+\.[0-9]+
character_constant   '[a-zA-Z]'

identifer           {letter}({letter}|{digit})*

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
                            /*yylval.item.identifer = malloc(strlen(yytext));
                            strcpy(yytext, yylval.item.identifer);*/
                            RETURN(identifier, IDENTIFIER);
                        }


{character_constant}    {
                            /*yylval.item.character = yytext;*/
                            RETURN(character_constant,CHARACTER_CONSTANT);
                        }   

{real_constant}         {
                            /*yylval.item.real = atof(yytext); //d = atof(yytext);*/
                            RETURN(real_constant, REAL_CONSTANT);
                        }

{integer_constant}      {
                            /*yylval.item.integer = atoi(yytext);*/
                            RETURN(integer_constant, INTEGER_CONSTANT);
                        }
                        

