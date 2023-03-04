#include <stdio.h>
#include <stdbool.h>
#include <float.h> // for DBL_MAX

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
  double used_slope[n*(n-1)/2]; int idx = 0;
  //for(int i = 0; i < n*(n-1)/2; ++i){ used_slope[i] = -1; }
  int cnt = 0;
	for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
			for(int k = j+1; k < n; ++k){
        int x1 = p[i].first, y1 = p[i].second;
        int x2 = p[j].first, y2 = p[j].second;
        int x3 = p[k].first, y3 = p[k].second;
        //printf("%d%d %d%d %d%d\n", x1, y1, x2, y2, x3, y3);
        double slope1 = (x2-x1) == 0? DBL_MAX:(double)((y2 - y1) / (x2 - x1));
        double slope2 = (x3-x2) == 0? DBL_MAX:(double)((y3 - y2) / (x3 - x2));
        double slope3 = (x3-x1) == 0? DBL_MAX:(double)((y3 - y1) / (x3 - x1));
        //printf("%lf %lf %lf\n", slope1, slope2, slope3);
        bool used = false;
        for(int i = 0; i < n*(n-1)/2; ++i){
          if(used_slope[i] == slope1 || used_slope[i] == slope2 || used_slope[i] == slope3){
						used = true;
            break;
          }
        }
        if(used){	continue;	}
                
        if (slope1 == slope2 && slope2 == slope3) {
          if(slope1 == DBL_MAX){
            if(x1 == x2 && x2 == x3){
              cnt++;
            }
          }else{
            cnt++;
          }
          used_slope[idx] = slope1;
          //printf("used_slope[%d] = %lf\n", idx, slope1);
          idx++;
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