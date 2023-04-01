#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include<string.h>

typedef struct {
	int nrm;             //enrolment number
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
} STUDENT;

void main()
{
	char numefd[30] = "Studenti_s.dat", numeft[30];
	FILE* f,*g;
	STUDENT x;
	int crt;
	int sgr;


	f=fopen(numefd, "rb");
	if (!f)
		printf("\nYou have probably misplaced your file. Stopping here.");
	else
	{
		printf("\nSearch group nr.: "); scanf("%d", &sgr);
		while (sgr!=0)
		{
			sprintf(numeft, "Group_%d.txt", sgr); // construieste un text si il scrie intr-o variabila
			g = fopen(numeft, "wt");
			fprintf(g, "ATP grades for students in group %d", sgr);
			fprintf(g, "\n\nCrt. Nrm. %-29s %-13s ATP grade", "Nume", "CNP");
			rewind(f);
			crt = 0;
			fread(&x, sizeof(STUDENT), 1, f);
			while (!feof(f))
			{
				if (x.grupa == sgr)
					fprintf(g, "\n%4d %4d %-29s %-13s %2d", ++crt, x.nrm, x.nume, x.CNP, x.note[5]);
				fread(&x, sizeof(STUDENT), 1, f);
			}
			fclose(g);
			if (!crt)
			{
				printf("\nNo students in group %d", sgr);
				remove(numeft); // fisierul trb sa fie inchis
			}
			else
				printf("\nList of students for group %d available in file %s", sgr, numeft);
			printf("\n\n\nTry again? Search group nr.(or 0 for exit): "); 
			scanf("%d", &sgr);
		}
		fclose(f);
	}
	printf("\nDone. Press a key");
	_getch();
}