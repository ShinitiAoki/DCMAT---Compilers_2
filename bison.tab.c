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
#line 2 "bison.y"

	#include <stdbool.h>
	#include <stdio.h>
	#include "hashtable.h"
	#include <math.h>
	#include "matriz.h"
	#define MAX_LINE_SIZE 10000
	#define max(a,b) (a) > (b) ? (a) : (b)

	int quit = 0;
	extern int yylex();
	extern int lexical_error;
	extern char *yytext;
	void input_scanner(char *input);
	void empty_buffer();

	char buffer[MAX_LINE_SIZE];
	char* in_buffer =NULL;
	int in_size;
	float** matrix;
	Matriz* sampleText = NULL;
	varTypes* lastInserted = NULL;
	Hashtable* hashtable = NULL;
	
	float h_view_lo = -6.500000;
	float h_view_hi = 6.500000;
	float v_view_lo = -3.500000;
	float v_view_hi = 3.500000;
	int float_precision = 6;
	int integral_steps = 1000;

	bool draw_axis = true;
	bool erase_plots = true;
	bool draw_connected_dots = false;

	int m_lines = 0;
	int m_columns = 0;
	int max_lines = 0;
	int max_columns = 0;

	void yyerror(void *s){
		if(lexical_error){
			printf("Invalid Symbol: %s\n", yytext);
			lexical_error = 0;
		}
		else if(strcmp(yytext, "\n") == 0){
			printf("Syntax Error: Incomplete Command\n");
		}
		else{
			printf("Syntax Error: [%s]\n", yytext);
		}
	};
	void MatrizMaxBoundary(){
		printf("ERROR: Matrix limits out of boundaries.\n");
	}
	
	void show_Settings(){
		printf("h_view_lo: %.*f\n", float_precision, h_view_lo);
		printf("h_view_hi: %.*f\n", float_precision, h_view_hi);
		printf("v_view_lo: %.*f\n", float_precision, v_view_lo);
		printf("v_view_hi: %.*f\n", float_precision, v_view_hi);
		printf("float_precision: %d\n", float_precision);
		printf("integral_steps: %d\n", integral_steps);

		printf("Draw Axis: %s\n", draw_axis ? "ON" : "OFF");
		printf("Erase Plots: %s\n", erase_plots ? "ON" : "OFF");
		printf("Connect Dots: %s\n", draw_connected_dots ? "ON" : "OFF");

	}
	void reset_settings(){
		h_view_lo = -6.500000;
		h_view_hi = 6.500000;
		v_view_lo = -3.500000;
		v_view_hi = 3.500000;
		float_precision = 6;
		integral_steps = 1000;
		draw_axis = true;
		erase_plots = true;
		draw_connected_dots = false;
	}
	

