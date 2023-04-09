#include <stdio.h>

void bin(int i){
  if(i){
    bin(i/2);
    printf("%d", i%2);
  }
}

int main(){
  
  bin(16);
  printf("\n");

  return 0;
}