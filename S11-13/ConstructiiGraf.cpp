#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Tipuri.h"
#include "OperatiiMatrice.h"

void conversieMatriceAdiacenta(GRAF & graf) {
	int i, j, nrColoaneTabel= graf.ponderat+2, nrLiniiTabel= graf.m;
	graf.adj = alocaMatrice(graf.n, graf.n);

	// initializare matrice adiacenta
	for (i = 0; i < graf.n; i++) {
		for (j = 0; j < graf.n; j++) {
			if (graf.ponderat) graf.adj[i][j] = INF;
			else graf.adj[i][j] = 0;
		}
	}

	// populare matrice adiacenta
	for (i = 0; i < nrLiniiTabel; i++) {
		// identificare indici in matricea de adiacenta in fct de parcurgerea tabelului
		int linieAdj = graf.tabel[i][0]-1; // nod inceput
		int coloanaAdj = graf.tabel[i][1]-1; // nod final 

		// calc valoare in functie de graf ponderat/neponderat
		int valoare = graf.ponderat ? graf.tabel[i][2] : 1; // pondere sau 1 
		graf.adj[linieAdj][coloanaAdj] = valoare;

		// constructie simetrica in cazul grafului neorientat
		if (!graf.orientat) graf.adj[coloanaAdj][linieAdj] = valoare;

	}

	//De adaugat simetrie la neorientat	
	
}

// construieste in variabila 'graf' matricea reprezentarii tabelare a grafului, preluata dintr-un fisier cu date de forma:
/* nrVarfuri nrMuchii
inceputMuchie sfMuchie pondere?
...
inceputMuchie(m) sfMuchie(m) pondere?
*/
// @ponderat: char = 0 - neponderat, 1 - ponderat
// @orientat: char = 0 - neorientat, 1 - orientat
// returneaza un cod: 0 - succes, 1 - eroare
int constructieReprezentareTabel(char* numeFisier, GRAF& graf, char ponderat, char orientat) {
	FILE* f;
	int eroare, i, j;
	
	f = fopen(numeFisier, "rt");
	if (!f) {
		eroare = 1;
	}
	else {
		fscanf(f, "%d", &graf.n);
		fscanf(f, "%d", &graf.m);
		graf.ponderat = ponderat;
		graf.orientat = orientat;

		int nrColoaneTabel = 2 + ponderat;
		graf.tabel = alocaMatrice(graf.m, nrColoaneTabel);
		for (i = 0; i < graf.m; i++) {
			for (j = 0; j < nrColoaneTabel; j++) {
				fscanf(f, "%d", &graf.tabel[i][j]);
			}
		}
		
		conversieMatriceAdiacenta(graf);
		eroare = 0;
		fclose(f);
	}
	return eroare;
};