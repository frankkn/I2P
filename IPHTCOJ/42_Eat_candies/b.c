#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
	int q;
  scanf("%d", &q);
  while(q--){
    int arr[3];
    for(int i = 0; i < 3; ++i) scanf("%d", &arr[i]);
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
        if(arr[j] > arr[j+1]){
          swap(&arr[j], &arr[j+1]);
        }
      }
    }
    if(arr[0] + arr[1] <= arr[2]){
      printf("%d\n", arr[0] + arr[1]);
    }else{
      printf("%d\n", arr[2] + (arr[0] + arr[1] - arr[2]) / 2);
    }
  }
  return 0;
}