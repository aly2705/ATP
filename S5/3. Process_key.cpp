#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef struct {
	int nrm;             //enrolment number - works as relative key
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
	char is;
} STUDENT;

int filesize(FILE* f, int rec_size)
{
	long crt_pos;
	int size;

	crt_pos = ftell(f);
	fseek(f, 0, SEEK_END);
	size = ftell(f) / rec_size;
	fseek(f, crt_pos, SEEK_SET);
	return size;
}

void main()
{
	char numefr[30] = "..\\Studenti_r.dat";
	FILE* f;
	STUDENT x;
	int i, key, dim;
	unsigned char new_grade;
	char ans[4];

	//convention: grade for ATP in position 5
	fopen(&f, numefr, "rb+");
	dim = filesize(f, sizeof(STUDENT));

	printf("Enrollment number: ");
	scanf("%d", &key);
	while (key != 0)
	{
		//check key range
		if (key >= dim)
			printf("\nThere is no student with this enrollment number. Try again?");
		else
		{
			//check if valid key
			fseek(f, key * sizeof(STUDENT), SEEK_SET);
			fread(&x, sizeof(STUDENT), 1, f);
			if (x.is == 0)
				printf("\nThere is no student with this enrollment number. Try again?");
			else
			{
				//process the record corresponding to the key
				//VISUALIZE
				printf("\nStudent: %s, Year: %d, Group: %d, ATP grade: %d\n", x.nume, x.an, x.grupa, x.note[5]);

				//UPDATE - comment the following section if not updating
				printf("\nNew grade (0 to leave unchanged): ");
				scanf("%hhi", &new_grade);       //read new value in separate variable
				if (new_grade != 0)                //confirm by entering a non zero new grade. zero means no change
				{ //change the record
					x.note[5] = new_grade;
					//overwrite the old record in the file
					fseek(f, ftell(f) - sizeof(STUDENT), 0);
					fwrite(&x, sizeof(STUDENT), 1, f);
					fseek(f, 0, 1);					//required to switch between "write" and "read" modes
					printf("\nModification saved!");
				}
				else
					printf("\nSkipping, no change.");
				//UPDATE end

				//DELETE - comment the following section if not deleting
				//printf("\nDelete (Y / Enter to skip): ");  //read confirmation
				//gets_s(ans); gets_s(ans);			//first call to clear the buffer                
				//if(ans[0]=='Y')  
				//{ //change the record
				//  x.is=0;
				//  //overwrite the old record in the file
				//  fseek(f,ftell(f)-sizeof(STUDENT),0);
				//  fwrite(&x,sizeof(STUDENT),1,f);
				//  fseek(f,0,1);
				//  printf_s("\nDeleted!");
				//}
				//else
				//  printf_s("\nSkipping, no change.");
				//DELETE end
			}
		}
		printf_s("\n\nEnrollment number (or 0): ");
		scanf_s("%d", &key);
	}

	fclose(f);
	fclose(stdin);

	printf("\nDone. Press a key.", numefr);
	_getch();
}