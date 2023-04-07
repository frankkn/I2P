#include <stdio.h>
#define N 8

int q[N];
void place(int row);
void show();
int count;

int main(){
  place(0);
  printf("Count:%d\n", count);
  return 0;
}

int valid(int r, int c){
  for(int i = 0; i < r; ++i){
    //同一col
    if(q[i] == c) return 0;
    //水平方向的移動量 == 垂直方向的移動量 (斜率為1 or -1)
    if(r-i == c - q[i]) return 0;
    if(i-r == c - q[i]) return 0;
  }
  return 1;
}

void place(int row){
  if(row >= N){
    count++;
    show();
    return;
  }
  for(int j = 0; j < N; ++j){
    if(valid(row, j)){
      q[row] = j; // q[0] = 1, 第0列的皇后擺第j行 (row, j)
      place(row + 1);
      // q[row] = 0 No need, since we use "j" as Queen 
    }
  }
  
}

void show(){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(q[i] == j){
        printf("Q");
      }else{
        printf("-");
      }
    }
    printf("\n");
  }
  printf("~~~~~~~~~~~~~~~~~\n");
}