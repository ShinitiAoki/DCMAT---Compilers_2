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
  YYSYMBOL_UADD = 10,                      /* UADD  */
  YYSYMBOL_USUB = 11,                      /* USUB  */
  YYSYMBOL_L_BRACKET = 12,                 /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 13,                 /* R_BRACKET  */
  YYSYMBOL_INTERVAL = 14,                  /* INTERVAL  */
  YYSYMBOL_EQUALS = 15,                    /* EQUALS  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_L_S_BRACKET = 17,               /* L_S_BRACKET  */
  YYSYMBOL_R_S_BRACKET = 18,               /* R_S_BRACKET  */
  YYSYMBOL_SEMICOLON = 19,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 20,                     /* COLON  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_PI = 22,                        /* PI  */
  YYSYMBOL_EULER = 23,                     /* EULER  */
  YYSYMBOL_NUM_FLOAT = 24,                 /* NUM_FLOAT  */
  YYSYMBOL_NUM_INT = 25,                   /* NUM_INT  */
  YYSYMBOL_IDENTIFIER = 26,                /* IDENTIFIER  */
  YYSYMBOL_ABOUT = 27,                     /* ABOUT  */
  YYSYMBOL_ABS = 28,                       /* ABS  */
  YYSYMBOL_AXIS = 29,                      /* AXIS  */
  YYSYMBOL_CONNECTED_DOTS = 30,            /* CONNECTED_DOTS  */
  YYSYMBOL_COS = 31,                       /* COS  */
  YYSYMBOL_DETERMINANT = 32,               /* DETERMINANT  */
  YYSYMBOL_E = 33,                         /* E  */
  YYSYMBOL_ERASE = 34,                     /* ERASE  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_H_VIEW = 36,                    /* H_VIEW  */
  YYSYMBOL_INTEGRAL_STEPS = 37,            /* INTEGRAL_STEPS  */
  YYSYMBOL_INTEGRATE = 38,                 /* INTEGRATE  */
  YYSYMBOL_LINEAR_SYSTEM = 39,             /* LINEAR_SYSTEM  */
  YYSYMBOL_MATRIX = 40,                    /* MATRIX  */
  YYSYMBOL_OFF = 41,                       /* OFF  */
  YYSYMBOL_ON = 42,                        /* ON  */
  YYSYMBOL_PLOT = 43,                      /* PLOT  */
  YYSYMBOL_PRECISION = 44,                 /* PRECISION  */
  YYSYMBOL_QUIT = 45,                      /* QUIT  */
  YYSYMBOL_RESET = 46,                     /* RESET  */
  YYSYMBOL_RPN = 47,                       /* RPN  */
  YYSYMBOL_SEN = 48,                       /* SEN  */
  YYSYMBOL_SET = 49,                       /* SET  */
  YYSYMBOL_SETTINGS = 50,                  /* SETTINGS  */
  YYSYMBOL_SHOW = 51,                      /* SHOW  */
  YYSYMBOL_SOLVE = 52,                     /* SOLVE  */
  YYSYMBOL_SUM = 53,                       /* SUM  */
  YYSYMBOL_SYMBOLS = 54,                   /* SYMBOLS  */
  YYSYMBOL_TAN = 55,                       /* TAN  */
  YYSYMBOL_V_VIEW = 56,                    /* V_VIEW  */
  YYSYMBOL_X = 57,                         /* X  */
  YYSYMBOL_UNKNOW = 58,                    /* UNKNOW  */
  YYSYMBOL_END_OF_FILE = 59,               /* END_OF_FILE  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_begin = 61,                     /* begin  */
  YYSYMBOL_input = 62,                     /* input  */
  YYSYMBOL_show_options = 63,              /* show_options  */
  YYSYMBOL_solve_matrices = 64,            /* solve_matrices  */
  YYSYMBOL_reset_settings = 65,            /* reset_settings  */
  YYSYMBOL_setters = 66,                   /* setters  */
  YYSYMBOL_set_h_view = 67,                /* set_h_view  */
  YYSYMBOL_set_v_view = 68,                /* set_v_view  */
  YYSYMBOL_number_handlers = 69,           /* number_handlers  */
  YYSYMBOL_plot_options = 70,              /* plot_options  */
  YYSYMBOL_set_axis = 71,                  /* set_axis  */
  YYSYMBOL_set_erase_plot = 72,            /* set_erase_plot  */
  YYSYMBOL_assign_to = 73,                 /* assign_to  */
  YYSYMBOL_expresao_mat = 74,              /* expresao_mat  */
  YYSYMBOL_fator = 75,                     /* fator  */
  YYSYMBOL_expoente = 76,                  /* expoente  */
  YYSYMBOL_termo = 77,                     /* termo  */
  YYSYMBOL_vector = 78,                    /* vector  */
  YYSYMBOL_numSequence = 79,               /* numSequence  */
  YYSYMBOL_vecSequence = 80,               /* vecSequence  */
  YYSYMBOL_testMatrix = 81                 /* testMatrix  */
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
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   179,   179,   180,   181,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   195,   196,   197,   199,
     200,   202,   204,   205,   206,   207,   208,   209,   211,   217,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   237,   238,   239,   240,   242,   243,   246,
     247,   248,   251,   252,   253,   255,   256,   257,   258,   260,
     261,   263,   264,   265,   266,   267,   268,   272,   278,   279,
     281,   282,   284
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
  "MULT", "DIV", "MOD", "EXP", "UADD", "USUB", "L_BRACKET", "R_BRACKET",
  "INTERVAL", "EQUALS", "ASSIGN", "L_S_BRACKET", "R_S_BRACKET",
  "SEMICOLON", "COLON", "COMMA", "PI", "EULER", "NUM_FLOAT", "NUM_INT",
  "IDENTIFIER", "ABOUT", "ABS", "AXIS", "CONNECTED_DOTS", "COS",
  "DETERMINANT", "E", "ERASE", "FLOAT", "H_VIEW", "INTEGRAL_STEPS",
  "INTEGRATE", "LINEAR_SYSTEM", "MATRIX", "OFF", "ON", "PLOT", "PRECISION",
  "QUIT", "RESET", "RPN", "SEN", "SET", "SETTINGS", "SHOW", "SOLVE", "SUM",
  "SYMBOLS", "TAN", "V_VIEW", "X", "UNKNOW", "END_OF_FILE", "$accept",
  "begin", "input", "show_options", "solve_matrices", "reset_settings",
  "setters", "set_h_view", "set_v_view", "number_handlers", "plot_options",
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

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -12,   106,    79,   -15,   -42,   -42,   -42,   -42,     7,
      -8,    -4,     3,    31,   -42,    -3,    49,    88,   -29,    20,
      54,   -42,    80,    77,   -42,   -42,   -42,   110,   131,   100,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
       2,    15,   -42,    14,    64,    79,    79,    94,    79,   -42,
     -42,    79,    33,    73,    74,    15,   101,    15,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,    79,   -42,   117,   -42,    79,
      79,    79,    79,    79,    79,   -42,   -42,    37,   -42,   -15,
     114,   -42,    89,   -42,   122,    60,   -42,    66,    93,   -42,
     -42,   -42,   104,   118,   -42,   129,   -42,   -42,   130,    95,
     -42,   131,   131,   100,   100,   100,   -42,   -42,    15,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,    15,    15,
     -42,   -42,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,    36,    38,    30,    33,    40,
       0,     0,     0,    43,    15,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    10,     8,    61,     0,    52,    55,
      59,     6,    31,    34,    37,    39,    32,    35,    41,    40,
       0,     0,    70,     0,     0,     0,     0,     0,     0,    14,
      21,     0,     0,     0,     0,     0,     0,     0,    11,    18,
      17,    16,     9,    20,    19,     0,     1,     0,     4,     0,
       0,     0,     0,     0,     0,    63,    68,     0,    72,     0,
      61,    13,    51,    50,     0,     0,     7,     0,     0,    46,
      45,    22,     0,     0,    25,     0,    24,    26,     0,     0,
       3,    53,    54,    56,    57,    58,    60,    67,     0,    71,
      62,    64,    44,    65,    48,    47,    23,    27,     0,     0,
      66,    69,    28,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -41,
     -42,   -42,   -42,   -42,    -2,    78,    69,   -40,    72,   -42,
     -42,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    22,    23,    62,    24,    25,    58,    94,    97,    26,
      49,    91,   116,    81,    27,    28,    29,    30,    42,    77,
      43,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      76,    40,    41,    80,    45,    84,    69,    70,    46,     1,
       2,    59,    32,    33,    95,    75,    98,     3,    47,     1,
       2,    60,     4,    44,    -5,    61,   -12,     5,     6,     7,
       8,     9,    78,    10,   106,    79,    11,     5,     6,     7,
       8,    39,    82,    48,    85,    12,    87,    50,    13,    88,
      14,    15,    63,    16,    17,   107,    18,    19,   108,    64,
      20,    51,    21,    99,    69,    70,    65,   121,     1,     2,
      69,    70,    21,   111,    89,    90,     3,   122,   123,   112,
      66,     4,    83,     1,     2,    86,     5,     6,     7,     8,
      39,     3,    10,    69,    70,    11,    67,    69,    70,    69,
      70,     5,     6,     7,     8,    39,   113,    10,   120,    74,
      11,     4,    16,    68,    69,    70,    92,    52,    93,    20,
     100,    21,    53,    54,    55,    56,    96,    16,    34,    35,
      36,    37,    38,   -49,    20,   110,    21,    71,    72,    73,
     103,   104,   105,   117,    57,   114,   115,   101,   102,   118,
     119,   109
};

