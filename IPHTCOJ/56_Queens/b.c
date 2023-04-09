#include <stdio.h>
#define MAXN 14

int q[MAXN];
int count = 0;
int N;

int valid(int r, int c){
	for(int i = 0; i < r; ++i){
    	if(q[i] == c) return 0;
        if(r - i == c-q[i]) return 0;
        if(r - i == q[i]-c) return 0;
    }
    return 1;
}

void show(){
	for(int i = 0; i < N; ++i){
    	for(int j = 0; j < N; ++j){
    		if(q[i] == j){
            	printf("Q");
            }else{
            	printf("-");
            }    
        }
        printf("\n");
    }
    printf("~~~~~~~~~~~~\n");
}

void placerow(int i){
	if(i >= N){
        count++;
        //show();
        return;
	}
    for(int j = 0; j < N; ++j){
    	if(valid(i, j)){
        	q[i] = j;
            placerow(i+1);
        }
    }

}

int main(){
    scanf("%d", &N);
    placerow(0);
    printf("%d\n", count);
    return 0;
}