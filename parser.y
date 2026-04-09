%{
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

%}

%union {
    int int_val;
    float float_val;
    char* str_val;
}

/* Tokens */
%token PROGRAM VAR BEGIN_BLOCK END_BLOCK
%token INT_TYPE FLOAT_TYPE STRING_TYPE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token FOR TO STEP ENDFOR
%token PRINT READ
%token ASSIGN
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token EQUALS NOT_EQUALS LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQUAL
%token AND OR NOT
%token LPAREN RPAREN SEMICOLON COMMA COLON
%token ERROR_TOKEN

%token <str_val> IDENTIFIER STRING_LITERAL
%token <int_val> INTEGER_LITERAL
%token <float_val> FLOAT_LITERAL

/* Non-terminals semantic types */
%type <str_val> program variable_declarations declaration_list declaration variable_list type
%type <str_val> statement_list statement assignment_statement if_statement while_statement for_statement print_statement read_statement
%type <str_val> expression term factor condition comparison_operator

/* Precedence */
%left OR
%left AND
%right NOT
%left EQUALS NOT_EQUALS
%left LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right UMINUS

%%

program:
    PROGRAM IDENTIFIER SEMICOLON
    {
        out = fopen("a.c", "w");
        fprintf(out, "#include <stdio.h>\n#include <string.h>\n\nint main() {\n");
    }
    variable_declarations
    BEGIN_BLOCK
    statement_list
    END_BLOCK
    {
        // Write the buffered statements
        if ($7) {
            fprintf(out, "%s", $7);
            free($7);
        }
        fprintf(out, "    return 0;\n}\n");
        fclose(out);
        printf("C code generated in a.c\n");
    }
    ;

variable_declarations:
    /* empty */ { }
    | VAR declaration_list { }
    ;

declaration_list:
    declaration
    | declaration_list declaration
    ;

declaration:
    variable_list COLON type SEMICOLON
    {
        char* var_copy = strdup($1);
        char* var = strtok(var_copy, ",");
        while (var != NULL) {
            // Trim whitespace
            while (*var == ' ' || *var == '\t') var++;
            
            // Handle string type specially - allocate space and initialize
            if (strcmp($3, "char*") == 0) {
                fprintf(out, "    char %s[256] = \"\";\n", var);
                add_symbol(var, "char*");
            } else {
                fprintf(out, "    %s %s = 0;\n", $3, var);
                add_symbol(var, $3);
            }
            
            var = strtok(NULL, ",");
        }
        free(var_copy);
        free($1);
    }
    ;

variable_list:
    IDENTIFIER { $$ = strdup($1); }
    | variable_list COMMA IDENTIFIER
    {
        char* temp = malloc(strlen($1)+strlen($3)+2);
        sprintf(temp, "%s,%s", $1, $3);
        free($1);
        $$ = temp;
    }
    ;

type:
    INT_TYPE { $$ = strdup("int"); }
    | FLOAT_TYPE { $$ = strdup("float"); }
    | STRING_TYPE { $$ = strdup("char*"); }
    ;

