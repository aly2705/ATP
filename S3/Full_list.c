#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

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
	char numefd[30], numeft[30];
	FILE* f, *g;
	STUDENT x;
	int crt, j;


	//strcpy(numefd, "..\\Studenti_s_f1.dat"); strcpy(numeft, "..\\Report1.txt");
	strcpy(numefd, "..\\Studenti_f2.dat"); strcpy(numeft, "..\\Report2.txt");

	f = fopen(numefd, "rb");
	//fopen(&f, numefd, "rb");
	if (!f)
		printf("\nYou have probably misplaced your file. Stopping here.");
	else
	{
		//fopen(&g, numeft, "wt");
		g = fopen(numeft, "wt");
		fprintf(g, "%4s %4s %-30s %-14s %2s %4s %4s", "Crt.", "Nrm.", "Nume", "CNP", "An", "Gr.", "Note");
		crt = 0;
		fread(&x, sizeof(STUDENT), 1, f);
		while (!feof(f))
		{
			fprintf(g, "\n%4d %4d %-30s %-14s %2d %2d ", ++crt, x.nrm, x.nume, x.CNP, x.an, x.grupa);
			for (j = 0; j < 20; j++)
				fprintf(g, "%2d ", x.note[j]);
			fread(&x, sizeof(STUDENT), 1, f);
		}

		fclose(g);
		fclose(f);
		printf("\nThe full list is in <%s>.", numeft);
	}

	printf("\nDone. Press a key");
	_getch();
}