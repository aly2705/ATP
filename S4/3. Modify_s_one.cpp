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
	int snr;
	unsigned char new_grade;  

	//update ATP grade
	f=fopen(numefd, "rb+");
	if (!f)
		printf("\nYou have probably misplaced your file. Stopping here.");
	else
	{
		printf("\nSearch enrollment nr.: ");		//replace to change search criteria
		scanf("%d", &snr);
		while (snr != 0)							//use 0 as conventional value to end processing
		{
			rewind(f);
			vb = 0;
			fread(&x, sizeof(STUDENT), 1, f);
			while ((!feof(f)) && (!vb))				//if searching for multiple records remove second part of the condition
			{
				if (x.nrm == snr)
				{
					vb = 1;   //found
					//visualize
					//convention: grade for ATP in position 5
					printf("\nStudent: %s, Year: %d, Group: %d, ATP grade: %d\n", x.nume, x.an, x.grupa, x.note[5]);
					//update
					printf("\nNew grade (0 to leave unchanged): ");
					scanf("%hhi", &new_grade);       //read new value in separate variable
					if (new_grade != 0)              //confirm by entering a non zero new grade. zero means no change
					{ //change the record
						x.note[5] = new_grade;
						//overwrite the old record in the file
						fseek(f, ftell(f) - sizeof(STUDENT), 0);
						fwrite(&x, sizeof(STUDENT), 1, f);
						fseek(f, 0, 1);					//required to switch between "read" and "write" modes
					}
				}
				fread(&x, sizeof(STUDENT), 1, f);
			}
			if (!vb)
				printf("\nNo such student.");
			printf("\nTry again? Search enrollment nr. (0 to stop): ");
			scanf("%d", &snr);
		}
		fclose(f);
	}

	printf_s("\nDone. Press a key");
	_getch();
}