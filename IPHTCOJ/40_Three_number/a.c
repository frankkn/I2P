#include <stdio.h>
#define ll long long
int main(){
    ll A, B, C;
    scanf("%lld%lld%lld", &A, &B, &C);
    ll total = (A+B+C)/2;
	printf("%lld %lld %lld\n", total-B, total-C, total-A);
	return 0;
}