statement_list:
    /* empty */ { $$ = strdup(""); }
    | statement_list statement
    {
        if ($1 && $2) {
            char* temp = malloc(strlen($1) + strlen($2) + 1);
            sprintf(temp, "%s%s", $1, $2);
            free($1); free($2);
            $$ = temp;
        } else if ($1) {
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
    ;

statement:
    assignment_statement { $$ = $1; }
    | if_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | print_statement { $$ = $1; }
    | read_statement { $$ = $1; }
    ;

assignment_statement:
    IDENTIFIER ASSIGN expression SEMICOLON
    {
        char* temp = malloc(strlen($1) + strlen($3) + 50);
        
        // Check if we're assigning a string
        char* var_type = get_var_type($1);
        char* expr_type = get_expr_type($3);
        
        if (strcmp(var_type, "char*") == 0) {
            // For string assignment, use strcpy
            // Remove quotes from string literal if present
            if ($3[0] == '"') {
                sprintf(temp, "    strcpy(%s, %s);\n", $1, $3);
            } else {
                sprintf(temp, "    strcpy(%s, %s);\n", $1, $3);
            }
        } else {
            sprintf(temp, "    %s = %s;\n", $1, $3);
        }
        
        free($1); free($3);
        $$ = temp;
    }
    ;

if_statement:
    IF condition THEN statement_list ENDIF
    {
        char* temp = malloc(strlen($2) + strlen($4) + 100);
        sprintf(temp, "    if (%s) {\n%s    }\n", $2, $4);
        free($2); free($4);
        $$ = temp;
    }
    | IF condition THEN statement_list ELSE statement_list ENDIF
    {
        char* temp = malloc(strlen($2) + strlen($4) + strlen($6) + 150);
        sprintf(temp, "    if (%s) {\n%s    } else {\n%s    }\n", $2, $4, $6);
        free($2); free($4); free($6);
        $$ = temp;
    }
    ;

while_statement:
    WHILE condition DO statement_list ENDWHILE
    {
        char* temp = malloc(strlen($2) + strlen($4) + 100);
        sprintf(temp, "    while (%s) {\n%s    }\n", $2, $4);
        free($2); free($4);
        $$ = temp;
    }
    ;

for_statement:
    FOR IDENTIFIER ASSIGN expression TO expression STEP expression DO statement_list ENDFOR
    {
        char* temp = malloc(strlen($2)*3 + strlen($4) + strlen($6) + strlen($8) + strlen($10) + 150);
        sprintf(temp, "    for (%s=%s; %s<=%s; %s+=%s) {\n%s    }\n", $2,$4,$2,$6,$2,$8,$10);
        free($2); free($4); free($6); free($8); free($10);
        $$ = temp;
    }
    ;

print_statement:
    PRINT LPAREN expression RPAREN SEMICOLON
    {
        char* temp = malloc(strlen($3) + 150);
        
        // Check if expression is a string literal (starts and ends with ")
        if ($3[0] == '"') {
            // It's a string literal - print directly
            sprintf(temp, "    printf(\"%%s\\n\", %s);\n", $3);
        } else {
            // Check variable type
            char* expr_type = get_expr_type($3);
            
            if (strcmp(expr_type, "char*") == 0 || strcmp(expr_type, "string") == 0) {
                sprintf(temp, "    printf(\"%%s\\n\", %s);\n", $3);
            } else if (strcmp(expr_type, "float") == 0) {
                sprintf(temp, "    printf(\"%%f\\n\", (float)%s);\n", $3);
            } else {
                sprintf(temp, "    printf(\"%%d\\n\", %s);\n", $3);
            }
        }
        
        free($3);
        $$ = temp;
    }
    ;

read_statement:
    READ LPAREN IDENTIFIER RPAREN SEMICOLON
    {
        char* temp = malloc(strlen($3) + 150);
        
        // Determine format based on variable type
        char* var_type = get_var_type($3);
        
        if (strcmp(var_type, "char*") == 0) {
            // For strings, use fgets to handle spaces and newlines properly
            sprintf(temp, "    if (fgets(%s, 256, stdin)) {\n        %s[strcspn(%s, \"\\n\")] = 0;\n    }\n", $3, $3, $3);
        } else if (strcmp(var_type, "float") == 0) {
            sprintf(temp, "    scanf(\"%%f\", &%s);\n    getchar();\n", $3);
        } else {
            sprintf(temp, "    scanf(\"%%d\", &%s);\n    getchar();\n", $3);
        }
        
        free($3);
        $$ = temp;
    }
    ;

expression:
    expression PLUS term
    {
        char* temp = malloc(strlen($1)+strlen($3)+4);
        sprintf(temp, "(%s+%s)", $1, $3);
        free($1); free($3);
        $$ = temp;
    }
    | expression MINUS term
    {
        char* temp = malloc(strlen($1)+strlen($3)+4);
        sprintf(temp, "(%s-%s)", $1, $3);
        free($1); free($3);
        $$ = temp;
    }
    | term { $$ = $1; }
    ;

term:
    term MULTIPLY factor
    {
        char* temp = malloc(strlen($1)+strlen($3)+4);
        sprintf(temp, "(%s*%s)", $1, $3);
        free($1); free($3);
        $$ = temp;
    }
    | term DIVIDE factor
    {
        char* temp = malloc(strlen($1)+strlen($3)+4);
        sprintf(temp, "(%s/%s)", $1, $3);
        free($1); free($3);
        $$ = temp;
    }
    | term MODULO factor
    {
        char* temp = malloc(strlen($1)+strlen($3)+6);
        sprintf(temp, "(%s%%%s)", $1, $3);
        free($1); free($3);
        $$ = temp;
    }
    | factor { $$ = $1; }
    ;

factor:
    IDENTIFIER { $$ = strdup($1); free($1); }
    | INTEGER_LITERAL
    {
        char* temp = malloc(32); sprintf(temp,"%d",$1); $$=temp;
    }
    | FLOAT_LITERAL
    {
        char* temp = malloc(32); sprintf(temp,"%f",$1); $$=temp;
    }
    | STRING_LITERAL { $$ = strdup($1); free($1); }
    | LPAREN expression RPAREN { $$ = $2; }
    | MINUS factor %prec UMINUS
    {
        char* temp = malloc(strlen($2)+3); sprintf(temp,"(-%s)",$2);
        free($2); $$ = temp;
    }
    ;

condition:
    expression comparison_operator expression
    {
        char* temp = malloc(strlen($1)+strlen($2)+strlen($3)+4);
        sprintf(temp,"(%s %s %s)", $1,$2,$3);
        free($1); free($2); free($3);
        $$ = temp;
    }
    | condition AND condition
    {
        char* temp = malloc(strlen($1)+strlen($3)+6);
        sprintf(temp,"(%s && %s)", $1,$3);
        free($1); free($3);
        $$ = temp;
    }
    | condition OR condition
    {
        char* temp = malloc(strlen($1)+strlen($3)+6);
        sprintf(temp,"(%s || %s)", $1,$3);
        free($1); free($3);
        $$ = temp;
    }
    | NOT condition
    {
        char* temp = malloc(strlen($2)+4);
        sprintf(temp,"(!%s)",$2);
        free($2); $$ = temp;
    }
    | LPAREN condition RPAREN { $$ = $2; }
    ;

comparison_operator:
    EQUALS { $$ = strdup("=="); }
    | NOT_EQUALS { $$ = strdup("!="); }
    | LESS_THAN { $$ = strdup("<"); }
    | LESS_EQUAL { $$ = strdup("<="); }
    | GREATER_THAN { $$ = strdup(">"); }
    | GREATER_EQUAL { $$ = strdup(">="); }
    ;

%%

int main(int argc, char** argv) {
    if(argc!=2){ printf("Usage: %s <file>\n",argv[0]); return 1;}
    FILE* f = fopen(argv[1],"r");
    if(!f){ printf("Cannot open file %s\n",argv[1]); return 1; }
    yyin = f;
    yyparse();
    fclose(f);
    return 0;
}