#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
int main(){
  int t;  scanf("%d", &t);
  while(t--){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    k = min(k, m-1);
    int a[5001], ans = 0;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    if(k >= m-1){ // 我可以控制我之前的所有人
      // 假設k = 3, m = 4
      // 第一回合，我拿掉右邊三個(k個)，然後選max(最左,最右)；第二回合，我拿掉右邊二個左邊一個，然後選max(最左，最右)，以此類推。
      for(int l = 1, r = n - (m-1); r <= n; ++l, ++r){  
        int pick = max(a[l], a[r]);
        ans = max(ans, pick);
      }
      printf("%d\n", ans);
    }else{
      // 第一回合，我先拿掉右邊k個，第二回合，我先拿掉右邊(k-1)個左邊1個，以此類推。
      for(int l = 1, r = n-k; r <= n; ++l, ++r){
        int _min = 0x3f3f3f3f;
        // 右邊已經拿了k個，剩下(m-1)-k個，(m-1去扣是因為最後一步是我要拿的)所以r-[(m-1)-k]
        for(int ll = l, rr = r-((m-1)-k); rr <= r; ++ll, ++rr){ // 
          int pick = max(a[ll], a[rr]);
          _min = min(_min, pick); // 因為後面的(m-1)-k個的順序是隨機的，所以要記下最糟糕的情況
        }
        ans = max(ans, _min);
        
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}