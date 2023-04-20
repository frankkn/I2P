#include <stdio.h>
int q[14];
int n = 0;
int cnt = 0;

void show(){
	for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
        	if(q[i] == j){
            	printf("Q");
            }else{
            	printf("-");
            }
        }
        printf("\n");
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int valid(int r, int c){
	for(int i = 0; i < r; ++i){
    if(q[i] == c)	return 0;
    if(r-i == q[i]-c) return 0;
    if(r-i == c-q[i]) return 0;
  }
  return 1;
}

void place(int row){
	if(row == n){
    cnt++;
    //show();
    return;
  }else{
    for(int j = 0; j < n; j++){
      if(valid(row, j)){
          q[row] = j;
          place(row+1);
        }
    }
  }
}

int main(){
	scanf("%d", &n);
    place(0);
    printf("%d\n", cnt);
	return 0;
}