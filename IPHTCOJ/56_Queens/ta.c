#include <stdio.h>
int col[14], d1[27], d2[27];
int n = 0;

int getans(int row){
  int res = 0;
	if(row == n){
    	return 1;
  }else{ 
    for(int j = 0; j < n; ++j){
        if(col[j])	continue;
        if(d1[row + j]) continue;
        if(d2[row - j +14]) continue;
        col[j] = 1;
        d1[row + j] = 1;
        d2[row - j +14] = 1;
        res += getans(row+1);
        col[j] = 0;
        d1[row + j] = 0;
        d2[row - j +14] = 0;
    }
    return res;
  }
}


int main(){
	scanf("%d", &n);
  printf("%d\n", getans(0));
	return 0;
}