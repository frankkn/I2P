#include <stdio.h>
#include <stdbool.h>
#define ll long long

ll gcd(ll a, ll b){
 return !b ? a : gcd(b, a % b);
}

int main(){
	ll T; scanf("%lld", &T);
    while(T--){
        ll n; scanf("%lld", &n);
        ll x1, x2, x3;
        scanf("%lld%lld%lld", &x1, &x2, &x3);
        x1 = gcd(n, x1);
        x2 = gcd(n, x2);
        x3 = gcd(n, x3);
        // find LCM of x1, x2
        ll x12 = x1 / gcd(x1, x2) * x2;
        // find LCM of x12, x3
        ll x123 = x12 / gcd(x12, x3) * x3;
        ll ans = n / x123;
        printf("%lld\n", ans);
    }
 return 0;
}
