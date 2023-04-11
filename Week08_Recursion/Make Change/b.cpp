#include <stdio.h>
#define MAXNV 5                  //0  1  2  
int values[MAXNV]; // values[] = {1, 5, 10};
int numbers[MAXNV];// numbers[] = {2, 1, 1};
int limit[MAXNV] = {5,5,5};

void show(int nv);
void change(int amount, int smallest_idx, int nv);

int main(void)
{
	int nv, i;
	int money;

	scanf("%d", &nv);
	if (nv>MAXNV || nv<1) return 0;

	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);  // 1 5 10
	}

	scanf("%d", &money);  // 17
	change(money, 0, nv); // change(17, 0, 3);

	return 0;
}

void show(int nv)
{
	int i;
	printf("(%d", numbers[0]);
	for (i=1; i<nv; i++) {
		printf(",%d", numbers[i]);
	}
	printf(")\n");
}

void change(int amount, int smallest_idx, int nv)
{
	if (smallest_idx<nv) {
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
			// do not use the smallest valued coin 
			change(amount, smallest_idx+1, nv);
			// use one coin of the smallest value
      if (numbers[smallest_idx] < limit[smallest_idx]) {
        numbers[smallest_idx] += 1;
        change(amount-values[smallest_idx], smallest_idx, nv);
        numbers[smallest_idx] -= 1;
      }
		}
	}
}