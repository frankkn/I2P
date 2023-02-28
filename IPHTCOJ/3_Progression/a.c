#include <stdio.h>

int main(){
	int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if(c-b == b-a){
    	int diff = b-a;
        int x = a-diff;
        int y = c+diff;
        printf("%d %d", x, y);
    }else{
		int diff = b/a;
        int x = a/diff;
        int y = c*diff;
        printf("%d %d", x, y);
    }
    return 0;
}