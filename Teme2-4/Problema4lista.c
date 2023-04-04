#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define START 1100

typedef struct {
    int zi;
    char luna; 
    int an;
} DATA;

typedef struct {
    int numar; // cheie relativa
    char denumire[30];
    char tip[20];
    float valoare;
    char numeGestionar[30];
    DATA dataAchizitiei;
    int is; // camp indicator de stare
} OBIECT;


void listareObiecte(FILE *f){
    char numeLista[30] = "..\\ListaObiecte.txt";
    FILE *g;
    int crt=0;
    OBIECT obj;

    g = fopen(numeLista, "wt");
    fprintf(g, "%4s %6s %-30s %-20s %-30s %-15s %-8s", "Crt.", "Numar", "Denumire", "Tip", "Nume Gestionar", "Data achizitie","Valoare");
    fseek(f, 0, SEEK_SET);
    fread(&obj, sizeof(OBIECT), 1, f);
    while(!feof(f)){
        if(obj.is == 1){
            fprintf(g, "\n%4d %6d %-30s %-20s %-30s %d/%hhi/%-10d %.2f", ++crt, obj.numar, obj.denumire, obj.tip, obj.numeGestionar, obj.dataAchizitiei.zi, obj.dataAchizitiei.luna, obj.dataAchizitiei.an, obj.valoare);
        }
        fread(&obj, sizeof(OBIECT), 1, f);
    }
    fclose(g);
    if(!crt) {
        remove(numeLista);
        printf("\nListare esuata. Nu au fost gasite obiecte de inventar.");
    }else {
        printf("\nLista a fost creata cu succes. Locatie: <%s>", numeLista);
    }
}

void main(){
    FILE *f;
    char numeFisier[30] = "..\\ObiecteInventar.dat";

    f = fopen(numeFisier, "rb");
    if(!f) printf("\nFisierul nu a fost gasit!");
    else {
        listareObiecte(f);
        fclose(f);
    }
    printf("\nGata. Apasa o tasta pentru iesire: ");
    _getch();
}