#line 154 "bison.tab.c"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EOL = 3,                        /* EOL  */
  YYSYMBOL_ADD = 4,                        /* ADD  */
  YYSYMBOL_SUB = 5,                        /* SUB  */
  YYSYMBOL_MULT = 6,                       /* MULT  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_EXP = 9,                        /* EXP  */
  YYSYMBOL_L_BRACKET = 10,                 /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 11,                 /* R_BRACKET  */
  YYSYMBOL_INTERVAL = 12,                  /* INTERVAL  */
  YYSYMBOL_EQUALS = 13,                    /* EQUALS  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_L_S_BRACKET = 15,               /* L_S_BRACKET  */
  YYSYMBOL_R_S_BRACKET = 16,               /* R_S_BRACKET  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_PI = 20,                        /* PI  */
  YYSYMBOL_EULER = 21,                     /* EULER  */
  YYSYMBOL_NUM_FLOAT = 22,                 /* NUM_FLOAT  */
  YYSYMBOL_NUM_INT = 23,                   /* NUM_INT  */
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_ABOUT = 25,                     /* ABOUT  */
  YYSYMBOL_ABS = 26,                       /* ABS  */
  YYSYMBOL_AXIS = 27,                      /* AXIS  */
  YYSYMBOL_CONNECTED_DOTS = 28,            /* CONNECTED_DOTS  */
  YYSYMBOL_COS = 29,                       /* COS  */
  YYSYMBOL_DETERMINANT = 30,               /* DETERMINANT  */
  YYSYMBOL_ERASE = 31,                     /* ERASE  */
  YYSYMBOL_FLOAT = 32,                     /* FLOAT  */
  YYSYMBOL_H_VIEW = 33,                    /* H_VIEW  */
  YYSYMBOL_INTEGRAL_STEPS = 34,            /* INTEGRAL_STEPS  */
  YYSYMBOL_INTEGRATE = 35,                 /* INTEGRATE  */
  YYSYMBOL_LINEAR_SYSTEM = 36,             /* LINEAR_SYSTEM  */
  YYSYMBOL_MATRIX = 37,                    /* MATRIX  */
  YYSYMBOL_OFF = 38,                       /* OFF  */
  YYSYMBOL_ON = 39,                        /* ON  */
  YYSYMBOL_PLOT = 40,                      /* PLOT  */
  YYSYMBOL_PRECISION = 41,                 /* PRECISION  */
  YYSYMBOL_QUIT = 42,                      /* QUIT  */
  YYSYMBOL_RESET = 43,                     /* RESET  */
  YYSYMBOL_RPN = 44,                       /* RPN  */
  YYSYMBOL_SEN = 45,                       /* SEN  */
  YYSYMBOL_SET = 46,                       /* SET  */
  YYSYMBOL_SETTINGS = 47,                  /* SETTINGS  */
  YYSYMBOL_SHOW = 48,                      /* SHOW  */
  YYSYMBOL_SOLVE = 49,                     /* SOLVE  */
  YYSYMBOL_SUM = 50,                       /* SUM  */
  YYSYMBOL_SYMBOLS = 51,                   /* SYMBOLS  */
  YYSYMBOL_TAN = 52,                       /* TAN  */
  YYSYMBOL_V_VIEW = 53,                    /* V_VIEW  */
  YYSYMBOL_X = 54,                         /* X  */
  YYSYMBOL_UNKNOW = 55,                    /* UNKNOW  */
  YYSYMBOL_END_OF_FILE = 56,               /* END_OF_FILE  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_begin = 58,                     /* begin  */
  YYSYMBOL_input = 59,                     /* input  */
  YYSYMBOL_functions = 60,                 /* functions  */
  YYSYMBOL_show_options = 61,              /* show_options  */
  YYSYMBOL_solve_matrices = 62,            /* solve_matrices  */
  YYSYMBOL_reset_settings = 63,            /* reset_settings  */
  YYSYMBOL_setters = 64,                   /* setters  */
  YYSYMBOL_set_h_view = 65,                /* set_h_view  */
  YYSYMBOL_set_v_view = 66,                /* set_v_view  */
  YYSYMBOL_number_handlers = 67,           /* number_handlers  */
  YYSYMBOL_plot_options = 68,              /* plot_options  */
  YYSYMBOL_set_axis = 69,                  /* set_axis  */
  YYSYMBOL_set_erase_plot = 70,            /* set_erase_plot  */
  YYSYMBOL_assign_to = 71,                 /* assign_to  */
  YYSYMBOL_expresao_mat = 72,              /* expresao_mat  */
  YYSYMBOL_fator = 73,                     /* fator  */
  YYSYMBOL_expoente = 74,                  /* expoente  */
  YYSYMBOL_termo = 75,                     /* termo  */
  YYSYMBOL_vector = 76,                    /* vector  */
  YYSYMBOL_numSequence = 77,               /* numSequence  */
  YYSYMBOL_vecSequence = 78,               /* vecSequence  */
  YYSYMBOL_testMatrix = 79                 /* testMatrix  */
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   173,   173,   174,   175,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   190,   191,   192,
     194,   195,   196,   198,   199,   201,   203,   204,   205,   206,
     207,   208,   210,   217,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   238,   239,   241,
     242,   244,   245,   248,   249,   250,   253,   254,   255,   257,
     258,   259,   260,   262,   263,   265,   266,   267,   268,   269,
     270,   274,   280,   281,   283,   284,   286
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
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "ADD", "SUB",
  "MULT", "DIV", "MOD", "EXP", "L_BRACKET", "R_BRACKET", "INTERVAL",
  "EQUALS", "ASSIGN", "L_S_BRACKET", "R_S_BRACKET", "SEMICOLON", "COLON",
  "COMMA", "PI", "EULER", "NUM_FLOAT", "NUM_INT", "IDENTIFIER", "ABOUT",
  "ABS", "AXIS", "CONNECTED_DOTS", "COS", "DETERMINANT", "ERASE", "FLOAT",
  "H_VIEW", "INTEGRAL_STEPS", "INTEGRATE", "LINEAR_SYSTEM", "MATRIX",
  "OFF", "ON", "PLOT", "PRECISION", "QUIT", "RESET", "RPN", "SEN", "SET",
  "SETTINGS", "SHOW", "SOLVE", "SUM", "SYMBOLS", "TAN", "V_VIEW", "X",
  "UNKNOW", "END_OF_FILE", "$accept", "begin", "input", "functions",
  "show_options", "solve_matrices", "reset_settings", "setters",
  "set_h_view", "set_v_view", "number_handlers", "plot_options",
  "set_axis", "set_erase_plot", "assign_to", "expresao_mat", "fator",
  "expoente", "termo", "vector", "numSequence", "vecSequence",
  "testMatrix", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,    16,   105,   114,   -45,   -45,   -45,   -45,    26,   -45,
      -4,    18,   -45,    17,    38,   -45,     6,   -45,    51,    24,
     -10,   -27,   -45,    83,   -45,    82,    79,   -45,   -45,   -45,
     -45,   117,   124,    93,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,     3,     0,   114,   114,    84,   114,   -45,
     -45,   114,    36,    64,    69,    12,    12,    12,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   114,   -45,   111,   -45,   114,
     114,   114,   114,   114,   114,   -45,   101,   106,   -45,    60,
     -45,   122,    14,   -45,    65,    86,   -45,   -45,   -45,    40,
     116,   -45,   129,   -45,   -45,   130,    90,   -45,   124,   124,
      93,    93,    93,   -45,    12,   -45,    31,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,    12,    12,   -45,   -45,    43,
     -45,   101,   -45,   -45,   -45,    12,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,    40,    42,    34,    37,    44,    15,
       0,     0,    17,     0,    47,    16,     0,    18,     0,     0,
       0,     0,    19,     0,    46,     0,     0,     6,    10,     8,
      65,     0,    56,    59,    63,    35,    38,    41,    43,    36,
      39,    45,    44,     0,     0,     0,     0,     0,     0,    14,
      25,     0,     0,     0,     0,     0,     0,     0,    11,    22,
      21,    20,     9,    24,    23,     0,     1,     0,     4,     0,
       0,     0,     0,     0,     0,    67,     0,    65,    13,    55,
      54,     0,     0,     7,     0,     0,    50,    49,    26,     0,
       0,    29,     0,    28,    30,     0,     0,     3,    57,    58,
      60,    61,    62,    64,     0,    74,     0,    66,    68,    48,
      69,    52,    51,    27,    31,     0,     0,    70,    72,     0,
      76,     0,    32,    33,    71,     0,    75,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -44,   -45,   -45,   -45,   -45,    -2,    72,    73,   -43,    28,
     -45,   -45,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    25,    26,    27,    62,    28,    29,    58,    91,    94,
      30,    49,    88,   113,    78,    31,    32,    33,    34,   105,
     119,   106,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      77,    43,    81,    63,     1,     2,    45,    69,    70,    64,
       3,    92,    93,    95,    75,    76,     1,     2,    69,    70,
       4,     5,     6,     7,    42,   108,    10,    59,    46,    11,
      47,   103,     4,     5,     6,     7,    42,    60,    35,    36,
      44,    61,    79,   -12,    82,    18,    84,   120,    48,    85,
     121,    52,    23,    50,    24,    53,    54,    55,    56,   124,
     118,    51,   125,    96,    69,    70,    24,     1,     2,    69,
      70,   122,   123,     3,    86,    87,   109,    57,   111,   112,
      -5,   127,    66,     4,     5,     6,     7,     8,     9,    10,
      69,    70,    11,    65,    69,    70,    67,   110,    12,    76,
      13,   117,    74,    14,    89,    15,    16,    17,    18,    19,
      90,    20,    21,    22,    97,    23,   104,    24,     1,     2,
      68,    69,    70,   -53,     3,    37,    38,    39,    40,    41,
      71,    72,    73,   107,     4,     5,     6,     7,    42,   114,
      10,    98,    99,    11,   100,   101,   102,   115,   116,   126,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,    23,     0,    24
};

