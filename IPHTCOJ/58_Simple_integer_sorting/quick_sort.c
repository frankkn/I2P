#include<stdio.h>

void swap(int *a, int *b){
	int tmp = *a; 
  *a = *b; 
  *b = tmp;
}


int partition(int a[], int p, int r){
	int pivot = a[r];
  int i = p-1, j = p;
  for(;j < r; ++j){
    if(a[j] <= pivot){
      ++i;
      swap(&a[i], &a[j]);
    }
  }
  ++i;
	swap(&a[i], &a[r]);
  return i;
}

void quick_sort(int a[], int p, int r) {
  if(p < r){
  	int q = partition(a, p, r);
  	quick_sort(a, p, q-1);
    quick_sort(a, q+1, r);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i)
    {
      scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n-1);
    for(int i = 0; i < n; ++i)
    {
      if(i == n-1){
        printf("%d\n",a[i]);
        break;
      }
      printf("%d ",a[i]);
    }
  }
}