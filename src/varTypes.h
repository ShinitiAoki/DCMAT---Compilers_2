#ifndef VAR_TYPES_H
#define VAR_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <math.h>

typedef struct varTypes {
	int type; //1 to float, 2 to matriz, 3 to error.
	float* f;
	char* exp;
	Matriz *m;
} varTypes;

varTypes* createVarTypes(int type, void* content);
void printVarTypes(varTypes* content, int precision);
void printIdentifier(varTypes* content,int precision, char* name);
char* getKey(varTypes* content);
float* getFloat(varTypes* a);
Matriz* getMatriz(varTypes* a);

//math function between two varTypes variables
varTypes* Vsum(varTypes* a, varTypes* b);
varTypes* Vsub(varTypes* a, varTypes* b);
varTypes* mult(varTypes* a, varTypes* b);
varTypes* divi(varTypes* a, varTypes* b);
varTypes* powe(varTypes* a, varTypes* b);
varTypes* modules(varTypes* a, varTypes* b);
varTypes* Vmax(varTypes* a, varTypes* b);
varTypes* Vneg(varTypes* a);
varTypes* Vabs(varTypes* a);
varTypes* Vsin(varTypes* a);
varTypes* Vcos(varTypes* a);
varTypes* Vtan(varTypes* a);

#endif