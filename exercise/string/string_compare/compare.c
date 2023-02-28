#include <stdio.h>

int str_Compare(char* s1, char* s2){
    int i = 0, flag = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] != s2[i]){
            flag = 1; // not the same
            break;
        }
        i++;
    }
    return flag? 0 : 1;
}

int main(){
    
    char s1[40];
    char s2[40];
    
    printf("Enter the first string: ");
    scanf("%s",s1);
    printf("Enter the second string: ");
    scanf("%s",s2);
    int result = str_Compare(s1,s2);
    printf("%d", result);
    return 0;
}