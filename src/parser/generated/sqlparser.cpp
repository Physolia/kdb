/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 421 "KDbSqlParser.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <assert.h>
#include <limits.h>
//! @todo OK?
#ifdef Q_OS_WIN
//workaround for bug on msvc
# undef LLONG_MIN
#endif
#ifndef LLONG_MAX
# define LLONG_MAX     0x7fffffffffffffffLL
#endif
#ifndef LLONG_MIN
# define LLONG_MIN     0x8000000000000000LL
#endif
#ifndef LLONG_MAX
# define ULLONG_MAX    0xffffffffffffffffLL
#endif

#ifdef _WIN32
# include <malloc.h>
#endif

#include <QObject>
#include <QVariant>
#include <QPoint>

#include "KDbConnection.h"
#include "KDbQuerySchema.h"
#include "KDbQuerySchema_p.h"
#include "KDbField.h"
#include "KDbTableSchema.h"
#include "KDbParser.h"
#include "KDbParser_p.h"
#include "KDbSqlTypes.h"
#include "kdb_debug.h"

#ifdef Q_OS_SOLARIS
#include <alloca.h>
#endif

QDebug operator<<(QDebug dbg, const KDbExpressionPtr& expr)
{
    dbg.nospace() << expr.e;
    return dbg.space();
}

int yylex();

#define YY_NO_UNPUT
#define YYSTACK_USE_ALLOCA 1
#define YYMAXDEPTH 255

    extern "C"
    {
        int yywrap()
        {
            return 1;
        }
    }


#line 132 "KDbSqlParser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "KDbSqlParser.tab.h".  */
#ifndef YY_YY_KDBSQLPARSER_TAB_H_INCLUDED
# define YY_YY_KDBSQLPARSER_TAB_H_INCLUDED
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
    SQL_TYPE = 258,
    AS = 259,
    AS_EMPTY = 260,
    ASC = 261,
    AUTO_INCREMENT = 262,
    BIT = 263,
    BITWISE_SHIFT_LEFT = 264,
    BITWISE_SHIFT_RIGHT = 265,
    BY = 266,
    CHARACTER_STRING_LITERAL = 267,
    CONCATENATION = 268,
    CREATE = 269,
    DESC = 270,
    DISTINCT = 271,
    DOUBLE_QUOTED_STRING = 272,
    FROM = 273,
    JOIN = 274,
    KEY = 275,
    LEFT = 276,
    LESS_OR_EQUAL = 277,
    GREATER_OR_EQUAL = 278,
    SQL_NULL = 279,
    SQL_IS = 280,
    SQL_IS_NULL = 281,
    SQL_IS_NOT_NULL = 282,
    ORDER = 283,
    PRIMARY = 284,
    SELECT = 285,
    INTEGER_CONST = 286,
    REAL_CONST = 287,
    RIGHT = 288,
    SQL_ON = 289,
    DATE_CONST = 290,
    DATETIME_CONST = 291,
    TIME_CONST = 292,
    TABLE = 293,
    IDENTIFIER = 294,
    IDENTIFIER_DOT_ASTERISK = 295,
    QUERY_PARAMETER = 296,
    VARCHAR = 297,
    WHERE = 298,
    SQL = 299,
    SQL_TRUE = 300,
    SQL_FALSE = 301,
    UNION = 302,
    SCAN_ERROR = 303,
    AND = 304,
    BETWEEN = 305,
    NOT_BETWEEN = 306,
    EXCEPT = 307,
    SQL_IN = 308,
    INTERSECT = 309,
    LIKE = 310,
    ILIKE = 311,
    NOT_LIKE = 312,
    NOT = 313,
    NOT_EQUAL = 314,
    NOT_EQUAL2 = 315,
    OR = 316,
    SIMILAR_TO = 317,
    NOT_SIMILAR_TO = 318,
    XOR = 319,
    UMINUS = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 487 "KDbSqlParser.y" /* yacc.c:355  */

    QString* stringValue;
    QByteArray* binaryValue;
    qint64 integerValue;
    bool booleanValue;
    KDbField::Type colType;
    KDbField *field;
    KDbExpression *expr;
    KDbNArgExpression *exprList;
    KDbConstExpression *constExpression;
    KDbQuerySchema *querySchema;
    SelectOptionsInternal *selectOptions;
    OrderByColumnInternal::List *orderByColumns;
    QVariant *variantValue;

