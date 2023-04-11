#include <stdio.h>
int board[11][11];
void place(int row, int size);
void show_board(int size)
{
	int i, j;
	for (i=1; i<=size; i++) {
		for (j=1; j<=size; j++) {
			if (board[i][j]==0) {
			  printf("O");
			} else {
					printf("#");
			}
		}
		printf("\n");
	}
	printf("\n");
}
int main(void)
{
	place(1, 9);
	return 0;
}
int is_valid(int r, int c)
{
		int j;
	  for (j=r-1; j>=1; j--) {
				if (board[j][c]==1) {
						return 0;
				}
		}
		return 1;
}
void place(int row, int size)
{
	int i;
	if (row>size) {
		show_board(size);
	} else {
		for (i=1; i<=size; i++) {
			if (is_valid(row, i)) {
				board[row][i] = 1;
				place(row+1, size);  
				board[row][i] = 0;
			}
		}
	}
}

/*
0 1 0  row=1, i=1
0 0 0  row=2, i=1
0 0 0  row=3, i=2
*/