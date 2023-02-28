#include <stdio.h>
#include <string.h>

void swap(char* str, int left, int right)
{
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
}

void Reverse(char* str, int left, int right)
{
    if(left > right){
        return;
    }
    swap(str, left, right);
    left++;
    right--;
    Reverse(str, left, right);
}

int main()
{
  char str[40];
  printf("Enter a string: ");
  while(scanf("%s",str))
  {
    Reverse(str, 0, strlen(str)-1);
    printf("After reverse: %s\n",str);
    printf("Enter a string: ");
  }
}