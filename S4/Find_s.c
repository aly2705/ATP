#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include<string.h>

typedef struct {
	int nrm;             //enrollment number
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
} STUDENT;

void main()
{
	//char numefd[30] = "..\\Studenti_s.dat"; // daca e un nivel mai sus
    char numefd[30] = "Studenti_s.dat";
	FILE* f;
	STUDENT x;
	int vb;
	int snr;
	char sCNP[14];

	f=fopen(numefd, "rb");
	if (!f)
		printf("\nYou have probably misplaced your file. Stopping here.");
	else
	{
		printf("\nSearch enrollment nr.: "); scanf("%d", &snr);
		//printf("\nSearch CNP: "); gets(sCNP);
		while (!feof(stdin))
		{
			rewind(f); //fseek(f,0,0); fseek(f,0,SEEK_SET) 
            // FSEEK APEL: fseek()f, deplasament, reper)
            // UN ARTICOL INAPOI FATA DE CEL CURENT: fseek(f, f-sizeof(articol), 1) fseek(f, f-sizeof(articol), SEEK_CUR) fseek(f, ftell(f)-sizeof(articol), 0) 
			vb = 0;
			fread(&x, sizeof(STUDENT), 1, f);
			while ((!feof(f)) && (!vb))
			{
				if (x.nrm == snr)
				// if(!strcmp(x.CNP,sCNP))
				{
					vb = 1;
					printf("\nStudent: %s, Year: %d, Group: %d, ATP grade: %d\n", x.nume, x.an, x.grupa, x.note[5]);
				}
				fread(&x, sizeof(STUDENT), 1, f);
			}
			if (!vb)
				printf("\nNo such student.");
			printf("\nTry again? Search enrollment nr.(or CTRL+Z): "); scanf("%d", &snr);
			//printf("\nTry again? Search CNP (or CTRL+Z): "); gets(sCNP);
		}
		fclose(f);
	}

	printf("\nDone. Press a key");
	getch();
}