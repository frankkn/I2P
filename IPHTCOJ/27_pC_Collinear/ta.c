#include <stdio.h>
int t, ans;
long long x[103], y[103];
long long a[1000000], b[1000000], c[1000000]; // 10^6 -> C(100,3)
int main(){
  scanf("%d", &t);
  while(t--){
    ans = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%lld %lld", &x[i], &y[i]);
    for(int i = 0; i < n; ++i){
      for(int j = i+1; j < n; ++j){
        for(int k = j+1; k < n; ++k){
          long long A, B, C;
          A = y[j] - y[i];
          B = x[i] - x[j];
          C = -A * x[i] - B * y[i];
          // 3 points on the same line
          if(A * x[k] + B * y[k] + C != 0){
            continue;
          }
          int flag = 1;
          for(int l = 0; l < ans && flag == 1; l++){
            if(a[l] * B == A * b[l] ){
              if(b[l] * C == B * c[l]){
                if(c[l] * A == C * a[l]){
                  flag = 0;
                }
              }
            }
          }
          if(flag == 1){
            a[ans] = A, b[ans] = B, c[ans] = C;
            ans++;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}