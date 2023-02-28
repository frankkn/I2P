//寫一個string compare的function。相同return 0，不同return 1
#include <stdio.h>
#include <string.h>

int main(){
    
    char s1[40];
    char s2[40];
    
    printf("Enter the first string: ");
    scanf("%s",s1);
    printf("Enter the second string: ");
    scanf("%s",s2);
    int result = strcmp(s1,s2);
    if(result == 0){ // SAME!
      result = 1;
    }else{ // NOT THE SAME
      result = 0;
    }
    printf("%d", result);
    return 0;
}