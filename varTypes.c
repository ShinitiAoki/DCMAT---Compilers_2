#include "varTypes.h"


varTypes* createVarTypes(int type, void* content){
	varTypes* newVar = (varTypes*)malloc(sizeof(varTypes));
	newVar->type = type;
	if(type == 1){
	newVar->f = content;
	}
	else if(type == 2){
	newVar->m = content;
	}
	return newVar;
}

void printVarTypes(varTypes* content, int precision){
	if(content == NULL){
		return;
	}
	if(content->type == 1){
		float temp = *(content->f);
		printf("%.*f\n", precision, temp);
	}
	else if(content->type == 2){
		printFormatted(content->m, precision);
	}
}
void printIdentifier(varTypes* content,int precision, char* name){
	if(content == NULL){
		printf("Undefined Symbol\n");
		return;
	}
	if(content->type == 1){
		float temp = *(content->f);
		printf("%s = %f\n", name, temp);
	}
	else if(content->type == 2){
		printf("\n");
		printFormatted(content->m, precision);
	}
}


float* getFloat(varTypes* a){
	if(a == NULL){
		return NULL;
	}
	if(a->type == 1){
		return a->f;
	}
	else{
		return NULL;
	}

}
Matriz* getMatriz(varTypes* a){
	if(a == NULL){
		return NULL;
	}
	if(a->type == 2){
		return a->m;
	}
	else{
		return NULL;
	}

}

varTypes* Vsum(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	int key = a->type * 10 + b->type;
	switch(key)
	{
		case 11:
			float* temp = (float*)malloc(sizeof(float));
			*temp = *(a->f) + *(b->f);
			result = createVarTypes(1, temp);
			return result;
		break;
		case 22:
			if (a->m->colunas != b->m->colunas || a->m->linhas != b->m->linhas)
			{
				printf("Incorrect dimensions for operator '+' - have MATRIX [%d][%d] and MATRIX [%d][%d]\n", a->m->linhas, a->m->colunas, b->m->linhas, b->m->colunas);
				return NULL;
			}
			printf("case 2 mats. initiate Vsum\n");
			varTypes* temp2 = createVarTypes(2, sumMatrices(a->m, b->m));
			return temp2;
		break;
		case 12:
			printf("Incorrect type for operator '+' - have FLOAT and MATRIX\n");
			return NULL;
		case 21:
			printf("Incorrect type for operator '+' - have MATRIX and FLOAT\n");
			return NULL;
		break;
	}

}
varTypes* Vsub(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	
	int key = a->type * 10 + b->type;
	switch (key)
	{
	case 11:
		float* temp2 = (float*)malloc(sizeof(float));
		*temp2 = *(a->f) - *(b->f);
		result = createVarTypes(1, temp2);
		return result;
		break;
	case 22:
		if (a->m->colunas != b->m->colunas || a->m->linhas != b->m->linhas){
			printf("Incorrect dimensions for operator '-' - have MATRIX [%d][%d] and MATRIX [%d][%d]\n", a->m->linhas, a->m->colunas, b->m->linhas, b->m->colunas);
			return NULL;
		}
		varTypes* temp3 = createVarTypes(2, subtractMatrices(a->m, b->m));
		return temp3;
		break;
	case 21:
		printf("Incorrect type for operator '-' - have MATRIX and FLOAT\n");
		return NULL;
	case 12:
		printf("Incorrect type for operator '-' - have FLOAT and MATRIX\n");
		return NULL;
	default:
		printf("Invalid operation\n");
		return NULL;
		break;
	}

}
varTypes* mult(varTypes* a, varTypes* b){
	if(a == NULL || b == NULL){
		return NULL;
	}
	varTypes* result = NULL;
	int key = a->type * 10 + b->type;
	switch(key){
		case 11:
			float* temp = (float*)malloc(sizeof(float));
			*temp = *(a->f) * *(b->f);
			result = createVarTypes(1, temp);
			return result;
		case 22:
			varTypes* twomat = createVarTypes(2, multiplyMatrices(a->m, b->m));
			return twomat;
		case 21:
			varTypes* matscal = createVarTypes(2, multiplyByScalar(a->m, *(b->f)));
			return matscal;
		case 12:
			varTypes* scalmat = createVarTypes(2, multiplyByScalar(b->m, *(a->f)));
			return scalmat;
		default:
			printf("Invalid operation\n");
			return NULL;
	}

}
varTypes* divi(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	if(a->type == 1 && b->type ==1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = *(a->f) / *(b->f);
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2 && b->type == 2){
		return NULL;
		// Matriz* temp = NULL;
		// result = divideMatrices(a->m, b->m);
		// return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}

}
varTypes* powe(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	if(a->type == 1 && b->type ==1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = pow(*(a->f), *(b->f));
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2 && b->type == 2){
		return NULL;
		// Matriz* temp = NULL;
		// result = powMatrices(a->m, b->m);
		// return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}


}
varTypes* modules(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	if(a->type == 1 && b->type ==1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = fmod(*(a->f), *(b->f));
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2 && b->type == 2){
		return NULL;
		// Matriz* temp = NULL;
		// result = modulesMatrices(a->m, b->m);
		// return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}
}
varTypes* Vmax(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	if(a->type == 1 && b->type ==1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = fmax(*(a->f), *(b->f));
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2 && b->type == 2){
		return NULL;

	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}

}

varTypes* Vneg(varTypes* a){
	varTypes* result = NULL;
	if(a == NULL){
		return NULL;
	}
	if(a->type == 1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = -(*(a->f));
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2){
		varTypes* result = createVarTypes(2, multiplyByScalar(a->m, -1));
		return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}

}

varTypes* Vabs(varTypes* a){
	varTypes* result = NULL;
	if(a == NULL){
		return NULL;
	}
	if(a->type == 1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = fabs(*(a->f));
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2){
		return NULL;
		// Matriz* temp = NULL;
		// result = absMatrices(a->m);
		// return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}

}


varTypes* Vsin(varTypes* a){
	if(a == NULL){
		return NULL;
	}
	if(a->type == 1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = sin(*(a->f));
		varTypes* result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2){
		printf("Incorrect type for operator 'sen' - have MATRIX\n");
		return NULL;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}
	return NULL;
}
varTypes* Vcos(varTypes* a){
	if(a == NULL){
		return NULL;
	}
	if(a->type == 1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = cos(*(a->f));
		varTypes* result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2){
		printf("Incorrect type for operator 'cos' - have MATRIX\n");
		return NULL;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}
}
varTypes* Vtan(varTypes* a){
	if(a == NULL){
		return NULL;
	}
	if(a->type == 1){
		float* temp = (float*)malloc(sizeof(float));
		*temp = tan(*(a->f));
		varTypes* result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2){
		printf("Incorrect type for operator 'tan' - have MATRIX\n");
		return NULL;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}
	return NULL;
}