#line 254 "KDbSqlParser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KDBSQLPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "KDbSqlParser.cpp" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    78,    74,     2,
      80,    81,    77,    72,    67,    73,    68,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
      70,    71,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    75,     2,    79,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   541,   541,   551,   555,   556,   571,   670,   676,   683,
     688,   694,   700,   709,   717,   724,   730,   738,   749,   758,
     767,   777,   785,   797,   803,   810,   817,   821,   828,   833,
     840,   846,   853,   858,   864,   870,   876,   882,   889,   894,
     900,   906,   912,   918,   924,   930,   936,   946,   957,   962,
     967,   973,   978,   984,   991,   996,  1002,  1006,  1012,  1018,
    1025,  1030,  1036,  1042,  1049,  1055,  1060,  1065,  1070,  1075,
    1083,  1089,  1097,  1104,  1111,  1115,  1119,  1125,  1142,  1149,
    1154,  1163,  1167,  1174,  1180,  1188,  1233,  1238,  1247,  1275,
    1285,  1300,  1307,  1317,  1326,  1331,  1341,  1354,  1400,  1409,
    1418
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SQL_TYPE", "AS", "AS_EMPTY", "ASC",
  "AUTO_INCREMENT", "BIT", "BITWISE_SHIFT_LEFT", "BITWISE_SHIFT_RIGHT",
  "BY", "CHARACTER_STRING_LITERAL", "CONCATENATION", "CREATE", "DESC",
  "DISTINCT", "DOUBLE_QUOTED_STRING", "FROM", "JOIN", "KEY", "LEFT",
  "LESS_OR_EQUAL", "GREATER_OR_EQUAL", "SQL_NULL", "SQL_IS", "SQL_IS_NULL",
  "SQL_IS_NOT_NULL", "ORDER", "PRIMARY", "SELECT", "INTEGER_CONST",
  "REAL_CONST", "RIGHT", "SQL_ON", "DATE_CONST", "DATETIME_CONST",
  "TIME_CONST", "TABLE", "IDENTIFIER", "IDENTIFIER_DOT_ASTERISK",
  "QUERY_PARAMETER", "VARCHAR", "WHERE", "SQL", "SQL_TRUE", "SQL_FALSE",
  "UNION", "SCAN_ERROR", "AND", "BETWEEN", "NOT_BETWEEN", "EXCEPT",
  "SQL_IN", "INTERSECT", "LIKE", "ILIKE", "NOT_LIKE", "NOT", "NOT_EQUAL",
  "NOT_EQUAL2", "OR", "SIMILAR_TO", "NOT_SIMILAR_TO", "XOR", "UMINUS",
  "';'", "','", "'.'", "'>'", "'<'", "'='", "'+'", "'-'", "'&'", "'|'",
  "'/'", "'*'", "'%'", "'~'", "'('", "')'", "$accept", "TopLevelStatement",
  "StatementList", "Statement", "SelectStatement", "Select",
  "SelectOptions", "WhereClause", "OrderByClause", "OrderByColumnId",
  "OrderByOption", "aExpr", "aExpr2", "aExpr3", "aExpr4", "aExpr5",
  "aExpr6", "aExpr7", "aExpr8", "aExpr9", "aExpr10", "aExprList",
  "aExprList2", "Tables", "FlatTableList", "FlatTable", "ColViews",
  "ColItem", "ColExpression", "ColWildCard", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    59,    44,    46,    62,
      60,    61,    43,    45,    38,   124,    47,    42,    37,   126,
      40,    41
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,  -127,    21,  -127,   -32,  -127,    11,  -127,    25,  -127,
     -43,     5,  -127,  -127,  -127,   -21,  -127,  -127,  -127,   124,
     124,   124,  -127,   124,   124,  -127,  -127,    43,    -8,   157,
    -127,     7,    57,    22,  -127,  -127,     8,  -127,     9,  -127,
    -127,    81,    14,     1,  -127,   -28,     0,  -127,   -14,  -127,
    -127,  -127,  -127,    -7,   124,   124,   124,   124,   124,   124,
     124,   124,  -127,  -127,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,    56,   124,    70,  -127,    48,    -3,    46,
    -127,     6,    50,  -127,     5,  -127,  -127,  -127,    28,    15,
      64,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
      59,    61,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    -1,
    -127,  -127,    95,  -127,  -127,  -127,  -127,  -127,   124,  -127,
     124,   124,  -127,    72,    94,     4,    -1,  -127,  -127,  -127,
      99,  -127,  -127,  -127,    -1,    74,  -127,  -127,  -127,    -1,
    -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,     0,     2,     4,     6,     7,     1,     5,    76,
       0,     0,    73,    77,    78,    69,    70,    74,    75,     0,
       0,     0,    99,     0,     0,    97,    28,    32,    38,    48,
      51,    54,    60,    64,    79,    10,     8,    92,    93,    94,
       3,     0,    88,    85,    87,     0,     0,    71,    69,    68,
      66,    65,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    14,     9,     0,
      96,     0,     0,    89,     0,    72,   100,    82,    84,     0,
       0,    80,    29,    30,    31,    36,    34,    33,    35,    37,
       0,     0,    43,    41,    42,    39,    40,    44,    45,    52,
      53,    56,    55,    57,    58,    59,    61,    62,    63,     0,
      18,    91,     0,    12,    95,    98,    90,    86,     0,    81,
       0,     0,    25,    23,    15,    19,     0,    83,    46,    47,
       0,    17,    26,    27,     0,    20,    16,    24,    21,     0,
      22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,   136,  -127,  -127,  -127,    58,    13,  -126,  -127,
    -127,   -24,    69,   114,   -63,  -127,    -9,   101,    53,    98,
    -127,  -127,    20,   109,  -127,    65,  -127,    66,   111,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    86,    87,   144,   145,
     155,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    47,    99,    35,    43,    44,    36,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     152,    95,     9,    89,    57,    58,    73,    74,    92,   153,
     156,     7,    98,     9,    12,    83,    11,    10,   158,    11,
     142,    13,    14,   160,     8,    12,    83,    41,   143,    48,
      84,    16,    13,    14,    42,    17,    18,    45,    90,    96,
      15,    84,    16,    93,   100,     1,    17,    18,    19,    46,
     130,    59,    60,    61,   119,   120,    46,   129,    94,    19,
      75,   154,    20,    21,   101,    85,   132,   148,   149,    23,
      24,    97,     9,    20,    21,   134,    10,   135,    22,   136,
      23,    24,    54,     9,    12,   138,   139,    10,    80,    81,
      82,    13,    14,    95,    55,    12,   146,    56,   140,    15,
     141,    16,    13,    14,    98,    17,    18,    49,    50,    51,
      48,    52,    16,   102,   103,   104,    17,    18,    19,    76,
      77,    78,    79,   126,   127,   128,     9,    84,   157,    19,
     150,   159,    20,    21,    40,    88,   133,    22,    12,    23,
      24,   131,    91,    20,    21,    13,    14,   151,   147,   137,
      23,    24,     0,    48,     0,    16,     0,     0,     0,    17,
      18,   105,   106,   107,   108,   109,   121,   122,   123,   124,
     125,     0,    19,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,     0,    23,    24,     0,     0,    64,    65,     0,
      66,     0,    67,     0,    68,     0,    69,    70,     0,    71,
      72
};

