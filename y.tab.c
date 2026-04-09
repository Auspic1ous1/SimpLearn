/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE* yyin;

FILE* out;

// Symbol table for variable types
typedef struct {
    char* name;
    char* type;
} symbol_t;

symbol_t symbol_table[100];
int symbol_count = 0;

// Function to add variable to symbol table
void add_symbol(char* name, char* type) {
    symbol_table[symbol_count].name = strdup(name);
    symbol_table[symbol_count].type = strdup(type);
    symbol_count++;
}

// Function to get variable type
char* get_var_type(char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type;
        }
    }
    return "int"; // default
}

// Function to determine expression type
char* get_expr_type(char* expr) {
    // Check if it's a string literal (starts with ")
    if (expr[0] == '"') {
        return "string";
    }
    
    // Check if it's a known variable
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, expr) == 0) {
            return symbol_table[i].type;
        }
    }
    
    // Check if expression contains a float variable
    for (int i = 0; i < symbol_count; i++) {
        if (strstr(expr, symbol_table[i].name)) {
            if (strcmp(symbol_table[i].type, "float") == 0) {
                return "float";
            }
            if (strcmp(symbol_table[i].type, "char*") == 0) {
                return "string";
            }
        }
    }
    
    // Check for float literal (contains '.')
    if (strchr(expr, '.')) {
        return "float";
    }
    
    return "int"; // default
}

void yyerror(const char* s) { fprintf(stderr, "Syntax Error: %s\n", s); }


