#include <stdio.h>
int col[14];
int n = 0;
int L, M, R;

int getans(int row){
  int res = 0;
	if(row == n){
    	return 1;
  }else{ 
    for(int j = 0; j < n; ++j){
      if((L | M | R) & (1 << j)) continue;
      int l = L, m = M, r = R;
      L |= (1 << j);
      M |= (1 << j);
      R |= (1 << j);
      L <<= 1;
      R >>= 1;
      res += getans(row+1);
      L = l, M = m, R = r;
    }
    return res;
  }
}


int main(){
	scanf("%d", &n);
  printf("%d\n", getans(0));
	return 0;
}