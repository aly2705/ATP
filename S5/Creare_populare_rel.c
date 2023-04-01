#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define START 1000

typedef struct {
	int nrm;             //enrolment number - works as relative key (can be kept or not)
	char CNP[14];        //string ASCIIZ
	char nume[30];       //string
	int an;              //study year
	int grupa;           //group
	unsigned char note[20];  //grades
	char is; // CAMP INDICATOR DE STARE
} STUDENT;

int filesize(FILE* f, int rec_size)
{
	long crt_pos;
	int size;

	crt_pos = ftell(f);
	fseek(f, 0, SEEK_END);
	size = ftell(f) / rec_size;
	fseek(f, crt_pos, SEEK_SET); // no side-effects
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

	//freopen("..\\input.txt", "rt", stdin);  //remove if reading data from keyboard and uncomment the printf lines

	printf("Enrollment number: ");
	scanf("%d", &key);
	//while (!feof(stdin))
    while (key)
	{
		//check key range
		dim = filesize(f, sizeof(STUDENT));
		if ((key-START) >= dim)
		{ //extend the file
			x.is = 0;
			fseek(f, 0, SEEK_END); // sfarsitul 
			for (i = 0; i <= (key-START) - dim; i++)
				fwrite(&x, sizeof(STUDENT), 1, f);
		}
		//check if available position
		fseek(f, (key-START) * sizeof(STUDENT), SEEK_SET); // position pointer where key indicates
		fread(&x, sizeof(STUDENT), 1, f); // structure is now in internal memory
		if (x.is == 1)
			printf("\nError: duplicate key %d. Skipping.", key);
		else
		{
			x.nrm = key;
			printf("Name: ");
			gets(x.nume);
			gets(x.nume);
			printf("CNP: ");
			gets(x.CNP);
			printf("Year: "); 
			scanf("%d", &x.an);
			printf("Group: ");
			scanf("%d", &x.grupa);
			for (i = 0; i < 20; i++)
				x.note[i]=0;
				//scanf("%hhi", &x.note[i]);
			x.is = 1;
			fseek(f, (key-START) * sizeof(STUDENT), SEEK_SET);
			fwrite(&x, sizeof(STUDENT), 1, f);
		}
		printf("Enrollment number (or 0 to stop): ");
		scanf("%d", &key);
	}

	fclose(f);
	//fclose(stdin);

	printf("\nDone. File <%s> was created. Press a key.", numefr);
	_getch();
}