#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

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

// Intuition: 
// 令這三堆由小到大為A, B, C，相當於把較小的兩堆看成一堆(S)，看S跟C誰比較大。
// 如果S比較小，則直接回傳S的大小。
// 否則，回傳C + (S-C)/2，因為把S扣掉C之後再分成兩堆就好。

int main(){
  int T;
  scanf("%d", &T);
  while(T--){    
    int color[3];
    scanf("%d%d%d", &color[0], &color[1], &color[2]);
    bubble_sort(color, 3);
    if(color[0] + color[1] <= color[2]){
      printf("%d\n", color[0] + color[1]);
    }else{
      printf("%d\n", color[2] + (color[0] + color[1] - color[2]) / 2);
    }
  }
}