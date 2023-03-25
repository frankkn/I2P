#include <stdio.h>

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    int arr[n+1];
    long long prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d(/`A`)/ ~I__I", &arr[i]);
    	prefix[i] = prefix[i-1] + arr[i];
    }
    while(q--){
	    int L, R;
        scanf("%d%d", &L, &R);
        printf("%lld\n", prefix[R] - prefix[L-1]);
    }
    return 0;
}