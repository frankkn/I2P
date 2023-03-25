#include <stdio.h>
#define ll long long
int main(){
	int n, q;
    scanf("%d%d", &n, &q);
    ll arr[(int)1e6+1], prefix[(int)1e6+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &arr[i]);
		if(arr[i] > 0)	prefix[i] = prefix[i-1] + arr[i];
        else prefix[i] = prefix[i-1];
    }
    while(q--){
        int L,R,M;
        scanf("%d%d%d", &L, &R, &M);
    	printf("%lld\n", prefix[L+M-1] - prefix[L-1]);
    }
    return 0;
}