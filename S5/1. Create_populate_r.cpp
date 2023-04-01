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

	f=fopen(numefr, "wb+");
	//optionally preform the file

	freopen("..\\input.txt", "rt", stdin);  //remove if reading data from keyboard and uncomment the printf lines

	//printf("Enrollment number: ");
	scanf("%d", &key);
	while (!feof(stdin))
	{
		//check key range
		dim = filesize(f, sizeof(STUDENT));
		if (key >= dim)
		{ //extend the file
			x.is = 0;
			fseek(f, 0, SEEK_END);
			for (i = 0; i < key - dim; i++)
				fwrite(&x, sizeof(STUDENT), 1, f);
		}
		//check if available position
		fseek(f, key * sizeof(STUDENT), SEEK_SET);
		fread(&x, sizeof(STUDENT), 1, f);
		if (x.is == 1)
			printf("\nError: duplicate key %d. Skipping.", key);
		else
		{
			x.nrm = key;
			//printf("Name: ");
			gets_s(x.nume);
			gets_s(x.nume);
			//printf("CNP: ");
			gets_s(x.CNP);
			//printf("Year: "); 
			scanf("%d", &x.an);
			//printf("Group: ");
			scanf("%d", &x.grupa);
			for (i = 0; i < 20; i++)
				//x.note[i]=0;
				scanf_s("%hhi", &x.note[i]);
			x.is = 1;
			fseek(f, key * sizeof(STUDENT), SEEK_SET);
			fwrite(&x, sizeof(STUDENT), 1, f);
		}
		//printf("Enrollment number (or CTRL+Z): ");
		scanf("%d", &key);
	}

	fclose(f);
	fclose(stdin);

	printf("\nDone. File <%s> was created. Press a key.", numefr);
	_getch();
}