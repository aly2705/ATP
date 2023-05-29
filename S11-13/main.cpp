#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "OperatiiMatrice.h"
#include "Tipuri.h"
#include "ConstructiiGraf.h"
#include "OperatiiQS.h"
#include "Traversare.h"
#include "Dijkstra.h"

/* Programul testeaza algoritmi in graf (parcurgere in latime, parcurgere in adancime, algortmul Djikstra) */

void main() {
	char numeFisier[30] = "./Graf_ponderat.txt";
	GRAF graf;
	int eroare, varfInit, * parcurgere, nrVarfuri, i;
	ETICHETA *drumuri;

	eroare = constructieReprezentareTabel(numeFisier, graf,1,0);
	if (eroare) printf("\nNu s-a putut deschide fisierul");
	else { 
		// Verificari constructii graf
		afisareMatrice(graf.tabel, graf.m, 2, "\nReprezentare Tabelara");
		afisareMatrice(graf.adj, graf.n, graf.n, "\nMatrice adiacenta");

		// Parcurgeri
		printf("\nVarf initial pentru parcurgeri: ");
		scanf("%d", &varfInit);

		//BF
		BF(graf, varfInit, parcurgere, nrVarfuri);
		printf("\nParcurgere in latime: ");
		for(i = 0; i < nrVarfuri; i++) {
			printf("%d ", parcurgere[i]);
		}

		//DF
		nrVarfuri = 0;
		delete(parcurgere);
		parcurgere = NULL;
		DF(graf, varfInit, parcurgere, nrVarfuri);
		printf("\nParcurgere in lungime: ");
		for (i = 0; i < nrVarfuri; i++) {
			printf("%d ", parcurgere[i]);
		}

		// Dijkstra
		if (graf.ponderat) {
			printf("\nDrumurile de cost minim de la varful initial la toate celalalte varfuri sunt:");
			drumuri = Dijkstra(graf, varfInit);

			// Afisare drumuri gasite pentru fiecare nod
			for (i = 1; i <= graf.n; i++) {
				printf("\nDrumul pana la varful %2d (cost=%5.2f) este: ", i, drumuri[i-1].cost);
				path(drumuri, i);
			}

			delete(drumuri);
		}


		// Dezalocari
		
		delete(parcurgere);
		dezalocaMatrice(graf.adj, graf.n);
		dezalocaMatrice(graf.tabel, graf.m);
	}
	printf("\nGata, apasa o tasta ...");
	_getch();
}