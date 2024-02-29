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
    L_BRACKET = 265,               /* L_BRACKET  */
    R_BRACKET = 266,               /* R_BRACKET  */
    INTERVAL = 267,                /* INTERVAL  */
    EQUALS = 268,                  /* EQUALS  */
    ASSIGN = 269,                  /* ASSIGN  */
    L_S_BRACKET = 270,             /* L_S_BRACKET  */
    R_S_BRACKET = 271,             /* R_S_BRACKET  */
    SEMICOLON = 272,               /* SEMICOLON  */
    COLON = 273,                   /* COLON  */
    COMMA = 274,                   /* COMMA  */
    PI = 275,                      /* PI  */
    EULER = 276,                   /* EULER  */
    NUM_FLOAT = 277,               /* NUM_FLOAT  */
    NUM_INT = 278,                 /* NUM_INT  */
    IDENTIFIER = 279,              /* IDENTIFIER  */
    ABOUT = 280,                   /* ABOUT  */
    ABS = 281,                     /* ABS  */
    AXIS = 282,                    /* AXIS  */
    CONNECTED_DOTS = 283,          /* CONNECTED_DOTS  */
    COS = 284,                     /* COS  */
    DETERMINANT = 285,             /* DETERMINANT  */
    ERASE = 286,                   /* ERASE  */
    FLOAT = 287,                   /* FLOAT  */
    H_VIEW = 288,                  /* H_VIEW  */
    INTEGRAL_STEPS = 289,          /* INTEGRAL_STEPS  */
    INTEGRATE = 290,               /* INTEGRATE  */
    LINEAR_SYSTEM = 291,           /* LINEAR_SYSTEM  */
    MATRIX = 292,                  /* MATRIX  */
    OFF = 293,                     /* OFF  */
    ON = 294,                      /* ON  */
    PLOT = 295,                    /* PLOT  */
    PRECISION = 296,               /* PRECISION  */
    QUIT = 297,                    /* QUIT  */
    RESET = 298,                   /* RESET  */
    RPN = 299,                     /* RPN  */
    SEN = 300,                     /* SEN  */
    SET = 301,                     /* SET  */
    SETTINGS = 302,                /* SETTINGS  */
    SHOW = 303,                    /* SHOW  */
    SOLVE = 304,                   /* SOLVE  */
    SUM = 305,                     /* SUM  */
    SYMBOLS = 306,                 /* SYMBOLS  */
    TAN = 307,                     /* TAN  */
    V_VIEW = 308,                  /* V_VIEW  */
    X = 309,                       /* X  */
    UNKNOW = 310,                  /* UNKNOW  */
    END_OF_FILE = 311              /* END_OF_FILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "bison.y"

	int ival;
	float fval;
	char *sval;
	void *varTypes;

#line 127 "bison.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
