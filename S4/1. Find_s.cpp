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
	char numefd[30] = "..\\Studenti_s.dat";
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
		//printf("\nSearch CNP: "); gets_s(sCNP);
		while (!feof(stdin))
		{
			rewind(f);
			vb = 0;
			fread(&x, sizeof(STUDENT), 1, f);
			while ((!feof(f)) && (!vb))
			{
				if (x.nrm == snr)
				//if(!strcmp(x.CNP,sCNP))
				{
					vb = 1;
					printf("\nStudent: %s, Year: %d, Group: %d, ATP grade: %d\n", x.nume, x.an, x.grupa, x.note[5]);
				}
				fread(&x, sizeof(STUDENT), 1, f);
			}
			if (!vb)
				printf("\nNo such student.");
			printf("\nTry again? Search enrollment nr.(or CTRL+Z): "); scanf_s("%d", &snr);
			//printf("\nTry again? Search CNP (or CTRL+Z): "); gets_s(sCNP);
		}
		fclose(f);
	}

	printf_s("\nDone. Press a key");
	_getch();
}