#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int main(){
  int t; scanf("%d", &t);
  while(t--){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[5000], ans = 0;
    k = min(k, m-1);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i <= k; ++i){
      int at_least = 0x3f3f3f3f; // (1<<31) = 2^31 or (1ll<<32)
      for(int j = 0; j <= m-1 -k; ++j){
        at_least = min( max(a[i+j], a[i+j + (n-m)]), at_least);
      }
      ans = max(ans, at_least);
    }
    printf("%d\n", ans);
  }
  return 0;
}