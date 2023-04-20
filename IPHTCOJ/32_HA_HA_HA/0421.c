#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
int a[1000];
int n;

int gcd(int a, int b){
	return !b? a:gcd(b, a%b);
}


int find_max(){
	int _max = 0;
    for(int i = 0; i < n; ++i){
    	for(int j = i+1; j < n; ++j){
        	_max = max(_max, gcd(a[i], a[j]));
        }
    }
    return _max;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = find_max();
    printf("%d\n", ans);
	return 0;
}