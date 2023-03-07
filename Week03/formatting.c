#include <stdio.h>
#include <string.h>
#define BORDER "############################################"
int main(void)
{
  // 會輸出 uni 也就是只會輸出前三個字元
  printf("%.3s\n", "university");

  // 會輸出 university 前面會多五個空格
  printf("%15s\n", "university");
  
  // 會輸出 uni 也就輸出 university 的前三個字元 然後前面會多加入 12 個空格 總共長度是 15 個字元
  printf("%15.3s\n", "university");
  
  // 用動態的方式來設定格式 在這個例子得到的輸出結果也是 uni 也就是把兩個 * 號分別用 15 和 3 取代 相當於 "%15.3s\n" 的效果
  printf("%*.*s\n", 15, 3, "university");
  
  return 0 ;
}