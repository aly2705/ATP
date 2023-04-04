/* Programul realizeaza diminuarea cu 10% a valorii de inventar pentru obiectele achiziționate înainte de un an dat 
de la tastatură. 
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
    int anRef;

    f = fopen(numeFisier, "rb+");
    if(!f) printf("Fisierul nu a fost gasit. Se opreste programul...");
    else {
        printf("\nIntroduceti anul de referinta: ");
        scanf("%d", &anRef);

        fread(&obj, sizeof(OBIECT), 1, f);
        while(!feof(f)){
            if(obj.is == 1 && anRef > obj.dataAchizitiei.an){
                //vizualizare
                //printf("\n%6d %-30s %-20s %-30s %d/%hhi/%-10d %.2f", obj.numar, obj.denumire, obj.tip, obj.numeGestionar, obj.dataAchizitiei.zi, obj.dataAchizitiei.luna, obj.dataAchizitiei.an, obj.valoare);
                float valoareNoua = 0.9*obj.valoare;
                obj.valoare = valoareNoua;
                fseek(f, ftell(f)-sizeof(OBIECT), SEEK_SET);
                fwrite(&obj, sizeof(OBIECT), 1, f);
                fseek(f, 0, 1);
            }
            fread(&obj, sizeof(OBIECT), 1, f);
        }
        fclose(f); 
        printf("\nActualizarile au fost facute!");
    }
    printf("\nGata. Apasa o tasta ");
    _getch();
}