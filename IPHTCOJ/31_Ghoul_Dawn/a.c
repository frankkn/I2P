#include <stdio.h>

int main(){
	int n, k;
  scanf("%d%d", &n, &k);
  int a[n+1];
  for(int i = 1; i <= n; ++i){ scanf("%d", &a[i]); }
  int b[n+1];b[0] = 0;
  for(int i = 1; i <= n; ++i){ b[i] = b[i-1]+a[i]; }
  double _max = 0;
  for(int i = 1; i <= n-k+1; ++i){
    for(int j = i+k-1; j <= n; ++j){
      int sum = b[j] - b[i-1];
      double cur = (double)sum / (j-i+1);
      if(cur > _max){
        _max = cur;
      }
    }
  }
	printf("%.3lf\n", _max);
}