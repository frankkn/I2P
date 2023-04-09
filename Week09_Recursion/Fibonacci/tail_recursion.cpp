#include <stdio.h>

long long f(long long n, long long fp, long long fc){
  if(n == 0)
    return fp;
  if(n == 1)
    return fc;
  else
    return f(n-1, fc, fc+fp);
}

int main(void){
  int n;
  scanf("%d", &n);
  printf("Fib(%d) = %lld\n", n, f(n, 0, 1));
}