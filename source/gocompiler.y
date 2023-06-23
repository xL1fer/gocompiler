    //  "gocompiler.y"
    //
    //  ====================================
    //
    //  Universidade de Coimbra
    //  Faculdade de Ciências e Tecnologia
    //  Departamento de Engenharia Informatica
    //
    //  Daniel Gonçalves Portovedo - 2019214315
    //  Luís Miguel Gomes Batista  - 2019214869
    //
    //  ====================================
    //
    //  this file is used to syntactically analyse
    //  and generate the AST for deiGo coding language

    // yacc pre declarations
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "functions.h"
    #include "y.tab.h"

    int yylex(void);
    void yyerror(const char *s);

    int token_status = 0;

    is_node* myprogram = NULL;
    is_node* last_node = NULL;

    is_ambient* amb_head = NULL;

    int yylex_destroy();

    int errors = 0;
%}

    // yacc tokens
%token PACKAGE
%token VAR
%token INT
%token FLOAT32
%token BOOL
%token STRING
%token FUNC
%token ELSE
%token LBRACE
%token SEMICOLON
%token RBRACE
%token BLANKID
%token CMDARGS
%token LSQ
%token RSQ
%token COMMA
%token LPAR
%token RPAR
%token RESERVED

    // union types
%union {
        is_node* in;
        is_value* value;
}

%token <value> STRLIT
%token <value> INTLIT
%token <value> REALLIT
%token <value> ID
%token <value> ASSIGN
%token <value> IF
%token <value> FOR
%token <value> OR
%token <value> AND
%token <value> LT
%token <value> GT
%token <value> EQ
%token <value> NE
%token <value> LE
%token <value> GE
%token <value> STAR
%token <value> DIV
%token <value> MOD
%token <value> NOT
%token <value> MINUS
%token <value> PLUS
%token <value> PARSEINT
%token <value> RETURN
%token <value> PRINT

    // rule types
%type <in> Expr
%type <in> FuncInvocation
%type <in> ZeroPlus1
%type <in> ZeroPlus2
%type <in> ZeroPlus3
%type <in> ZeroPlus4
%type <in> Statement
%type <in> VarsAndStatements
%type <in> ParseArgs
%type <in> VarDeclaration
%type <in> VarSpec
%type <in> Type
%type <in> FuncBody
%type <in> Parameters
%type <in> FuncDeclaration
%type <in> Declarations
%type <in> Program

    // precedence
%left OR
%left AND

%left LT GT EQ NE LE GE

%left PLUS MINUS NOT
%left STAR DIV MOD
 
%nonassoc LPAR RPAR

    // yacc rules
%%
 
Program:
        PACKAGE ID SEMICOLON Declarations           {$$ = myprogram = insert_node(NULL,"Program",$4,NULL);}
    ;

Declarations:
        /* empty*/                                  {$$ = NULL;}
    |   VarDeclaration SEMICOLON Declarations       {if($3 == NULL) {$$ = $1;}else{$$ = insert_sibling($1,$3);};}
    |   FuncDeclaration SEMICOLON Declarations      {if($3 == NULL) {$$ = insert_node(NULL,"FuncDecl",$1,NULL);}else{$$ = insert_sibling(insert_node(NULL,"FuncDecl",$1,NULL),$3);};}
    ;
    
VarDeclaration:
        VAR LPAR VarSpec SEMICOLON RPAR             {$$ = $3;}
    |   VAR VarSpec                                 {$$ = $2;}
    ;

VarSpec:
        ID Type                                     {$$ = insert_node(NULL,"VarDecl",$2,insert_terminal($1,"Id"));}
    |   ID ZeroPlus4 Type                           {$$ = insert_sibling(insert_node(NULL,"VarDecl",$3,insert_terminal($1,"Id")), $2); if($3) change_type($$, $3->type);}
    ;

ZeroPlus4:
        COMMA ID                                    {$$ = insert_node(NULL,"VarDecl", insert_terminal(NULL,"None"), insert_terminal($2,"Id"));}
    |   COMMA ID ZeroPlus4                          {$$ = insert_sibling(insert_node(NULL,"VarDecl",insert_terminal(NULL,"None"),insert_terminal($2,"Id")), $3);}
    ;

Type:
        INT                                         {$$ = insert_terminal(NULL,"Int");}
    |   FLOAT32                                     {$$ = insert_terminal(NULL,"Float32");}
    |   BOOL                                        {$$ = insert_terminal(NULL,"Bool");}
    |   STRING                                      {$$ = insert_terminal(NULL,"String");}
    ;

