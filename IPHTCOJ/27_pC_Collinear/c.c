#include <stdio.h>
#define ll long long
int main(){
	int t;	scanf("%d", &t);
  while(t--){
    int line[100][100] = {0};
    int n;	scanf("%d", &n);
    ll x[100], y[100];
    for(int i = 0; i < n; ++i)	scanf("%lld %lld", &x[i], &y[i]);
    int cnt = 0;
    for(int i = 0; i < n; ++i){
      for(int j = i+1; j < n; ++j){
        for(int k = j+1; k < n; ++k){
          ll slope1 = (y[j] - y[i]) * (x[k] - x[j]);
          ll slope2 = (y[k] - y[j]) * (x[j] - x[i]);
          if(slope1 == slope2){
            if(line[i][j] == 0 && line[i][k] == 0 && line[j][k] == 0){
              cnt++;
            }
          line[i][j] = line[i][k] = line[j][k] = 1; // 不能寫在if裡面，理由是，一條線上，我最多只看三個點。
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
	return 0;
}