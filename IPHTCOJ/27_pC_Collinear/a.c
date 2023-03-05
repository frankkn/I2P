#include <stdio.h>
#include <stdbool.h>
#include <float.h> // for DBL_MAX
#define ll long long

typedef struct Pair{
	int first;
  int second;
}Pair;

Pair create_pair(int first, int second) {
  Pair p;
  p.first = first;
  p.second = second;
  return p;
}

void cal_line(Pair p[], int n){
  bool connect[n][n];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
        connect[i][j] = false;
      }
  }
  
  int cnt = 0;
	for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
			for(int k = j+1; k < n; ++k){
        // change int to ll, then AC WTF?
        ll x1 = p[i].first, y1 = p[i].second;
        ll x2 = p[j].first, y2 = p[j].second;
        ll x3 = p[k].first, y3 = p[k].second;

        ll slope1 = (y2-y1)*(x3-x2);
        ll slope2 = (y3-y2)*(x2-x1);
                
        if(slope1 == slope2){
          if(!connect[i][j] && !connect[j][k] && !connect[i][k]){
            ++cnt;
          }
          connect[i][j] = connect[j][k] = connect[i][k] = true;
        }
      }
    }
  }
  printf("%d\n", cnt);
}

int main(){
	int T; scanf("%d", &T);
  while(T--){
    int n; scanf("%d", &n);
    if(n <= 2){
      printf("0\n");
      continue;
    }
    Pair p[n];
    for(int i = 0; i < n; ++i){
      int x, y;
      scanf("%d%d", &x, &y);
      p[i] = create_pair(x, y);
    }
    cal_line(p, n);
  }
	return 0;
}