static const yytype_int16 yycheck[] =
{
      24,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       6,    39,    12,     4,    22,    23,     9,    10,     4,    15,
     146,     0,    46,    12,    24,    28,    18,    16,   154,    18,
      31,    31,    32,   159,    66,    24,    28,    80,    39,    39,
      43,    41,    31,    32,    39,    45,    46,    68,    39,    77,
      39,    43,    41,    39,    68,    30,    45,    46,    58,    80,
      84,    69,    70,    71,    73,    74,    80,    11,    67,    58,
      13,    67,    72,    73,    81,    67,    28,   140,   141,    79,
      80,    81,    12,    72,    73,    39,    16,    81,    77,    39,
      79,    80,    49,    12,    24,    67,    81,    16,    76,    77,
      78,    31,    32,    39,    61,    24,    11,    64,    49,    39,
      49,    41,    31,    32,   138,    45,    46,    19,    20,    21,
      39,    23,    41,    54,    55,    56,    45,    46,    58,    72,
      73,    74,    75,    80,    81,    82,    12,    43,    39,    58,
      68,    67,    72,    73,     8,    36,    88,    77,    24,    79,
      80,    85,    41,    72,    73,    31,    32,   144,   138,    94,
      79,    80,    -1,    39,    -1,    41,    -1,    -1,    -1,    45,
      46,    57,    58,    59,    60,    61,    75,    76,    77,    78,
      79,    -1,    58,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    80,    -1,    -1,    50,    51,    -1,
      53,    -1,    55,    -1,    57,    -1,    59,    60,    -1,    62,
      63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    83,    84,    85,    86,    87,     0,    66,    12,
      16,    18,    24,    31,    32,    39,    41,    45,    46,    58,
      72,    73,    77,    79,    80,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   105,   108,   109,   110,   111,
      84,    80,    39,   106,   107,    68,    80,   103,    39,   101,
     101,   101,   101,    93,    49,    61,    64,    22,    23,    69,
      70,    71,    26,    27,    50,    51,    53,    55,    57,    59,
      60,    62,    63,     9,    10,    13,    72,    73,    74,    75,
      76,    77,    78,    28,    43,    67,    88,    89,   105,     4,
      39,   110,     4,    39,    67,    39,    77,    81,    93,   104,
      68,    81,    94,    94,    94,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   100,    11,
      93,   109,    28,    88,    39,    81,    39,   107,    67,    81,
      49,    49,    31,    39,    90,    91,    11,   104,    96,    96,
      68,    89,     6,    15,    67,    92,    90,    39,    90,    67,
      90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    87,    88,    88,    88,    88,    89,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    93,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   110,   110,   111,
     111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     4,     1,     1,     3,     4,     4,     2,     1,
       2,     3,     4,     1,     3,     1,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     5,     5,     1,     2,
       2,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     2,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     1,     2,     3,     1,     1,     2,
       3,     3,     1,     1,     1,     3,     2,     1,     4,     1,
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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

  return yystpcpy (yyres, yystr) - yyres;
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
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

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
                  (unsigned long int) yystacksize));

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
#line 542 "KDbSqlParser.y" /* yacc.c:1646  */
    {
//todo: multiple statements
//todo: not only "select" statements
    KDbParserPrivate::get(globalParser)->setStatementType(KDbParser::Select);
    KDbParserPrivate::get(globalParser)->setQuerySchema((yyvsp[0].querySchema));
}
#line 1500 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 552 "KDbSqlParser.y" /* yacc.c:1646  */
    {
//todo: multiple statements
}
#line 1508 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 557 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.querySchema) = (yyvsp[-1].querySchema);
}
#line 1516 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 572 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.querySchema) = (yyvsp[0].querySchema);
}
#line 1524 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 671 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "Select";
    if (!((yyval.querySchema) = buildSelectQuery( (yyvsp[0].querySchema), 0 )))
        return 0;
}
#line 1534 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 677 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "Select ColViews=" << *(yyvsp[0].exprList);

    if (!((yyval.querySchema) = buildSelectQuery( (yyvsp[-1].querySchema), (yyvsp[0].exprList) )))
        return 0;
}
#line 1545 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 684 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    if (!((yyval.querySchema) = buildSelectQuery( (yyvsp[-2].querySchema), (yyvsp[-1].exprList), (yyvsp[0].exprList) )))
        return 0;
}
#line 1554 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 689 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "Select ColViews Tables";
    if (!((yyval.querySchema) = buildSelectQuery( (yyvsp[-1].querySchema), 0, (yyvsp[0].exprList) )))
        return 0;
}
#line 1564 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 695 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "Select ColViews Conditions";
    if (!((yyval.querySchema) = buildSelectQuery( (yyvsp[-2].querySchema), (yyvsp[-1].exprList), 0, (yyvsp[0].selectOptions) )))
        return 0;
}
#line 1574 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 701 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "Select ColViews Tables SelectOptions";
    if (!((yyval.querySchema) = buildSelectQuery( (yyvsp[-3].querySchema), (yyvsp[-2].exprList), (yyvsp[-1].exprList), (yyvsp[0].selectOptions) )))
        return 0;
}
#line 1584 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 710 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "SELECT";
    (yyval.querySchema) = KDbQuerySchema::Private::createQuery(globalParser->connection());
}
#line 1593 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 718 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "WhereClause";
    (yyval.selectOptions) = new SelectOptionsInternal;
    (yyval.selectOptions)->whereExpr = *(yyvsp[0].expr);
    delete (yyvsp[0].expr);
}
#line 1604 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 725 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "OrderByClause";
    (yyval.selectOptions) = new SelectOptionsInternal;
    (yyval.selectOptions)->orderByColumns = (yyvsp[0].orderByColumns);
}
#line 1614 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 731 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "WhereClause ORDER BY OrderByClause";
    (yyval.selectOptions) = new SelectOptionsInternal;
    (yyval.selectOptions)->whereExpr = *(yyvsp[-3].expr);
    delete (yyvsp[-3].expr);
    (yyval.selectOptions)->orderByColumns = (yyvsp[0].orderByColumns);
}
#line 1626 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 739 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "OrderByClause WhereClause";
    (yyval.selectOptions) = new SelectOptionsInternal;
    (yyval.selectOptions)->whereExpr = *(yyvsp[0].expr);
    delete (yyvsp[0].expr);
    (yyval.selectOptions)->orderByColumns = (yyvsp[-1].orderByColumns);
}
#line 1638 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 750 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr);
}
#line 1646 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 759 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "ORDER BY IDENTIFIER";
    (yyval.orderByColumns) = new OrderByColumnInternal::List;
    OrderByColumnInternal orderByColumn;
    orderByColumn.setColumnByNameOrNumber( *(yyvsp[0].variantValue) );
    (yyval.orderByColumns)->append( orderByColumn );
    delete (yyvsp[0].variantValue);
}
#line 1659 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 768 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "ORDER BY IDENTIFIER OrderByOption";
    (yyval.orderByColumns) = new OrderByColumnInternal::List;
    OrderByColumnInternal orderByColumn;
    orderByColumn.setColumnByNameOrNumber( *(yyvsp[-1].variantValue) );
    orderByColumn.ascending = (yyvsp[0].booleanValue);
    (yyval.orderByColumns)->append( orderByColumn );
    delete (yyvsp[-1].variantValue);
}
#line 1673 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 778 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.orderByColumns) = (yyvsp[0].orderByColumns);
    OrderByColumnInternal orderByColumn;
    orderByColumn.setColumnByNameOrNumber( *(yyvsp[-2].variantValue) );
    (yyval.orderByColumns)->append( orderByColumn );
    delete (yyvsp[-2].variantValue);
}
#line 1685 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 786 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.orderByColumns) = (yyvsp[0].orderByColumns);
    OrderByColumnInternal orderByColumn;
    orderByColumn.setColumnByNameOrNumber( *(yyvsp[-3].variantValue) );
    orderByColumn.ascending = (yyvsp[-2].booleanValue);
    (yyval.orderByColumns)->append( orderByColumn );
    delete (yyvsp[-3].variantValue);
}
#line 1698 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 798 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.variantValue) = new QVariant( *(yyvsp[0].stringValue) );
    kdbDebug() << "OrderByColumnId: " << *(yyval.variantValue);
    delete (yyvsp[0].stringValue);
}
#line 1708 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 804 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.variantValue) = new QVariant( *(yyvsp[-2].stringValue) + QLatin1Char('.') + *(yyvsp[0].stringValue) );
    kdbDebug() << "OrderByColumnId: " << *(yyval.variantValue);
    delete (yyvsp[-2].stringValue);
    delete (yyvsp[0].stringValue);
}
#line 1719 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 811 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.variantValue) = new QVariant((yyvsp[0].integerValue));
    kdbDebug() << "OrderByColumnId: " << *(yyval.variantValue);
}
#line 1728 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 818 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.booleanValue) = true;
}
#line 1736 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 822 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.booleanValue) = false;
}
#line 1744 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 834 "KDbSqlParser.y" /* yacc.c:1646  */
    {
//    kdbDebug() << "AND " << $3.debugString();
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::AND, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1755 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 841 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::OR, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1765 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 847 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::XOR, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1775 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 859 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '>', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1785 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 865 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::GREATER_OR_EQUAL, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1795 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 871 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '<', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1805 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 877 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::LESS_OR_EQUAL, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1815 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 883 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '=', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1825 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 895 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::NOT_EQUAL, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1835 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 901 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::NOT_EQUAL2, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1845 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 907 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::LIKE, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1855 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 913 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::NOT_LIKE, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1865 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 919 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::SQL_IN, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1875 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 925 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::SIMILAR_TO, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1885 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 931 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::NOT_SIMILAR_TO, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1895 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 937 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbNArgExpression(KDb::RelationalExpression, KDbToken::BETWEEN_AND);
    (yyval.expr)->toNArg().append( *(yyvsp[-4].expr) );
    (yyval.expr)->toNArg().append( *(yyvsp[-2].expr) );
    (yyval.expr)->toNArg().append( *(yyvsp[0].expr) );
    delete (yyvsp[-4].expr);
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1909 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 947 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbNArgExpression(KDb::RelationalExpression, KDbToken::NOT_BETWEEN_AND);
    (yyval.expr)->toNArg().append( *(yyvsp[-4].expr) );
    (yyval.expr)->toNArg().append( *(yyvsp[-2].expr) );
    (yyval.expr)->toNArg().append( *(yyvsp[0].expr) );
    delete (yyvsp[-4].expr);
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1923 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 963 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbUnaryExpression( KDbToken::SQL_IS_NULL, *(yyvsp[-1].expr) );
    delete (yyvsp[-1].expr);
}
#line 1932 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 968 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbUnaryExpression( KDbToken::SQL_IS_NOT_NULL, *(yyvsp[-1].expr) );
    delete (yyvsp[-1].expr);
}
#line 1941 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 979 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::BITWISE_SHIFT_LEFT, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1951 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 985 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::BITWISE_SHIFT_RIGHT, *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1961 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 997 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '+', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1971 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1003 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), KDbToken::CONCATENATION, *(yyvsp[0].expr));
}
#line 1979 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1007 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '-', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1989 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1013 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '&', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 1999 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1019 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '|', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 2009 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1031 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '/', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 2019 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1037 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '*', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 2029 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1043 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(*(yyvsp[-2].expr), '%', *(yyvsp[0].expr));
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].expr);
}
#line 2039 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1056 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbUnaryExpression( '-', *(yyvsp[0].expr) );
    delete (yyvsp[0].expr);
}
#line 2048 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1061 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbUnaryExpression( '+', *(yyvsp[0].expr) );
    delete (yyvsp[0].expr);
}
#line 2057 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1066 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbUnaryExpression( '~', *(yyvsp[0].expr) );
    delete (yyvsp[0].expr);
}
#line 2066 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1071 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbUnaryExpression( KDbToken::NOT, *(yyvsp[0].expr) );
    delete (yyvsp[0].expr);
}
#line 2075 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1076 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbVariableExpression( *(yyvsp[0].stringValue) );

    //! @todo simplify this later if that's 'only one field name' expression
    kdbDebug() << "  + identifier: " << *(yyvsp[0].stringValue);
    delete (yyvsp[0].stringValue);
}
#line 2087 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1084 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbQueryParameterExpression( *(yyvsp[0].stringValue) );
    kdbDebug() << "  + query parameter:" << *(yyval.expr);
    delete (yyvsp[0].stringValue);
}
#line 2097 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1090 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "  + function:" << *(yyvsp[-1].stringValue) << "(" << *(yyvsp[0].exprList) << ")";
    (yyval.expr) = new KDbFunctionExpression(*(yyvsp[-1].stringValue), *(yyvsp[0].exprList));
    delete (yyvsp[-1].stringValue);
    delete (yyvsp[0].exprList);
}
#line 2108 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1098 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbVariableExpression( *(yyvsp[-2].stringValue) + QLatin1Char('.') + *(yyvsp[0].stringValue) );
    kdbDebug() << "  + identifier.identifier:" << *(yyvsp[-2].stringValue) << "." << *(yyvsp[0].stringValue);
    delete (yyvsp[-2].stringValue);
    delete (yyvsp[0].stringValue);
}
#line 2119 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1105 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbConstExpression( KDbToken::SQL_NULL, QVariant() );
    kdbDebug() << "  + NULL";
