/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 18 "gocompiler.y"

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

#line 92 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

#line 239 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   130,   131,   132,   136,   137,   141,   142,
     146,   147,   151,   152,   153,   154,   158,   159,   160,   161,
     165,   166,   170,   171,   175,   179,   180,   181,   182,   186,
     187,   189,   190,   192,   193,   195,   196,   197,   198,   200,
     201,   202,   203,   204,   205,   207,   208,   210,   212,   216,
     217,   221,   222,   226,   227,   228,   230,   234,   235,   239,
     240,   241,   242,   243,   245,   246,   247,   249,   250,   251,
     252,   253,   255,   256,   257,   258,   259,   260,   262,   263,
     265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PACKAGE", "VAR", "INT", "FLOAT32",
  "BOOL", "STRING", "FUNC", "ELSE", "LBRACE", "SEMICOLON", "RBRACE",
  "BLANKID", "CMDARGS", "LSQ", "RSQ", "COMMA", "LPAR", "RPAR", "RESERVED",
  "STRLIT", "INTLIT", "REALLIT", "ID", "ASSIGN", "IF", "FOR", "OR", "AND",
  "LT", "GT", "EQ", "NE", "LE", "GE", "STAR", "DIV", "MOD", "NOT", "MINUS",
  "PLUS", "PARSEINT", "RETURN", "PRINT", "$accept", "Program",
  "Declarations", "VarDeclaration", "VarSpec", "ZeroPlus4", "Type",
  "FuncDeclaration", "Parameters", "ZeroPlus3", "FuncBody",
  "VarsAndStatements", "Statement", "ZeroPlus2", "ParseArgs",
  "FuncInvocation", "ZeroPlus1", "Expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    -3,    23,    17,   -76,    26,    -1,     6,   -76,    29,
      30,    13,   122,   -76,    31,    26,    26,    39,   -76,   -76,
     -76,   -76,    28,   254,   -76,    19,   -76,   -76,    34,    38,
     -76,    41,   254,    52,   -76,   -76,   -76,    63,   -76,    60,
      41,    69,   -76,    61,   -76,    63,   -76,   -76,    74,   -76,
     -76,   -14,   307,    65,   307,    76,    88,    91,   -76,   -76,
     254,   -76,   -76,    92,    96,    98,   172,   307,   184,   -76,
     -76,   104,   307,   307,   307,   -76,   199,    97,   216,   355,
     267,   -76,   -76,    60,   120,   -76,    89,   112,   -76,   264,
     355,   115,   321,   -76,   -76,   -76,   125,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     -76,   103,   133,   117,   341,   -76,   -76,   100,   -76,   307,
     -76,   119,   -76,   -76,   139,   138,   368,   380,   178,   178,
     178,   178,   178,   178,   -76,   -76,   -76,    54,    54,   -76,
     -76,   141,   -76,   -76,   136,   286,   -76,   146,   149,   -76,
       0,   -76,   155,   152,   147,   159,   -76,   158,   161,   -76,
     307,   -76,   -76,   163,   239,   -76,   164,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     0,
       0,     0,     0,     7,     0,     3,     3,     0,    12,    13,
      14,    15,     0,     0,     8,     0,     4,     5,     0,    10,
       9,     0,     0,     0,     6,    11,    25,     0,    17,    20,
       0,     0,    18,     0,    21,     0,    19,    48,     0,    26,
      24,     0,     0,     0,    33,     0,     0,     0,    32,    31,
       0,    16,    46,     0,     0,     0,     0,     0,     0,    59,
      60,    61,     0,     0,     0,    62,     0,     0,     0,    34,
       0,    27,    28,    22,     0,    45,     0,     0,    53,     0,
      47,     0,     0,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,    23,    50,     0,    56,     0,
      54,     0,    80,    63,    40,     0,    78,    79,    72,    73,
      74,    75,    76,    77,    69,    70,    71,    68,    67,    35,
      37,     0,    29,    30,     0,    57,    55,     0,    39,    36,
       0,    58,     0,     0,     0,     0,    44,     0,     0,    52,
       0,    42,    43,     0,     0,    41,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,     4,   140,   168,   165,   -15,   -76,   -76,   107,
     -34,   -76,   157,   -75,   -76,   -41,    42,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,     9,    13,    23,    24,    10,    33,    44,
      38,    41,    63,    64,    58,    75,   121,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   154,   111,    42,    65,    66,    46,    59,    30,   116,
       1,    61,    67,    78,    79,   155,    37,    39,    11,    26,
      27,   125,     3,     4,    12,    45,    89,    90,    92,     5,
       6,    14,    93,    94,    95,     7,    59,   141,    12,    31,
     114,    15,    16,    59,    32,    83,    18,    19,    20,    21,
      25,    28,    36,    29,    34,    59,    22,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      47,    59,    40,     6,    36,    47,    77,   157,    43,   145,
      48,    49,    50,   163,    68,    48,    60,    62,    69,    70,
      71,   105,   106,   107,    51,    80,    52,    53,    47,    51,
      81,    52,    53,    82,    84,    72,    73,    74,    48,    85,
     110,    59,    86,    54,    55,   117,   139,    59,    54,    55,
     164,    47,    51,    66,    52,    53,    47,    18,    19,    20,
      21,    48,   118,   -49,    47,   122,    48,   142,   124,   146,
      22,    54,    55,   144,    48,    51,   140,    52,    53,   147,
      51,   148,    52,    53,   149,   150,    47,   152,    51,   153,
      52,    53,    47,   158,    54,    55,    48,   159,   156,    54,
      55,   161,    48,    87,   162,   160,   165,    54,    55,    17,
      51,    56,    52,    53,   167,    91,    51,   151,    52,    53,
     115,    68,    88,     0,    35,    69,    70,    71,    57,    54,
      55,     0,     0,    68,     0,    54,    55,    69,    70,    71,
      96,     0,    72,    73,    74,   105,   106,   107,     0,   108,
     109,     0,     0,     0,    72,    73,    74,   112,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,   109,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   166,   108,   109,    18,
      19,    20,    21,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,   109,   119,     0,   120,     0,    68,     0,     0,   113,
      69,    70,    71,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   119,   108,   109,    72,    73,    74,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    68,   108,   109,     0,
      69,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,    72,    73,    74,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   143,   108,   109,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,   109,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
     109,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109
};

