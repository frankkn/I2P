#include <stdio.h>

int main(){
	int T;
  scanf("%d", &T);
  while(T--){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a == 1){
      if(b == 0){	printf("%d\n", 1); }
      else if(b == 1){ printf("%d\n", 3); }
      else{ printf("%d\n", 2); }
    }else{
      int tmp = 0;
      for(int i = 1; i < a; ++i){
        tmp ^= i;
      }           
      if(tmp == b){
        printf("%d\n", a);
      }else{
        int miss_num = tmp ^ b;
        if(miss_num == a){
          printf("%d\n", a+2);
        }else{
          printf("%d\n", a+1);
        }
      }
    }
  }
  return 0;
}