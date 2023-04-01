/* 
Programul creeaza si populeaza un fisier binar cu articole de tip AUTOMOBIL
(de la tastatura sau din fisier text in functie de configuratie) 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

#define CITIRE_TASTATURA 0 // 1 pentru citire de la tastatura, 2 pentru citire din fisier text (ex: input.txt)

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
    char numeFisier[30] = "..\\Automobile.dat";
    AUTOMOBIL x;

    // Deschidere fisier
    fisier = fopen(numeFisier, "wb");

    //CITIRE_TASTATURA are rolul de a schimba stdin(tastatura) cu fisierul text si de a activa/dezactiva printf-urile in functie de nevoie
    if(!CITIRE_TASTATURA) freopen("input.txt", "rt", stdin);

    if(!fisier) printf("Nu s-a putut deschide fisierul");
    else{
    //Introducere date
    if(CITIRE_TASTATURA) printf("Introduceti nr inmatriculare: ");
    gets(x.nrInmat);

    while(!feof(stdin)){
        if(CITIRE_TASTATURA) printf("Marca: "); 
        gets(x.marca);

        if(CITIRE_TASTATURA) printf("An Fabricatie: "); 
        scanf("%d", &x.anFabricatie);

        if(CITIRE_TASTATURA) printf("Nr Km: "); 
        scanf("%li", &x.nrKm);

        if(CITIRE_TASTATURA) printf("Valoarea: "); 
        scanf("%f", &x.valoare);   

        //Scriere articol in fisierul binar
        fwrite(&x, sizeof(AUTOMOBIL), 1, fisier);

        //Incercare citire articol nou dupa numarul de inmatriculare
        if(CITIRE_TASTATURA) printf("\n\nNr Inmatriculare sau CTRL+Z pentru iesire: ");
        gets(x.nrInmat);
        gets(x.nrInmat); // repetitia este necesara atunci cand se citeste un string cu gets DUPA O DATA NUMERICA
    }

    fclose(fisier);
    }

    printf("\nFinalizare. Apasati orice tasta");
    _getch();
}