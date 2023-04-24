#include <stdio.h>
#include <stdbool.h>
#define ll long long

ll gcd(ll a, ll b){
  return !b? a: gcd(b, a%b);
}

int main(){
	int t; scanf("%d", &t);
    while(t--){
    	ll N, R, B, Y;
      scanf("%lld %lld %lld %lld", &N, &R, &B, &Y);
      ll a = gcd(N, R), b = gcd(N, B), c = gcd(N, Y);
      ll ab = a / gcd(a,b) * b; 
      ll abc = ab / gcd(ab,c) * c;
    	printf("%lld\n", N/abc);
    }
	return 0;
}