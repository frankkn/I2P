#include <stdio.h>
#define MAXK 8

int value[MAXK]; // = {1, 5, 10}
int num[MAXK]; // = {0, 0, 0}

void show(int k){
  printf("(");
  for(int i = 0; i < k; ++i){
    printf("%d", num[i]);
    if(i == k-1){
      printf(")\n");
    }else{
      printf(",");
    }
  }
}


void change(int m, int i, int k){
  int tmp;
  if(i == k){
    if(m == 0){
      show(k);
      return;
    }
  }else if(m < 0){

  }else if(m == 0){
    show(k);
  }else{
    // 不使用第i個coin
    change(m, i+1, k);

    // 用一個第i個coin
    num[i]++;
    change(m-value[i], i, k);
    num[i]--;

    // tmp = num[i];
    // num[i]++;
    // change(m - value[i], i, k);
    // // 我現在 還是有m元，我用的value[i]的銅板，只用了tmp個。
    // num[i] = tmp; // 因為global大家都可以改
  }
}

int main(){
  int i, M, K;
  scanf("%d", &K);
  for(int i = 0; i < K; ++i){
    scanf("%d", &value[i]);
  }
  scanf("%d", &M);
  change(M, 0, K);
  return 0;
}