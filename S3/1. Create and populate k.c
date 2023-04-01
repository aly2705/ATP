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
} STUDENT;

void main()
{
	char numef[30] = "..\\Studenti_s_k.dat";
	FILE* f;
	STUDENT x;
	int i;

	printf("File name: ");
	gets_s(numef);
	f=fopen(numef, "wb");

	printf("Enrollment number: ");
	scanf("%d", &x.nrm);
	while(x.nrm!=0)			//convention, to avoid microsoft issues
	//while (!feof(stdin))	//replace with another convention in visual studio
	{						//for example while(x.nrm) to stop when a zero is entered
		printf("CNP: "); /*fflush(stdin);*/ gets_s(x.CNP); gets_s(x.CNP);
		printf("Name: "); gets_s(x.nume);
		printf("Year: "); scanf("%d", &x.an);
		printf("Group: "); scanf("%d", &x.grupa);
		for (i = 0; i < 20; i++)
			x.note[i] = 0;
		fwrite(&x, sizeof(STUDENT), 1, f);
		printf("Enrollment number: ");
		scanf("%d", &x.nrm);
	}

	fclose(f);

	printf("\nDone. File <%s> was created. Press a key...", numef);
	_getch();
}