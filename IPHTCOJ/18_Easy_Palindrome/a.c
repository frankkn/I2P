#include <stdio.h>

int main(){
	int front, back;
    scanf("%d.%d", &front, &back);
    int _front = front, _back = back; 
    int a = 0, b = 0;
    for(int i = 0; i < 3; ++i){
    	a *= 10;
        a += (front%10);
        front /= 10;
        
        b *= 10;
        b += (back%10);
        back /= 10;
    }
    int ans_front = a + _front; 
    int ans_back = b + _back;
    
    if(ans_back >= 1000){
    	ans_back -= 1000;
        ans_front += 1;
    }
    printf("%d.%d\n", ans_front, ans_back);
    
	return 0;
}