#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "OperatiiMatrice.h"
#include "Tipuri.h"


// fisier cu implementarea functiilor de afisare, alocare si dezalocare matrice

// I: adresa matricei (mat), numar linii (nrLinii), numar coloane (nrCol), titlul matricei (titlu = default NULL)
// E: -
void afisareMatrice(int** mat, int nrLinii, int nrCol, const char* titlu) {
	if (titlu) printf("\n%s\n", titlu);
	int i, j;
	for (i = 0; i < nrLinii; i++) {
		for (j = 0; j < nrCol; j++) {
			if (mat[i][j] == INF)
				printf("INF ");
			else printf("%3d ", mat[i][j]);

		}
		printf("\n");
	}	
};


// I: nrLinii, nrColoane
// E: adresa matricei
int** alocaMatrice(int nrLinii, int nrColoane) {
	int** mat;

	// Alocare dinamica a unui vector de pointeri
	mat = new int* [nrLinii];
	for (int i = 0; i < nrLinii; i++) {
		// Alocare dinamica pe fiecare pozitie a vectorului de pointeri, a cate unui pointer la vector de intregi
		mat[i] = new int[nrColoane];
	}
	return mat;
};

// BONUS!!!!
// [] - operator de indexare; in spate mat[i] === *(mat+i) si mat[i][j] === *(*(mat+i)+j)

// I: adresaMatricei, nrLinii
// E: adresaMatrcei setata NULL
void dezalocaMatrice(int**& mat, int nrLinii) {
	for (int i = 0; i < nrLinii; i++) {
		delete mat[i];
	}
	delete mat;
	mat = NULL;
};