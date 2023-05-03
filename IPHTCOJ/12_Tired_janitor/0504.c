#include <stdio.h>

int main(){
	int n, q; scanf("%d %d", &n, &q);
  int a[(int)1e6+1];
  long long p[(int)1e6+1];
  p[0] = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d(/`A`)/ ~I__I", &a[i]);
    p[i] = p[i-1]+a[i];
  }
  for(int i = 0; i < q; ++i){
    int L, R; scanf("%d %d", &L, &R);
    printf("%lld\n", p[R]-p[L-1]);
  }
	return 0;
}