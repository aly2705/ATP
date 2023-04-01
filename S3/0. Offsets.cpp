#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct{ 
                short int a;
                char b;
                int c;
                long d;
              } V1;

typedef struct{ 
                char b;
                int c;
                short int a;
                long d;
              } V2;

typedef struct {
				 int c;
				 short int a;
				 long d;
				 char b;
} V3;

void main()
{
  V1 x;
  V2 y;
  V3 z;

  printf("\nsize of V1: %d",sizeof(V1));
  printf("\nsize of V2: %d",sizeof(V2));
  printf("\nsize of V3: %d",sizeof(V3));

  printf("\n\nOffsets for V1");
  printf("\na: %2d\nb: %2d\nc: %2d\nd: %2d",(char*)&x.a-(char*)&x,
                                            (char*)&x.b-(char*)&x,
                                            (char*)&x.c-(char*)&x,
                                            (char*)&x.d-(char*)&x);
  printf("\n\nOffsets for V2");
  printf("\nb: %2d\nc: %2d\na: %2d\nd: %2d",(char*)&y.b-(char*)&y,
                                            (char*)&y.c-(char*)&y,
                                            (char*)&y.a-(char*)&y,
                                            (char*)&y.d-(char*)&y);
  printf("\n\nOffsets for V3");
  printf("\nc: %2d\na: %2d\nd: %2d\nb: %2d", (char*)&z.c - (char*)&z,
											 (char*)&z.a - (char*)&z,
											 (char*)&z.d - (char*)&z,
											 (char*)&z.b - (char*)&z);
}
