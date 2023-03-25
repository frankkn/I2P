#include <stdio.h>

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1){
            if(b == 0)	printf("%d\n", 0);
            else	printf("%d\n", b==1?3:2);
        }else{
        	int xor = 0;
            for(int i = 1; i < a; ++i)	xor ^= i;
            if(xor == b){
            	printf("%d\n", a);
            }else{
            	int complement = xor^b;
                if(complement == a){
                	printf("%d\n", a+2);
                }else{
                	printf("%d\n", a+1);
                }
            }
        }
    }
    return 0;
}