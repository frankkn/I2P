#include <stdio.h>

int main(){
	int n;
  scanf("%d", &n);
  int ans = 0;
  if(n%3==0){
      if(n <= 3){
        ans = n;
      }else{
      ans = n/3 * 2 + 1;
      }
  }else{
    ans = n/3 * 2 + n % 3;
  }
  printf("%d\n", ans);
}