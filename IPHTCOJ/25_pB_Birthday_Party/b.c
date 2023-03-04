#include <stdio.h>
#include <stdbool.h>
#define ll long long


ll find_gcd(ll a, ll b){
	return !b ? a : find_gcd(b, a % b);
}
 
void distribute_balloon(ll arr[], ll n, ll x){
	ll i = x;
    ll original_arr[n+1];
    for(ll i = 0; i <= n; ++i){
    	original_arr[i] = arr[i];
    }
    while(true){
    	if(arr[i] == original_arr[i]){
        	arr[i]++;
            i += x;
            if(i > n)	i%=n;
        }else{
        	break;
        }
    }
}
 
void pony_balloon(int n, int x1, int x2, int x3){
	ll arr[n+1];
 
    for(ll i = 0; i <= n; ++i){ arr[i] = 0; }
 
    ll co_prime1 = find_gcd(n, x1) == 1? 1:0;
    ll co_prime2 = find_gcd(n, x2) == 1? 1:0;
    ll co_prime3 = find_gcd(n, x3) == 1? 1:0;
    //printf("%d %d %d\n", co_prime1, co_prime2, co_prime3);
    ll tmp = co_prime1 + co_prime2 + co_prime3;
    if(tmp == 3){
        printf("%lld\n", n);
        return;
    }else{
    	for(ll i = 0; i <= n; ++i){
        	arr[i] = tmp;
        }
    }
    if(co_prime1 != 1){	distribute_balloon(arr, n, x1); }
    if(co_prime2 != 1){	distribute_balloon(arr, n, x2); }
    if(co_prime3 != 1){	distribute_balloon(arr, n, x3); }
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        if(arr[i] == 3){
        	ans++;
        }
    }
	printf("%lld\n", ans);
}
 
int main(){
	int T;
    scanf("%d", &T);
    while(T--){
    	ll n; scanf("%d", &n);
        ll x1, x2, x3;
        scanf("%lld%lld%lld", &x1, &x2, &x3);
        pony_balloon(n, x1, x2, x3);
    }
 
	return 0;
}