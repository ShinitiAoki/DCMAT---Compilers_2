%option noyywrap


%{
	#include <bison.tab.h>

	void input_scanner(char *input){
		yy_scan_string(input);
	}
	void empty_buffer(){
		yy_delete_buffer(YY_CURRENT_BUFFER);
	}
%}

%%
"+"	{ return ADD; }
"-" { return SUB; }
"*"	{ return MULT;}
"/"	{ return DIV; }
"%"	{ return MOD; }
"^" { return EXP; }


"("	{ return L_BRACKET; }
")"	{ return R_BRACKET; }
":" { return COLON;}
";" { return SEMICOLON; }
"," { return COMMA; }
"=" { return EQUALS; }
":=" { return ASSIGN; }
"[" { return L_S_BRACKET; }
"]" { return R_S_BRACKET; }
" " {}

("\n"|"\r")                 { return EOL; }
" "                         {}

about                       { return ABOUT; }
abs                         { return ABS; }
axis                        { return AXIS; }
connected_dots              { return CONNECTED_DOTS; }
cos                         { return COS; }
determinant                 { return DETERMINANT; }
erase                       { return ERASE; }

float                       { return FLOAT; }
h_view                      { return H_VIEW; }
integral_steps              { return INTEGRAL_STEPS; }
integrate                   { return INTEGRATE; }
linear_system               { return LINEAR_SYSTEM; }
matrix                      { return MATRIX; }
off                         { return OFF; }
on                          { return ON; }
plot                        { return PLOT; }
precision                   { return PRECISION; }
quit                        { return QUIT; }
reset                       { return RESET; }
rpn                         { return RPN; }
sen                         { return SEN; }
set                         { return SET; }
solve                       { return SOLVE; }
sum                         { return SUM; }
symbols                     { return SYMBOLS; }
tan                         { return TAN; }
v_view                      { return V_VIEW; }
[xX]                        { return X; }
show						{ return SHOW; }
settings					{ return SETTINGS; }
quit						{ return QUIT; }

[pP][iI] 					{ return PI; }
[Ee] 						{ return EULER; }

[0-9]+ 						{ yylval.ival = atoi(yytext); return NUM_INT; }
[0-9]+"."[0-9]+ 			{ yylval.fval = atof(yytext); return NUM_FLOAT;}
[a-zA-Z]+[_0-9a-zA-Z]*		{ yylval.sval = strdup(yytext); return IDENTIFIER; }

.							{ yylval.sval = strdup(yytext); return UNKNOW; }
<<EOF>> { return EOL; }

%%
