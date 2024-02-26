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
	if(a->type == 1 && b->type ==1 ){
		float* temp = (float*)malloc(sizeof(float));
		*temp = *(a->f) + *(b->f);
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2 && b->type == 2){
		return NULL;
		// Matriz* temp = NULL;
		// result = sumMatrices(a->m, b->m);
		// return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}
}
varTypes* Vsub(varTypes* a, varTypes* b){
	varTypes* result = NULL;
	if(a == NULL || b == NULL){
		return NULL;
	}
	if(a->type == 1 && b->type ==1){
		printf("Vsub called\n");
		printf("a: %f\n", *(a->f));
		printf("b: %f\n", *(b->f));
		float* temp = (float*)malloc(sizeof(float));
		*temp = *(a->f) - *(b->f);
		result = createVarTypes(1, temp);
		return result;
	}
	else if(a->type == 2 && b->type == 2){
		return NULL;
		// Matriz* temp = NULL;
		// result = subtractMatrices(a->m, b->m);
		// return result;
	}
	else{
		printf("Invalid operation\n");
		return NULL;
	}

}
varTypes* mult(varTypes* a, varTypes* b){
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
	return NULL;
}
varTypes* Vcos(varTypes* a){
	return NULL;
}
varTypes* Vtan(varTypes* a){
	return NULL;
}