static const yytype_int8 yycheck[] =
{
      44,     3,    45,    30,     4,     5,    10,     4,     5,    36,
      10,    55,    56,    57,    11,    15,     4,     5,     4,     5,
      20,    21,    22,    23,    24,    11,    26,    37,    10,    29,
      13,    74,    20,    21,    22,    23,    24,    47,    22,    23,
      14,    51,    44,    17,    46,    45,    48,    16,    10,    51,
      19,    27,    52,    47,    54,    31,    32,    33,    34,    16,
     104,    10,    19,    65,     4,     5,    54,     4,     5,     4,
       5,   115,   116,    10,    38,    39,    11,    53,    38,    39,
      17,   125,     0,    20,    21,    22,    23,    24,    25,    26,
       4,     5,    29,    10,     4,     5,    17,    11,    35,    15,
      37,    11,     9,    40,    40,    42,    43,    44,    45,    46,
      41,    48,    49,    50,     3,    52,    15,    54,     4,     5,
       3,     4,     5,    17,    10,    20,    21,    22,    23,    24,
       6,     7,     8,    11,    20,    21,    22,    23,    24,    23,
      26,    69,    70,    29,    71,    72,    73,    18,    18,   121,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    10,    20,    21,    22,    23,    24,    25,
      26,    29,    35,    37,    40,    42,    43,    44,    45,    46,
      48,    49,    50,    52,    54,    58,    59,    60,    62,    63,
      67,    72,    73,    74,    75,    22,    23,    20,    21,    22,
      23,    24,    24,    72,    14,    10,    10,    13,    10,    68,
      47,    10,    27,    31,    32,    33,    34,    53,    64,    37,
      47,    51,    61,    30,    36,    10,     0,    17,     3,     4,
       5,     6,     7,     8,     9,    11,    15,    67,    71,    72,
      79,    75,    72,    79,    72,    72,    38,    39,    69,    40,
      41,    65,    67,    67,    66,    67,    72,     3,    73,    73,
      74,    74,    74,    75,    15,    76,    78,    11,    11,    11,
      11,    38,    39,    70,    23,    18,    18,    11,    67,    77,
      16,    19,    67,    67,    16,    19,    76,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      64,    64,    65,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    77,    77,    78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     1,     3,     1,     2,
       1,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     2,     2,
       2,     3,     3,     3,     1,     2,     2,     1,     2,     2,
       1,     2,     1,     2,     1,     2,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     4,     3,     4,     4,
       4,     3,     1,     3,     1,     3,     3
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
  case 3: /* begin: input SEMICOLON EOL  */
#line 174 "bison.y"
                             { return 0;}
#line 1317 "bison.tab.c"
    break;

  case 4: /* begin: expresao_mat EOL  */
#line 175 "bison.y"
                           { printVarTypes((yyvsp[-1].varTypes), float_precision); return 0;}
#line 1323 "bison.tab.c"
    break;

  case 6: /* input: functions  */
#line 178 "bison.y"
                            {printf("finished functions\n");}
#line 1329 "bison.tab.c"
    break;

  case 7: /* input: MATRIX EQUALS testMatrix  */
#line 179 "bison.y"
                                           { lastInserted = (yyvsp[0].varTypes); printf("finished matrix rule\n");}
#line 1335 "bison.tab.c"
    break;

  case 8: /* input: reset_settings  */
#line 180 "bison.y"
                                 {printf(" finished reset settings rule\n");}
#line 1341 "bison.tab.c"
    break;

  case 9: /* input: SHOW show_options  */
#line 181 "bison.y"
                                    {printf("finished show rule\n");}
#line 1347 "bison.tab.c"
    break;

  case 10: /* input: solve_matrices  */
#line 182 "bison.y"
                                 { printf("finished solve matrices rule\n");}
#line 1353 "bison.tab.c"
    break;

  case 11: /* input: SET setters  */
#line 183 "bison.y"
                              {printf(" finished set rule\n");}
#line 1359 "bison.tab.c"
    break;

  case 12: /* input: IDENTIFIER  */
#line 184 "bison.y"
                             { printIdentifier(search(hashtable,(yyvsp[0].sval)), float_precision, (yyvsp[0].sval)); }
#line 1365 "bison.tab.c"
    break;

  case 13: /* input: IDENTIFIER ASSIGN assign_to  */
#line 185 "bison.y"
                                              { insert_update(hashtable, (yyvsp[-2].sval), (yyvsp[0].varTypes)); printf("finished assign\n");}
#line 1371 "bison.tab.c"
    break;

  case 14: /* input: PLOT plot_options  */
#line 186 "bison.y"
                                    { printf("finished plot\n");}
#line 1377 "bison.tab.c"
    break;

  case 15: /* input: ABOUT  */
#line 187 "bison.y"
                        {printf("finished about\n");}
#line 1383 "bison.tab.c"
    break;

  case 16: /* input: QUIT  */
#line 188 "bison.y"
                       {quit = 1; return 0;}
#line 1389 "bison.tab.c"
    break;

  case 17: /* functions: INTEGRATE  */
#line 190 "bison.y"
                     {printf("finished integrate\n");}
#line 1395 "bison.tab.c"
    break;

  case 18: /* functions: RPN  */
#line 191 "bison.y"
                      {printf("finished rpn\n");}
#line 1401 "bison.tab.c"
    break;

  case 19: /* functions: SUM  */
#line 192 "bison.y"
                      {printf("finished sum\n");}
#line 1407 "bison.tab.c"
    break;

  case 20: /* show_options: SYMBOLS  */
#line 194 "bison.y"
                      { showSymbols(hashtable); }
#line 1413 "bison.tab.c"
    break;

  case 21: /* show_options: SETTINGS  */
#line 195 "bison.y"
                           {printf("\n"); show_Settings();}
#line 1419 "bison.tab.c"
    break;

  case 22: /* show_options: MATRIX  */
#line 196 "bison.y"
                         { if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;} printFormatted(getMatriz(lastInserted), float_precision);}
