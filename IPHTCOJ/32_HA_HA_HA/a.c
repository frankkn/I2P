#include <stdio.h>
#include <stdbool.h>
int gcd(int a, int b){
	return !b? a: gcd(b, a%b);
}

int main(){
	int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
    	scanf("%d", &a[i]);
    }
    int _max = 0;
    for(int i = 0; i < n; ++i){
    	for(int j = i+1; j < n; ++j){
        	int cur = gcd(a[i], a[j]);
            if(cur > _max)	_max = cur;
        }
    }
    printf("%d\n", _max);
    
	return 0;
}