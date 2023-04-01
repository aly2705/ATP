#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef struct {
	int nrm;             //enrolment number
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
	char is;
} STUDENT;

void main()
{
	char numefr[30] = "..\\Studenti_r.dat";
	char numeft[30] = "..\\List_r.txt";
	FILE* f, *g;
	STUDENT x;
	int crt, j;

	f=fopen(numefr, "rb");
	if (!f)
		printf("\nYou have probably misplaced your file. Stopping here.");
	else
	{
		g=fopen(numeft, "wt");
		fprintf(g, "Crt. Nrm. %-30s %-14s Yr Gr. Grades", "Nume", "CNP");
		crt = 0;
		fread(&x, sizeof(STUDENT), 1, f);
		while (!feof(f))
		{
			if (x.is == 1)
			{
				fprintf(g, "\n%4d %4d %-30s %14s %2d %2d ", ++crt, x.nrm, x.nume, x.CNP, x.an, x.grupa);
				for (j = 0; j < 20; j++)
					fprintf(g, "%2d ", x.note[j]);
			}
			fread(&x, sizeof(STUDENT), 1, f);
		}

		fclose(g);
		fclose(f);
		printf("\nThe full list is in <%s>.", numeft);
	}

	printf("\nDone. Press a key", numeft);
	_getch();
}