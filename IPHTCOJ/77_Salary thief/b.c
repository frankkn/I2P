#include <stdio.h>
#include <string.h>
#define MOD ((int) 1e9 + 7)

char s[(int)3e6+1], temp[(int)3e6+1];

int main(){
	int t;scanf("%d", &t);
  while(t--){
    int x; scanf("%d %s", &x, s);
    int ans = strlen(s); // O(n)
    int true_len = ans;
    int left = s[0] - '0';
    for(int i = 1; i <= x; ++i){
      ans += ((ans - i) % MOD * (left - 1)) % MOD;
      ans %= MOD;
      if(true_len <= x){
        strcpy(temp, s+i);
        for(int j = 1; j <= left-1; ++j){
          strcat(s, temp);
        }
        true_len += (true_len - i) * (left - 1);
      }
      left = s[i] - '0';
    }
    if(ans < 0) ans+=MOD;
    printf("%d\n", ans);
  }
  return 0;
}