static const yytype_int16 yycheck[] =
{
      41,     1,    77,    37,    18,    19,    40,    48,    23,    84,
       3,    45,    26,    53,    54,    15,    31,    32,    19,    15,
      16,    96,    25,     0,    25,    40,    66,    67,    68,    12,
       4,    25,    72,    73,    74,     9,    77,   112,    25,    20,
      80,    12,    12,    84,    25,    60,     5,     6,     7,     8,
      19,    12,    11,    25,    20,    96,    18,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       1,   112,    20,     4,    11,     1,    11,   152,    18,   119,
      11,    12,    13,   158,    19,    11,    25,    13,    23,    24,
      25,    37,    38,    39,    25,    19,    27,    28,     1,    25,
      12,    27,    28,    12,    12,    40,    41,    42,    11,    13,
      13,   152,    14,    44,    45,    26,    13,   158,    44,    45,
     160,     1,    25,    19,    27,    28,     1,     5,     6,     7,
       8,    11,    20,    13,     1,    20,    11,    20,    13,    20,
      18,    44,    45,    43,    11,    25,    13,    27,    28,    10,
      25,    13,    27,    28,    13,    19,     1,    11,    25,    10,
      27,    28,     1,    11,    44,    45,    11,    20,    13,    44,
      45,    13,    11,     1,    13,    16,    13,    44,    45,    11,
      25,    41,    27,    28,    20,     1,    25,   145,    27,    28,
      83,    19,    20,    -1,    29,    23,    24,    25,    41,    44,
      45,    -1,    -1,    19,    -1,    44,    45,    23,    24,    25,
      11,    -1,    40,    41,    42,    37,    38,    39,    -1,    41,
      42,    -1,    -1,    -1,    40,    41,    42,    11,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    17,    41,    42,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    18,    -1,    20,    -1,    19,    -1,    -1,    22,
      23,    24,    25,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    18,    41,    42,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    19,    41,    42,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    20,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    25,     0,    12,     4,     9,    48,    49,
      53,    19,    25,    50,    25,    12,    12,    50,     5,     6,
       7,     8,    18,    51,    52,    19,    48,    48,    12,    25,
      52,    20,    25,    54,    20,    51,    11,    52,    56,    52,
      20,    57,    56,    18,    55,    52,    56,     1,    11,    12,
      13,    25,    27,    28,    44,    45,    49,    58,    60,    61,
      25,    56,    13,    58,    59,    18,    19,    26,    19,    23,
      24,    25,    40,    41,    42,    61,    63,    11,    63,    63,
      19,    12,    12,    52,    12,    13,    14,     1,    20,    63,
      63,     1,    63,    63,    63,    63,    11,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    42,
      13,    59,    11,    22,    63,    55,    59,    26,    20,    18,
      20,    62,    20,    20,    13,    59,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    13,
      13,    59,    20,    20,    43,    63,    20,    10,    13,    13,
      19,    62,    11,    10,     1,    15,    13,    59,    11,    20,
      16,    13,    13,    59,    63,    13,    17,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     3,     5,     2,     2,     3,
       2,     3,     1,     1,     1,     1,     7,     5,     6,     6,
       2,     3,     3,     4,     3,     0,     2,     3,     3,     4,
       4,     1,     1,     1,     2,     4,     5,     4,     3,     5,
       4,     9,     8,     8,     7,     3,     2,     3,     1,     2,
       3,    11,     8,     3,     4,     5,     4,     2,     3,     1,
       1,     1,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 126 "gocompiler.y"
                                                    {(yyval.in) = myprogram = insert_node(NULL,"Program",(yyvsp[0].in),NULL);}
#line 1576 "y.tab.c"
    break;

  case 3:
#line 130 "gocompiler.y"
                                                    {(yyval.in) = NULL;}
#line 1582 "y.tab.c"
    break;

  case 4:
#line 131 "gocompiler.y"
                                                    {if((yyvsp[0].in) == NULL) {(yyval.in) = (yyvsp[-2].in);}else{(yyval.in) = insert_sibling((yyvsp[-2].in),(yyvsp[0].in));};}
#line 1588 "y.tab.c"
    break;

  case 5:
#line 132 "gocompiler.y"
                                                    {if((yyvsp[0].in) == NULL) {(yyval.in) = insert_node(NULL,"FuncDecl",(yyvsp[-2].in),NULL);}else{(yyval.in) = insert_sibling(insert_node(NULL,"FuncDecl",(yyvsp[-2].in),NULL),(yyvsp[0].in));};}
#line 1594 "y.tab.c"
    break;

  case 6:
#line 136 "gocompiler.y"
                                                    {(yyval.in) = (yyvsp[-2].in);}
#line 1600 "y.tab.c"
    break;

  case 7:
#line 137 "gocompiler.y"
                                                    {(yyval.in) = (yyvsp[0].in);}
#line 1606 "y.tab.c"
    break;

  case 8:
#line 141 "gocompiler.y"
                                                    {(yyval.in) = insert_node(NULL,"VarDecl",(yyvsp[0].in),insert_terminal((yyvsp[-1].value),"Id"));}
#line 1612 "y.tab.c"
    break;

  case 9:
#line 142 "gocompiler.y"
                                                    {(yyval.in) = insert_sibling(insert_node(NULL,"VarDecl",(yyvsp[0].in),insert_terminal((yyvsp[-2].value),"Id")), (yyvsp[-1].in)); if((yyvsp[0].in)) change_type((yyval.in), (yyvsp[0].in)->type);}
#line 1618 "y.tab.c"
    break;

  case 10:
#line 146 "gocompiler.y"
                                                    {(yyval.in) = insert_node(NULL,"VarDecl", insert_terminal(NULL,"None"), insert_terminal((yyvsp[0].value),"Id"));}
#line 1624 "y.tab.c"
    break;

  case 11:
#line 147 "gocompiler.y"
                                                    {(yyval.in) = insert_sibling(insert_node(NULL,"VarDecl",insert_terminal(NULL,"None"),insert_terminal((yyvsp[-1].value),"Id")), (yyvsp[0].in));}
#line 1630 "y.tab.c"
    break;

  case 12:
#line 151 "gocompiler.y"
                                                    {(yyval.in) = insert_terminal(NULL,"Int");}
#line 1636 "y.tab.c"
    break;

  case 13:
#line 152 "gocompiler.y"
                                                    {(yyval.in) = insert_terminal(NULL,"Float32");}
#line 1642 "y.tab.c"
    break;

  case 14:
#line 153 "gocompiler.y"
                                                    {(yyval.in) = insert_terminal(NULL,"Bool");}
#line 1648 "y.tab.c"
    break;

  case 15:
#line 154 "gocompiler.y"
                                                    {(yyval.in) = insert_terminal(NULL,"String");}
#line 1654 "y.tab.c"
    break;

  case 16:
#line 158 "gocompiler.y"
                                                    {(yyval.in) = insert_sibling(insert_node(NULL,"FuncHeader", insert_terminal((yyvsp[-5].value), "Id"), insert_sibling((yyvsp[-1].in), insert_node(NULL,"FuncParams", (yyvsp[-3].in), NULL))), (yyvsp[0].in));}
#line 1660 "y.tab.c"
    break;

  case 17:
#line 159 "gocompiler.y"
                                                    {(yyval.in) = insert_sibling(insert_node(NULL,"FuncHeader",insert_terminal((yyvsp[-3].value),"Id"),insert_terminal(NULL,"FuncParams")),(yyvsp[0].in));}
#line 1666 "y.tab.c"
    break;

  case 18:
#line 160 "gocompiler.y"
                                                    {(yyval.in) = insert_sibling(insert_node(NULL,"FuncHeader", insert_terminal((yyvsp[-4].value), "Id"), insert_sibling((yyvsp[-1].in),insert_terminal(NULL,"FuncParams"))), (yyvsp[0].in));}
#line 1672 "y.tab.c"
    break;

  case 19:
#line 161 "gocompiler.y"
                                                    {(yyval.in) = insert_sibling(insert_node(NULL,"FuncHeader", insert_terminal((yyvsp[-4].value), "Id"), insert_node(NULL,"FuncParams", (yyvsp[-2].in), NULL)), (yyvsp[0].in));}
#line 1678 "y.tab.c"
    break;

  case 20:
#line 165 "gocompiler.y"
                                                {(yyval.in) = insert_node(NULL,"ParamDecl", insert_sibling((yyvsp[0].in), insert_terminal((yyvsp[-1].value), "Id")), NULL);}
#line 1684 "y.tab.c"
    break;

  case 21:
#line 166 "gocompiler.y"
                                                {(yyval.in) = insert_sibling(insert_node(NULL,"ParamDecl", insert_sibling((yyvsp[-1].in), insert_terminal((yyvsp[-2].value), "Id")), NULL), (yyvsp[0].in));}
#line 1690 "y.tab.c"
    break;

  case 22:
#line 170 "gocompiler.y"
                                                {(yyval.in) = insert_node(NULL,"ParamDecl", insert_sibling((yyvsp[0].in), insert_terminal((yyvsp[-1].value), "Id")), NULL);}
#line 1696 "y.tab.c"
    break;

  case 23:
#line 171 "gocompiler.y"
                                                {(yyval.in) = insert_sibling(insert_node(NULL,"ParamDecl", insert_sibling((yyvsp[-1].in), insert_terminal((yyvsp[-2].value), "Id")), NULL), (yyvsp[0].in));}
#line 1702 "y.tab.c"
    break;

  case 24:
#line 175 "gocompiler.y"
                                                {(yyval.in) = insert_node(NULL,"FuncBody", (yyvsp[-1].in), NULL);}
#line 1708 "y.tab.c"
    break;

  case 25:
#line 179 "gocompiler.y"
                                                    {(yyval.in) = NULL;}
#line 1714 "y.tab.c"
    break;

  case 26:
#line 180 "gocompiler.y"
                                                    {(yyval.in) = (yyvsp[-1].in);}
#line 1720 "y.tab.c"
    break;

  case 27:
#line 181 "gocompiler.y"
                                                    {if ((yyvsp[-2].in) == NULL) (yyval.in) = (yyvsp[-1].in); else (yyval.in) = insert_sibling((yyvsp[-2].in), (yyvsp[-1].in));}
#line 1726 "y.tab.c"
    break;

  case 28:
#line 182 "gocompiler.y"
                                                    {if ((yyvsp[-2].in) == NULL) (yyval.in) = (yyvsp[-1].in); else (yyval.in) = insert_sibling((yyvsp[-2].in), (yyvsp[-1].in));}
#line 1732 "y.tab.c"
    break;

  case 29:
#line 186 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-3].value),"Print",insert_terminal((yyvsp[-1].value),"StrLit"),NULL);}
#line 1738 "y.tab.c"
    break;

  case 30:
#line 187 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-3].value),"Print",(yyvsp[-1].in),NULL);}
#line 1744 "y.tab.c"
    break;

  case 31:
#line 189 "gocompiler.y"
                                                                                {(yyval.in) = (yyvsp[0].in);}
#line 1750 "y.tab.c"
    break;

  case 32:
#line 190 "gocompiler.y"
                                                                                {(yyval.in) = (yyvsp[0].in);}
#line 1756 "y.tab.c"
    break;

  case 33:
#line 192 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[0].value),"Return",NULL,NULL);}
#line 1762 "y.tab.c"
    break;

  case 34:
#line 193 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Return",(yyvsp[0].in),NULL);}
#line 1768 "y.tab.c"
    break;

  case 35:
#line 195 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-3].value),"For",insert_block((yyvsp[-1].in),0),NULL);}
#line 1774 "y.tab.c"
    break;

  case 36:
#line 196 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-4].value),"For",(yyvsp[-3].in),insert_block((yyvsp[-1].in),0));}
#line 1780 "y.tab.c"
    break;

  case 37:
#line 197 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-3].value),"For",(yyvsp[-2].in),insert_block(NULL,0));}
#line 1786 "y.tab.c"
    break;

  case 38:
#line 198 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-2].value),"For",insert_block(NULL,0),NULL);}
#line 1792 "y.tab.c"
    break;

  case 39:
#line 200 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-4].value),"If",(yyvsp[-3].in),insert_block((yyvsp[-1].in),1));}
#line 1798 "y.tab.c"
    break;

  case 40:
#line 201 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-3].value),"If",(yyvsp[-2].in),insert_block(NULL,1));}
#line 1804 "y.tab.c"
    break;

  case 41:
#line 202 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-8].value),"If",(yyvsp[-7].in),insert_sibling(insert_block((yyvsp[-5].in),0),insert_block((yyvsp[-1].in),0)));}
#line 1810 "y.tab.c"
    break;

  case 42:
#line 203 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-7].value),"If",(yyvsp[-6].in),insert_sibling(insert_block(NULL,0),insert_block((yyvsp[-1].in),0)));}
#line 1816 "y.tab.c"
    break;

  case 43:
#line 204 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-7].value),"If",(yyvsp[-6].in),insert_sibling(insert_block((yyvsp[-4].in),0),insert_block(NULL,0)));}
#line 1822 "y.tab.c"
    break;

  case 44:
#line 205 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-6].value),"If",(yyvsp[-5].in),insert_sibling(insert_block(NULL,0),insert_block(NULL,0)));}
#line 1828 "y.tab.c"
    break;

  case 45:
#line 207 "gocompiler.y"
                                                                                {if((yyvsp[-1].in) && (yyvsp[-1].in)->sibling != NULL){(yyval.in) = insert_block((yyvsp[-1].in),0);}else{(yyval.in) = (yyvsp[-1].in);};}
#line 1834 "y.tab.c"
    break;

  case 46:
#line 208 "gocompiler.y"
                                                                                {(yyval.in) = NULL;}
#line 1840 "y.tab.c"
    break;

  case 47:
#line 210 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Assign", insert_terminal((yyvsp[-2].value),"Id"),(yyvsp[0].in));}
#line 1846 "y.tab.c"
    break;

  case 48:
#line 212 "gocompiler.y"
                                                                                {;}
#line 1852 "y.tab.c"
    break;

  case 49:
#line 216 "gocompiler.y"
                                                                                {(yyval.in) = (yyvsp[-1].in);}
#line 1858 "y.tab.c"
    break;

  case 50:
#line 217 "gocompiler.y"
                                                                                {if((yyvsp[-2].in) != NULL && (yyvsp[0].in) != NULL) (yyval.in) = insert_sibling((yyvsp[-2].in), (yyvsp[0].in)); else if ((yyvsp[-2].in) != NULL && (yyvsp[0].in) == NULL) (yyval.in) = (yyvsp[-2].in); else if ((yyvsp[-2].in) == NULL && (yyvsp[0].in) != NULL) (yyval.in) = (yyvsp[0].in); else (yyval.in) = NULL;}
#line 1864 "y.tab.c"
    break;

  case 51:
#line 221 "gocompiler.y"
                                                                                {(yyval.in) = insert_node((yyvsp[-6].value),"ParseArgs",insert_terminal((yyvsp[-10].value),"Id"),(yyvsp[-2].in));}
#line 1870 "y.tab.c"
    break;

  case 52:
#line 222 "gocompiler.y"
                                                                                {;}
#line 1876 "y.tab.c"
    break;

  case 53:
#line 226 "gocompiler.y"
                                                {(yyval.in) = insert_node(NULL,"Call",insert_terminal((yyvsp[-2].value),"Id"),NULL);}
#line 1882 "y.tab.c"
    break;

  case 54:
#line 227 "gocompiler.y"
                                                {(yyval.in) = insert_node(NULL,"Call",insert_terminal((yyvsp[-3].value),"Id"),(yyvsp[-1].in));}
#line 1888 "y.tab.c"
    break;

  case 55:
#line 228 "gocompiler.y"
                                                {(yyval.in) = insert_node(NULL,"Call",insert_terminal((yyvsp[-4].value),"Id"),insert_sibling((yyvsp[-2].in),(yyvsp[-1].in)));}
#line 1894 "y.tab.c"
    break;

  case 56:
#line 230 "gocompiler.y"
                                                {;}
#line 1900 "y.tab.c"
    break;

  case 57:
#line 234 "gocompiler.y"
                                                {(yyval.in) = (yyvsp[0].in);}
#line 1906 "y.tab.c"
    break;

  case 58:
#line 235 "gocompiler.y"
                                                {(yyval.in) = insert_sibling((yyvsp[-1].in), (yyvsp[0].in));}
#line 1912 "y.tab.c"
    break;

  case 59:
#line 239 "gocompiler.y"
                                                {(yyval.in) = insert_terminal((yyvsp[0].value),"IntLit");}
#line 1918 "y.tab.c"
    break;

  case 60:
#line 240 "gocompiler.y"
                                                {(yyval.in) = insert_terminal((yyvsp[0].value),"RealLit");}
#line 1924 "y.tab.c"
    break;

  case 61:
#line 241 "gocompiler.y"
                                                {(yyval.in) = insert_terminal((yyvsp[0].value),"Id");}
#line 1930 "y.tab.c"
    break;

  case 62:
#line 242 "gocompiler.y"
                                                {(yyval.in) = (yyvsp[0].in);}
#line 1936 "y.tab.c"
    break;

  case 63:
#line 243 "gocompiler.y"
                                                {(yyval.in) = (yyvsp[-1].in);}
#line 1942 "y.tab.c"
    break;

  case 64:
#line 245 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Not",(yyvsp[0].in),NULL);}
#line 1948 "y.tab.c"
    break;

  case 65:
#line 246 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Minus",(yyvsp[0].in),NULL);}
#line 1954 "y.tab.c"
    break;

  case 66:
#line 247 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Plus",(yyvsp[0].in),NULL);}
#line 1960 "y.tab.c"
    break;

  case 67:
#line 249 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Add",(yyvsp[-2].in),(yyvsp[0].in));}
#line 1966 "y.tab.c"
    break;

  case 68:
#line 250 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Sub",(yyvsp[-2].in),(yyvsp[0].in));}
#line 1972 "y.tab.c"
    break;

  case 69:
#line 251 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Mul",(yyvsp[-2].in),(yyvsp[0].in));}
#line 1978 "y.tab.c"
    break;

  case 70:
#line 252 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Div",(yyvsp[-2].in),(yyvsp[0].in));}
#line 1984 "y.tab.c"
    break;

  case 71:
#line 253 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Mod",(yyvsp[-2].in),(yyvsp[0].in));}
#line 1990 "y.tab.c"
    break;

  case 72:
#line 255 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Lt",(yyvsp[-2].in),(yyvsp[0].in));}
#line 1996 "y.tab.c"
    break;

  case 73:
#line 256 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Gt",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2002 "y.tab.c"
    break;

  case 74:
#line 257 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Eq",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2008 "y.tab.c"
    break;

  case 75:
#line 258 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Ne",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2014 "y.tab.c"
    break;

  case 76:
#line 259 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Le",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2020 "y.tab.c"
    break;

  case 77:
#line 260 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Ge",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2026 "y.tab.c"
    break;

  case 78:
#line 262 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"Or",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2032 "y.tab.c"
    break;

  case 79:
#line 263 "gocompiler.y"
                                                {(yyval.in) = insert_node((yyvsp[-1].value),"And",(yyvsp[-2].in),(yyvsp[0].in));}
#line 2038 "y.tab.c"
    break;

  case 80:
#line 265 "gocompiler.y"
                                                {;}
#line 2044 "y.tab.c"
    break;


#line 2048 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 268 "gocompiler.y"


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
