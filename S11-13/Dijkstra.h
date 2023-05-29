#pragma once

#include "Tipuri.h"

typedef struct {
	float cost;
	int precedent;
}ETICHETA;

// aplica algoritmul Dijkstra pentru aflarea drumurilor de cost minim de la un varf initial la toate celalalte varfuri
// I: graful, varful initial
// E: vectorul de etichete (indexul etichetei - nodul coresp etichetei)
ETICHETA* Dijkstra(GRAF graf, int varfInit);

// realizeaza constructia drumului de cost minim
// I: vectorul etichete construit de alg Dijkstra, varful curent
// E: -
void path(ETICHETA* etichete, int i);