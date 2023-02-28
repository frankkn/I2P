#include <stdio.h>

int main(){
	int a1, a2, b1, b2;
    scanf("%d.%d %d.%d", &a1, &a2, &b1, &b2);
    int ans = (a1*100+a2)*(b1*100+b2);
    printf("%d.%04d\n", ans/10000, ans%10000);
    
	return 0;
}