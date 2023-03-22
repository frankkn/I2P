#include <stdio.h>
#include <stdlib.h>

int lowbit(int x){
  return x&-x;
}

int main(){
	int T; scanf("%d", &T);
    while(T--){
    	int n; scanf("%d", &n);
      int arr[n];
      int xor = 0;
      for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        xor ^= arr[i]; // Get the XOR of all elements
      }

      int low_bit = lowbit(xor); // We can take any set bit for xor

      int a = 0, b = 0;
      for(int i = 0; i < n; ++i){
        if(arr[i] & low_bit){ // Same bit set
          a ^= arr[i];
        }else{ // Same bit not set
          b ^= arr[i];
        }
      }

      if(a > b) printf("%d %d\n", b, a);
      else printf("%d %d\n", a, b);
    }
	return 0;
}