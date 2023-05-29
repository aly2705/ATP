#pragma once

#define INF 10000

// tipul contine informatiile despre GRAF, cu restrictia ca ponderile sunt intregi (daca e graf ponderat)
typedef struct {
	int n; // numar varfuri (noduri)
	int m; // numar muchii
	int orientat; // 0-nu, 1-da
	int ponderat; // 0-nu, 1-da
	int** tabel; // matrice asociata reprezentarii tabelare a grafului (m linii si 2 sau 3 coloane pt neponderat respectiv ponderat
	int** adj;  // matricea de adiacenta a grafului 
				// (simetrica pt grafuri neorientate, avand 0 sau 1 ca elemente pt grafuri neponderate si ponderea sau INF pt ponderate
} GRAF;

// coada sau stiva - structuri folosite pentru parcurgeri
typedef struct {
	int size; // dimensiunea actuala a stivei/cozii (cate elemente contine)
	int max; // dimensiunea maxima a stivei/cozii
	int* space; // vectorul alocat dinamic corespunzator stivei/cozii
} QS;
