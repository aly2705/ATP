/* Programul creeaza si populeaza un fisier binar cu obiecte de inventar organizate relativ dupa numarul de inventar */

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

// subprogramul returneaza numarul de articole care incap in fisierul binar la momentul apelului
int filesize(FILE *f, int dimArticol){
    long pozitieCurenta;
    int spatiuTotal;

    pozitieCurenta = ftell(f);
    fseek(f, 0, SEEK_END); // plasare la finalul fisierului
    spatiuTotal = ftell(f) / dimArticol; // aflare spatiu
    fseek(f, pozitieCurenta, SEEK_SET); // repozitionare
    return spatiuTotal;
}

void listareObiecte(FILE *f){
    char numeLista[30] = "..\\ListaObiecte.txt";
    FILE *g;
    int crt=0;
    OBIECT obj;

    g = fopen(numeLista, "wt");
    fprintf(g, "%4s %6s %-30s %-20s %-30s %-15s %-8s", "Crt.", "Numar", "Denumire", "Tip", "Nume Gestionar", "Data achizitie","Valoare");
    fseek(f,0,SEEK_SET);
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
        printf("\nA fost creata o lista cu articolele introduse <%s>", numeLista);
    }
}

void main(){
    FILE *f;
    char numeFisier[30] = "..\\ObiecteInventar.dat";
    OBIECT obj;
    int i, cheie, dim;
    int creareSiListare = 0;

    f=fopen(numeFisier, "rb+");

    if(!f) printf("Nu s-a putut deschide fisierul. Se opreste aici...");
    else {

    printf("Introduceti numarul de inventar: ");
    scanf("%d", &cheie);

    while(cheie != -1){
        // cautam daca avem spatiu fizic
        dim = filesize(f, sizeof(OBIECT));
        if((cheie-START) >= dim){
            //extindere fisier
            obj.is = 0;
            fseek(f, 0, SEEK_END); //plasare la final
            for(i=0; i< (cheie-START) - dim; i++){
                fwrite(&obj, sizeof(OBIECT), 1, f);
            }
        }
        // verificare daca pozitia este valabila
        fseek(f, (cheie-START)*sizeof(OBIECT), SEEK_SET); // pozitionare la locul indicat de cheie
        fread(&obj, sizeof(OBIECT), 1, f);
        if(obj.is == 1){
            printf("\nCheie duplicat %d. Incercati o alta cheie. ", cheie);
        } else {
            // pozitie libera, se scrie in fisier
            obj.numar = cheie;
            printf("Denumire obiect: ");
            gets(obj.denumire);
            gets(obj.denumire);
            printf("Tip obiect: ");
            gets(obj.tip);
            printf("Data achizitiei: ");
            printf("\nZi: ");
            scanf("%d", &obj.dataAchizitiei.zi);
            printf("Luna: ");
            scanf("%hhi", &obj.dataAchizitiei.luna);
            printf("An: ");
            scanf("%d", &obj.dataAchizitiei.an);
            printf("Valoarea obiectului: ");
            scanf("%f", &obj.valoare);
            printf("Numele gestionarului: ");
            gets(obj.numeGestionar);
            gets(obj.numeGestionar);
            obj.is = 1;
            fseek(f, (cheie-START)*sizeof(OBIECT), SEEK_SET); //repozitionare
            fwrite(&obj, sizeof(OBIECT), 1, f);
        }
        printf("\nIntroduceti un numar de inventar (>=1100) sau -1 pentru iesire: ");
        scanf("%d", &cheie);
    }
    listareObiecte(f);
    fclose(f);
    }
    printf("Gata. Apasa o tasta pentru a iesi...");
    _getch();
}