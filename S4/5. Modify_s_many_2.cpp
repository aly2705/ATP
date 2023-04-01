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
	char numefd[30] = "..\\Studenti_s.dat";
	FILE* f;
	STUDENT x;
	int vb;
	int sgr;

	//update ATP grade
	f = fopen(numefd, "rb+");
	if (!f)
		printf("\nYou have probably misplaced your file. Stopping here.");
	else
	{
		printf("\nSearch group nr.: ");		//replace to change search criteria
		scanf("%d", &sgr);
		while (sgr != 0)							//use 0 as conventional value to end processing
		{
			rewind(f);
			vb = 0;
			fread(&x, sizeof(STUDENT), 1, f);
			while (!feof(f))				//if searching for multiple records remove second part of the condition
			{
				if (x.grupa == sgr)
				{
					vb = 1;   //found
					//visualize
					//convention: grade for ATP in position 5
					//printf("\nStudent: %s, ATP grade: %d\n", x.nume, x.note[5]);
					//update
					x.note[5] +=1;
					if (x.note[5] > 10)
						x.note[5] = 10;
					//overwrite the old record in the file
					fseek(f, ftell(f) - sizeof(STUDENT), 0);
					fwrite(&x, sizeof(STUDENT), 1, f);
					fseek(f, 0, 1);					//required to switch between "read" and "write" modes
				}
				fread(&x, sizeof(STUDENT), 1, f);
			}
			if (!vb)
				printf("\nNo students in group %d",sgr);
			printf("\n\nTry again? Search group nr. (0 to stop): ");
			scanf("%d", &sgr);
		}
		fclose(f);
	}
	printf("\nDone. Press a key");
	_getch();
}