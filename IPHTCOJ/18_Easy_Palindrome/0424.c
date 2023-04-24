#include <stdio.h>

int rev(int x){
	int ans = 0;
    while(x){
    	ans *= 10;
      ans += (x % 10);
      x /= 10;
    }
	return ans;
}


int main(){
	int f, b; scanf("%d.%d", &f, &b);
    
	double new_f = rev(f);
  double new_b = (double)rev(b) / 1000;
  
  double db = (double)b/ 1000;
  
  printf("%.3lf\n", new_f+new_b +f+db);
	return 0;
}