#line 1425 "bison.tab.c"
    break;

  case 23: /* solve_matrices: SOLVE LINEAR_SYSTEM  */
#line 198 "bison.y"
                                    {if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;}if(!linearsysFormat(getMatriz(lastInserted))){printf("Matrix format incorrect!\n");return 0;} printLinearSystemSolution(LinearSystem(getMatriz(lastInserted)), float_precision);}
#line 1431 "bison.tab.c"
    break;

  case 24: /* solve_matrices: SOLVE DETERMINANT  */
#line 199 "bison.y"
                                   { if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;}if(!isSquare(getMatriz(lastInserted))){printf("Matrix format incorrect!\n"); return 0;} ;printf("%.*f\n", float_precision, determinant(getMatriz(lastInserted), getMatLines(getMatriz(lastInserted))));}
#line 1437 "bison.tab.c"
    break;

  case 25: /* reset_settings: RESET SETTINGS  */
#line 201 "bison.y"
                               { reset_settings(); }
#line 1443 "bison.tab.c"
    break;

  case 26: /* setters: AXIS set_axis  */
#line 203 "bison.y"
                       {printf("finished axis\n");}
#line 1449 "bison.tab.c"
    break;

  case 27: /* setters: ERASE PLOT set_erase_plot  */
#line 204 "bison.y"
                                            {printf("finished erase plot\n");}
