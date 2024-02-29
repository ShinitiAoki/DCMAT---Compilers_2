#include "matriz.h"


Matriz* createMatriz(float** mat, int linhas, int colunas) {
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    m->linhas = linhas;
    m->colunas = colunas;

    // Dynamically allocate memory for matrix
    m->mat = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++) {
        m->mat[i] = (float *)malloc(colunas * sizeof(float));
        // Copy the contents of mat to m.mat
        for (int j = 0; j < colunas; j++) {
            m->mat[i][j] = mat[i][j];
        }
    }
    return m;
}


// Function to print a matrix

void setZero(float** matrix, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

int getMatLines(Matriz* m){
	return m->linhas;
}

void matriceBounds(int colunas, int* spaces){
	printf("+-");
	for(int i = 0; i < colunas; i++){
		for(int j = 0; j < spaces[i]; j++){
			printf(" ");
		}
		if(i < colunas - 1){
			printf(" ");
		}
	}
	printf("-+\n");
}

int spacingSize(Matriz* mat, int column){
	int minSpace = 0;
	for(int i = 0; i < mat->linhas; i++){
		int curretMin = 0;
		int currentVal = mat->mat[i][column];
		if(currentVal < 0){
			curretMin++;
			currentVal *= -1;
		}
		while(currentVal > 0){
			currentVal /= 10;
			curretMin++;
		}
		if(curretMin > minSpace){
			minSpace = curretMin;
		}
	}
	return minSpace;
}

void printFormatted(Matriz* mat, int floatPrecision){
	int spaces[mat->colunas];
	for(int i = 0; i < mat->colunas; i++){
		spaces[i] = spacingSize(mat, i);

		if(floatPrecision > 0){
			spaces[i] += floatPrecision + 1;
		}
	}

	matriceBounds(mat->colunas, spaces);
	for(int i = 0; i < mat->linhas; i++){
		printf("| ");
		for(int j = 0; j < mat->colunas; j++){
			printf("%*.*f ", spaces[j], floatPrecision, mat->mat[i][j]);
		}
		printf("|\n");
	}
	matriceBounds(mat->colunas, spaces);
}


Matriz* sumMatrices(Matriz* m1, Matriz* m2) {
	if(m1 == NULL || m2 == NULL){
		printf("any of them is null cannot sum\n");
		return NULL;
	}
    if (m1->linhas != m2->linhas || m1->colunas != m2->colunas) {
        printf("Matrix format incorrect!\n");
        return NULL;
    }
    float** temp = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		temp[i] = (float*)malloc(10*sizeof(float));
	}
	Matriz* result = createMatriz(temp, m1->linhas, m2->colunas);
    for (int i = 0; i < m1->linhas; ++i) {
        result->mat[i] = (float*)malloc(m1->colunas * sizeof(float));
        for (int j = 0; j < m1->colunas; ++j) {
            result->mat[i][j] = m1->mat[i][j] + m2->mat[i][j];
        }
    }
    return result;
}

