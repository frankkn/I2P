#include <stdio.h>
#define ll long long
int main(){
	int t;
    scanf("%d", &t);
	while(t--){
    	int n; scanf("%d", &n);
        int arr[(int)2e5];
        ll xor = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
            xor ^= arr[i];
        }
        ll lowbit = xor & -xor;
        int a = 0, b = 0;
        for(int i = 0; i < n; ++i){
        	if(lowbit & arr[i]){
            	a ^= arr[i];
            }
        }
        b = xor ^ a;
        if(a > b){
        	int temp = a;
            a = b;
            b = temp;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}