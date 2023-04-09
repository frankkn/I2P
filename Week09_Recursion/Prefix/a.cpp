// A piece of C code
#include <stdio.h>
#include <ctype.h>
int cal(void){
    int ans, op1, op2;
    char c = getchar();
    if ( c == ' ' ) return cal();
    if ( isdigit(c) ) {
        ungetc(c, stdin);
        scanf("%d", &ans);
        printf("%d", ans);
    }
    if( c == '+' ){
      printf("(");
      op1 = cal();
      printf("+");
      op2 = cal();
      printf(")");
      ans = op1 + op2;
    }
    if( c == '-' ){
      printf("(");
      op1 = cal();
      printf("-");
      op2 = cal();
      printf(")");
      ans = op1 - op2;
    }
    if( c == '*' ){
      printf("(");
      op1 = cal();
      printf("*");
      op2 = cal();
      printf(")");
      ans = op1 * op2;
    }
    return ans;
}
int main(void){
    // * + 2 3 + 4 + - 5 6 - 7 8
    printf(" = %d\n", cal());
    return 0;
}