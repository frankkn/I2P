#include <stdio.h>

int main(){
	int n, q;
  scanf("%d%d", &n, &q);
  long long a[1000000];
  for(int i = 1; i <= n; ++i){
    // scanf("%lld(/`A`)/ ~I__I", &a[i]);
    scanf("%lld%*s %*s", &a[i]);
    // scanf("%lld%*13c", &a[i]);
    // scanf("%lld%*13[^\n]", &a[i]);
    // scanf("%lld%*13[0-9]", &a[i]);
  }

  long long pre[1000001];
  for(int i = 1; i <= n; ++i){
    pre[i] = pre[i-1] + a[i];
  }

  while(q--){
    int L, R;
    scanf("%d%d", &L, &R);
    printf("%lld\n", pre[R] - pre[L-1]);
  }
  
	return 0;
}