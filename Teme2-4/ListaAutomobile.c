/* Programul creeaza un fisier text cu o lista stil tabel care contine date despre articolele de tip AUTOMOBIL 
aflate in fisierul preinitializat Automobile.dat */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef struct {
    char nrInmat[12];
    char marca[20];
    int anFabricatie;
    long nrKm;
    float valoare;
} AUTOMOBIL;

void main(){
    // Declaratii (2 fisiere, numele lor, o variabila de tip AUTOMOBIL, crt - numar folosit la numerotarea articolelor)
    FILE *f, *lista;
    AUTOMOBIL x;
    char numef[20] = "..\\Automobile.dat";
    char numer[30] = "..\\ListaAutomobile.txt";
    int crt;

    // Deschidere pentru citire (r) a unui fisier binar (b)
    f = fopen(numef, "rb");
   
    if(!f){
        printf("Fisierul nu a fost gasit. Se oprește programul");
    } else {
        // Fisierul lista se deschide pentru a scrie in el (w) si este de tip text (t)
        lista = fopen(numer, "wt");
        // Formatare cap de tabel si initializare nr curent
        fprintf(lista,"%4s %-12s %-20s %-4s %-2s %9s", "Crt.", "Numar", "Marca", "An", "Nr Km", "Valoare");
        crt=0;
        
        // Citire articol din fisier conducator (cel binar in acest caz)
        fread(&x, sizeof(AUTOMOBIL), 1, f);

        while(!feof(f)){
            // Formatare date direct in fisierul text
            fprintf(lista, "\n%4d %-12s %-20s %2d %-7li %.2f", ++crt, x.nrInmat, x.marca, x.anFabricatie, x.nrKm, x.valoare);
            // Incercare citire noua
            fread(&x, sizeof(AUTOMOBIL), 1, f);
        }

        fclose(f); fclose(lista);

        printf("\nFisierul lista a fost creat cu succes <%s>.", numer);
        
    }

    printf("\nGata. Apasa o tasta pentru a parasi programul!");
    _getch();
}