#line 1455 "bison.tab.c"
    break;

  case 28: /* setters: INTEGRAL_STEPS number_handlers  */
#line 205 "bison.y"
                                                 { if(*getFloat((yyvsp[0].varTypes)) <= 0){printf("integral_steps must be a positive non-zero integer\n"); return 0;} integral_steps = *getFloat((yyvsp[0].varTypes));}
#line 1461 "bison.tab.c"
    break;

  case 29: /* setters: H_VIEW set_h_view  */
#line 206 "bison.y"
                                    {printf("finished h_view\n");}
#line 1467 "bison.tab.c"
    break;

  case 30: /* setters: V_VIEW set_v_view  */
#line 207 "bison.y"
                                    {printf("finished v_view\n");}
#line 1473 "bison.tab.c"
    break;

  case 31: /* setters: FLOAT PRECISION NUM_INT  */
#line 208 "bison.y"
                                          { if((yyvsp[0].ival) < 0 || (yyvsp[0].ival) > 8){printf("ERROR: float precision must be from 0 to 8\n"); return 0;} float_precision = (yyvsp[0].ival);}
#line 1479 "bison.tab.c"
    break;

  case 32: /* set_h_view: number_handlers COLON number_handlers  */
#line 210 "bison.y"
                                                  { 
										if(*getFloat((yyvsp[-2].varTypes)) >= *getFloat((yyvsp[0].varTypes))){printf("ERROR: h_view_lo must be smaller than h_view_hi\n"); return 0;}
										h_view_lo = *getFloat((yyvsp[-2].varTypes));
										h_view_hi = *getFloat((yyvsp[0].varTypes));
										("h_view set!\n");
										}