#line 145 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 300 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_BEGIN_BLOCK = 5,                /* BEGIN_BLOCK  */
  YYSYMBOL_END_BLOCK = 6,                  /* END_BLOCK  */
  YYSYMBOL_INT_TYPE = 7,                   /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 8,                 /* FLOAT_TYPE  */
  YYSYMBOL_STRING_TYPE = 9,                /* STRING_TYPE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_THEN = 11,                      /* THEN  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_ENDIF = 13,                     /* ENDIF  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_ENDWHILE = 16,                  /* ENDWHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_TO = 18,                        /* TO  */
  YYSYMBOL_STEP = 19,                      /* STEP  */
  YYSYMBOL_ENDFOR = 20,                    /* ENDFOR  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_READ = 22,                      /* READ  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 26,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 27,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 28,                    /* MODULO  */
  YYSYMBOL_EQUALS = 29,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 30,                /* NOT_EQUALS  */
  YYSYMBOL_LESS_THAN = 31,                 /* LESS_THAN  */
  YYSYMBOL_LESS_EQUAL = 32,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_THAN = 33,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 34,             /* GREATER_EQUAL  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_LPAREN = 38,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 39,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_COLON = 42,                     /* COLON  */
  YYSYMBOL_ERROR_TOKEN = 43,               /* ERROR_TOKEN  */
  YYSYMBOL_IDENTIFIER = 44,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 45,            /* STRING_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 46,           /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 47,             /* FLOAT_LITERAL  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_variable_declarations = 52,     /* variable_declarations  */
  YYSYMBOL_declaration_list = 53,          /* declaration_list  */
  YYSYMBOL_declaration = 54,               /* declaration  */
  YYSYMBOL_variable_list = 55,             /* variable_list  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_statement_list = 57,            /* statement_list  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_assignment_statement = 59,      /* assignment_statement  */
  YYSYMBOL_if_statement = 60,              /* if_statement  */
  YYSYMBOL_while_statement = 61,           /* while_statement  */
  YYSYMBOL_for_statement = 62,             /* for_statement  */
  YYSYMBOL_print_statement = 63,           /* print_statement  */
  YYSYMBOL_read_statement = 64,            /* read_statement  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_condition = 68,                 /* condition  */
  YYSYMBOL_comparison_operator = 69        /* comparison_operator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   117,   139,   140,   144,   145,   149,   174,
     175,   185,   186,   187,   191,   192,   208,   209,   210,   211,
     212,   213,   217,   243,   250,   260,   270,   280,   307,   329,
     336,   343,   347,   354,   361,   368,   372,   373,   377,   381,
     382,   383,   391,   398,   405,   412,   418,   422,   423,   424,
     425,   426,   427
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "VAR",
  "BEGIN_BLOCK", "END_BLOCK", "INT_TYPE", "FLOAT_TYPE", "STRING_TYPE",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "FOR", "TO",
  "STEP", "ENDFOR", "PRINT", "READ", "ASSIGN", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "MODULO", "EQUALS", "NOT_EQUALS", "LESS_THAN", "LESS_EQUAL",
  "GREATER_THAN", "GREATER_EQUAL", "AND", "OR", "NOT", "LPAREN", "RPAREN",
  "SEMICOLON", "COMMA", "COLON", "ERROR_TOKEN", "IDENTIFIER",
  "STRING_LITERAL", "INTEGER_LITERAL", "FLOAT_LITERAL", "UMINUS",
  "$accept", "program", "$@1", "variable_declarations", "declaration_list",
  "declaration", "variable_list", "type", "statement_list", "statement",
  "assignment_statement", "if_statement", "while_statement",
  "for_statement", "print_statement", "read_statement", "expression",
  "term", "factor", "condition", "comparison_operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    -5,    47,    18,   -68,   -68,    59,     7,    68,   -68,
       7,   -68,    55,   -68,   -68,    36,   127,    11,   -68,   -68,
     -68,   -68,    43,   -68,    44,    44,    49,    90,   102,    62,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    54,    44,
      44,   -68,   -68,   -68,   -68,    89,   111,   -68,    41,    51,
      83,    54,    85,    54,    54,   -68,   -68,    78,    39,    54,
      54,   -68,   -68,   -68,   -68,   -68,   -68,    54,    54,    54,
      54,   -68,    44,    44,   -68,    54,   -19,   103,   -22,   -15,
     -68,   -68,   111,   111,    91,   -68,   -68,   -68,    24,   -68,
     109,    40,   106,   101,   105,   -68,   -68,   -68,   -68,    54,
     -68,   -68,     9,   108,   -68,    54,    80,   -68,    50,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     4,     0,     0,     9,
       5,     6,     0,    14,     7,     0,     0,     0,    10,    11,
      12,    13,     0,     3,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,     8,     0,     0,
       0,    36,    39,    37,    38,     0,    31,    35,     0,     0,
       0,     0,     0,     0,     0,    41,    45,     0,     0,     0,
       0,    47,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    14,     0,     0,    14,     0,     0,     0,     0,     0,
      40,    46,    29,    30,    42,    32,    33,    34,     0,    43,
      44,     0,     0,     0,     0,    22,    14,    23,    25,     0,
      27,    28,     0,     0,    24,     0,     0,    14,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -68,   133,   -68,   -68,   -67,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -40,    66,   -26,   -24,
     -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     8,    10,    11,    12,    22,    17,    30,
      31,    32,    33,    34,    35,    36,    45,    46,    47,    48,
      67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      57,    49,    59,    60,    88,    59,    60,    91,     1,    59,
      60,    76,    55,    78,    79,    56,    58,    23,    95,    24,
      93,    24,   104,    25,    80,    25,    26,    84,    26,   102,
      27,    28,    27,    28,    24,    92,    96,    97,    25,     3,
     108,    26,    85,    86,    87,    27,    28,     4,    89,    90,
      24,     9,    71,    29,    25,    29,    98,    26,     5,   103,
      24,    27,    28,     7,    25,   106,    74,    26,    29,    38,
     109,    27,    28,    13,    72,    73,    72,    73,    81,    38,
      18,    39,    40,    37,    29,    53,    72,    73,    41,    42,
      43,    44,    54,    50,    29,   107,    15,    16,    41,    42,
      43,    44,    59,    60,    59,    60,    75,    61,    62,    63,
      64,    65,    66,    59,    60,    59,    60,    80,    61,    62,
      63,    64,    65,    66,    99,    82,    83,   105,    51,    77,
      59,    60,    59,    60,    19,    20,    21,    68,    69,    70,
      52,   100,    94,    14,    72,   101
};

static const yytype_int8 yycheck[] =
{
      40,    25,    24,    25,    71,    24,    25,    74,     3,    24,
      25,    51,    38,    53,    54,    39,    40,     6,    40,    10,
      39,    10,    13,    14,    39,    14,    17,    67,    17,    96,
      21,    22,    21,    22,    10,    75,    12,    13,    14,    44,
     107,    17,    68,    69,    70,    21,    22,     0,    72,    73,
      10,    44,    11,    44,    14,    44,    16,    17,    40,    99,
      10,    21,    22,     4,    14,   105,    15,    17,    44,    25,
      20,    21,    22,     5,    35,    36,    35,    36,    39,    25,
      44,    37,    38,    40,    44,    23,    35,    36,    44,    45,
      46,    47,    38,    44,    44,    15,    41,    42,    44,    45,
      46,    47,    24,    25,    24,    25,    23,    29,    30,    31,
      32,    33,    34,    24,    25,    24,    25,    39,    29,    30,
      31,    32,    33,    34,    18,    59,    60,    19,    38,    44,
      24,    25,    24,    25,     7,     8,     9,    26,    27,    28,
      38,    40,    39,    10,    35,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    50,    44,     0,    40,    51,     4,    52,    44,
      53,    54,    55,     5,    54,    41,    42,    57,    44,     7,
       8,     9,    56,     6,    10,    14,    17,    21,    22,    44,
      58,    59,    60,    61,    62,    63,    64,    40,    25,    37,
      38,    44,    45,    46,    47,    65,    66,    67,    68,    68,
      44,    38,    38,    23,    38,    67,    68,    65,    68,    24,
      25,    29,    30,    31,    32,    33,    34,    69,    26,    27,
      28,    11,    35,    36,    15,    23,    65,    44,    65,    65,
      39,    39,    66,    66,    65,    67,    67,    67,    57,    68,
      68,    57,    65,    39,    39,    40,    12,    13,    16,    18,
      40,    40,    57,    65,    13,    19,    65,    15,    57,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    51,    50,    52,    52,    53,    53,    54,    55,
      55,    56,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    59,    60,    60,    61,    62,    63,    64,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     2,     1,     2,     4,     1,
       3,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     4,     5,     7,     5,    11,     5,     5,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 118 "parser.y"
    {
        out = fopen("a.c", "w");
        fprintf(out, "#include <stdio.h>\n#include <string.h>\n\nint main() {\n");
    }
#line 1430 "y.tab.c"
    break;

  case 3: /* program: PROGRAM IDENTIFIER SEMICOLON $@1 variable_declarations BEGIN_BLOCK statement_list END_BLOCK  */
