#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
int count(int n){
	int cnt = 0;
  for(int i = 1; i*i <= n; ++i){
    if(n == i*i){
      cnt += 1;
      break;
    }
    if(n % i == 0){
      cnt += 2;
    }
  }
  return cnt;
}

int main(){
	int t; scanf("%d", &t);
  int fac[20001] = {0};
  for(int i = 1; i <= 20000; ++i){
    fac[i] = count(i);
  }
  while(t--){
    int L, R;
    scanf("%d%d", &L, &R);
    int _max = 0;
    int idx_ans = 0; 
    for(int i = L; i <= R; ++i){
      if(fac[i] > _max){
        _max = fac[i];
        idx_ans = i;
      }
    }
    printf("%d\n", idx_ans);
  }

	return 0;
}