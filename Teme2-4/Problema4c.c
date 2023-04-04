/* Programul realizeaza eliminarea obiectelor ale căror numere de inventar se dau de la tastatură 
Mentiune: este nevoie de crearea initiala a unui fisier binar cu ajutorul programului din Problema4a.c */
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

void main(){
    FILE *f;
    char numeFisier[30] = "..\\ObiecteInventar.dat";
    OBIECT obj;
    int numarIntrodus;

    f = fopen(numeFisier, "rb+");
    if(!f) printf("Nu s-a putut deschide fisierul.");
    else {
        printf("Introduceti numarul de inventar al obiectului de sters(>=1100): ");
        scanf("%d", &numarIntrodus);

        while(numarIntrodus){
            int raspuns;
            fseek(f, (numarIntrodus-START)*sizeof(OBIECT), SEEK_SET);
            fread(&obj, sizeof(OBIECT), 1, f);
            if(obj.is == 1){
                //vizualizare
                printf("\nObiectul este: ");
                printf("\n%6d %-30s %-20s %-30s %d/%hhi/%-10d %.2f", obj.numar, obj.denumire, obj.tip, obj.numeGestionar, obj.dataAchizitiei.zi, obj.dataAchizitiei.luna, obj.dataAchizitiei.an, obj.valoare);
                printf("\nIntroduceti 1 daca doriti stergerea, 0 pentru anulare: ");
                scanf("%d", &raspuns);
                if(raspuns == 1){
                    //stergere
                    obj.is = 0;
                    fseek(f, (numarIntrodus-START)*sizeof(OBIECT), SEEK_SET);
                    fwrite(&obj, sizeof(OBIECT), 1, f);
                    printf("\nStergere reusita");
                } else {
                    printf("\nStergere anulata");
                }
            }else {
                printf("\nNu exista un obiect cu numarul %d.", numarIntrodus);
            }
            printf("\nIntroduceti numarul de inventar al obiectului de sters(>=1100) sau 0 pentru iesire: ");
            scanf("%d", &numarIntrodus);
        }
    }
}