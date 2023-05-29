#pragma once

// fisier cu antete pentru functii de afisare, alocare si dezalocare matrice

// I: adresa matricei (mat), numar linii (nrLinii), numar coloane (nrCol), titlul matricei (titlu = default NULL)
// E: -
void afisareMatrice(int** mat, int nrLinii, int nrCol, const char* titlu = 0);

// I: nrLinii, nrColoane
// E: adresa matricei
int** alocaMatrice(int nrLinii, int nrColoane);

// I: adresaMatricei, nrLinii
// E: adresaMatrcei setata NULL
void dezalocaMatrice(int** &mat, int nrLinii);

