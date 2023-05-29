#pragma once

#include "Tipuri.h"

// realizeaza constructia matricii de adiacenta in graf.adj din reprezentarea tabelara aflata in graf.tabel
int conversieMatriceAdiacenta(GRAF& graf);

// construieste in variabila 'graf' matricea reprezentarii tabelare a grafului, preluata dintr-un fisier cu date de forma:
/* nrVarfuri nrMuchii 
inceputMuchie sfMuchie pondere?
...
inceputMuchie(m) sfMuchie(m) pondere?
*/
// @ponderat: char = 0 - neponderat, 1 - ponderat
// @orientat: char = 0 - neorientat, 1 - orientat
// returneaza un cod: 0 - succes, 1 - eroare
int constructieReprezentareTabel(char *numeFisier, GRAF &graf, char ponderat=0, char orientat=0);

