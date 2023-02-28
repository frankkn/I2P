#include <stdio.h>
#include <string.h>

void swap(char* a,char* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void Reverse(char* s, int left, int right)
{
    while(left < right)
    {
        swap(&s[left],&s[right]);
        left++;
        right--;
    }
    printf("%s\n", s);

}

int main()
{
    char s[1000];
    scanf("%s",s);
    Reverse(s, 0, strlen(s)-1);
    return 0;
}