#line 126 "parser.y"
    {
        // Write the buffered statements
        if ((yyvsp[-1].str_val)) {
            fprintf(out, "%s", (yyvsp[-1].str_val));
            free((yyvsp[-1].str_val));
        }
        fprintf(out, "    return 0;\n}\n");
        fclose(out);
        printf("C code generated in a.c\n");
    }
#line 1445 "y.tab.c"
    break;

  case 4: /* variable_declarations: %empty  */
#line 139 "parser.y"
                { }
#line 1451 "y.tab.c"
    break;

  case 5: /* variable_declarations: VAR declaration_list  */
#line 140 "parser.y"
                           { }
#line 1457 "y.tab.c"
    break;

  case 8: /* declaration: variable_list COLON type SEMICOLON  */
#line 150 "parser.y"
    {
        char* var_copy = strdup((yyvsp[-3].str_val));
        char* var = strtok(var_copy, ",");
        while (var != NULL) {
            // Trim whitespace
            while (*var == ' ' || *var == '\t') var++;
            
            // Handle string type specially - allocate space and initialize
            if (strcmp((yyvsp[-1].str_val), "char*") == 0) {
                fprintf(out, "    char %s[256] = \"\";\n", var);
                add_symbol(var, "char*");
            } else {
                fprintf(out, "    %s %s = 0;\n", (yyvsp[-1].str_val), var);
                add_symbol(var, (yyvsp[-1].str_val));
            }
            
            var = strtok(NULL, ",");
        }
        free(var_copy);
        free((yyvsp[-3].str_val));
    }
#line 1483 "y.tab.c"
    break;

  case 9: /* variable_list: IDENTIFIER  */
#line 174 "parser.y"
               { (yyval.str_val) = strdup((yyvsp[0].str_val)); }
#line 1489 "y.tab.c"
    break;

  case 10: /* variable_list: variable_list COMMA IDENTIFIER  */
#line 176 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+2);
        sprintf(temp, "%s,%s", (yyvsp[-2].str_val), (yyvsp[0].str_val));
        free((yyvsp[-2].str_val));
        (yyval.str_val) = temp;
    }
#line 1500 "y.tab.c"
    break;

  case 11: /* type: INT_TYPE  */
#line 185 "parser.y"
             { (yyval.str_val) = strdup("int"); }
#line 1506 "y.tab.c"
    break;

  case 12: /* type: FLOAT_TYPE  */
#line 186 "parser.y"
                 { (yyval.str_val) = strdup("float"); }
#line 1512 "y.tab.c"
    break;

  case 13: /* type: STRING_TYPE  */
#line 187 "parser.y"
                  { (yyval.str_val) = strdup("char*"); }
#line 1518 "y.tab.c"
    break;

  case 14: /* statement_list: %empty  */
