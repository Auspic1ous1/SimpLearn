/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    VAR = 259,                     /* VAR  */
    BEGIN_BLOCK = 260,             /* BEGIN_BLOCK  */
    END_BLOCK = 261,               /* END_BLOCK  */
    INT_TYPE = 262,                /* INT_TYPE  */
    FLOAT_TYPE = 263,              /* FLOAT_TYPE  */
    STRING_TYPE = 264,             /* STRING_TYPE  */
    IF = 265,                      /* IF  */
    THEN = 266,                    /* THEN  */
    ELSE = 267,                    /* ELSE  */
    ENDIF = 268,                   /* ENDIF  */
    WHILE = 269,                   /* WHILE  */
    DO = 270,                      /* DO  */
    ENDWHILE = 271,                /* ENDWHILE  */
    FOR = 272,                     /* FOR  */
    TO = 273,                      /* TO  */
    STEP = 274,                    /* STEP  */
    ENDFOR = 275,                  /* ENDFOR  */
    PRINT = 276,                   /* PRINT  */
    READ = 277,                    /* READ  */
    ASSIGN = 278,                  /* ASSIGN  */
    PLUS = 279,                    /* PLUS  */
    MINUS = 280,                   /* MINUS  */
    MULTIPLY = 281,                /* MULTIPLY  */
    DIVIDE = 282,                  /* DIVIDE  */
    MODULO = 283,                  /* MODULO  */
    EQUALS = 284,                  /* EQUALS  */
    NOT_EQUALS = 285,              /* NOT_EQUALS  */
    LESS_THAN = 286,               /* LESS_THAN  */
    LESS_EQUAL = 287,              /* LESS_EQUAL  */
    GREATER_THAN = 288,            /* GREATER_THAN  */
    GREATER_EQUAL = 289,           /* GREATER_EQUAL  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    NOT = 292,                     /* NOT  */
    LPAREN = 293,                  /* LPAREN  */
    RPAREN = 294,                  /* RPAREN  */
    SEMICOLON = 295,               /* SEMICOLON  */
    COMMA = 296,                   /* COMMA  */
    COLON = 297,                   /* COLON  */
    ERROR_TOKEN = 298,             /* ERROR_TOKEN  */
    IDENTIFIER = 299,              /* IDENTIFIER  */
    STRING_LITERAL = 300,          /* STRING_LITERAL  */
    INTEGER_LITERAL = 301,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 302,           /* FLOAT_LITERAL  */
    UMINUS = 303                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PROGRAM 258
#define VAR 259
#define BEGIN_BLOCK 260
#define END_BLOCK 261
#define INT_TYPE 262
#define FLOAT_TYPE 263
#define STRING_TYPE 264
#define IF 265
#define THEN 266
#define ELSE 267
#define ENDIF 268
#define WHILE 269
#define DO 270
#define ENDWHILE 271
#define FOR 272
#define TO 273
#define STEP 274
#define ENDFOR 275
#define PRINT 276
#define READ 277
#define ASSIGN 278
#define PLUS 279
#define MINUS 280
#define MULTIPLY 281
#define DIVIDE 282
#define MODULO 283
#define EQUALS 284
#define NOT_EQUALS 285
#define LESS_THAN 286
#define LESS_EQUAL 287
#define GREATER_THAN 288
#define GREATER_EQUAL 289
#define AND 290
#define OR 291
#define NOT 292
#define LPAREN 293
#define RPAREN 294
#define SEMICOLON 295
#define COMMA 296
#define COLON 297
#define ERROR_TOKEN 298
#define IDENTIFIER 299
#define STRING_LITERAL 300
#define INTEGER_LITERAL 301
#define FLOAT_LITERAL 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 75 "parser.y"

    int int_val;
    float float_val;
    char* str_val;

#line 169 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
