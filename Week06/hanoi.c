#include <stdio.h>
void hanoi(char from, char to, char buffer, int n_disks);

int main(void)
{
	int n;
	printf("Number of disks: ");
	scanf("%d", &n);
	hanoi('1', '3', '2', n);

	return 0;
}

/* move n disks from a to b using c as a buffer */
void hanoi(char a, char b, char c, int n)
{
	if (n == 0) {		
		return;
	}
	hanoi(a, c, b, n-1); /* move the top n-1 disks from a to c */
	printf("Move the top disk from Tower %c to Tower %c\n", a, b); /* move the last disk from a to b */
	hanoi(c, b, a, n-1); /* move the top n-1 disks from c to b */
}

void hanoi2(int s, int t, int n){ // Only for 3 pegs
  if (n == 0) {
    return;
  }
  hanoi(s, 6-(s+t), n-1);
  printf("%d ---> %d\n", s, t);
  hanoi(6-(s+t), t, n-1);
}