#line 1490 "bison.tab.c"
    break;

  case 33: /* set_v_view: number_handlers COLON number_handlers  */
#line 217 "bison.y"
                                                  {
										if(*getFloat((yyvsp[-2].varTypes)) >= *getFloat((yyvsp[0].varTypes))){printf("ERROR: v_view_lo must be smaller than v_view_hi\n"); return 0;}
										v_view_lo = *getFloat((yyvsp[-2].varTypes));
										v_view_hi = *getFloat((yyvsp[0].varTypes));
										printf("v_view set!\n");
}
#line 1501 "bison.tab.c"
    break;

  case 34: /* number_handlers: NUM_FLOAT  */
#line 224 "bison.y"
                           { float* wrapper= malloc(sizeof(float)); *wrapper= (yyvsp[0].fval); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1507 "bison.tab.c"
    break;

  case 35: /* number_handlers: ADD NUM_FLOAT  */
#line 225 "bison.y"
                                { float* wrapper= malloc(sizeof(float)); *wrapper= (yyvsp[0].fval); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1513 "bison.tab.c"
    break;

  case 36: /* number_handlers: SUB NUM_FLOAT  */
#line 226 "bison.y"
                                { float* wrapper= malloc(sizeof(float)); *wrapper= -(yyvsp[0].fval); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1519 "bison.tab.c"
    break;

  case 37: /* number_handlers: NUM_INT  */
#line 227 "bison.y"
                          { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(yyvsp[0].ival); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1525 "bison.tab.c"
    break;

  case 38: /* number_handlers: ADD NUM_INT  */
#line 228 "bison.y"
                              { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(yyvsp[0].ival); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1531 "bison.tab.c"
    break;

  case 39: /* number_handlers: SUB NUM_INT  */
#line 229 "bison.y"
                              { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(-(yyvsp[0].ival)); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1537 "bison.tab.c"
    break;

  case 40: /* number_handlers: PI  */
#line 230 "bison.y"
                     { float* wrapper = malloc(sizeof(float)); *wrapper = 3.14159265; varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value;}
#line 1543 "bison.tab.c"
    break;

  case 41: /* number_handlers: SUB PI  */
#line 231 "bison.y"
                         { float* wrapper = malloc(sizeof(float)); *wrapper = -3.14159265; varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1549 "bison.tab.c"
    break;

  case 42: /* number_handlers: EULER  */
#line 232 "bison.y"
                        { float* wrapper = malloc(sizeof(float)); *wrapper = 2.71828182; varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1555 "bison.tab.c"
    break;

  case 43: /* number_handlers: SUB EULER  */
#line 233 "bison.y"
                            { float* wrapper = malloc(sizeof(float)); *wrapper = -2.71828182; varTypes* value = createVarTypes(1, wrapper); (yyval.varTypes) = value; }
#line 1561 "bison.tab.c"
    break;

  case 44: /* number_handlers: IDENTIFIER  */
#line 234 "bison.y"
                             { if(search(hashtable,(yyvsp[0].sval)) == NULL){printf("Undefined Symbol [%s]\n", (yyvsp[0].sval)); return 0;} else{ (yyval.varTypes) = search(hashtable,(yyvsp[0].sval));}; }
#line 1567 "bison.tab.c"
    break;

  case 45: /* number_handlers: SUB IDENTIFIER  */
#line 235 "bison.y"
                                 { varTypes* value = search(hashtable,(yyvsp[0].sval)); (yyval.varTypes) = Vneg(value); }
#line 1573 "bison.tab.c"
    break;

  case 46: /* number_handlers: X  */
#line 236 "bison.y"
                    { printf("X value\n"); (yyval.varTypes) == NULL;}
#line 1579 "bison.tab.c"
    break;

  case 47: /* plot_options: %empty  */
#line 238 "bison.y"
               {printf("finished plot\n");}
#line 1585 "bison.tab.c"
    break;

  case 48: /* plot_options: L_BRACKET expresao_mat R_BRACKET  */
#line 239 "bison.y"
                                                           {printf("finished plot w/ exp\n");}
#line 1591 "bison.tab.c"
    break;

  case 49: /* set_axis: ON  */
#line 241 "bison.y"
             { draw_axis=true;}
#line 1597 "bison.tab.c"
    break;

  case 50: /* set_axis: OFF  */
#line 242 "bison.y"
                      { draw_axis=false; }
#line 1603 "bison.tab.c"
    break;

  case 51: /* set_erase_plot: ON  */
#line 244 "bison.y"
                   { erase_plots=true;}
#line 1609 "bison.tab.c"
    break;

  case 52: /* set_erase_plot: OFF  */
#line 245 "bison.y"
                              { erase_plots=false; }
#line 1615 "bison.tab.c"
    break;

  case 53: /* assign_to: number_handlers  */
#line 248 "bison.y"
                           { (yyval.varTypes) = (yyvsp[0].varTypes);}
#line 1621 "bison.tab.c"
    break;

  case 54: /* assign_to: testMatrix  */
#line 249 "bison.y"
                             {printf("matrix assigned!\n"); (yyval.varTypes) = (yyvsp[0].varTypes);}
#line 1627 "bison.tab.c"
    break;

  case 55: /* assign_to: expresao_mat  */
#line 250 "bison.y"
                              {printf("expression assigned!\n"); (yyval.varTypes) = (yyvsp[0].varTypes);}
#line 1633 "bison.tab.c"
    break;

  case 56: /* expresao_mat: fator  */
#line 253 "bison.y"
                    { (yyval.varTypes)=(yyvsp[0].varTypes); }
#line 1639 "bison.tab.c"
    break;

  case 57: /* expresao_mat: expresao_mat ADD fator  */
#line 254 "bison.y"
                                         { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = Vsum(val1,val2); }
#line 1645 "bison.tab.c"
    break;

  case 58: /* expresao_mat: expresao_mat SUB fator  */
#line 255 "bison.y"
                                         { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = Vsub(val1,val2); }
#line 1651 "bison.tab.c"
    break;

  case 59: /* fator: expoente  */
#line 257 "bison.y"
                { (yyval.varTypes) = (yyvsp[0].varTypes); }
#line 1657 "bison.tab.c"
    break;

  case 60: /* fator: fator MULT expoente  */
#line 258 "bison.y"
                                      { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = mult(val1,val2); }
#line 1663 "bison.tab.c"
    break;

  case 61: /* fator: fator DIV expoente  */
#line 259 "bison.y"
                                     { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = divi(val1,val2); }
#line 1669 "bison.tab.c"
    break;

  case 62: /* fator: fator MOD expoente  */
#line 260 "bison.y"
                                     { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = modules(val1,val2); }
#line 1675 "bison.tab.c"
    break;

  case 63: /* expoente: termo  */
#line 262 "bison.y"
                { (yyval.varTypes) = (yyvsp[0].varTypes); }
#line 1681 "bison.tab.c"
    break;

  case 64: /* expoente: expoente EXP termo  */
#line 263 "bison.y"
                                    { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = powe(val1,val2); }
#line 1687 "bison.tab.c"
    break;

  case 65: /* termo: number_handlers  */
#line 265 "bison.y"
                       { (yyval.varTypes) = (yyvsp[0].varTypes); }
#line 1693 "bison.tab.c"
    break;

  case 66: /* termo: ABS L_BRACKET termo R_BRACKET  */
#line 266 "bison.y"
                                                { (yyval.varTypes) = Vabs((yyvsp[-1].varTypes)); }
#line 1699 "bison.tab.c"
    break;

  case 67: /* termo: L_BRACKET expresao_mat R_BRACKET  */
#line 267 "bison.y"
                                                   { (yyval.varTypes) = (yyvsp[-1].varTypes); }
#line 1705 "bison.tab.c"
    break;

  case 68: /* termo: COS L_BRACKET expresao_mat R_BRACKET  */
#line 268 "bison.y"
                                                       { (yyval.varTypes) = Vcos((yyvsp[-1].varTypes)); }
#line 1711 "bison.tab.c"
    break;

  case 69: /* termo: SEN L_BRACKET expresao_mat R_BRACKET  */
#line 269 "bison.y"
                                                       { (yyval.varTypes) = Vsin((yyvsp[-1].varTypes)); }
#line 1717 "bison.tab.c"
    break;

  case 70: /* termo: TAN L_BRACKET expresao_mat R_BRACKET  */
#line 270 "bison.y"
                                                       { (yyval.varTypes) = Vtan((yyvsp[-1].varTypes)); }
#line 1723 "bison.tab.c"
    break;

  case 71: /* vector: L_S_BRACKET numSequence R_S_BRACKET  */
#line 274 "bison.y"
                                            {   m_lines++;
												max_columns = max(max_columns,m_columns);
												max_lines = m_lines;
												m_columns=0;
											}
#line 1733 "bison.tab.c"
    break;

  case 72: /* numSequence: number_handlers  */
#line 280 "bison.y"
                             { matrix[m_lines][m_columns] = *getFloat((yyvsp[0].varTypes)); m_columns++; }
#line 1739 "bison.tab.c"
    break;

  case 73: /* numSequence: numSequence COMMA number_handlers  */
#line 281 "bison.y"
                                                    { matrix[m_lines][m_columns] = *getFloat((yyvsp[0].varTypes)); m_columns++;}
#line 1745 "bison.tab.c"
    break;

  case 74: /* vecSequence: vector  */
#line 283 "bison.y"
                    {  }
#line 1751 "bison.tab.c"
    break;

  case 75: /* vecSequence: vecSequence COMMA vector  */
#line 284 "bison.y"
                                           { }
#line 1757 "bison.tab.c"
    break;

  case 76: /* testMatrix: L_S_BRACKET vecSequence R_S_BRACKET  */
#line 286 "bison.y"
                                                { varTypes* dummy; if(max_lines>10||max_columns>10){MatrizMaxBoundary(); return 0;} sampleText = createMatriz(matrix,max_lines,max_columns); dummy = createVarTypes(2,sampleText); (yyval.varTypes) = dummy;}
#line 1763 "bison.tab.c"
    break;


#line 1767 "bison.tab.c"

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

#line 288 "bison.y"


int main(int argc, char **argv){
	matrix = (float**)malloc(20*sizeof(float*));
	for(int i = 0; i < 20; i++){
		matrix[i] = (float*)malloc(20*sizeof(float));
	}
	hashtable = createHashtable();
	while(!quit){
		m_lines = 0;
		m_columns = 0;
		max_columns = 0;
		max_lines = 0;
		setZero(matrix,20,20);
		printf(">");

		if(fgets(buffer, MAX_LINE_SIZE, stdin) == NULL){
			break;
		}

		input_scanner(buffer);
		yyparse();
		empty_buffer();
	}
	printf("Bye!\n");
	printHashtable(hashtable, float_precision);
	freeHashtable(hashtable);

	return 0;
}
