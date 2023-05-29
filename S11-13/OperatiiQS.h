#pragma once
#include <stdio.h>
#include "Tipuri.h"
// biblioteca implementeaza operatiile simple de baza pop/push pentru o coada sau stiva

// initializeaza o structura de tip QS
// I: variabila in care se construieste structura, dimensiunea maxima
// E: structura initializata, cod eroare (1 - structura deja initializata, 0 - succes)
int initQS(QS& qs, int maxSize);

// dezaloca structura QS (vectorul qs.space)
// I: structura
// E: structura curatata
void cleanQS(QS& qs);

// adauga la finalul vectorului din structura QS o valoare 
// (operatiile de adaugare in coada/stiva se fac la finalul vectorului)
// I: structura, valoarea de adaugat
// E: structura actualizata, cod eroare (2 - struct neinitializata, 1 - structura de dimensiune maxima, 0 - succes)
int pushQS(QS& qs, int valoare);

// scoate de la o valoare de la inceputul vectorului (tip coada) 
// I: structura de tip coada
// E: structura de tip coada actualizata, elementul extras, cod eroare (1 - coada qoala, 0 - succes)
int popQ(QS& q, int& extracted);

// scoate de la o valoare de la finalul vectorului (tip stiva) 
// I: structura de tip stiva
// E: structura de tip stiva actualizata, elementul extras, cod eroare (1 - stiva qoala, 0 - succes)
int popS(QS& s, int& extracted);