static const yytype_int8 yycheck[] =
{
      41,     3,    17,    44,    12,    45,     4,     5,    12,     4,
       5,    40,    24,    25,    55,    13,    57,    12,    15,     4,
       5,    50,    17,    16,    19,    54,    19,    22,    23,    24,
      25,    26,    18,    28,    74,    21,    31,    22,    23,    24,
      25,    26,    44,    12,    46,    40,    48,    50,    43,    51,
      45,    46,    32,    48,    49,    18,    51,    52,    21,    39,
      55,    12,    57,    65,     4,     5,    12,   108,     4,     5,
       4,     5,    57,    13,    41,    42,    12,   118,   119,    13,
       0,    17,    44,     4,     5,    47,    22,    23,    24,    25,
      26,    12,    28,     4,     5,    31,    19,     4,     5,     4,
       5,    22,    23,    24,    25,    26,    13,    28,    13,     9,
      31,    17,    48,     3,     4,     5,    43,    29,    44,    55,
       3,    57,    34,    35,    36,    37,    25,    48,    22,    23,
      24,    25,    26,    19,    55,    13,    57,     6,     7,     8,
      71,    72,    73,    25,    56,    41,    42,    69,    70,    20,
      20,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    12,    17,    22,    23,    24,    25,    26,
      28,    31,    40,    43,    45,    46,    48,    49,    51,    52,
      55,    57,    61,    62,    64,    65,    69,    74,    75,    76,
      77,    81,    24,    25,    22,    23,    24,    25,    26,    26,
      74,    17,    78,    80,    16,    12,    12,    15,    12,    70,
      50,    12,    29,    34,    35,    36,    37,    56,    66,    40,
      50,    54,    63,    32,    39,    12,     0,    19,     3,     4,
       5,     6,     7,     8,     9,    13,    69,    79,    18,    21,
      69,    73,    74,    81,    77,    74,    81,    74,    74,    41,
      42,    71,    43,    44,    67,    69,    25,    68,    69,    74,
       3,    75,    75,    76,    76,    76,    77,    18,    21,    78,
      13,    13,    13,    13,    41,    42,    72,    25,    20,    20,
      13,    69,    69,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      64,    65,    66,    66,    66,    66,    66,    66,    67,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    78,    79,    79,
      80,    80,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     1,     3,     1,     2,
       1,     2,     1,     3,     2,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     2,     2,     2,     3,     3,     3,
       1,     2,     2,     1,     2,     2,     1,     2,     1,     2,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     4,     3,     4,     4,     4,     3,     1,     3,
       1,     3,     3
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
#line 180 "bison.y"
                             { return 0;}
#line 1317 "bison.tab.c"
    break;

  case 4: /* begin: expresao_mat EOL  */
#line 181 "bison.y"
                           { printVarTypes((yyvsp[-1].varTypes), float_precision); return 0;}
#line 1323 "bison.tab.c"
    break;

  case 6: /* input: testMatrix  */
#line 184 "bison.y"
                             { printf("finished matrix rule\n");}
#line 1329 "bison.tab.c"
    break;

  case 7: /* input: MATRIX EQUALS testMatrix  */
#line 185 "bison.y"
                                           { lastInserted = (yyvsp[0].varTypes); printf("finished matrix rule\n");}
#line 1335 "bison.tab.c"
    break;

  case 8: /* input: reset_settings  */
#line 186 "bison.y"
                                 {printf(" finished reset settings rule\n");}
#line 1341 "bison.tab.c"
    break;

  case 9: /* input: SHOW show_options  */
#line 187 "bison.y"
                                    {printf("finished show rule\n");}
#line 1347 "bison.tab.c"
    break;

  case 10: /* input: solve_matrices  */
#line 188 "bison.y"
                                 { printf("finished solve matrices rule\n");}
#line 1353 "bison.tab.c"
    break;

  case 11: /* input: SET setters  */
#line 189 "bison.y"
                              {printf(" finished set rule\n");}
#line 1359 "bison.tab.c"
    break;

  case 12: /* input: IDENTIFIER  */
#line 190 "bison.y"
                             { printIdentifier(search(hashtable,(yyvsp[0].sval)), float_precision, (yyvsp[0].sval)); }
#line 1365 "bison.tab.c"
    break;

  case 13: /* input: IDENTIFIER ASSIGN assign_to  */
#line 191 "bison.y"
                                              { insert_update(hashtable, (yyvsp[-2].sval), (yyvsp[0].varTypes)); printf("finished assign\n");}
#line 1371 "bison.tab.c"
    break;

  case 14: /* input: PLOT plot_options  */
#line 192 "bison.y"
                                    { printf("finished plot\n");}
#line 1377 "bison.tab.c"
    break;

  case 15: /* input: QUIT  */
#line 193 "bison.y"
                       {quit = 1; return 0;}
#line 1383 "bison.tab.c"
    break;

  case 16: /* show_options: SYMBOLS  */
#line 195 "bison.y"
                      { showSymbols(hashtable); }
#line 1389 "bison.tab.c"
    break;

  case 17: /* show_options: SETTINGS  */
#line 196 "bison.y"
                           {printf("\n"); show_Settings();}
#line 1395 "bison.tab.c"
    break;

  case 18: /* show_options: MATRIX  */
#line 197 "bison.y"
                         { if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;} printFormatted(getMatriz(lastInserted), float_precision);}
