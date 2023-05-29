#include <stdio.h>

#include "Tipuri.h"
#include "OperatiiQS.h"
#include "Traversare.h"

// Parcurgere in latime - Breadth First
// I: graf, varf initial
// E: vectorul varfurilor vizitate, numarul varfurilor vizitate
void BF(GRAF graf, int varfInit, int* &parcurgere, int &nrVizitate) {
	// 1) Declaratii
	int i, *stare, nod;
	QS queue;

	// 2) Pregatire coada
	queue.space = NULL;
	initQS(queue, graf.n);

	// 3) Pregatire vector de parcurgere
	parcurgere = new int[graf.n];
	nrVizitate = 0;

	// 4) Pregatire vector de stare (nod vizitat/nevizitat)
	stare = new int[graf.n];
	for (i = 0; i < graf.n; i++) {
		stare[i] = 0;
	}

	// 5) Adaugare varf initial in coada
	pushQS(queue, varfInit);
	stare[varfInit - 1] = 1;

	// 6) Cat timp coada e nevida 
	while(queue.size){
		// 6.1) Extragere element din coada
		int extras;
		popQ(queue, extras);

		// 6.2) Parcurgerea varfului
		parcurgere[nrVizitate++] = extras;

		// 6.3) Descoperirea vecinilor nevizitati si adaugarea lor in coada
		for (nod = 0; nod < graf.n; nod++) {
			int faraMuchie = graf.ponderat ? INF : 0;

			// daca exista muchie si nodul nu e vizitat
			if (graf.adj[extras-1][nod] != faraMuchie && stare[nod] == 0) {
				stare[nod] = 1;
				pushQS(queue, nod + 1);
			}
		}
	}
	// 7) Dezalocari
	delete(stare);
	cleanQS(queue);
};


// Parcurgere in adancime - Depth First
// I: graf, varf initial
// E: vectorul varfurilor vizitate, numarul varfurilor vizitate
void DF(GRAF graf, int varfInit, int* &parcurgere, int &nrVizitate) {
	// 1) Declaratii
	int i, *stare, nod;
	QS stack;

	// 2) Pregatire stiva
	stack.space = NULL;
	initQS(stack, graf.n);

	// 3) Pregatire vector de parcurgere
	parcurgere = new int[graf.n];
	nrVizitate = 0;

	// 4) Pregatire vector de stare (nod vizitat/nevizitat)
	stare = new int[graf.n];
	for (i = 0; i < graf.n; i++) {
		stare[i] = 0;
	}

	// 5) Adaugare varf initial in stiva
	pushQS(stack, varfInit);
	stare[varfInit - 1] = 1;

	// 6) Loop cat timp stiva e nevida 
	while(stack.size){
		// 6.1) Extragere element din stiva
		int extras;
		popS(stack, extras);
		
		// 6.2) Parcurgerea varfului
		parcurgere[nrVizitate++] = extras;

		// 6.3) Descoperirea vecinilor nevizitati si adaugarea lor in stiva
		for (int nod = 0; nod < graf.n; nod++) {
			int faraMuchie = graf.ponderat ? INF : 0;

			if (graf.adj[extras - 1][nod] != faraMuchie && stare[nod] == 0) {
				pushQS(stack, nod + 1);
				stare[nod] = 1;
			}
		}
	}
	// 7) Dezalocari
	delete [] stare;
	cleanQS(stack);
};