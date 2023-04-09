#include <stdio.h>

void F(int i){
  if(i > 10)  return;
  // printf("%d ", i);
  F(i + 1);
  printf("%d ", i);
}

int main(){
  
  F(1);
  printf("\n");

  return 0;
}