#line 1401 "bison.tab.c"
    break;

  case 19: /* solve_matrices: SOLVE LINEAR_SYSTEM  */
#line 199 "bison.y"
                                    {if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;} printLinearSystemSolution(LinearSystem(getMatriz(lastInserted)), float_precision);}
#line 1407 "bison.tab.c"
    break;

  case 20: /* solve_matrices: SOLVE DETERMINANT  */
#line 200 "bison.y"
                                   { if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;}if(!isSquare(getMatriz(lastInserted))){printf("Matrix format incorrect!\n"); return 0;} ;printf("%.*f\n", float_precision, determinant(getMatriz(lastInserted), getMatLines(getMatriz(lastInserted))));}
#line 1413 "bison.tab.c"
    break;

  case 21: /* reset_settings: RESET SETTINGS  */
#line 202 "bison.y"
                               { reset_settings(); }
#line 1419 "bison.tab.c"
    break;

  case 22: /* setters: AXIS set_axis  */
#line 204 "bison.y"
                       {printf("finished axis\n");}
#line 1425 "bison.tab.c"
    break;

  case 23: /* setters: ERASE PLOT set_erase_plot  */
#line 205 "bison.y"
                                            {printf("finished erase plot\n");}
#line 1431 "bison.tab.c"
    break;

  case 24: /* setters: INTEGRAL_STEPS NUM_INT  */
