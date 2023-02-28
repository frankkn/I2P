#include <stdio.h>
#include <string.h>
#define MAXN 2000

char s[MAXN+1];
int dp[MAXN][MAXN];

int main(){
  while(scanf("%s", &s)!= EOF){
    int n = strlen(s);
    memset(dp, 0, sizeof(dp));
    
    // len = 1 
    for(int i = 0; i < n; ++i){
      dp[i][i] = 1;
    }
    // len = 2
    for(int i = 0; i < n-1; ++i){
      if(s[i] == s[i+1]){
          dp[i][i+1] = 1;
        }
    }
    for(int len = 3; len <= n; ++len){
      for(int i = 0; i <= n-len; ++i){
          int j = i + len - 1;
            if(s[i] == s[j]){
                if(len <= 3 || dp[i+1][j-1]){
                  dp[i][j] = 1;
                }
            }else{
              dp[i][j] = 0; 
            }
        }
    }
    int cnt = 0;
    
    for(int i = 0; i < n; ++i){
      for(int j = i+1; j < n; ++j){
            // printf("dp[%d][%d] = %d", i,j,dp[i][j]);
          cnt += dp[i][j];
        }
        //printf("\n");
    }
    
    printf("%d\n", cnt);
  }
  return 0;
}