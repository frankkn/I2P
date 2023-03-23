#include <stdio.h>
#include <stdlib.h>

int main(){
	int T; scanf("%d", &T);
    while(T--){
    	int n; scanf("%d", &n);
      int arr[n];
      long long xor = 0;
      for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        xor ^= arr[i]; // Get the XOR of all elements
      }

      long long lowbit = xor & (-xor); // We can take any set bit for xor
      // xor = -2147483648
      // -xor = 2147483648

      int a = 0;
      for(int i = 0; i < n; ++i){
        if(arr[i] & lowbit){ // Same bit set
          a ^= arr[i];
        }
      }

      int b = a ^ xor;

      if(a > b) printf("%d %d\n", b, a);
      else printf("%d %d\n", a, b);
    }
	return 0;
}