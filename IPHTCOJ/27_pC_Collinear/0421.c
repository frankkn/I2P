#include <stdio.h>
#define ll long long
ll x[100], y[100];
ll a[1000000], b[1000000], c[1000000]; // 10^6
int ans = 0;

int main(){
  int t; scanf("%d", &t);
  while(t--){
    ans = 0; // !!
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i)	scanf("%lld %lld", &x[i], &y[i]); // lld !!
    for(int i = 0; i < n; ++i) for(int j = i+1; j < n; ++j) for(int k = j+1; k < n; ++k){
      ll A, B, C;
      A = y[j] - y[i];
      B = x[i] - x[j];
      C = -A * x[i] - B * y[i];
      // 3 points on the same line
      if(A * x[k] + B * y[k] + C != 0)	continue;
      // traverse all lines
      int flag = 1; // if found "SAME LINE", no need to look up rest lines
      for(int l = 0; l < ans && flag; ++l){
        if(A * b[l] == B * a[l])
          if(B * c[l] == C * b[l])
            if(A * c[l] == C * a[l])
              flag = 0;
      }
      if(flag){
        a[ans] = A, b[ans] = B, c[ans] = C;
        ans++;
      }
    }
    printf("%d\n", ans);
  }
	return 0;
}