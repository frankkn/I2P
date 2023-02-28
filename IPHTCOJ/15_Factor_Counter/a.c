#include <stdio.h>
#include <math.h>

int find_factor(int n){
  int cnt = 0;
  double sq = sqrt(n);
  for(int i = 1; i < sq; ++i){
    if(n%i == 0){
      cnt += 2;
    }
  }
  if(sq - floor(sq) == 0.0){
    cnt += 1;
  }
	return cnt;
}

int main(){
 	int T;
  scanf("%d", &T);
  while(T--){
    int L,R;
    scanf("%d%d", &L,&R);
    if(L == R){
      printf("%d\n", L);
      continue;
    }    
    int _max = 0, _most = 0;
    for(int i = L; i <= R; ++i){
      int cur_factor_num = find_factor(i);
      if(cur_factor_num > _max){
        _max = cur_factor_num;
        _most = i;
      }
    }
    printf("%d\n", _most);
  }
	return 0;   
}