//    $$ = new KDbField();
    //$$->setName(QString::null);
}
#line 2130 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1112 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbConstExpression( KDbToken::SQL_TRUE, true );
}
#line 2138 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1116 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbConstExpression( KDbToken::SQL_FALSE, false );
}
#line 2146 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1120 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbConstExpression( KDbToken::CHARACTER_STRING_LITERAL, *(yyvsp[0].stringValue) );
    kdbDebug() << "  + constant " << (yyvsp[0].stringValue);
    delete (yyvsp[0].stringValue);
}
#line 2156 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1126 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    QVariant val;
    if ((yyvsp[0].integerValue) <= INT_MAX && (yyvsp[0].integerValue) >= INT_MIN)
        val = (int)(yyvsp[0].integerValue);
    else if ((yyvsp[0].integerValue) <= UINT_MAX && (yyvsp[0].integerValue) >= 0)
        val = (uint)(yyvsp[0].integerValue);
    else if ((yyvsp[0].integerValue) <= LLONG_MAX && (yyvsp[0].integerValue) >= LLONG_MIN)
        val = (qint64)(yyvsp[0].integerValue);

//    if ($1 < ULLONG_MAX)
//        val = (quint64)$1;
//! @todo ok?

    (yyval.expr) = new KDbConstExpression( KDbToken::INTEGER_CONST, val );
    kdbDebug() << "  + int constant: " << val.toString();
}
#line 2177 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1143 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbConstExpression( KDbToken::REAL_CONST, *(yyvsp[0].binaryValue) );
    kdbDebug() << "  + real constant: " << *(yyvsp[0].binaryValue);
    delete (yyvsp[0].binaryValue);
}
#line 2187 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1155 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "(expr)";
    (yyval.expr) = new KDbUnaryExpression('(', *(yyvsp[-1].expr));
    delete (yyvsp[-1].expr);
}
#line 2197 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1164 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = (yyvsp[-1].exprList);
}
#line 2205 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1168 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = new KDbNArgExpression(KDb::ArgumentListExpression, ',');
}
#line 2213 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1175 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = (yyvsp[0].exprList);
    (yyval.exprList)->prepend( *(yyvsp[-2].expr) );
    delete (yyvsp[-2].expr);
}
#line 2223 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1181 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = new KDbNArgExpression(KDb::ArgumentListExpression, ',');
    (yyval.exprList)->append( *(yyvsp[0].expr) );
}
#line 2232 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1189 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = (yyvsp[0].exprList);
}
#line 2240 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1234 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = (yyvsp[-2].exprList);
    (yyval.exprList)->append(*(yyvsp[0].expr));
}
#line 2249 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1239 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = new KDbNArgExpression(KDb::TableListExpression, KDbToken::IDENTIFIER); //ok?
    (yyval.exprList)->append(*(yyvsp[0].expr));
    delete (yyvsp[0].expr);
}
#line 2259 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1248 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    kdbDebug() << "FROM: '" << *(yyvsp[0].stringValue) << "'";
    (yyval.expr) = new KDbVariableExpression(*(yyvsp[0].stringValue));

    //! @todo this isn't ok for more tables:
    /*
    KDbField::ListIterator it = globalParser->query()->fieldsIterator();
    for(KDbField *item; (item = it.current()); ++it)
    {
        if(item->table() == dummy)
        {
            item->setTable(schema);
        }

        if(item->table() && !item->isQueryAsterisk())
        {
            KDbField *f = item->table()->field(item->name());
            if(!f)
            {
                KDbParserError err(KDbParser::tr("Field List Error"), KDbParser::tr("Unknown column '%1' in table '%2'",item->name(),schema->name()), ctoken, current);
                globalParser->setError(err);
                yyerror("fieldlisterror");
            }
        }
    }*/
    delete (yyvsp[0].stringValue);
}
#line 2291 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1276 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    //table + alias
    (yyval.expr) = new KDbBinaryExpression(
        KDbVariableExpression(*(yyvsp[-1].stringValue)), KDbToken::AS_EMPTY,
        KDbVariableExpression(*(yyvsp[0].stringValue))
    );
    delete (yyvsp[-1].stringValue);
    delete (yyvsp[0].stringValue);
}
#line 2305 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1286 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    //table + alias
    (yyval.expr) = new KDbBinaryExpression(
        KDbVariableExpression(*(yyvsp[-2].stringValue)), KDbToken::AS,
        KDbVariableExpression(*(yyvsp[0].stringValue))
    );
    delete (yyvsp[-2].stringValue);
    delete (yyvsp[0].stringValue);
}
#line 2319 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1301 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = (yyvsp[-2].exprList);
    (yyval.exprList)->append(*(yyvsp[0].expr));
    delete (yyvsp[0].expr);
    kdbDebug() << "ColViews: ColViews , ColItem";
}
#line 2330 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1308 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.exprList) = new KDbNArgExpression(KDb::FieldListExpression, KDbToken());
    (yyval.exprList)->append(*(yyvsp[0].expr));
    delete (yyvsp[0].expr);
    kdbDebug() << "ColViews: ColItem";
}
#line 2341 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1318 "KDbSqlParser.y" /* yacc.c:1646  */
    {
//    $$ = new KDbField();
//    dummy->addField($$);
//    $$->setExpression( $1 );
//    globalParser->query()->addField($$);
    (yyval.expr) = (yyvsp[0].expr);
    kdbDebug() << " added column expr:" << *(yyvsp[0].expr);
}
#line 2354 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1327 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr);
    kdbDebug() << " added column wildcard:" << *(yyvsp[0].expr);
}
#line 2363 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1332 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(
        *(yyvsp[-2].expr), KDbToken::AS,
        KDbVariableExpression(*(yyvsp[0].stringValue))
    );
    kdbDebug() << " added column expr:" << *(yyval.expr);
    delete (yyvsp[-2].expr);
    delete (yyvsp[0].stringValue);
}
#line 2377 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1342 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbBinaryExpression(
        *(yyvsp[-1].expr), KDbToken::AS_EMPTY,
        KDbVariableExpression(*(yyvsp[0].stringValue))
    );
    kdbDebug() << " added column expr:" << *(yyval.expr);
    delete (yyvsp[-1].expr);
    delete (yyvsp[0].stringValue);
}
#line 2391 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1355 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[0].expr);
}
#line 2399 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1401 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = (yyvsp[-1].expr);
//! @todo DISTINCT '(' ColExpression ')'
//    $$->setName("DISTINCT(" + $3->name() + ")");
}
#line 2409 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1410 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    (yyval.expr) = new KDbVariableExpression(QLatin1String("*"));
    kdbDebug() << "all columns";

//    KDbQueryAsterisk *ast = new KDbQueryAsterisk(globalParser->query(), dummy);
//    globalParser->query()->addAsterisk(ast);
//    requiresTable = true;
}
#line 2422 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1419 "KDbSqlParser.y" /* yacc.c:1646  */
    {
    QString s( *(yyvsp[-2].stringValue) );
    s += QLatin1String(".*");
    (yyval.expr) = new KDbVariableExpression(s);
    kdbDebug() << "  + all columns from " << s;
    delete (yyvsp[-2].stringValue);
}
#line 2434 "KDbSqlParser.cpp" /* yacc.c:1646  */
    break;


#line 2438 "KDbSqlParser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
#line 1434 "KDbSqlParser.y" /* yacc.c:1906  */


KDB_TESTING_EXPORT const char* g_tokenName(unsigned int offset) {
    const int t = YYTRANSLATE(offset);
    if (t >= YYTRANSLATE(::SQL_TYPE)) {
        return yytname[t];
    }
    return 0;
}

//static
const int KDbToken::maxCharTokenValue = 253;

//static
const int KDbToken::maxTokenValue = YYMAXUTOK;
