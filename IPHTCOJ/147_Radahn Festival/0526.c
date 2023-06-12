#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5+3)

typedef struct _Segment{
	double L, R;
} Segment;

Segment segs[MAXN];

int cmp(const void * a, const void * b){
	Segment aa = *(Segment *) a;
  Segment bb = *(Segment *) b;
  if(aa.L != bb.L) return aa.L - bb.L;
  return aa.R - bb.R;
}

int main(){
	int t; scanf("%d", &t);
  while(t--){
    int n, q; scanf("%d%d", &n, &q);
    for(int i = 0; i < q; ++i){
      scanf("%lf%lf", &segs[i].L, &segs[i].R);
    }
    qsort(segs, q, sizeof(segs[0]), cmp);
    double L = segs[0].L, R = segs[0].R;
    double tot = 0;
    for(int i = 1; i < q; ++i){
      if(segs[i].L <= R){ // 先判斷有沒有overlap
        if(segs[i].R > R){ // 再判斷有沒有辦法更新R
          R = segs[i].R;
        }
      }else{
        tot += (R-L);
        L = segs[i].L;
        R = segs[i].R;
      }
    }
    tot += (R-L);
    printf("%lf\n", (n-tot) / n);
  }
	return 0;
}