#include <stdbool.h>
#include <stdio.h>

bool test_composite(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return true;
    }
  }
  return false;
}

int main(){
  int n;
  scanf("%d", &n);
  if(test_composite(n+8)){
    printf("%d %d\n", n+8, 8);
  }else{
    printf("%d %d\n", n+9, 9);
  }

  return 0;
}