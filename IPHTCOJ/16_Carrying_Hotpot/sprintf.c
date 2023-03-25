#include <string.h> // for sprintf
#include <stdio.h>

int main(){
  double x, y; int z;
  scanf("%lf %lf %d", &x, &y, &z);

  char arr[20];
  sprintf(arr, "%%.%dlf\n", z);
  printf("%s", arr); // %.2lf 
  printf(arr, x*y);

  return 0;
}