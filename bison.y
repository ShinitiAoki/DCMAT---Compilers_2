
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
	void input_scanner(char *input);
	void empty_buffer();

	char buffer[MAX_LINE_SIZE];
	char* in_buffer =NULL;
	int in_size;
	float** matrix;
	Matriz* sampleText = NULL;
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
		printf("Error\n");
	};
	
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

%token UADD
%token USUB

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
%type <fval> matrix
%type <varTypes> assign_to
%type <varTypes> number_handlers
/* %type <fval> funcao_mat */
%type <varTypes> expresao_mat
%type <varTypes> fator
%type <varTypes> termo
%type <varTypes> expoente
%type <fval> matrix_content
%type <fval> matrix_line
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
%token E
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

%token UNKNOW

%token END_OF_FILE

%start begin

%%
begin: 
	| input SEMICOLON EOL{ return 0;}
	| expresao_mat EOL { printVarTypes($1, float_precision); return 0;}
;
input:
		| testMatrix { printf("finished matrix rule\n");}
		| MATRIX EQUALS testMatrix { printf("finished matrix rule\n");}
		| reset_settings {printf(" finished reset settings rule\n");}
		| show_settings { show_Settings(); }
		| show_matrix { printf("finished show matrix rule\n");}
		| solve_matrices { printf("finished solve matrices rule\n");}
	//	| matrix {printf(" finished matrix rule\n"); printf("%.*f\n", float_precision, $1); }
		| SET setters {printf(" finished set rule\n");}
		| IDENTIFIER { printVarTypes(search(hashtable,$1),float_precision);}
		| IDENTIFIER ASSIGN assign_to { insert_update(hashtable, $1, $3); printf("finished assign\n");}
		| QUIT {quit = 1; return 0;}
;
show_settings: SHOW SETTINGS {printf("\n");}
;
show_matrix: SHOW MATRIX { printFormatted(sampleText, float_precision); printf("finished show matrix\n");}
;
solve_matrices: SOLVE LINEAR_SYSTEM {printf("finished solve\n");}
		|SOLVE DETERMINANT { printf("%.*f\n", float_precision, determinant(sampleText, getMatLines(sampleText)));}
;
reset_settings: RESET SETTINGS {printf("reseted settings\n");}
;
setters: AXIS set_axis {printf("finished axis\n");}
		| ERASE PLOT set_erase_plot {printf("finished erase plot\n");}
		| INTEGRAL_STEPS NUM_INT {printf("finished integral steps\n");}
		| H_VIEW set_h_view {printf("finished h_view\n");}
		| V_VIEW set_v_view {printf("finished v_view\n");}
set_h_view: number_handlers COLON number_handlers { 
										h_view_lo = *getFloat($1);
										h_view_hi = *getFloat($3);
										("h_view set!\n");
										}
;
set_v_view: number_handlers COLON number_handlers {
										v_view_lo = *getFloat($1);
										v_view_hi = *getFloat($3);
										printf("v_view set!\n");
}
;
number_handlers: NUM_FLOAT { float* wrapper= malloc(sizeof(float)); *wrapper= $1; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,$1); $$ = value;
		| SUB NUM_FLOAT { float* wrapper= malloc(sizeof(float)); *wrapper= -$2; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-$2); $$ = value;
		| NUM_INT { float* wrapper= malloc(sizeof(float)); *wrapper= (float)$1; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,$1); $$ = value;
		| SUB NUM_INT { float* wrapper= malloc(sizeof(float)); *wrapper= (float)(-$2); varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-$2); $$ = value;
		| PI { float* wrapper = malloc(sizeof(float)); *wrapper = 3.14159265; varTypes* value = createVarTypes(1,wrapper); $$ = value;} //varTypes* value = createVarTypes(1,3.14159265); $$ = value;
		| SUB PI { float* wrapper = malloc(sizeof(float)); *wrapper = -3.14159265; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-3.14159265); $$ = value;
		| EULER { float* wrapper = malloc(sizeof(float)); *wrapper = 2.71828182; varTypes* value = createVarTypes(1,wrapper); $$ = value; } //varTypes* value = createVarTypes(1,2.71828182); $$ = value;
		| SUB EULER { float* wrapper = malloc(sizeof(float)); *wrapper = -2.71828182; varTypes* value = createVarTypes(1, wrapper); $$ = value; } //varTypes* value = createVarTypes(1,-2.71828182); $$ = value;

;
set_axis: ON { draw_axis=true;}
		| OFF { draw_axis=false; }
;
set_erase_plot: ON { erase_plots=true;}
			| OFF { erase_plots=false; }
;

assign_to: number_handlers { $$ = $1;}
		| testMatrix {printf("matrix assigned!\n"); $$ = $1;}
		|expresao_mat {printf("expression assigned!\n"); $$ = $1;}
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
		| IDENTIFIER { $$ = search(hashtable,$1); }
		| COS L_BRACKET expresao_mat R_BRACKET { $$ = Vcos($3); }
		| SEN L_BRACKET expresao_mat R_BRACKET { $$ = Vsin($3); }
		| TAN L_BRACKET expresao_mat R_BRACKET { $$ = Vtan($3); }
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
testMatrix: L_S_BRACKET vecSequence R_S_BRACKET { varTypes* dummy; printf("matrix Done!\n"); sampleText = createMatriz(matrix,max_lines,max_columns); dummy = createVarTypes(2,sampleText); $$ = dummy;}
;
%%

int main(int argc, char **argv){
	matrix = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		matrix[i] = (float*)malloc(10*sizeof(float));
	}
	hashtable = createHashtable();
	while(!quit){
		m_lines = 0;
		m_columns = 0;
		max_columns = 0;
		max_lines = 0;
		setZero(matrix,10,10);
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