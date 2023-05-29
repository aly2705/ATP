#include <stdio.h>
#include "Tipuri.h"
// biblioteca implementeaza operatiile simple de baza pop/push pentru o coada sau stiva

// initializeaza o structura de tip QS
int initQS(QS &qs, int maxSize) {
	int eroare;
	if (qs.space != NULL) {
		eroare = 1;
	}
	else {
		qs.max = maxSize;
		qs.size = 0;
		qs.space = new int[maxSize];
		eroare = 0;
	}
	return eroare;
}

// dezaloca structura QS
void cleanQS(QS& qs) {
	if (qs.space) delete qs.space;
	qs.space = NULL;
}

// adauga la finalul vectorului din structura QS o valoare 
// (operatiile de adaugare in coada/stiva se fac la finalul vectorului)
int pushQS(QS& qs, int valoare) {
	int eroare;
	if (qs.space == NULL) eroare = 2;
	else {
		if (qs.size == qs.max) {
			eroare = 1;
		}
		else {
			qs.space[qs.size++] = valoare;
			eroare = 0;
		}

	}
	return eroare;
}

int popQ(QS& q, int& extracted) {
	int eroare, i;
	if (q.space == NULL) {
		eroare = 1;
	}
	else {
		extracted = q.space[0];
		for (i = 0; i < q.size - 1; i++) {
			q.space[i] = q.space[i + 1];
		}
		q.size--;
		eroare = 0;
	}
	return eroare;
}

int popS(QS& s, int& extracted) {
	int eroare;
	if (s.space == NULL) {
		eroare = 1;
	}
	else {
		extracted = s.space[--s.size];
		eroare = 0;
	}

	return eroare;
}