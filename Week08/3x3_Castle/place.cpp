#include <stdio.h>

int board[5][5];
void place(int row);
void show();
int count;

int valid(int r, int c){
  for(int i = 1; i < r; ++i){
    if(board[i][c]){
      return 0;
    }
  }
  return 1;
}

int main(){
  place(1);
  printf("Count:%d\n", count);
  return 0;
}

void place(int row){
  if(row > 3){
    count++;
    show();
    return;
  }
  for(int j = 1; j <= 3; ++j){
    if(valid(row,j)){
      board[row][j] = 1;
      place(row+1);
      board[row][j] = 0;
    }
  }
}

void show(){
  for(int i = 1; i <= 3; ++i){
    for(int j = 1; j <= 3; ++j){
      if(board[i][j]){
        printf("#");
      }else{
        printf("-");
      }
    }
    printf("\n");
  }
  printf("~~~~~~~~~~~~~~~~~\n");
}