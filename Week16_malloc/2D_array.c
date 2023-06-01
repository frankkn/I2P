#include <stdio.h>
#include <stdlib.h> // malloc, rand

int main(void)
{
    int** a;  // a[0], a[1], ..., a[9]
    int * array;
    int row, col;
    int i, j;
    scanf("%d%d", &row, &col);
  
    /*
    row = 5
    col = 3
    row*col = 15
     0  1  2   3  4  5  6  7  8  9  10 11   12 13 14
    |1  2  3  |4  5  6 |7  8  9 |10 11 12 | 13 14 15|
    */
 
    array = (int*) malloc(row*col*sizeof(int));
    a = (int**) malloc(row*sizeof(int*));
    for (i=0; i<row; ++i) {
      a[i] = &array[i*col];
    }
 
    for (i=0; i<row; ++i) {
        for (j=0; j<col; ++j) {
            a[i][j] = i*col + (j+1);
        }
    }

    for (i=0; i<row; ++i) {
        printf("a[%d]: %p a[%d][0]=%d, a[%d][1]=%d, a[%d][2]=%d %p\n", 
               i, a[i], i, a[i][0], i, a[i][1], i, a[i][2], &a[i][2]);
    }
 
    free(a);
    free(array);
    
    return 0;
}