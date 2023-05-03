#include <stdio.h>

int main(){
	int t; scanf("%d", &t);
  while(t--){
    int a, b; scanf("%d %d", &a, &b);
    int _xor = 0;
    for(int i = 0; i < a; ++i) _xor ^= i;
    if(_xor == b){
      printf("%d\n", a);
      continue;
    }
    
    if((_xor ^ b) == a){
      printf("%d\n", a+2);
    }else{
      printf("%d\n", a+1);
    }
  }
}