#include <stdio.h>

int lowbit(int x){
  return x&-x;
}

void get_rest_nums(int a[], int n, int tmp){
  int x = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] == tmp) continue;
    x ^= a[i];
  }
  int low_bit = lowbit(x);
  int num1 = 0, num2 = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] == tmp) continue;
    if(low_bit & a[i]){
      num1 ^= a[i];
    }
  }
  num2 = (x^num1);
  printf("%d %d\n", num1, num2);
}

int main(){
  int q; scanf("%d", &q);
  while(q--){
    int n; scanf("%d", &n);
    int a[(int)1e6+3];
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int x = 0;
    for(int i = 0; i < n; ++i) x ^= a[i];
    // x is the xor result of all numbers
    for(int i = 0; i < 32; ++i){
      int tmp = 0;
      for(int j = 0; j < n; ++j){
        // if a[j]'s ith bit equal x's ith bit
        if( (a[j] & (1<<i)) == (x & (1<<i)) ){
          // xor all the number with ith bit equal x's ith bit
          tmp ^= a[j];
        }
      }
      if(tmp != x){
        // get one number for answer !!
        printf("%d ", tmp);
        get_rest_nums(a, n, tmp);
        break;
      }
    }
  }
  return 0;
}