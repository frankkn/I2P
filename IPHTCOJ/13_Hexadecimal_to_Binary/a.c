#include <stdio.h>
#include <math.h>

int hex_to_dec(int n){
	int ans = 0;
  int exp = 0;
  while(n > 0){
    int cur_digit = n%16;
    n/=16;
    ans += cur_digit * pow(16, exp);
    exp++;
  }
  return ans;
}

void dec_to_bin(int n){
	int bin[64];
  int i = 0;
  while(n > 0){
    bin[i] = n%2;
    n/=2;
    i++;
  }
  for(int j = i-1; j >= 0; --j){
    printf("%d", bin[j]);
  }
}

int main(){
	int x, y;
  scanf("%x%x", &x, &y);
  int sum_in_hex = x+y;
  int sum_in_dec = hex_to_dec(sum_in_hex);
  
  dec_to_bin(sum_in_dec);
  //int sum_in_bin = dec_to_bin(sum_in_dec);
  //printf("%d\n", sum_in_bin);

  return 0;
}