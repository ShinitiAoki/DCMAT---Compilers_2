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
    if (m1->linhas != m2->linhas || m1->colunas != m2->colunas) {
        fprintf(stderr, "Matrix dimensions do not match\n");
        return NULL;
    }
    Matriz* result = createMatriz((float**)malloc(m1->linhas * sizeof(float*)), m1->linhas, m1->colunas);
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
    Matriz* result = createMatriz((float**)malloc(m1->linhas * sizeof(float*)), m1->linhas, m1->colunas);
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
    Matriz* result = createMatriz((float**)malloc(m1->linhas * sizeof(float*)), m1->linhas, m2->colunas);
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
    Matriz* result = createMatriz((float**)malloc(m->linhas * sizeof(float*)), m->linhas, m->colunas);
    for (int i = 0; i < m->linhas; ++i) {
        result->mat[i] = (float*)malloc(m->colunas * sizeof(float));
        for (int j = 0; j < m->colunas; ++j) {
            result->mat[i][j] = m->mat[i][j] * scalar;
        }
    }
    return result;
}


float determinante(Matriz* m){
	if (m->linhas != m->colunas) {
        printf("Error: Determinant is only defined for square matrices.\n");
        return 0.0; // Return 0 if matrix is not square
    }

    if (m->linhas == 1) {
        return m->mat[0][0]; // Base case for 1x1 matrix
    } else if (m->linhas == 2) {
        return (m->mat[0][0] * m->mat[1][1]) - (m->mat[0][1] * m->mat[1][0]); // Base case for 2x2 matrix
    } else {
        float det = 0.0;
        Matriz* submatrix = createMatriz(NULL, m->linhas - 1, m->colunas - 1);

        for (int i = 0; i < m->linhas; i++) {
            int subi = 0; // Submatrix's i index
            for (int row = 1; row < m->linhas; row++) {
                int subj = 0; // Submatrix's j index
                for (int col = 0; col < m->colunas; col++) {
                    if (col == i) // Skip the i-th column
                        continue;
                    submatrix->mat[subi][subj] = m->mat[row][col];
                    subj++;
                }
                subi++;
            }
            det += (i % 2 == 0 ? 1 : -1) * m->mat[0][i] * determinante(submatrix);
        }

        // Free dynamically allocated memory
        for (int i = 0; i < submatrix->linhas; i++) {
            free(submatrix->mat[i]);
        }
        free(submatrix->mat);
        free(submatrix);

        return det;
    }
}


// Function to free memory allocated for a matrix
void freeMatriz(Matriz* m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->mat[i]);
    }
    free(m->mat);
}