// Function to subtract one matrix from another
Matriz* subtractMatrices(Matriz* m1, Matriz* m2) {
    if (m1->linhas != m2->linhas || m1->colunas != m2->colunas) {
        fprintf(stderr, "Matrix dimensions do not match\n");
        return NULL;
    }
    float** temp = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		temp[i] = (float*)malloc(10*sizeof(float));
	}
	Matriz* result = createMatriz(temp, m1->linhas, m2->colunas);
    for (int i = 0; i < m1->linhas; ++i) {
        result->mat[i] = (float*)malloc(m1->colunas * sizeof(float));
        for (int j = 0; j < m1->colunas; ++j) {
            result->mat[i][j] = m1->mat[i][j] - m2->mat[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matriz* multiplyMatrices(Matriz* m1, Matriz* m2) {
    if (m1->colunas != m2->linhas) {
        fprintf(stderr, "Matrix dimensions do not match for multiplication\n");
        return NULL;
    }
	float** temp = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		temp[i] = (float*)malloc(10*sizeof(float));
	}
	Matriz* result = createMatriz(temp, m1->linhas, m2->colunas);
    for (int i = 0; i < m1->linhas; ++i) {
        result->mat[i] = (float*)malloc(m2->colunas * sizeof(float));
        for (int j = 0; j < m2->colunas; ++j) {
            result->mat[i][j] = 0.0;
            for (int k = 0; k < m1->colunas; ++k) {
                result->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];
            }
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matriz* multiplyByScalar(Matriz* m, float scalar) {
	float** temp = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		temp[i] = (float*)malloc(10*sizeof(float));
	}
    Matriz* result = createMatriz(temp, m->linhas, m->colunas);
    for (int i = 0; i < m->linhas; ++i) {
        result->mat[i] = (float*)malloc(m->colunas * sizeof(float));
        for (int j = 0; j < m->colunas; ++j) {
            result->mat[i][j] = m->mat[i][j] * scalar;
        }
    }
	//free temp:
	for(int i = 0; i < 10; i++){
		free(temp[i]);
	}
	free(temp);
    return result;
}



void getCofactor(Matriz* m, Matriz* temp, int p, int q, int n) {
	int i = 0, j = 0;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (row != p && col != q) {
				temp->mat[i][j++] = m->mat[row][col];
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}
int isSquare(Matriz* m) {
	if(m->linhas == m->colunas){
		return 1;
	}
	return 0;
}
int linearsysFormat(Matriz* m){
	if(m->linhas == m->colunas - 1){
		return 1;
	}
	return 0;
}
float determinant(Matriz* m, int n) {
	float D = 0;
	if (n == 1) {
		return m->mat[0][0];
	}
	float** temp = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		temp[i] = (float*)malloc(10*sizeof(float));
	}
	Matriz* t = createMatriz(temp, m->linhas, m->colunas);
	int sign = 1;
	for (int f = 0; f < n; f++) {
		getCofactor(m, t, 0, f, n);
		D += sign * m->mat[0][f] * determinant(t, n - 1);
		sign = -sign;
	}
	//free temp:
	for(int i = 0; i < 10; i++){
		free(temp[i]);
	}
	free(temp);
	return D;
}
Matriz* LinearSystem(Matriz* m){
	if(m == NULL){
		return NULL;
	}
	Matriz* temp = createMatriz(m->mat, m->linhas, m->colunas);
	float** resmat = NULL;
	resmat = (float**)malloc(10*sizeof(float*));
	for(int i = 0; i < 10; i++){
		resmat[i] = (float*)malloc(10*sizeof(float));
	}
	for(int i = 0; i < m->linhas; i++){
		for(int j = i+1; j < m->linhas; j++){
			float ratio = temp->mat[j][i]/temp->mat[i][i];
			for(int k = 0; k < m->colunas; k++){
				temp->mat[j][k] -= ratio * temp->mat[i][k];
			}
		}
	}
	printf("Matrix after forward elimination:\n");
	//check for infinite solutions or no solution
	printFormatted(temp, 2);
	///////////////////////
	
	if(temp->mat[temp->linhas -1][temp->colunas -2] == 0){
		if(temp->mat[temp->linhas -1][temp->colunas -1] == 0){
			printf("SPI - The Linear System has infinitely many solutions\n");
			return NULL;
		}
		else{
			printf("SI - The Linear System has no solution\n");
			return NULL;
		}
	}

	//back substitution
	for(int i = temp->linhas - 1; i >= 0; i--){
		resmat[i][0] = temp->mat[i][temp->colunas - 1];
		for(int j = i + 1; j < temp->linhas; j++){
			resmat[i][0] -= temp->mat[i][j] * resmat[j][0];
		}
		resmat[i][0] /= temp->mat[i][i];
	}
	

	Matriz* result = createMatriz(resmat, temp->linhas, 1);
	// freeMatriz(temp);
	return result;
	
}
void printLinearSystemSolution(Matriz* m, int precision){
	if(m == NULL){
		return;
	}
	if(m->colunas != 1){
		printf("format incorrect\n");
		return;
	}
	printf("\n");
	for(int i = 0; i < m->linhas; i++){
		printf("%.*f\n", precision, m->mat[i][0]);
	}
}


// Function to free memory allocated for a matrix
void freeMatriz(Matriz* m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->mat[i]);
    }
    free(m->mat);
}
