#include <stdio.h>

int main(){
	int n;
  scanf("%d", &n);
  int cnt = 0;
  int tmp = n;
  while(n & 1 != 0){
    cnt++;
    n >>= 1;
  }
  char bin[11];
  int idx = 0;
	++tmp;
  while(tmp){
    bin[idx++] = (tmp&1)+'0';
    tmp >>= 1;
  }
  for(int i = idx-1; i >= 0; --i){
    printf("%c", bin[i]);
  }
  
  printf(" %d\n", cnt);
    
	return 0;
}