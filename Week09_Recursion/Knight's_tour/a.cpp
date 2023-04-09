// A piece of C code
#include <stdio.h>
#define n 5//棋盤大小
#define start_row 3
#define start_col 3

int board[n+2][n+2];

void place(int row, int col, int num);

void show_board(void)
{
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if(board[i][j]<10){                   //為了讓輸出的棋盤更好看
                printf(" %d ", board[i][j]);
            }else{
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    place(start_row, start_col, 1);
    return 0;
}

int valid(int row, int col)
{
    if(board[row][col]==0 && row>=1 && row<=n && col>=1 && col<=n){
        return 1;
    }
    return 0;
}

void place(int row, int col, int num)
{
    if (num==n*n+1) {
        show_board();
    } else {
        if(valid(row, col)){
            board[row][col]=num;
            place(row-2, col+1, num+1);
            place(row-1, col+2, num+1);
            place(row+1, col+2, num+1);
            place(row+2, col+1, num+1);
            place(row+2, col-1, num+1);
            place(row+1, col-2, num+1);
            place(row-1, col-2, num+1);
            place(row-2, col-1, num+1);
            board[row][col]=0;
        }
    }
}