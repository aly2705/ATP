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
	char numef[30] = "..\\Studenti_s_f1.dat";
	FILE* f;
	STUDENT x;
	int i;

	//printf("Name for the new binary file: ");
	//gets_s(numef);
	f=fopen_s(numef, "wb");
	freopen("..\\Input.txt", "rt", stdin);

	//printf("Enrollment number: ");
	scanf("%d", &x.nrm);
	while (!feof(stdin))	
	{						
		//printf_s("Name: "); /*fflush(stdin);*/ 
		gets_s(x.nume); gets_s(x.nume);
		//printf_s("CNP: "); 
		gets_s(x.CNP);
		//printf_s("Year: "); 
		scanf("%d", &x.an);
		//printf_s("Group: "); 
		scanf("%d", &x.grupa);
		for (i = 0; i < 20; i++)
			scanf("%hhi", &x.note[i]);		//!!!
		fwrite(&x, sizeof(STUDENT), 1, f);
		//printf_s("Enrollment number: ");
		scanf("%d", &x.nrm);
	}

	fclose(f);

	printf("\nDone. File <%s> was created. Press a key...", numef);
	_getch();
}