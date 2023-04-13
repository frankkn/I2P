#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
int main(){
  int t;  scanf("%d", &t);
  while(t--){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    k = min(k, m-1);
    int a[5001], ans = 0;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int l = 1, r = n-k; r <= n; ++l, ++r){
      int _min = 0x3f3f3f3f;
      for(int ll = l, rr = r-((m-1)-k); rr <= r; ++ll, ++rr){ // 
        int pick = max(a[ll], a[rr]);
        _min = min(_min, pick); 
      }
      ans = max(ans, _min);
    }
    printf("%d\n", ans);    
  }
  return 0;
}