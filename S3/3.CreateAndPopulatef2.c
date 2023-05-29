#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
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
	char nameb[30] = "..\\Studenti_s_f2.dat";
	char namet[30] = "Input.txt";
	FILE* f;
	FILE *g;
	STUDENT x;
	int i;
		
	printf("Text file name (used as input): ");
	gets(namet);

	g = fopen(namet, "rt");
	if (!g)
		printf("File %s can not be opened. Maybe you misplaced your file.",namet);
	else
	{
		printf("New binary file name: ");
		gets(nameb);
		f = fopen(nameb, "wb");

		fscanf(g,"%d", &x.nrm);
		while (!feof(g))
		{
			fgets(x.nume, 30, g);
			fgets(x.nume, 30, g);
			x.nume[strcspn(x.nume, "\n")] = 0;

			fgets(x.CNP,14,g);
			x.nume[strcspn(x.nume, "\n")] = 0;

			fscanf(g,"%d", &x.an);

			fscanf(g,"%d", &x.grupa);
			for (i = 0; i < 20; i++)
				fscanf(g, "%hhi", &x.note[i]);
			fwrite(&x, sizeof(STUDENT), 1, f);

			fscanf(g,"%d", &x.nrm);
		}

		fclose(g);
		fclose(f);
		printf("\n\nFile <%s> was created.", nameb);
	}
	printf("\n\nDone, press a key to finish...");
	_getch();
}