FuncDeclaration:
        FUNC ID LPAR Parameters RPAR Type FuncBody  {$$ = insert_sibling(insert_node(NULL,"FuncHeader", insert_terminal($2, "Id"), insert_sibling($6, insert_node(NULL,"FuncParams", $4, NULL))), $7);}
    |   FUNC ID LPAR RPAR FuncBody                  {$$ = insert_sibling(insert_node(NULL,"FuncHeader",insert_terminal($2,"Id"),insert_terminal(NULL,"FuncParams")),$5);}
    |   FUNC ID LPAR RPAR Type FuncBody             {$$ = insert_sibling(insert_node(NULL,"FuncHeader", insert_terminal($2, "Id"), insert_sibling($5,insert_terminal(NULL,"FuncParams"))), $6);}
    |   FUNC ID LPAR Parameters RPAR FuncBody       {$$ = insert_sibling(insert_node(NULL,"FuncHeader", insert_terminal($2, "Id"), insert_node(NULL,"FuncParams", $4, NULL)), $6);}
    ;

Parameters:
        ID Type                                 {$$ = insert_node(NULL,"ParamDecl", insert_sibling($2, insert_terminal($1, "Id")), NULL);}
    |   ID Type ZeroPlus3                       {$$ = insert_sibling(insert_node(NULL,"ParamDecl", insert_sibling($2, insert_terminal($1, "Id")), NULL), $3);}
    ;

ZeroPlus3:
        COMMA ID Type                           {$$ = insert_node(NULL,"ParamDecl", insert_sibling($3, insert_terminal($2, "Id")), NULL);}
    |   COMMA ID Type ZeroPlus3                 {$$ = insert_sibling(insert_node(NULL,"ParamDecl", insert_sibling($3, insert_terminal($2, "Id")), NULL), $4);}
    ;

FuncBody:
        LBRACE VarsAndStatements RBRACE         {$$ = insert_node(NULL,"FuncBody", $2, NULL);}
    ;
    
VarsAndStatements:
        /* empty */                                 {$$ = NULL;}
    |   VarsAndStatements SEMICOLON                 {$$ = $1;}
    |   VarsAndStatements VarDeclaration SEMICOLON  {if ($1 == NULL) $$ = $2; else $$ = insert_sibling($1, $2);}
    |   VarsAndStatements Statement SEMICOLON       {if ($1 == NULL) $$ = $2; else $$ = insert_sibling($1, $2);}
    ;
    
Statement:
        PRINT LPAR STRLIT RPAR                                                  {$$ = insert_node($1,"Print",insert_terminal($3,"StrLit"),NULL);}
    |   PRINT LPAR Expr RPAR                                                    {$$ = insert_node($1,"Print",$3,NULL);} 

    |   FuncInvocation                                                          {$$ = $1;}
    |   ParseArgs                                                               {$$ = $1;}

    |   RETURN                                                                  {$$ = insert_node($1,"Return",NULL,NULL);}
    |   RETURN Expr                                                             {$$ = insert_node($1,"Return",$2,NULL);}

    |   FOR LBRACE ZeroPlus2 RBRACE                                             {$$ = insert_node($1,"For",insert_block($3,0),NULL);}
    |   FOR Expr LBRACE ZeroPlus2 RBRACE                                        {$$ = insert_node($1,"For",$2,insert_block($4,0));}
    |   FOR Expr LBRACE RBRACE                                                  {$$ = insert_node($1,"For",$2,insert_block(NULL,0));}
    |   FOR LBRACE RBRACE                                                       {$$ = insert_node($1,"For",insert_block(NULL,0),NULL);}  

    |   IF Expr LBRACE ZeroPlus2 RBRACE                                         {$$ = insert_node($1,"If",$2,insert_block($4,1));}
    |   IF Expr LBRACE RBRACE                                                   {$$ = insert_node($1,"If",$2,insert_block(NULL,1));}
    |   IF Expr LBRACE ZeroPlus2 RBRACE ELSE LBRACE ZeroPlus2 RBRACE            {$$ = insert_node($1,"If",$2,insert_sibling(insert_block($4,0),insert_block($8,0)));}
    |   IF Expr LBRACE RBRACE ELSE LBRACE ZeroPlus2 RBRACE                      {$$ = insert_node($1,"If",$2,insert_sibling(insert_block(NULL,0),insert_block($7,0)));}
    |   IF Expr LBRACE ZeroPlus2 RBRACE ELSE LBRACE RBRACE                      {$$ = insert_node($1,"If",$2,insert_sibling(insert_block($4,0),insert_block(NULL,0)));}
    |   IF Expr LBRACE RBRACE ELSE LBRACE RBRACE                                {$$ = insert_node($1,"If",$2,insert_sibling(insert_block(NULL,0),insert_block(NULL,0)));}

    |   LBRACE ZeroPlus2 RBRACE                                                 {if($2 && $2->sibling != NULL){$$ = insert_block($2,0);}else{$$ = $2;};}
    |   LBRACE RBRACE                                                           {$$ = NULL;}

    |   ID ASSIGN Expr                                                          {$$ = insert_node($2,"Assign", insert_terminal($1,"Id"),$3);}

    |   error                                                                   {;}
    ;

