#include <stdio.h>
#include "Tipuri.h"
#include "Dijkstra.h"

// aplica algoritmul Dijkstra pentru aflarea drumurilor de cost minim de la un varf initial la toate celalalte varfuri
// I: graful, varful initial
// E: vectorul de etichete (indexul etichetei - nodul coresp etichetei)
ETICHETA* Dijkstra(GRAF graf, int varfInit) {
	//1) Declaratii
	int i, * permanente, varfMinim, ultimPerm, nod;
	float costMinim;
	ETICHETA* rezultat;

	//2) Pregatire vectori de etichete si de stare
	rezultat = new ETICHETA[graf.n];
	for (i = 0; i < graf.n; i++) {
		rezultat[i].cost = INF;
	}

	permanente = new int[graf.n];
	for (i = 0; i < graf.n; i++) {
		permanente[i] = 0;
	}

	//3) Incorporare varf initial
	rezultat[varfInit - 1].cost = 0;
	rezultat[varfInit - 1].precedent = -1;
	permanente[varfInit - 1] = 1;
	ultimPerm = varfInit;

	//4) Parcurgem n-1 iteratii
	for(i=0; i<graf.n-1; i++){

		//4.1) Cautam un cost minim pe iteratie si varful coresp care va candida pt includerea in multimea varfurilor permanente
		costMinim = INF;
		//4.2) Iteram varfurile temporare 
		for (nod = 1; nod <= graf.n; nod++) {
			if(!permanente[nod-1]) {
				//4.2.1) Daca este cazul, actualizam costurile prin ultimulPermanent
				if (rezultat[nod - 1].cost > rezultat[ultimPerm - 1].cost + graf.adj[ultimPerm - 1][nod - 1]) {
					rezultat[nod - 1].cost = rezultat[ultimPerm - 1].cost + graf.adj[ultimPerm - 1][nod - 1];
					rezultat[nod - 1].precedent = ultimPerm;
				}
				//4.2.2) Cautam varful cu costul minim si costul asociat
				if (rezultat[nod - 1].cost < costMinim) {
					costMinim = rezultat[nod - 1].cost;
					varfMinim = nod;
				}
			}
		}

		ultimPerm = varfMinim;
		permanente[ultimPerm - 1] = 1;
		//4.3) Adaugam varful gasit cu costul minim in permanente
	}
	//5) Dezalocari si furnizare rezultat
	delete(permanente);
	return rezultat;
};

// realizeaza constructia drumului de cost minim
// I: vectorul etichete construit de alg Dijkstra, varful curent
// E: -
void path(ETICHETA* etichete, int i) {
	if (i != -1) {
		path(etichete, etichete[i - 1].precedent);
		printf("%d ", i);
	}
};