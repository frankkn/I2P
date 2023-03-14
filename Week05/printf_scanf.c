#include <stdio.h>
#include <string.h>
#include <ctype.h>

// int:32 bits
// short: 16 bits
// char: 8 bits
// long: 32 bits
// long long: 64 bits 整數型態
// 二進位表示法是用同樣的邏輯在儲存
// 差別在於位元數不同
int main(void)
{
  int c; 
  int z, u;

  // scanf %d  read a sequence of digits, interpret it as an integer
  z = 0;
  while ( (c=getchar()) && isdigit(c)) {  //'1' '2' '3' '4' (ASCII:48-59)
    z = z*10 + c - '0';
  }
  
  // printf %d
  u = 1;
  while (u <= z) {
    u = u * 10;
  }
  u = u/10; // 找到最靠近 z 的 10 的次方
  while (u > 0) { // z=12345 u=10000  z/u==1, z%u==2345  u/10==1000
    putchar(z/u + '0'); // '1'
    z = z % u; // z = 2345
    u = u / 10; // u = 1000
  }

  // scanf %x  read a sequence of digits, interpret it as an integer
  z = 0;
  while ( (c=getchar()) && isxdigit(c)) {  //'1' '2' '3' '4'
    if (isdigit(c)) {
      z = z*16 + c - '0';
    } else {
      z = z*16 + (toupper(c) - 'A' + 10); // 'A'-->10, 'B'-->11, ..., 'F'-->15
    }
  }


  // printf %x
  u = 1;
  while (u <= z) {
    u = u * 16;
  }
  u = u/16; // 找到最靠近 z 的 16 的次方
  while (u > 0) { // z=12345 u=10000  z/u==1, z%u==2345  u/10==1000
    if (z/u < 10) {
      putchar(z/u + '0');
    } else {
      putchar(z/u-10 + 'A');
    }
    z = z % u;
    u = u / 16;
  }
}