ZeroPlus2:
        Statement SEMICOLON                                                     {$$ = $1;}
    |   Statement SEMICOLON ZeroPlus2                                           {if($1 != NULL && $3 != NULL) $$ = insert_sibling($1, $3); else if ($1 != NULL && $3 == NULL) $$ = $1; else if ($1 == NULL && $3 != NULL) $$ = $3; else $$ = NULL;}
    ;

ParseArgs:      
        ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR         {$$ = insert_node($5,"ParseArgs",insert_terminal($1,"Id"),$9);}
    |   ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR                        {;}
    ;

FuncInvocation:
        ID LPAR RPAR                            {$$ = insert_node(NULL,"Call",insert_terminal($1,"Id"),NULL);}
    |   ID LPAR Expr RPAR                       {$$ = insert_node(NULL,"Call",insert_terminal($1,"Id"),$3);}
    |   ID LPAR Expr ZeroPlus1 RPAR             {$$ = insert_node(NULL,"Call",insert_terminal($1,"Id"),insert_sibling($3,$4));}

    |   ID LPAR error RPAR                      {;}
    ;

ZeroPlus1:
        COMMA Expr                              {$$ = $2;}
    |   COMMA Expr ZeroPlus1                    {$$ = insert_sibling($2, $3);}
    ;

Expr:
        INTLIT                                  {$$ = insert_terminal($1,"IntLit");}
    |   REALLIT                                 {$$ = insert_terminal($1,"RealLit");}
    |   ID                                      {$$ = insert_terminal($1,"Id");}
    |   FuncInvocation                          {$$ = $1;}
    |   LPAR Expr RPAR                          {$$ = $2;}

    |   NOT Expr   %prec LPAR                   {$$ = insert_node($1,"Not",$2,NULL);}
    |   MINUS Expr %prec LPAR                   {$$ = insert_node($1,"Minus",$2,NULL);}
    |   PLUS Expr  %prec LPAR                   {$$ = insert_node($1,"Plus",$2,NULL);}

    |   Expr PLUS Expr                          {$$ = insert_node($2,"Add",$1,$3);}
    |   Expr MINUS Expr                         {$$ = insert_node($2,"Sub",$1,$3);}
    |   Expr STAR Expr                          {$$ = insert_node($2,"Mul",$1,$3);}
    |   Expr DIV Expr                           {$$ = insert_node($2,"Div",$1,$3);}
    |   Expr MOD Expr                           {$$ = insert_node($2,"Mod",$1,$3);}

    |   Expr LT Expr                            {$$ = insert_node($2,"Lt",$1,$3);}
    |   Expr GT Expr                            {$$ = insert_node($2,"Gt",$1,$3);}
    |   Expr EQ Expr                            {$$ = insert_node($2,"Eq",$1,$3);}
    |   Expr NE Expr                            {$$ = insert_node($2,"Ne",$1,$3);}
    |   Expr LE Expr                            {$$ = insert_node($2,"Le",$1,$3);}
    |   Expr GE Expr                            {$$ = insert_node($2,"Ge",$1,$3);}

    |   Expr OR Expr                            {$$ = insert_node($2,"Or",$1,$3);}
    |   Expr AND Expr                           {$$ = insert_node($2,"And",$1,$3);}

    |   LPAR error RPAR                         {;}
    ;

%%

int main(int argc, char** argv)
{
    if (argc != 1 && strcmp(argv[1], "-l") == 0)                // token to print lex tokens
        token_status = 1;
    else if(argc != 1 && strcmp(argv[1], "-t") == 0)            // token to print ast
        token_status = 2;
    else if(argc != 1 && strcmp(argv[1], "-s") == 0)            // token to print symb tables and annotated ast
        token_status = 3;


    if (yyparse() == 0)                                         // if yacc has no errors
    {
        if (myprogram) check_ast(myprogram->child,0,NULL);      // semantic analysis
        check_unused_symbs();                                   // verify if any symb is not used

        if (token_status > 1)                                   // if we either need to print ast or symb tables
        {
                if (token_status == 3)                          // if we need to specifically print symb tables
                {       
                        print_global(1);                         // print symb tables
                }

                print_program(myprogram, 0);                    // print ast
        }
    }

    if (token_status == 0) {

        print_global(0);                                        // load symb tab without printing
        //print_program(myprogram, 0);                            // generate llvm code if no argument is passed and no errors where found
        generate_llvm(myprogram->child, 0);

        // print empty file
        if(myprogram->child == NULL)
                printf("define i32 @main() {\n\tret i32 0\n}\n");
        
        generate_llvm_prints();
    }

    //free memory
    free_ast(last_node);
    yylex_destroy();

    return 0;
}