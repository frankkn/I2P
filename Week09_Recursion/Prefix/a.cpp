#include <stdio.h>
#include <ctype.h>

int cal(void)
{
  int ans, op1, op2;
  char c = getchar();
  if (c == ' ') {
		return cal();
	} else if (isdigit(c)) {
    ungetc(c, stdin);
    scanf("%d", &ans);
    printf("%d", ans);
    return ans;
  } 
  
  printf("(");
  op1 = cal();
  printf(" %c ", c);
  op2 = cal();  
  printf(")");
    
  if(c == '+') {
		return op1 + op2;
	} else if(c == '-') {
		return op1 - op2;
	} else if(c == '*') {
		return op1 * op2;
	}
}

int main(void)
{
  printf(" = %d\n", cal());
  return 0;
}

// ((2 + 3) * (4 + ((5 - 6) + (17 - 18))))