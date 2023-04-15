#include <stdio.h>
#define MOD (int)(1e9+7)

char str[(int)3e6+3];
char temp[(int)3e6+3];

int main(){
	int t; scanf("%d", &t);
  while(t--){
    int x; scanf("%d", &x);
    scanf("%s", str);
    int ans = strlen(str);
    long long true_len = ans; // true_len = strlen(str)
    for(int i = 1; i <= x; ++i){
      int left = str[i-1] - '0'; // leftmost number
      int temp_len = (ans - i + MOD) % MOD; // right part length
      ans = (ans % MOD + (ans - i) * (left - 1) % MOD ) % MOD;
      if(true_len < x){
        strcpy(temp, str+i); // temp = right part
        for(int j = 1; j < left; ++j){
          strcat(str, temp);
          true_len += temp_len;
        }
      }
    }
    if(ans < 0) ans += MOD;
    printf("%lld\n", ans);
  }
	return 0;
}