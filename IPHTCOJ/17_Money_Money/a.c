#include <stdio.h>

int main(){
	int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int total = (x+y+z)/2;
	printf("%d %d %d\n", total-y, total-z, total-x);
    return 0;
}