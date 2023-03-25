#include <stdio.h>

int count(int i){
  int cnt = 0;
	while(i){
    if(i%10 == 1){
      cnt++;
    }
    i /= 10;
  }
	return cnt;
}

int main(){
	int t;
  scanf("%d", &t);
  int prefix[(int)1e6+1] = {0};
  for(int i = 1; i <= (int)1e6; ++i){
    int ones = count(i);
      prefix[i] = prefix[i-1] + ones;
  }
  while(t--){
    int L, R;
      scanf("%d%d", &L, &R);
      printf("%d\n", prefix[R] - prefix[L-1]);
  }
  return 0;
}