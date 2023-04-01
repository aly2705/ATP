/* Programul listeaza intr-un fisier MasiniVechi.txt autoturismele mai vechi de 10 ani si cu peste 300000 km*/

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
    // Declaratii
    FILE *f, *g;
    char numeF[20] = "..\\Automobile.dat";
    char numeG[20] = "..\\MasiniVechi.txt";
    AUTOMOBIL x;
    int anCurent = 2023;

    //Deschidere fisier
    f = fopen(numeF, "rb+");

    if(!f) printf("\nNu s-a putut deschide fisierul. Se opreste aici...");
    else {
        g=fopen(numeG, "wt");
        fprintf(g, "%4s %-12s %-20s %-4s %-2s %9s", "Crt.", "Numar", "Marca", "An", "Nr Km", "Valoare");
        int crt = 0;
        fread(&x, sizeof(AUTOMOBIL),1, f);
        while(!feof(f)){
            if(anCurent-x.anFabricatie>10 && x.nrKm>300000){
                fprintf(g,"\n%4d %-12s %-20s %2d %-7li %.2f", ++crt, x.nrInmat, x.marca, x.anFabricatie, x.nrKm, x.valoare);
            }
            fread(&x, sizeof(AUTOMOBIL), 1, f);
        }
        fclose(g);
        if(!crt) {
            printf("\nNu a fost gasit niciun automobil vechi.");
            remove(numeG);
        } else {
            printf("\nLista a fost creata cu succes si se afla in %s", numeG);
        }
        fclose(f);
    }
    printf("\n\nFinalizare. Apasa orice tasta pentru iesire: ");
    _getch();
}