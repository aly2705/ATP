/* Programul permite modificarea de la tastatura a valorii unui automobil identificat prin introducerea unui numar de inmatriculare*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
    char nrInmat[12];
    char marca[20];
    int anFabricatie;
    long nrKm;
    float valoare;
} AUTOMOBIL;

void main(){
    // Declaratii
    FILE *fisier;
    AUTOMOBIL x;
    char numeFisier[20] = "..\\Automobile.dat";
    char nrInmatriculare[12];

    // Deschidere fisier
    fisier = fopen(numeFisier, "rb+");

    // Testare existenta fisier
    if(!fisier) printf("Nu am putut deschide fisierul. Se opreste programul...");
    else {
        // Citire primul numar de inmatriculare
        printf("Introduceti numarul de inmatriculare: ");
        gets(nrInmatriculare);

        // Bucla algoritmului de parcurgere secventiala cu fisier conducator
        while(!feof(stdin)){
            int gasit = 0;
            // Plasare pointer la inceputul fisierului
            fseek(fisier, 0, SEEK_SET);
            
            // Aducere in memorie
            fread(&x, sizeof(AUTOMOBIL), 1, fisier);

            // Parcurgere si cautare nr inmatriculare
            while(!feof(fisier) && !gasit){
                if(strcmp(x.nrInmat, nrInmatriculare) == 0){
                    // Gasim numarul cautat
                    float valoareNoua;
                    gasit=1;

                    // Afisare pe ecran
                    printf("\nAutomobilul gasit este:");
                    printf("\n%-12s %-20s %2d %-7li %.2f", x.nrInmat, x.marca, x.anFabricatie, x.nrKm, x.valoare);

                    // Introducere valoare noua (si confirmare a schimbarii)
                    printf("\nIntroduceti noua valoare a automobilului sau 0 pentru anularea actiunii: ");
                    scanf("%f", &valoareNoua);
                    if(valoareNoua){
                        // Modificare in memoria interna
                        x.valoare = valoareNoua;
                        printf("\nValoarea a fost actualizata cu succes");
                        // Plasare pointer la inceputul articolului care trebuie modificat
                        fseek(fisier, ftell(fisier) - sizeof(AUTOMOBIL), SEEK_SET);
                        // Suprascriere in fisier
                        fwrite(&x, sizeof(AUTOMOBIL), 1, fisier);
                        // Pregatire pentru o noua citire
                        fseek(fisier, 0, 1);
                    }else {
                        printf("\nActiune anulata");
                    }
                }
                fread(&x, sizeof(AUTOMOBIL), 1, fisier);
            }
            // Finalul fisierului si nu a fost gasit?
            if(!gasit){
                // Mesajul pentru utilizator ca automobilul nu a fost gasit
                printf("\nNu am putut gasi automobilul cu numarul %s!", nrInmatriculare);
            
            }

            // Alt automobil? 
            printf("\n\nIntroduceti un numar de inmatriculare sau CTRL+Z pentru iesire: ");
            if(gasit) gets(nrInmatriculare);
            gets(nrInmatriculare);
        }

        // Inchidere fisier
        fclose(fisier);
    }

    // Finalizare
    printf("Gata. Apasa o tasta...");
    _getch();
}