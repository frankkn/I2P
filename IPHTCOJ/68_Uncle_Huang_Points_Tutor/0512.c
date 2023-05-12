#include <stdio.h>
#define ll long long

ll fast_power(ll x, ll y, ll m){
	ll res = 1 % m;
  while(y){
    if(y & 1)	res = res * x % m;
    x = x * x % m;
    y = y/2;
  }
  return res;
}

int main(){
	ll x, y, m; scanf("%lld%lld%lld", &x, &y, &m);
  ll ans = fast_power(x%m, y, m);
	printf("%lld\n", ans);
	return 0;
}