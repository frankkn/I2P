#include <stdbool.h>
int q[20];
int cnt;

int valid(int r, int c){
	for(int i = 0; i < r; ++i){
    if(q[i] == c) return 0;
    if(r-i == c - q[i]) return 0;
    if(r-i == q[i] - c) return 0;
  }
  return 1;
}

void place(int row, int size){
	if(row == size){
    cnt++;
    return;
  }else{
    for(int j = 0; j < size; ++j){
      if(valid(row, j)){
        q[row] = j;
        place(row+1, size);
      }
    }
  }
}

int main(){
  int N;
  scanf("%d", &N);
	place(0, N);
  printf("%d\n", cnt);
  return 0;
}