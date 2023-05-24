# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define SIZE 10

int compare(const void *a, const void *b)
{
  const char *ca = (const char *) a;
  const char *cb = (const char *) b;
  return strcmp(ca, cb);
}

int main(void)
{
  char strs[SIZE][4] = {
    "aab", "abc", "aaa", "abb", "acb",
    "aab", "abc", "aaa", "abb", "acb"
  };
  int i;

  for (i=0; i<SIZE; i++) {
    printf("%s\n", strs[i]);
  }
  printf("\n");
  qsort(strs, SIZE, 4*sizeof(char), compare);
  for (i=0; i<SIZE; i++) {
    printf("%s\n", strs[i]);
  }

  return 0;
}