#include <stdio.h>
#include <string.h>
#define ll long long

// keeps track of which points are already connected by a line
int line[100][100];

int main(){
  int T;  scanf("%d",&T);
  while(T--){
    int n;  scanf("%d",&n);
    int cnt = 0;
    ll x[n];
    ll y[n];
    for(int i = 0; i < n; ++i){
      scanf("%lld%lld", &x[i], &y[i]);
    }
    // Intuition: Pick random 3 points check if they are on the same line
    for(int i = 0; i < n; ++i){
      for(int j = i+1; j < n; ++j){
        for(int k = j+1; k < n; ++k){
          // x1 = (xi, yi), x2 = (xj, yj), x3 = (xk, yk)
          // check slope(x1,x2) == slope(x2, x3) ?
          // (yj-yi)/(xj-xi) == (yk-yj)/(xk-xj) ?
          // (yj-yi)*(xk-xj) == (yk-yj)*(xj-xi) ? 
          ll slope1 = (y[j] - y[i]) * (x[k] - x[j]);
          ll slope2 = (y[k] - y[j]) * (x[j] - x[i]);

          if(slope1 == slope2){
            if(line[i][j] == 0 && line[i][k] == 0 && line[j][k] == 0){
              cnt++;
            }
            line[i][j] = line[i][k] = line[j][k] = 1; // 不能寫在if裡面，理由是一條線上，我最多只看三個點。
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        line[i][j] = 0;
      } 
    }
    printf("%d\n", cnt);
  }
  return 0;
}