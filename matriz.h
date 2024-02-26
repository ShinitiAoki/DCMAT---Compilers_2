#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Matriz {
	float **mat;
	int linhas;
	int colunas;
} Matriz;

Matriz* createMatriz(float** mat, int linhas, int colunas);

void setZero(float** mat, int lines, int columns);
void printFormatted(Matriz* mat, int floatPrecision);
int getMatLines(Matriz* m);

/* Matrice Operations */
Matriz* sumMatrices(Matriz* m1, Matriz* m2);
Matriz* subtractMatrices(Matriz* m1, Matriz* m2);
Matriz* multiplyMatrices(Matriz* m1, Matriz* m2);
Matriz* multiplyByScalar(Matriz* m, float scalar);

//special functions
float determinant(Matriz* m, int n);


// Function to free memory allocated for a matrix
void freeMatriz(Matriz* m);

#endif