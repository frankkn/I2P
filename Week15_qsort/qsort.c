#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int compare_int(const void *a, const void *b)
{
  const int *va = (const int *) a;
  const int *vb = (const int *) b;  
  return *va-*vb;
}

int compare_double(const void *a, const void *b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;
  /*
  if (*da < *db) return -1;
  else if (*da == *db) return 0;
  else return 1;
  */
  return (*db < *da) - (*db > *da);
}

int main(void)
{
  int data1[SIZE];
  double data2[SIZE];
  int i;

  for (i=0; i<SIZE; i++) {
    data1[i] = rand()%SIZE;
    data2[i] = (double)rand()/RAND_MAX;
  }

  printf("original: ");
  for (i=0; i<SIZE; i++) {
    printf("%d ", data1[i]);
  }
  printf("\n");

  printf("  sorted: ");
  qsort(data1, SIZE, sizeof(int), compare_int);
  for (i=0; i<SIZE; i++) {
    printf("%d ", data1[i]);
  }
  printf("\n");

  printf("original: ");
  for (i=0; i<SIZE; i++) {
    printf("%.2f ", data2[i]);
  }
  printf("\n");

  printf("  sorted: ");
  qsort(data2, SIZE, sizeof(double), compare_double);
  for (i=0; i<SIZE; i++) {
    printf("%.2f ", data2[i]);
  }
  printf("\n");

  return 0;
}