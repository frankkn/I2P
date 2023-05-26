#include <stdio.h>

typedef struct _Point{
	int x, y;
} Point;

Point points[1003];
int visited[1003];
int n, r;

int isNeighbor(int p, int i){
if(((points[p].x-points[i].x)*(points[p].x-points[i].x) + (points[p].y-points[i].y)*(points[p].y-points[i].y)) <= (r * r)){
    return 1;
  }else{
    return 0;
  }
}

int cnt = 0;

void dfs(int p)
{
  visited[p] = 1;
  cnt++;
	for(int i = 0; i < n; ++i){
    if(visited[i])	continue;
      if(isNeighbor(p, i) == 0) continue;	
    dfs(i);
  }
}

int main(){
	scanf("%d%d", &n, &r);
  for(int i = 0; i < n; ++i){
    scanf("%d%d", &points[i].x, &points[i].y);
  }
  int g1 = 0, g2 = 0;
  for(int i = 0; i < n; ++i){
    if(!visited[i]){
    cnt = 0;
      dfs(i);
      if(cnt == 1) g1++;
      else g2++;
    }
  }
  printf("%d %d\n", g1, g2);

	return 0;
}