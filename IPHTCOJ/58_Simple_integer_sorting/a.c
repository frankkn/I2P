#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r){
	int i = p-1, j = p;
  int pivot = arr[r];
  while(j < r){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
    j++;
  }
  i++;
  swap(&arr[i], &arr[r]); // !
  return i; // !
}

void Qsort(int arr[], int p, int r){
	if(p < r){
    int q = partition(arr, p, r);
    Qsort(arr, p, q-1); // !
    Qsort(arr, q+1, r);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    int arr[(int)1e4];
    for(int i = 0; i < n; ++i){
      scanf("%d", &arr[i]);
    }
    Qsort(arr, 0, n-1);
    for(int i = 0; i < n; ++i){
      printf("%d", arr[i]);
      if(i == n-1){
        printf("\n");
      }else{
        printf(" ");
      }
    }
  }
	return 0;
}