#line 206 "bison.y"
                                         {printf("finished integral steps\n");}
#line 1437 "bison.tab.c"
    break;

  case 25: /* setters: H_VIEW set_h_view  */
#line 207 "bison.y"
                                    {printf("finished h_view\n");}
#line 1443 "bison.tab.c"
    break;

  case 26: /* setters: V_VIEW set_v_view  */
#line 208 "bison.y"
                                    {printf("finished v_view\n");}
#line 1449 "bison.tab.c"
    break;

  case 27: /* setters: FLOAT PRECISION NUM_INT  */
#line 209 "bison.y"
                                          { if((yyvsp[0].ival) < 0 || (yyvsp[0].ival) > 8){printf("ERROR: float precision must be from 0 to 8\n"); return 0;} float_precision = (yyvsp[0].ival);}
#line 1455 "bison.tab.c"
    break;

  case 28: /* set_h_view: number_handlers COLON number_handlers  */
#line 211 "bison.y"
                                                  { 
										h_view_lo = *getFloat((yyvsp[-2].varTypes));
										h_view_hi = *getFloat((yyvsp[0].varTypes));
										("h_view set!\n");
										}
#line 1465 "bison.tab.c"
    break;

  case 29: /* set_v_view: number_handlers COLON number_handlers  */
#line 217 "bison.y"
                                                  {
										v_view_lo = *getFloat((yyvsp[-2].varTypes));
										v_view_hi = *getFloat((yyvsp[0].varTypes));
										printf("v_view set!\n");
}
#line 1475 "bison.tab.c"
    break;

  case 30: /* number_handlers: NUM_FLOAT  */
