
%{
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
	int sum_lo, sum_hi =0;

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
	void about(){
		printf("+---------------------------------+\n|     Lucas Shin-Iti Aoki         |\n|     201900560188                |\n+---------------------------------+\n\n");
	}

	
%}
%union{
	int ival;
	float fval;
	char *sval;
	void *varTypes;
}

%token EOL

%token ADD
%token SUB
%token MULT
%token DIV
%token MOD
%token EXP


%token L_BRACKET
%token R_BRACKET

%token INTERVAL
%token EQUALS
%token ASSIGN
%token L_S_BRACKET
%token R_S_BRACKET
%token SEMICOLON
%token COLON
%token COMMA

%token PI
%token EULER
%token <fval> NUM_FLOAT
%token <ival> NUM_INT
%type <varTypes> assign_to
%type <varTypes> number_handlers
/* %type <fval> funcao_mat */
%type <varTypes> expresao_mat
%type <varTypes> fator
%type <varTypes> termo
%type <varTypes> expoente
/* %type <fval> testing */
%type <fval> vector
%type <fval> numSequence
%type <fval> vecSequence
%type <varTypes> testMatrix
%type <varTypes> solve_matrices

%token <sval> IDENTIFIER



%token ABOUT
%token ABS
%token AXIS
%token CONNECTED_DOTS
%token COS
%token DETERMINANT
%token ERASE
%token FLOAT
%token H_VIEW
%token INTEGRAL_STEPS
%token INTEGRATE
%token LINEAR_SYSTEM
%token MATRIX
%token OFF
%token ON
%token PLOT
%token PRECISION
%token QUIT
%token RESET
%token RPN
%token SEN
%token SET
%token SETTINGS
%token SHOW
%token SOLVE
%token SUM
%token SYMBOLS
%token TAN
%token V_VIEW
%token X

%token <sval> UNKNOW

%token END_OF_FILE

%start begin

%%
begin:
	| EOL { return 0;}
	| input SEMICOLON EOL{ return 0;}
	| expresao_mat EOL { printVarTypes($1, float_precision); return 0;}
;
input:
		| functions {printf("finished functions\n");}
		| MATRIX EQUALS testMatrix { lastInserted = $3; printf("finished matrix rule\n");}
		| reset_settings {printf(" finished reset settings rule\n");}
		| SHOW show_options {printf("finished show rule\n");}
		| solve_matrices { printf("finished solve matrices rule\n");}
		| SET setters {printf(" finished set rule\n");}
		| IDENTIFIER { printIdentifier(search(hashtable,$1), float_precision, $1); }
		| IDENTIFIER ASSIGN assign_to { insert_update(hashtable, $1, $3); printf("finished assign\n");}
		| PLOT plot_options { printf("finished plot\n");}
		| ABOUT {printf("\n"); about();}
		| QUIT {quit = 1; return 0;}
;
functions: INTEGRATE {printf("finished integrate\n");}
		| RPN {printf("finished rpn\n");}
		| SUM L_BRACKET IDENTIFIER COMMA sum_limits COMMA expresao_mat R_BRACKET { } //Vsummation($3, sum_lo, sum_hi); /////insert_update(hashtable,$3,$4); printf("saved: %s\nsum_lo: %d\nsum_hi: %d\n");
		;
show_options: SYMBOLS { showSymbols(hashtable); }
		| SETTINGS {printf("\n"); show_Settings();}
		| MATRIX { if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;} printFormatted(getMatriz(lastInserted), float_precision);}
		;
solve_matrices: SOLVE LINEAR_SYSTEM {if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;}if(!linearsysFormat(getMatriz(lastInserted))){printf("Matrix format incorrect!\n");return 0;} printLinearSystemSolution(LinearSystem(getMatriz(lastInserted)), float_precision);}
		|SOLVE DETERMINANT { if(lastInserted == NULL){printf("No Matrix defined!\n");return 0;}if(!isSquare(getMatriz(lastInserted))){printf("Matrix format incorrect!\n"); return 0;} ;printf("%.*f\n", float_precision, determinant(getMatriz(lastInserted), getMatLines(getMatriz(lastInserted))));}
;
reset_settings: RESET SETTINGS { reset_settings(); }
;
setters: AXIS set_axis {printf("finished axis\n");}
		| ERASE PLOT set_erase_plot {printf("finished erase plot\n");}
		| INTEGRAL_STEPS number_handlers { if(*getFloat($2) <= 0){printf("integral_steps must be a positive non-zero integer\n"); return 0;} integral_steps = *getFloat($2);}
		| H_VIEW set_h_view {printf("finished h_view\n");}
		| V_VIEW set_v_view {printf("finished v_view\n");}
		| FLOAT PRECISION NUM_INT { if($3 < 0 || $3 > 8){printf("ERROR: float precision must be from 0 to 8\n"); return 0;} float_precision = $3;}
		;
set_h_view: number_handlers COLON number_handlers { 
										if(*getFloat($1) >= *getFloat($3)){printf("ERROR: h_view_lo must be smaller than h_view_hi\n"); return 0;}
										h_view_lo = *getFloat($1);
										h_view_hi = *getFloat($3);
										}
