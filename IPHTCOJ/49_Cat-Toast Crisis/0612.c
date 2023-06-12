#include <stdio.h>
typedef struct _Point{
	int x,y;
}Point;

Point p[1003];
int visited[1003];
int n, r; 
int isNeighbor(int i, int j){
	return ((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)) <= r*r;
}

int dfs(int i){
	if(visited[i]) return 1;
    visited[i] = 1;
    int cnt = 0;
    for(int j = 0; j < n; ++j){
    	if(isNeighbor(i, j)){
        	cnt += dfs(j);
        }
    }
    return cnt;
}

int main(){
	scanf("%d%d", &n, &r);
    for(int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
    int g1 = 0, g2 = 0;
    for(int i = 0; i < n; ++i){
    	if(!visited[i]){
        	if(dfs(i) == 1) g1++;
            else g2++;
        }
    }
    printf("%d %d", g1, g2);
	return 0;
}