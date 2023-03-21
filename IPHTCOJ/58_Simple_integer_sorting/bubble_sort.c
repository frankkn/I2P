#include<stdio.h>

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (arr[i] > arr[j]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
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
    bubble_sort(a, n);
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