#include <stdio.h>

char bit[(int)1e6];
int N;

void show_bit(int i){
  if(i == N){
    printf("%s\n", bit);
    return;
  }else{
    bit[i] = '0';
    show_bit(i+1);
    bit[i] = '1';
    show_bit(i+1);
  }

}

int main(){
  scanf("%d", &N);
  bit[N] = '\0';
  show_bit(0);
  return 0;
}