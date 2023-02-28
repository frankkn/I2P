#include <iostream>
#include <cstdio> // scanf
#include <cstring> // strcmp
using namespace std;

int main()
{
  int i;
  for(i = 1; i <= 3; i++){
    char* account = new char [10];
    char* password = new char [10];
    scanf("%s", account);
    scanf("%s", password);

    int result = 0; // 0 both are correct, 1 acc is wrong, 2 password is wrong
    if(strcmp(account,"abcd") != 0){
      result = 1;
    }
    else if(strcmp(password,"1234") != 0){
      result = 2;
    }

    if(result == 0){
      printf("%s", "Welcome!");
      break;
    }
    else if(result == 1){
      printf("%s", "Account is wrong!\n");
    }
    else{
      printf("%s", "Password is wrong!\n");
    }
  }
  if(i == 4){
    printf("%s", "Over three times!");
  }
  return 0;
}