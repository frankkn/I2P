#include <stdio.h>

int main(){
	int x, y;
  scanf("%x %x", &x, &y);
  int z = x+y; 
  int bin[10000] = {0};
  int idx = 0;
  while(z){
    if(z & 1 == 1){
        bin[idx++] = 1;
      }else{
        bin[idx++] = 0;
      }
    z >>= 1;
  }
  for(int i = idx-1; i >= 0; --i){
    printf("%d", bin[i]);
  }
  printf("\n");

	return 0;
}