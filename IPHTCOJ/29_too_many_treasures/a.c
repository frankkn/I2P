#include <stdio.h>
#define ll long long

int main(){
	int n, q;scanf("%d%d", &n, &q);
  ll c[n+1], prefix_sum[n+1];
  prefix_sum[0] = 0;
  for(int i = 1; i <= n; ++i){ 
    scanf("%lld", &c[i]);
    if(c[i] > 0){
      prefix_sum[i] = prefix_sum[i-1] + c[i];
    }else{
      prefix_sum[i] = prefix_sum[i-1];
    }
  }
    
	while(q--){
    int L, R, M;
    scanf("%d%d%d", &L, &R, &M);
    --M;
    ll sum = prefix_sum[L+M] - prefix_sum[L-1];
    printf("%lld\n", sum);
  }
  return 0;
}