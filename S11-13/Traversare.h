#pragma once
#include "Tipuri.h"

// Parcurgere in latime - Breadth First
// I: graf, varf initial
// E: vectorul varfurilor vizitate, numarul varfurilor vizitate
void BF(GRAF graf, int varfInit, int* &parcurgere, int &nrVizitate);


// Parcurgere in adancime - Depth First
// I: graf, varf initial
// E: vectorul varfurilor vizitate, numarul varfurilor vizitate
void DF(GRAF graf, int varfInit, int* &parcurgere, int &nrVizitate);