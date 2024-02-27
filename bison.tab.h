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

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
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
    EOL = 258,                     /* EOL  */
    ADD = 259,                     /* ADD  */
    SUB = 260,                     /* SUB  */
    MULT = 261,                    /* MULT  */
    DIV = 262,                     /* DIV  */
    MOD = 263,                     /* MOD  */
    EXP = 264,                     /* EXP  */
    UADD = 265,                    /* UADD  */
    USUB = 266,                    /* USUB  */
    L_BRACKET = 267,               /* L_BRACKET  */
    R_BRACKET = 268,               /* R_BRACKET  */
    INTERVAL = 269,                /* INTERVAL  */
    EQUALS = 270,                  /* EQUALS  */
    ASSIGN = 271,                  /* ASSIGN  */
    L_S_BRACKET = 272,             /* L_S_BRACKET  */
    R_S_BRACKET = 273,             /* R_S_BRACKET  */
    SEMICOLON = 274,               /* SEMICOLON  */
    COLON = 275,                   /* COLON  */
    COMMA = 276,                   /* COMMA  */
    PI = 277,                      /* PI  */
    EULER = 278,                   /* EULER  */
    NUM_FLOAT = 279,               /* NUM_FLOAT  */
    NUM_INT = 280,                 /* NUM_INT  */
    IDENTIFIER = 281,              /* IDENTIFIER  */
    ABOUT = 282,                   /* ABOUT  */
    ABS = 283,                     /* ABS  */
    AXIS = 284,                    /* AXIS  */
    CONNECTED_DOTS = 285,          /* CONNECTED_DOTS  */
    COS = 286,                     /* COS  */
    DETERMINANT = 287,             /* DETERMINANT  */
    E = 288,                       /* E  */
    ERASE = 289,                   /* ERASE  */
    FLOAT = 290,                   /* FLOAT  */
    H_VIEW = 291,                  /* H_VIEW  */
    INTEGRAL_STEPS = 292,          /* INTEGRAL_STEPS  */
    INTEGRATE = 293,               /* INTEGRATE  */
    LINEAR_SYSTEM = 294,           /* LINEAR_SYSTEM  */
    MATRIX = 295,                  /* MATRIX  */
    OFF = 296,                     /* OFF  */
    ON = 297,                      /* ON  */
    PLOT = 298,                    /* PLOT  */
    PRECISION = 299,               /* PRECISION  */
    QUIT = 300,                    /* QUIT  */
    RESET = 301,                   /* RESET  */
    RPN = 302,                     /* RPN  */
    SEN = 303,                     /* SEN  */
    SET = 304,                     /* SET  */
    SETTINGS = 305,                /* SETTINGS  */
    SHOW = 306,                    /* SHOW  */
    SOLVE = 307,                   /* SOLVE  */
    SUM = 308,                     /* SUM  */
    SYMBOLS = 309,                 /* SYMBOLS  */
    TAN = 310,                     /* TAN  */
    V_VIEW = 311,                  /* V_VIEW  */
    X = 312,                       /* X  */
    UNKNOW = 313,                  /* UNKNOW  */
    END_OF_FILE = 314              /* END_OF_FILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "bison.y"

	int ival;
	float fval;
	char *sval;
	void *varTypes;

#line 130 "bison.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
