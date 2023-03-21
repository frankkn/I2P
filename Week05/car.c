# include <stdio.h>
# define MAP_SIZE 12
# define CAR_SIZE 3
//#define ONLINE_JUDGE 

int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);

void map_show(void);

int blocks[MAP_SIZE][MAP_SIZE];
void blocks_read(void);
void blocks_put_on_map(void);

int jewels[MAP_SIZE][MAP_SIZE];
void jewels_read(void);
void jewels_put_on_map(void);

int car[CAR_SIZE][CAR_SIZE] = {{'O', 'O', '@'}, {'O', 'O', 'O'}, {'O', 'O', '@'}};
int car_row = 3, car_col = 4;
int car_direction;
int car_earnings;
void car_rotate90(void);
void car_put_on_map(void);
void car_move(void);

int main(void)
{
	char dir[] = {'R', 'D', 'L', 'U'};
	char ch;
	blocks_read();
	jewels_read();

	map_reset();
	blocks_put_on_map();
	jewels_put_on_map();
	car_put_on_map();
	map_show();

  #ifndef ONLINE_JUDGE	
	freopen("actions.txt", "r", stdin);
  #endif
	while( (ch=getchar()) != EOF ) {
		map_reset();

		if (ch=='F') car_move();
		else if (ch=='R') car_rotate90();
		else {}

		blocks_put_on_map();
		jewels_put_on_map();
		car_put_on_map();
		map_show();
	}	

	printf("Earnings: %d\n", car_earnings);
	printf("Position: row=%d, col=%d\n",
		       	car_row, car_col);
	printf("Direction: %c\n", dir[car_direction]);

    	return 0;
}

void map_reset(void)
{
	int i, j;
	for (i=0; i<MAP_SIZE; i++) {
		for (j=0; j<MAP_SIZE; j++) {
			map[i][j] = '.';
		}
	}
	for (i=0; i<MAP_SIZE; i++) {
		map[0][i] = map[i][0] = map[i][MAP_SIZE-1] = map[MAP_SIZE-1][i] = 'H';
	}
}

void map_show(void)
{
	int i, j;
	for (i=0; i<MAP_SIZE; i++) {
		for (j=0; j<MAP_SIZE; j++) {
			putchar(map[i][j]);
		}
		putchar('\n');
	}
}

void blocks_read(void)
{
	int n, r, c;
  #ifndef ONLINE_JUDGE
	freopen("blocks.txt", "r", stdin);
  #endif
	scanf("%d", &n);
	while (n>0) {
		scanf("%d%d", &r, &c);
		blocks[r][c] = 1;
		n--;
	}
}

void blocks_put_on_map(void)
{
	int i, j;
	for (i=0; i<MAP_SIZE; i++) {
		for (j=0; j<MAP_SIZE; j++) {
			if (blocks[i][j]==1) {
				map[i][j] = '#';
			}
		}
	}
}

void jewels_read(void)
{
	int n, r, c;
  #ifndef ONLINE_JUDGE
	freopen("jewels.txt", "r", stdin);
  #endif
	scanf("%d", &n);
	while (n>0) {
		scanf("%d%d", &r, &c);
		jewels[r][c]++ ;
		n--;
	}
}

void jewels_put_on_map(void)
{
	int i, j;
	for (i=0; i<MAP_SIZE; i++) {
		for (j=0; j<MAP_SIZE; j++) {
			if (jewels[i][j]>0) {
				map[i][j] = '$';
			}
		}
	}
}

void car_put_on_map(void)
{
	int i, j;
	for (i=0; i<CAR_SIZE; i++) {
		for (j=0; j<CAR_SIZE; j++) {
			map[car_row+i][car_col+j] 
				= car[i][j];
		}
	}
}

void car_move(void)
{
	int i, j, valid;
	int car_row_n;
	int car_col_n;
	int diff_r[4] = {0, 1, 0, -1};
	int diff_c[4] = {1, 0, -1, 0};

	printf("move forward\n");
	car_row_n = car_row + diff_r[car_direction];
	car_col_n = car_col + diff_c[car_direction];


	valid = 1;
	for (i=0; i<CAR_SIZE; i++) {
		for (j=0; j<CAR_SIZE; j++) {
			if (blocks[car_row_n+i][car_col_n+j]!=0
			|| map[car_row_n+i][car_col_n+j]!='.') 
				valid=0;
        break;
		}
	}
	if (valid) {
		car_row = car_row_n;
		car_col = car_col_n;
	}

	for (i=0; i<CAR_SIZE; i++) {
		for (j=0; j<CAR_SIZE; j++) {
			if (jewels[car_row+i][car_col+j]>0){
        jewels[car_row+i][car_col+j]--;
        car_earnings++;
			}
		}
	}
	
}

void car_rotate90(void)
{
  int tmp;
  if (car_direction%2) { // 朝上或朝下，對調左上跟右下
    tmp = car[0][0];
    car[0][0] = car[2][2];
    car[2][2] = tmp;
  } else { // 朝左或朝右，對調右上跟左下
    tmp = car[0][2];
    car[0][2] = car[2][0];
    car[2][0] = tmp;      
  }
	for (i=0; i<CAR_SIZE; i++) {
		for (j=0; j<CAR_SIZE; j++) {
			if (jewels[car_row+i][car_col+j]>0){
        jewels[car_row+i][car_col+j]--;
        car_earnings++;
			}
		}
	}
	car_direction = (car_direction+1)%4;
}