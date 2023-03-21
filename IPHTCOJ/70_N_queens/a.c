#include <stdbool.h>
#include <stdio.h>

bool col_has_queen[14];
bool LU_RD[14*2+1];
bool RU_LD[14*2+1];

int n = 0;
int ans = 0;

void update(int y, int x, bool val){
  col_has_queen[x] = val;
  LU_RD[y+x] = val;
  RU_LD[(n-1) + (y-x)] = val;
}

bool isValid(int y, int x){
  if(col_has_queen[x])  return false;
  if(LU_RD[y+x])  return false;
  if(RU_LD[(n-1) + (y-x)])  return false;
  return true;
}

void dfs(int y){
  if(y == n){
    ans++;
    return;
  }
  for(int x = 0; x < n; ++x){
    if(!isValid(y, x)){
      continue;
    }
    update(y, x, true);
    dfs(y+1);
    update(y, x, false);
  }
}

int main(){
  // int n;
  scanf("%d", &n);

  dfs(0);
  printf("%d\n", ans);
  return 0;
}