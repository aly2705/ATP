#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Interclasare pentru sortare - Merging for merge sort
// I: v - vector address; p1, u1 - index limits for first sequence; p2, u2 - index limits for second sequence
// E: -
void inter(float* v, int p1, int u1, int p2, int u2)
{
  int i, j, k;
  float* t;

  t = new float[u2 - p1 + 1];							
  i = p1; j = p2; k = 0;							
  while((i<=u1)&&(j<=u2))
    if(v[i]<v[j])
      t[k++]=v[i++];
    else
      t[k++]=v[j++];
  while(i<=u1)
    t[k++]=v[i++];
  while(j<=u2)
    t[k++]=v[j++];

  for(i=0;i<k;i++)
    v[p1+i]=t[i];
  delete t;
}

// Sortare prin interclasare - Merge sort
// I: a - vector address; s, d - index limits for sequence to be sorted
// E: - 
void sort_i(float* a, int s, int d)
{
  int m;
  if(s<d)
  {
    m=(s+d)/2;
    sort_i(a,s,m);
    sort_i(a,m+1,d);
    inter(a, s, m, m+1,d);
  }
}
  

// Determinare pivot pentru sortare rapida - positioning for quicksort
// I: v - vector address; p, u - index limits for vector sequence
// E: pivot index
int pivot(float* v, int p, int u)
{
  int i, j, di, dj;
  float t;
  i=p; j=u; di=0; dj=-1;
  while(i<j)
  {
    if(v[i]>v[j]) //v[i]<v[j] for decreasing order sort
    {
      t=v[i]; v[i]=v[j]; v[j]=t;
      di=-dj;
      dj=di-1;
    }
    i+=di;
    j+=dj;
  }
  return i;
}

// Sortare rapida - quick sort
// I: a - vector address; s, d - index limits for vector sequence to be sorted
// E: -
void sort_r(float* a, int s, int d)
{
  int k;
  if(s<d)
  {
    k=pivot(a, s, d);
    sort_r(a, s, k-1);
    sort_r(a, k+1, d);
  }
}



void main()
{
  float* x, *y;
  int n, i;
  float a,b;

  a=1; b=99;
  n=20;
  x=new float[n];
  y=new float[n];
  for(i=0;i<n;i++)
  {
    x[i]=(double)rand()/RAND_MAX*(b-a)+a;
    y[i]=x[i];
  }

  printf_s("\nInainte de sortare:\n");		//before sorting
  for(i=0;i<n;i++)
    printf_s("%5.2f ",x[i]);

  sort_i(x,0,n-1);

  printf_s("\nDupa sortare prin interclasare:\n");		//after merge sort
  for(i=0;i<n;i++)
    printf_s("%5.2f ",x[i]);

  sort_r(y,0,n-1);

  printf_s("\nDupa sortare rapida:\n");					//after quick sort
  for(i=0;i<n;i++)
    printf_s("%5.2f ",y[i]);

  delete x;
  delete y;
  printf_s("\n\nGata. Apasa o tasta");			//done. press a key
  _getch();

}