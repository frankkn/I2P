#include <stdio.h>

int count(int i){
	int cnt = 0;
  while(i){
    if(i % 10 == 1)	cnt++;
    i /= 10;
  }
	return cnt;
}

int main(){
	int t; scanf("%d", &t);
  int a[(int)1e6+3], p[(int)1e6+3];
  p[0] = 0;
  for(int i = 1; i <= (int)1e6; ++i){
    a[i] = count(i);
    p[i] = p[i-1]+a[i];
  }
  
  while(t--){
    int L,R; scanf("%d %d", &L, &R);
    printf("%d\n", p[R]-p[L-1]);
  }
	
	return 0;
}