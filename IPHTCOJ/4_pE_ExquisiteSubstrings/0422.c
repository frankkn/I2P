#include <stdio.h>
#include <string.h>

char s[2001];
int main(){
	while(scanf("%s", s) != EOF){
    int n = strlen(s);
    int dp[2000][2000] = {0};
    for(int i = 0; i < n; ++i) dp[i][i] = 1;
    for(int i = 0; i < n-1; ++i)	if(s[i] == s[i+1])	dp[i][i+1] = 1;
    for(int len = 3; len <= n; ++len){
      for(int i = 0; i <= n-len; ++i){
        int j = i+len-1;
        if(s[i] == s[j]){
          dp[i][j] = dp[i+1][j-1];
        }else{
          dp[i][j] = 0;
        }
      }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
      for(int j = i+1; j < n; ++j){
        if(dp[i][j])	cnt++;
      }
    }
    printf("%d\n", cnt);
  }
	return 0;
}