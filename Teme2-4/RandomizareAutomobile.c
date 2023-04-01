#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int genereazaNumar(int min, int max){
    double random = (double)rand()/RAND_MAX*(max-min) + min;
    return (double)rand()/RAND_MAX*(max-min) + min;
}

char* genereazaNrInmat(char *nrInmat){
    char judete[8][3] = {"B","CT", "IF", "GJ", "DJ", "BV", "TM"};
    char judet[3];
    strcpy(judet, judete[genereazaNumar(0,6)]);
    char litera1[2] = {(char)genereazaNumar(65, 90)};
    char litera2[2] = {(char)genereazaNumar(65, 90)};
    char litera3[2] = {(char)genereazaNumar(65, 90)};
    char numar[4] = {(char)genereazaNumar(48,57), (char)genereazaNumar(48,57), (char)genereazaNumar(48,57)};
    
    strcpy(nrInmat, judet); strcat(nrInmat, "-");
    strcat(nrInmat, numar); strcat(nrInmat, "-");
    strcat(nrInmat, litera1);
    strcat(nrInmat, litera2);
    strcat(nrInmat, litera3);
    return nrInmat;
}

char* genereazaMarca(char* marca){
    char marci[12][20] = {"Nissan", "Seat",  "Audi", "Chevrolet", "Jeep", "Jaguar", "Mitsubishi", "Land Rover", "Alfa Romeo", "Peugeot", "Renault"}; 
    strcpy(marca, marci[genereazaNumar(0,11)]);
    return marca;
}

void main(){
    FILE *output;
    char numeFisier[20] = "input.txt";

    output = fopen(numeFisier, "wb");
    if(!output) printf("Nu s-a putut deschide fisierul. Apasati o tasta pentru a confirma inchiderea programului.");
    else {

    char nrInmat[12], marca[20];
    for(int i=0; i<100; i++){
        fprintf(output,"%s\n", genereazaNrInmat(nrInmat));
        fprintf(output,"%s\n", genereazaMarca(marca));
        fprintf(output, "%d\n", genereazaNumar(1998, 2023));
        fprintf(output, "%li\n", (long)genereazaNumar(0, 999)*1000);
        fprintf(output, "%.2f\n", (float)genereazaNumar(4, 60)*1000);
    }
    fclose(output);
    printf("Fisierul creat este: <%s>. Apasati o tasta pentru incheierea programului", numeFisier);
    
    }
    _getch();
}