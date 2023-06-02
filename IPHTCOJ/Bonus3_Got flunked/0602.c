#include <stdio.h>
#define ll long long

// n == k*(2^i-1) +k(k-1)/2
// people == 2^i * k
// k is odd => k = 2m+1
// n == (2m+1)*(m-1) + 2^i * (2m+1)

ll binary_search(ll n, ll pow_of_2, ll L, ll R)
{
  while(L < R){
    ll M = (L+R)/2;
    if( (2*M+1) * (M-1) + pow_of_2 * (2*M+1) >= n) R = M;
    else L = M + 1;
  }
  if(n == (2*L+1) * (L-1) + pow_of_2 * (2*L + 1)) return L;
  else return -1;
}

int main()
{
  int t;  scanf("%d",&t);
  while(t--){
    ll n; scanf("%lld",&n);
    ll pow_of_2, k, R;
    for(int i = 0; i < 64; ++i){
      pow_of_2 = 1ll << i;
        
      if(pow_of_2 > (ll)1e9){
        R = (ll)(1e18/pow_of_2);
      }
      else{
        R = (ll)1e9;
      }
        
      k = binary_search(n, pow_of_2, 0, R);
      if(k != -1) break;
    }
    if(k == -1) printf("-1\n");
    else printf("%lld\n", pow_of_2*(2*k+1));
  }
  return 0;
}