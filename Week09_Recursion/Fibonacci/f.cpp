#include <stdio.h>

int dp[(int)1e5];

int F(int i){
  if(dp[i])  return dp[i];

  if(i == 1 || i == 2){
    return 1;
  }else{
    return dp[i] = F(i-1) + F(i-2);
  }
}

int main(){
  printf("%d\n", F(30));
  return 0;
}