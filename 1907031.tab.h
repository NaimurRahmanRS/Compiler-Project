
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 258,
     INT = 259,
     FLOAT = 260,
     STRING = 261,
     MOD = 262,
     LT = 263,
     GT = 264,
     GEQ = 265,
     LEQ = 266,
     EQ = 267,
     NEQ = 268,
     VARIABLE = 269,
     NUMBER = 270,
     STR = 271,
     IMPORT = 272,
     HEADER = 273,
     MAIN = 274,
     INC = 275,
     DEC = 276,
     NOT = 277,
     SIN = 278,
     COS = 279,
     LOG = 280,
     TAN = 281,
     LN = 282,
     ODDEVEN = 283,
     FACTORIAL = 284,
     MAX = 285,
     MIN = 286,
     PRIME = 287,
     DEF = 288,
     DISPLAY = 289,
     IF = 290,
     ELSE_IF = 291,
     ELSE = 292,
     FOR = 293,
     FLINC = 294,
     FLDEC = 295,
     WHILE = 296,
     CASE = 297,
     SWITCH = 298,
     DEFAULT = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 126 "1907031.y"

    int num;
    float flt;
    char* string;



/* Line 1676 of yacc.c  */
#line 104 "1907031.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


