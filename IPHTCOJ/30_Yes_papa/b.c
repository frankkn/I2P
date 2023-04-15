#include <stdio.h>
#include <string.h>
char a[1000], b[1000];

int eq(char a[], char b[]){
  int n = strlen(a);
  // if(n == 2){
  //   if( (a[0] == b[0] && a[1] == b[1]) || (a[0] == b[1] && a[1] == b[0])){
  //     return 1;
  //   }else{
  //     return 0;
  //   }
  // }
	if(n % 2 == 1){
    return strcmp(a, b) == 0)? 1:0;
  }else{
    char a1[n/2+1], a2[n/2+1], b1[n/2+1], b2[n/2+1]; 
    strncpy(a1, a, n/2); strncpy(a2, a+n/2, n/2);
    strncpy(b1, b, n/2); strncpy(b2, b+n/2, n/2);
    a1[n/2] = '\0';
    a2[n/2] = '\0';
    b1[n/2] = '\0';
    b2[n/2] = '\0';
    return ( eq(a1,b1) && eq(a2,b2) ) || ( eq(a1,b2) && eq(a2,b1) );
  }
}

int main(){
	scanf("%s %s", a, b);
  if(eq(a, b)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
	return 0;
}