#line 191 "parser.y"
                { (yyval.str_val) = strdup(""); }
#line 1524 "y.tab.c"
    break;

  case 15: /* statement_list: statement_list statement  */
#line 193 "parser.y"
    {
        if ((yyvsp[-1].str_val) && (yyvsp[0].str_val)) {
            char* temp = malloc(strlen((yyvsp[-1].str_val)) + strlen((yyvsp[0].str_val)) + 1);
            sprintf(temp, "%s%s", (yyvsp[-1].str_val), (yyvsp[0].str_val));
            free((yyvsp[-1].str_val)); free((yyvsp[0].str_val));
            (yyval.str_val) = temp;
        } else if ((yyvsp[-1].str_val)) {
            (yyval.str_val) = (yyvsp[-1].str_val);
        } else {
            (yyval.str_val) = (yyvsp[0].str_val);
        }
    }
#line 1541 "y.tab.c"
    break;

  case 16: /* statement: assignment_statement  */
#line 208 "parser.y"
                         { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1547 "y.tab.c"
    break;

  case 17: /* statement: if_statement  */
#line 209 "parser.y"
                   { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1553 "y.tab.c"
    break;

  case 18: /* statement: while_statement  */
#line 210 "parser.y"
                      { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1559 "y.tab.c"
    break;

  case 19: /* statement: for_statement  */
#line 211 "parser.y"
                    { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1565 "y.tab.c"
    break;

  case 20: /* statement: print_statement  */
#line 212 "parser.y"
                      { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1571 "y.tab.c"
    break;

  case 21: /* statement: read_statement  */
#line 213 "parser.y"
                     { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1577 "y.tab.c"
    break;

  case 22: /* assignment_statement: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 218 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-3].str_val)) + strlen((yyvsp[-1].str_val)) + 50);
        
        // Check if we're assigning a string
        char* var_type = get_var_type((yyvsp[-3].str_val));
        char* expr_type = get_expr_type((yyvsp[-1].str_val));
        
        if (strcmp(var_type, "char*") == 0) {
            // For string assignment, use strcpy
            // Remove quotes from string literal if present
            if ((yyvsp[-1].str_val)[0] == '"') {
                sprintf(temp, "    strcpy(%s, %s);\n", (yyvsp[-3].str_val), (yyvsp[-1].str_val));
            } else {
                sprintf(temp, "    strcpy(%s, %s);\n", (yyvsp[-3].str_val), (yyvsp[-1].str_val));
            }
        } else {
            sprintf(temp, "    %s = %s;\n", (yyvsp[-3].str_val), (yyvsp[-1].str_val));
        }
        
        free((yyvsp[-3].str_val)); free((yyvsp[-1].str_val));
        (yyval.str_val) = temp;
    }
#line 1604 "y.tab.c"
    break;

  case 23: /* if_statement: IF condition THEN statement_list ENDIF  */
#line 244 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-3].str_val)) + strlen((yyvsp[-1].str_val)) + 100);
        sprintf(temp, "    if (%s) {\n%s    }\n", (yyvsp[-3].str_val), (yyvsp[-1].str_val));
        free((yyvsp[-3].str_val)); free((yyvsp[-1].str_val));
        (yyval.str_val) = temp;
    }
#line 1615 "y.tab.c"
    break;

  case 24: /* if_statement: IF condition THEN statement_list ELSE statement_list ENDIF  */
#line 251 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-5].str_val)) + strlen((yyvsp[-3].str_val)) + strlen((yyvsp[-1].str_val)) + 150);
        sprintf(temp, "    if (%s) {\n%s    } else {\n%s    }\n", (yyvsp[-5].str_val), (yyvsp[-3].str_val), (yyvsp[-1].str_val));
        free((yyvsp[-5].str_val)); free((yyvsp[-3].str_val)); free((yyvsp[-1].str_val));
        (yyval.str_val) = temp;
    }
#line 1626 "y.tab.c"
    break;

  case 25: /* while_statement: WHILE condition DO statement_list ENDWHILE  */
#line 261 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-3].str_val)) + strlen((yyvsp[-1].str_val)) + 100);
        sprintf(temp, "    while (%s) {\n%s    }\n", (yyvsp[-3].str_val), (yyvsp[-1].str_val));
        free((yyvsp[-3].str_val)); free((yyvsp[-1].str_val));
        (yyval.str_val) = temp;
    }
#line 1637 "y.tab.c"
    break;

  case 26: /* for_statement: FOR IDENTIFIER ASSIGN expression TO expression STEP expression DO statement_list ENDFOR  */
#line 271 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-9].str_val))*3 + strlen((yyvsp[-7].str_val)) + strlen((yyvsp[-5].str_val)) + strlen((yyvsp[-3].str_val)) + strlen((yyvsp[-1].str_val)) + 150);
        sprintf(temp, "    for (%s=%s; %s<=%s; %s+=%s) {\n%s    }\n", (yyvsp[-9].str_val),(yyvsp[-7].str_val),(yyvsp[-9].str_val),(yyvsp[-5].str_val),(yyvsp[-9].str_val),(yyvsp[-3].str_val),(yyvsp[-1].str_val));
        free((yyvsp[-9].str_val)); free((yyvsp[-7].str_val)); free((yyvsp[-5].str_val)); free((yyvsp[-3].str_val)); free((yyvsp[-1].str_val));
        (yyval.str_val) = temp;
    }
#line 1648 "y.tab.c"
    break;

  case 27: /* print_statement: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 281 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val)) + 150);
        
        // Check if expression is a string literal (starts and ends with ")
        if ((yyvsp[-2].str_val)[0] == '"') {
            // It's a string literal - print directly
            sprintf(temp, "    printf(\"%%s\\n\", %s);\n", (yyvsp[-2].str_val));
        } else {
            // Check variable type
            char* expr_type = get_expr_type((yyvsp[-2].str_val));
            
            if (strcmp(expr_type, "char*") == 0 || strcmp(expr_type, "string") == 0) {
                sprintf(temp, "    printf(\"%%s\\n\", %s);\n", (yyvsp[-2].str_val));
            } else if (strcmp(expr_type, "float") == 0) {
                sprintf(temp, "    printf(\"%%f\\n\", (float)%s);\n", (yyvsp[-2].str_val));
            } else {
                sprintf(temp, "    printf(\"%%d\\n\", %s);\n", (yyvsp[-2].str_val));
            }
        }
        
        free((yyvsp[-2].str_val));
        (yyval.str_val) = temp;
    }
#line 1676 "y.tab.c"
    break;

  case 28: /* read_statement: READ LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 308 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val)) + 150);
        
        // Determine format based on variable type
        char* var_type = get_var_type((yyvsp[-2].str_val));
        
        if (strcmp(var_type, "char*") == 0) {
            // For strings, use fgets to handle spaces and newlines properly
            sprintf(temp, "    if (fgets(%s, 256, stdin)) {\n        %s[strcspn(%s, \"\\n\")] = 0;\n    }\n", (yyvsp[-2].str_val), (yyvsp[-2].str_val), (yyvsp[-2].str_val));
        } else if (strcmp(var_type, "float") == 0) {
            sprintf(temp, "    scanf(\"%%f\", &%s);\n    getchar();\n", (yyvsp[-2].str_val));
        } else {
            sprintf(temp, "    scanf(\"%%d\", &%s);\n    getchar();\n", (yyvsp[-2].str_val));
        }
        
        free((yyvsp[-2].str_val));
        (yyval.str_val) = temp;
    }
#line 1699 "y.tab.c"
    break;

  case 29: /* expression: expression PLUS term  */
#line 330 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+4);
        sprintf(temp, "(%s+%s)", (yyvsp[-2].str_val), (yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1710 "y.tab.c"
    break;

  case 30: /* expression: expression MINUS term  */
#line 337 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+4);
        sprintf(temp, "(%s-%s)", (yyvsp[-2].str_val), (yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1721 "y.tab.c"
    break;

  case 31: /* expression: term  */
#line 343 "parser.y"
           { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1727 "y.tab.c"
    break;

  case 32: /* term: term MULTIPLY factor  */
#line 348 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+4);
        sprintf(temp, "(%s*%s)", (yyvsp[-2].str_val), (yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1738 "y.tab.c"
    break;

  case 33: /* term: term DIVIDE factor  */
#line 355 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+4);
        sprintf(temp, "(%s/%s)", (yyvsp[-2].str_val), (yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1749 "y.tab.c"
    break;

  case 34: /* term: term MODULO factor  */
#line 362 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+6);
        sprintf(temp, "(%s%%%s)", (yyvsp[-2].str_val), (yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1760 "y.tab.c"
    break;

  case 35: /* term: factor  */
#line 368 "parser.y"
             { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1766 "y.tab.c"
    break;

  case 36: /* factor: IDENTIFIER  */
#line 372 "parser.y"
               { (yyval.str_val) = strdup((yyvsp[0].str_val)); free((yyvsp[0].str_val)); }
#line 1772 "y.tab.c"
    break;

  case 37: /* factor: INTEGER_LITERAL  */
#line 374 "parser.y"
    {
        char* temp = malloc(32); sprintf(temp,"%d",(yyvsp[0].int_val)); (yyval.str_val)=temp;
    }
#line 1780 "y.tab.c"
    break;

  case 38: /* factor: FLOAT_LITERAL  */
#line 378 "parser.y"
    {
        char* temp = malloc(32); sprintf(temp,"%f",(yyvsp[0].float_val)); (yyval.str_val)=temp;
    }
#line 1788 "y.tab.c"
    break;

  case 39: /* factor: STRING_LITERAL  */
#line 381 "parser.y"
                     { (yyval.str_val) = strdup((yyvsp[0].str_val)); free((yyvsp[0].str_val)); }
#line 1794 "y.tab.c"
    break;

  case 40: /* factor: LPAREN expression RPAREN  */
#line 382 "parser.y"
                               { (yyval.str_val) = (yyvsp[-1].str_val); }
#line 1800 "y.tab.c"
    break;

  case 41: /* factor: MINUS factor  */
#line 384 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[0].str_val))+3); sprintf(temp,"(-%s)",(yyvsp[0].str_val));
        free((yyvsp[0].str_val)); (yyval.str_val) = temp;
    }
#line 1809 "y.tab.c"
    break;

  case 42: /* condition: expression comparison_operator expression  */
#line 392 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[-1].str_val))+strlen((yyvsp[0].str_val))+4);
        sprintf(temp,"(%s %s %s)", (yyvsp[-2].str_val),(yyvsp[-1].str_val),(yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[-1].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1820 "y.tab.c"
    break;

  case 43: /* condition: condition AND condition  */
#line 399 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+6);
        sprintf(temp,"(%s && %s)", (yyvsp[-2].str_val),(yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1831 "y.tab.c"
    break;

  case 44: /* condition: condition OR condition  */
#line 406 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[-2].str_val))+strlen((yyvsp[0].str_val))+6);
        sprintf(temp,"(%s || %s)", (yyvsp[-2].str_val),(yyvsp[0].str_val));
        free((yyvsp[-2].str_val)); free((yyvsp[0].str_val));
        (yyval.str_val) = temp;
    }
#line 1842 "y.tab.c"
    break;

  case 45: /* condition: NOT condition  */
#line 413 "parser.y"
    {
        char* temp = malloc(strlen((yyvsp[0].str_val))+4);
        sprintf(temp,"(!%s)",(yyvsp[0].str_val));
        free((yyvsp[0].str_val)); (yyval.str_val) = temp;
    }
#line 1852 "y.tab.c"
    break;

  case 46: /* condition: LPAREN condition RPAREN  */
#line 418 "parser.y"
                              { (yyval.str_val) = (yyvsp[-1].str_val); }
#line 1858 "y.tab.c"
    break;

  case 47: /* comparison_operator: EQUALS  */
#line 422 "parser.y"
           { (yyval.str_val) = strdup("=="); }
#line 1864 "y.tab.c"
    break;

  case 48: /* comparison_operator: NOT_EQUALS  */
#line 423 "parser.y"
                 { (yyval.str_val) = strdup("!="); }
#line 1870 "y.tab.c"
    break;

  case 49: /* comparison_operator: LESS_THAN  */
#line 424 "parser.y"
                { (yyval.str_val) = strdup("<"); }
#line 1876 "y.tab.c"
    break;

  case 50: /* comparison_operator: LESS_EQUAL  */
#line 425 "parser.y"
                 { (yyval.str_val) = strdup("<="); }
#line 1882 "y.tab.c"
    break;

  case 51: /* comparison_operator: GREATER_THAN  */
#line 426 "parser.y"
                   { (yyval.str_val) = strdup(">"); }
#line 1888 "y.tab.c"
    break;

  case 52: /* comparison_operator: GREATER_EQUAL  */
#line 427 "parser.y"
                    { (yyval.str_val) = strdup(">="); }
#line 1894 "y.tab.c"
    break;


#line 1898 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 430 "parser.y"


int main(int argc, char** argv) {
    if(argc!=2){ printf("Usage: %s <file>\n",argv[0]); return 1;}
    FILE* f = fopen(argv[1],"r");
    if(!f){ printf("Cannot open file %s\n",argv[1]); return 1; }
    yyin = f;
    yyparse();
    fclose(f);
    return 0;
}
