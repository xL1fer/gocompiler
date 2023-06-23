/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PACKAGE = 258,
    VAR = 259,
    INT = 260,
    FLOAT32 = 261,
    BOOL = 262,
    STRING = 263,
    FUNC = 264,
    ELSE = 265,
    LBRACE = 266,
    SEMICOLON = 267,
    RBRACE = 268,
    BLANKID = 269,
    CMDARGS = 270,
    LSQ = 271,
    RSQ = 272,
    COMMA = 273,
    LPAR = 274,
    RPAR = 275,
    RESERVED = 276,
    STRLIT = 277,
    INTLIT = 278,
    REALLIT = 279,
    ID = 280,
    ASSIGN = 281,
    IF = 282,
    FOR = 283,
    OR = 284,
    AND = 285,
    LT = 286,
    GT = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    STAR = 292,
    DIV = 293,
    MOD = 294,
    NOT = 295,
    MINUS = 296,
    PLUS = 297,
    PARSEINT = 298,
    RETURN = 299,
    PRINT = 300
  };
#endif
/* Tokens.  */
#define PACKAGE 258
#define VAR 259
#define INT 260
#define FLOAT32 261
#define BOOL 262
#define STRING 263
#define FUNC 264
#define ELSE 265
#define LBRACE 266
#define SEMICOLON 267
#define RBRACE 268
#define BLANKID 269
#define CMDARGS 270
#define LSQ 271
#define RSQ 272
#define COMMA 273
#define LPAR 274
#define RPAR 275
#define RESERVED 276
#define STRLIT 277
#define INTLIT 278
#define REALLIT 279
#define ID 280
#define ASSIGN 281
#define IF 282
#define FOR 283
#define OR 284
#define AND 285
#define LT 286
#define GT 287
#define EQ 288
#define NE 289
#define LE 290
#define GE 291
#define STAR 292
#define DIV 293
#define MOD 294
#define NOT 295
#define MINUS 296
#define PLUS 297
#define PARSEINT 298
#define RETURN 299
#define PRINT 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "gocompiler.y"

        is_node* in;
        is_value* value;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