;
set_v_view: number_handlers COLON number_handlers {
										if(*getFloat($1) >= *getFloat($3)){printf("ERROR: v_view_lo must be smaller than v_view_hi\n"); return 0;}
										v_view_lo = *getFloat($1);
										v_view_hi = *getFloat($3);
}
sum_limits: number_handlers COLON number_handlers {
										if(*getFloat($1) >= *getFloat($3)){printf("ERROR: lower limit must be smaller than upper limit\n"); return 0;}
										sum_lo = (int)*getFloat($1);
										sum_hi = (int)*getFloat($3);
}
;
number_handlers: NUM_FLOAT { float* wrapper= malloc(sizeof(float)); *wrapper= $1; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,$1); $$ = value;
		| ADD NUM_FLOAT { float* wrapper= malloc(sizeof(float)); *wrapper= $2; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,$2); $$ = value;
		| SUB NUM_FLOAT { float* wrapper= malloc(sizeof(float)); *wrapper= -$2; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-$2); $$ = value;
		| NUM_INT { float* wrapper= malloc(sizeof(float)); *wrapper= (float)$1; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,$1); $$ = value;
		| ADD NUM_INT { float* wrapper= malloc(sizeof(float)); *wrapper= (float)$2; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,$2); $$ = value;
		| SUB NUM_INT { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(-$2); varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-$2); $$ = value;
		| PI { float* wrapper = malloc(sizeof(float)); *wrapper = 3.14159265; varTypes* value = createVarTypes(1,wrapper); $$ = value;} //varTypes* value = createVarTypes(1,3.14159265); $$ = value;
		| SUB PI { float* wrapper = malloc(sizeof(float)); *wrapper = -3.14159265; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-3.14159265); $$ = value;
		| EULER { float* wrapper = malloc(sizeof(float)); *wrapper = 2.71828182; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,2.71828182); $$ = value;
		| SUB EULER { float* wrapper = malloc(sizeof(float)); *wrapper = -2.71828182; varTypes* value = createVarTypes(1, wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-2.71828182); $$ = value;
		| IDENTIFIER { if(search(hashtable,$1) == NULL){printf("Undefined Symbol [%s]\n", $1); return 0;} else{ $$ = search(hashtable,$1);}; }
		| SUB IDENTIFIER { varTypes* value = search(hashtable,$2); $$ = Vneg(value); }
		| X { printf("The x variable cannot be present on expressions\n"); return 0;}
		;
plot_options:  {printf("finished plot\n");}
			| L_BRACKET expresao_mat R_BRACKET {printf("finished plot w/ exp\n");}
			;
set_axis: ON { draw_axis=true;}
		| OFF { draw_axis=false; }
;
set_erase_plot: ON { erase_plots=true;}
			| OFF { erase_plots=false; }
;

assign_to: number_handlers { $$ = $1;}
		| testMatrix { $$ = $1;}
		| expresao_mat { $$ = $1;}
;

expresao_mat: fator { $$=$1; }
		| expresao_mat ADD fator { varTypes* val1 = $1; varTypes* val2 = $3; $$ = Vsum(val1,val2); }
		| expresao_mat SUB fator { varTypes* val1 = $1; varTypes* val2 = $3; $$ = Vsub(val1,val2); }
;
fator: expoente { $$ = $1; }
		| fator MULT expoente { varTypes* val1 = $1; varTypes* val2 = $3; $$ = mult(val1,val2); }
		| fator DIV expoente { varTypes* val1 = $1; varTypes* val2 = $3; $$ = divi(val1,val2); }
		| fator MOD expoente { varTypes* val1 = $1; varTypes* val2 = $3; $$ = modules(val1,val2); }
;
expoente: termo { $$ = $1; }
		|expoente EXP termo { varTypes* val1 = $1; varTypes* val2 = $3; $$ = powe(val1,val2); }
		;
termo: number_handlers { $$ = $1; }
		| ABS L_BRACKET termo R_BRACKET { $$ = Vabs($3); }
		| L_BRACKET expresao_mat R_BRACKET { $$ = $2; }
		| COS L_BRACKET expresao_mat R_BRACKET { $$ = Vcos($3); }
		| SEN L_BRACKET expresao_mat R_BRACKET { $$ = Vsin($3); }
		| TAN L_BRACKET expresao_mat R_BRACKET { $$ = Vtan($3); }
;

spec_exp_string: 

;


vector: L_S_BRACKET numSequence R_S_BRACKET {   m_lines++;
												max_columns = max(max_columns,m_columns);
												max_lines = m_lines;
												m_columns=0;
											}
;
numSequence: number_handlers { matrix[m_lines][m_columns] = *getFloat($1); m_columns++; }// <- printa o primeiro numero
		| numSequence COMMA number_handlers { matrix[m_lines][m_columns] = *getFloat($3); m_columns++;}// <- printa o que não é primeiro
;
vecSequence: vector {  }
		| vecSequence COMMA vector { }
;
testMatrix: L_S_BRACKET vecSequence R_S_BRACKET { varTypes* dummy; if(max_lines>10||max_columns>10){MatrizMaxBoundary(); return 0;} sampleText = createMatriz(matrix,max_lines,max_columns); dummy = createVarTypes(2,sampleText); $$ = dummy;}
;
%%

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
	/* printf("Bye!\n");
	printHashtable(hashtable, float_precision); */
	freeHashtable(hashtable);

	return 0;
}