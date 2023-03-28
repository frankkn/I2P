#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  int arr[5001], prefix[5001];
  prefix[0] = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &arr[i]);
    prefix[i] = prefix[i-1] + arr[i];
  }
  double _max = 0.0;
  for(int i = 1; i <= n-k+1; ++i){
    for(int j = i+k-1; j <= n; ++j){
      double sum = prefix[j] - prefix[i-1];
      _max = max(sum / (j-i+1), _max);
    }
  }
  printf("%.3lf\n", _max);
	return 0;
}