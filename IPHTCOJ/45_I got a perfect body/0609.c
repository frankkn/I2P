#include <stdio.h>
#include <stdlib.h>

int arr[300003] = {0};
int buy_num[300003] = {0};

int cmp(const void *a, const void *b){
  int aa = *(int *)a;
  int bb = *(int *)b;
  if(aa < bb) return -1;
  else if(aa > bb) return 1;
  else return 0;
}

int main(){
  /*
  buy num 1 2 3 4 5
  money   2 3 6 8 13
  */
  int t; scanf("%d", &t);
  while(t--){
    int n, p, k; scanf("%d%d%d", &n, &p, &k);
    for(int i = 1; i <= n; ++i){
      scanf("%d", &arr[i]);
    }
    qsort(arr+1, n, sizeof(arr[0]), cmp);
    for(int i = 1; i <= n; ++i){
      if(i < k){
        buy_num[i] = buy_num[i-1] + arr[i];
      }else{
        buy_num[i] = arr[i] + buy_num[i-k];
      }
    }
    int _max = 0;  
    for(int i = 1; i <= n; ++i){
      if(buy_num[i] <= p) _max = i; // 不能break,因為非遞增函數
    }
    printf("%d\n", _max);
  }
  return 0;
}