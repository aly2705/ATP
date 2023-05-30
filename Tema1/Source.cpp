#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

float medieVector(float *vector, int n) {
	float suma=0;
	for (int i = 0; i < n; i++) {
		suma += vector[i];
	}
	return suma / n;
}

float medieMatrice_s(float matrice[30][30], int n, int m) {
	float suma = 0;
	for (int i = 0; i < n; i++) {
		for(int j=0; j< m; j++){
		suma += matrice[i][j];
		}
	}
	return suma / (n*m);
}
void minmaxMatrice_d(float** matrice, int n, int m, float &min, float &max) {
	max = -10000;
	min = 10000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrice[i][j] < min) {
				min = matrice[i][j];
			}
			else if(matrice[i][j]>max){
				max = matrice[i][j];
			}
		}
	}
}
void vectorMedie(float** matrice, int n, int m, float *&vectorMedie) {
	for (int i = 0; i < n; i++) {
		vectorMedie[i] = medieVector(matrice[i], m);
	}
}
int cmmdc(float* vector, int n) {
	int i, cmmdc=(int)vector[0];
	for (i = 1; i < n; i++) {
		int copie= (int)vector[i];
		while (copie != cmmdc) {
			if (copie > cmmdc) copie -= cmmdc;
			else if (copie < cmmdc) cmmdc -= copie;
		}
	}
	return cmmdc;

}

void main() {
	FILE* f,*g;
	float vectorStatic[30], * vectorDinamic;
	int n,i,m,j;
	char fisierVector[30] = "./Vector.txt";
	char fisierMatrice[30] = "./Matrice.txt";

	printf("\n\n---------Lucru pe vector---------");
	f = fopen(fisierVector, "rt");
	
	if (!f) printf("\nNu s-a putut gasi/deschide fisierul %s", fisierVector);
	else {
		// Alocare + Constructie vector 
		fscanf(f, "%d", &n);
		vectorDinamic = new float[n];
		for (i = 0; i < n; i++) {
			fscanf(f, "%f", &vectorStatic[i]);
			vectorDinamic[i] = vectorStatic[i];
		}
		// Apeluri subprograme + teste
		// Problema 1)
		printf("\nMedia este: %.2f (statica) %.2f (dinamica)", medieVector(vectorStatic, n), medieVector(vectorDinamic, n));
		// Problema 5)
		printf("\nCmmdc al numerelor din vector reduse la intregi este %d", cmmdc(vectorDinamic, n));

		// Dezalocare + terminare fisier
		delete vectorDinamic;
		fclose(f);
	}

	printf("\n\n---------Lucru pe matrice---------");
	float matriceStatica[30][30], **matriceDinamica, min, max;
	g = fopen(fisierMatrice, "rt");

	if (!g) printf("\nNu s-a putut gasi/deschide fisierul %s", fisierMatrice);
	else {
		// Alocare + Constructie matrice
		fscanf(g, "%d", &n);
		fscanf(g, "%d", &m);
		matriceDinamica = new float*[n];
		vectorDinamic = new float[n];
		for (i = 0; i < n; i++) {
			matriceDinamica[i] = new float[m];
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				fscanf(g, "%f", &matriceStatica[i][j]);
				matriceDinamica[i][j] = matriceStatica[i][j];
			}
		}
		// Apeluri subprograme
		minmaxMatrice_d(matriceDinamica, n, m, min, max);
		vectorMedie(matriceDinamica, n, m, vectorDinamic);

		// Teste
		// Problema 2)
		printf("\nMedia in matrice este: %.2f", medieMatrice_s(matriceStatica, n,m));
		// Problema 3)
		printf("\nMinimul in matrice este: %.2f si maximul este %.2f", min,max);

		// Problema 4)
		printf("\nVectorul de medie al matricei este:\n");
		for (i = 0; i < n; i++) {
			printf("%.2f ", vectorDinamic[i]);
		}

		// Dezalocare
		delete matriceDinamica;
		delete vectorDinamic;
		fclose(g);
	}

	printf("\nGata, apasa o tasta...");
	_getch();
}