#line 223 "bison.y"
                           { float* wrapper= malloc(sizeof(float)); *wrapper= (yyvsp[0].fval); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1481 "bison.tab.c"
    break;

  case 31: /* number_handlers: ADD NUM_FLOAT  */
#line 224 "bison.y"
                                { float* wrapper= malloc(sizeof(float)); *wrapper= (yyvsp[0].fval); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1487 "bison.tab.c"
    break;

  case 32: /* number_handlers: SUB NUM_FLOAT  */
#line 225 "bison.y"
                                { float* wrapper= malloc(sizeof(float)); *wrapper= -(yyvsp[0].fval); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1493 "bison.tab.c"
    break;

  case 33: /* number_handlers: NUM_INT  */
#line 226 "bison.y"
                          { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(yyvsp[0].ival); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1499 "bison.tab.c"
    break;

  case 34: /* number_handlers: ADD NUM_INT  */
#line 227 "bison.y"
                              { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(yyvsp[0].ival); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1505 "bison.tab.c"
    break;

  case 35: /* number_handlers: SUB NUM_INT  */
#line 228 "bison.y"
                              { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(-(yyvsp[0].ival)); varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1511 "bison.tab.c"
    break;

  case 36: /* number_handlers: PI  */
#line 229 "bison.y"
                     { float* wrapper = malloc(sizeof(float)); *wrapper = 3.14159265; varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value;}
#line 1517 "bison.tab.c"
    break;

  case 37: /* number_handlers: SUB PI  */
#line 230 "bison.y"
                         { float* wrapper = malloc(sizeof(float)); *wrapper = -3.14159265; varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1523 "bison.tab.c"
    break;

  case 38: /* number_handlers: EULER  */
#line 231 "bison.y"
                        { float* wrapper = malloc(sizeof(float)); *wrapper = 2.71828182; varTypes* value = createVarTypes(1,wrapper); (yyval.varTypes) = value; }
#line 1529 "bison.tab.c"
    break;

  case 39: /* number_handlers: SUB EULER  */
#line 232 "bison.y"
                            { float* wrapper = malloc(sizeof(float)); *wrapper = -2.71828182; varTypes* value = createVarTypes(1, wrapper); (yyval.varTypes) = value; }
#line 1535 "bison.tab.c"
    break;

  case 40: /* number_handlers: IDENTIFIER  */
#line 233 "bison.y"
                             { if(search(hashtable,(yyvsp[0].sval)) == NULL){printf("Undefined Symbol [%s]\n", (yyvsp[0].sval)); return 0;} else{ (yyval.varTypes) = search(hashtable,(yyvsp[0].sval));}; }
#line 1541 "bison.tab.c"
    break;

  case 41: /* number_handlers: SUB IDENTIFIER  */
#line 234 "bison.y"
                                 { varTypes* value = search(hashtable,(yyvsp[0].sval)); (yyval.varTypes) = Vneg(value); }
#line 1547 "bison.tab.c"
    break;

  case 42: /* number_handlers: X  */
#line 235 "bison.y"
                    {}
#line 1553 "bison.tab.c"
    break;

  case 43: /* plot_options: %empty  */
#line 237 "bison.y"
               {printf("finished plot\n");}
#line 1559 "bison.tab.c"
    break;

  case 44: /* plot_options: L_BRACKET expresao_mat R_BRACKET  */
#line 238 "bison.y"
                                                           {printf("finished plot w/ exp\n");}
#line 1565 "bison.tab.c"
    break;

  case 45: /* set_axis: ON  */
#line 239 "bison.y"
             { draw_axis=true;}
#line 1571 "bison.tab.c"
    break;

  case 46: /* set_axis: OFF  */
#line 240 "bison.y"
                      { draw_axis=false; }
#line 1577 "bison.tab.c"
    break;

  case 47: /* set_erase_plot: ON  */
#line 242 "bison.y"
                   { erase_plots=true;}
#line 1583 "bison.tab.c"
    break;

  case 48: /* set_erase_plot: OFF  */
#line 243 "bison.y"
                              { erase_plots=false; }
#line 1589 "bison.tab.c"
    break;

  case 49: /* assign_to: number_handlers  */
#line 246 "bison.y"
                           { (yyval.varTypes) = (yyvsp[0].varTypes);}
#line 1595 "bison.tab.c"
    break;

  case 50: /* assign_to: testMatrix  */
#line 247 "bison.y"
                             {printf("matrix assigned!\n"); (yyval.varTypes) = (yyvsp[0].varTypes);}
#line 1601 "bison.tab.c"
    break;

  case 51: /* assign_to: expresao_mat  */
#line 248 "bison.y"
                              {printf("expression assigned!\n"); (yyval.varTypes) = (yyvsp[0].varTypes);}
#line 1607 "bison.tab.c"
    break;

  case 52: /* expresao_mat: fator  */
#line 251 "bison.y"
                    { (yyval.varTypes)=(yyvsp[0].varTypes); }
#line 1613 "bison.tab.c"
    break;

  case 53: /* expresao_mat: expresao_mat ADD fator  */
#line 252 "bison.y"
                                         { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = Vsum(val1,val2); }
#line 1619 "bison.tab.c"
    break;

  case 54: /* expresao_mat: expresao_mat SUB fator  */
#line 253 "bison.y"
                                         { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = Vsub(val1,val2); }
#line 1625 "bison.tab.c"
    break;

  case 55: /* fator: expoente  */
#line 255 "bison.y"
                { (yyval.varTypes) = (yyvsp[0].varTypes); }
#line 1631 "bison.tab.c"
    break;

  case 56: /* fator: fator MULT expoente  */
#line 256 "bison.y"
                                      { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = mult(val1,val2); }
#line 1637 "bison.tab.c"
    break;

  case 57: /* fator: fator DIV expoente  */
#line 257 "bison.y"
                                     { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = divi(val1,val2); }
#line 1643 "bison.tab.c"
    break;

  case 58: /* fator: fator MOD expoente  */
#line 258 "bison.y"
                                     { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = modules(val1,val2); }
#line 1649 "bison.tab.c"
    break;

  case 59: /* expoente: termo  */
#line 260 "bison.y"
                { (yyval.varTypes) = (yyvsp[0].varTypes); }
#line 1655 "bison.tab.c"
    break;

  case 60: /* expoente: expoente EXP termo  */
#line 261 "bison.y"
                                    { varTypes* val1 = (yyvsp[-2].varTypes); varTypes* val2 = (yyvsp[0].varTypes); (yyval.varTypes) = powe(val1,val2); }
#line 1661 "bison.tab.c"
    break;

  case 61: /* termo: number_handlers  */
#line 263 "bison.y"
                       { (yyval.varTypes) = (yyvsp[0].varTypes); }
#line 1667 "bison.tab.c"
    break;

  case 62: /* termo: ABS L_BRACKET termo R_BRACKET  */
#line 264 "bison.y"
                                                { (yyval.varTypes) = Vabs((yyvsp[-1].varTypes)); }
#line 1673 "bison.tab.c"
    break;

  case 63: /* termo: L_BRACKET expresao_mat R_BRACKET  */
#line 265 "bison.y"
                                                   { (yyval.varTypes) = (yyvsp[-1].varTypes); }
#line 1679 "bison.tab.c"
    break;

  case 64: /* termo: COS L_BRACKET expresao_mat R_BRACKET  */
#line 266 "bison.y"
                                                       { (yyval.varTypes) = Vcos((yyvsp[-1].varTypes)); }
#line 1685 "bison.tab.c"
    break;

  case 65: /* termo: SEN L_BRACKET expresao_mat R_BRACKET  */
#line 267 "bison.y"
                                                       { (yyval.varTypes) = Vsin((yyvsp[-1].varTypes)); }
#line 1691 "bison.tab.c"
    break;

  case 66: /* termo: TAN L_BRACKET expresao_mat R_BRACKET  */
#line 268 "bison.y"
                                                       { (yyval.varTypes) = Vtan((yyvsp[-1].varTypes)); }
#line 1697 "bison.tab.c"
    break;

  case 67: /* vector: L_S_BRACKET numSequence R_S_BRACKET  */
#line 272 "bison.y"
                                            {   m_lines++;
												max_columns = max(max_columns,m_columns);
												max_lines = m_lines;
												m_columns=0;
											}
#line 1707 "bison.tab.c"
    break;

  case 68: /* numSequence: number_handlers  */
#line 278 "bison.y"
                             { matrix[m_lines][m_columns] = *getFloat((yyvsp[0].varTypes)); m_columns++; }
#line 1713 "bison.tab.c"
    break;

  case 69: /* numSequence: numSequence COMMA number_handlers  */
#line 279 "bison.y"
                                                    { matrix[m_lines][m_columns] = *getFloat((yyvsp[0].varTypes)); m_columns++;}
#line 1719 "bison.tab.c"
    break;

  case 70: /* vecSequence: vector  */
#line 281 "bison.y"
                    {  }
#line 1725 "bison.tab.c"
    break;

  case 71: /* vecSequence: vecSequence COMMA vector  */
#line 282 "bison.y"
                                           { }
#line 1731 "bison.tab.c"
    break;

  case 72: /* testMatrix: L_S_BRACKET vecSequence R_S_BRACKET  */
#line 284 "bison.y"
                                                { varTypes* dummy; if(max_lines>10||max_columns>10){MatrizMaxBoundary(); return 0;} sampleText = createMatriz(matrix,max_lines,max_columns); dummy = createVarTypes(2,sampleText); (yyval.varTypes) = dummy;}
#line 1737 "bison.tab.c"
    break;


#line 1741 "bison.tab.c"

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

#line 286 "bison.y"


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
