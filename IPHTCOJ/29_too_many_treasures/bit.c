#include <stdio.h>
#define ll long long

int lowbit(ll x){ return x&-x; }

void update(int i, ll val, ll bit[], int n){
	for(;i <= n; i += lowbit(i)){
    bit[i] += val;
  }
}

ll query(ll bit[], int i){
	ll sum = 0;
  for(;i > 0; i -= lowbit(i)){
    sum += bit[i];
  }
  return sum;
}

int main(){
	int n, q;scanf("%d%d", &n, &q);
  ll c[n+1];
  for(int i = 1; i <= n; ++i){ 
      scanf("%lld", &c[i]); 
  }
  
  ll bit[n+1]; 
  for(int i = 0; i <= n; ++i){
    bit[i] = 0;
  }
  for(int i = 1; i <= n; ++i){
      update(i, c[i], bit, n); // update bit[i] using c[i]
  }

	while(q--){
    int L, R, M;
    scanf("%d%d%d", &L, &R, &M);
    int idx = 0;
    for(; idx < M; ++idx){
      if(c[L+idx] < 0){
        break;
      }
    }
    idx--;
    ll sum = query(bit, L+idx) - query(bit, L-1);
    printf("%lld\n", sum);
  }
  return 0;
}