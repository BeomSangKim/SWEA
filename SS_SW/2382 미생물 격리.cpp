#include <stdio.h>
int N,M,K;
typedef struct MyStruct{
	int x,y,num,dir;
}cluster;

cluster A[1000] = {0,};

int dirx[4] = {0, 0, -1, 1};
int diry[4] = {-1, 1, 0, 0};

bool is_wall(int i){
	if(A[i].x == 0 || A[i].y == 0 || A[i].x == N-1 || A[i].y == N-1)
		return true;
	return false;
}

void move(){
	for(int i = 0; i < K; i++){
		if(A[i].num == 0) continue; 
		if(!is_wall(i)){
			A[i].x = A[i].x + dirx[A[i].dir];
			A[i].y = A[i].y + diry[A[i].dir];
		}
		else{//벽이다 방향이 바뀌었따
			switch(A[i].dir){
			case 0:
				A[i].dir = 1;
				break;
			case 1:
				A[i].dir = 0;
				break;
			case 2:
				A[i].dir = 3;
				break;
			case 3:
				A[i].dir = 2;
				break;
			}
			A[i].x = A[i].x + dirx[A[i].dir];
			A[i].y = A[i].y + diry[A[i].dir];
		}
	}
}

void merge(){
	for(int i = 0; i < K; i++){
		if(A[i].num == 0) continue;
		for(int j = i + 1; j < K; j++){
			if(A[j].num == 0) continue;
			if(A[i].x == A[j].x && A[i].y == A[j].y){ // 같은 위치에 2군집
				int three = 0;
				int four  = 0;
				for(int k = j + 1; k < K; k++){
					if(A[k].num == 0) continue;
					if(A[i].x == A[k].x && A[i].y == A[k].y){ // 같은 위치에 3군집
						three = k;
						for(int l = k + 1; l < K; l++){
							if(A[l].num == 0) continue;
							if(A[i].x == A[l].x && A[i].y == A[l].y){ // 같은 위치에 4군집
								four = l;
								break;
							}
						}
					}
				}
				if(three == 0){ // 같은위치 2군집
					A[i].dir = A[i].num > A[j].num ? A[i].dir : A[j].dir;
					A[i].num = A[i].num + A[j].num;
					A[j].num = 0;
				}
				else if(four == 0){ // 같은 위치에 3군집
					if(A[i].num > A[j].num){
						A[i].dir = A[i].num > A[three].num ? A[i].dir : A[three].dir;
					}
					else if(A[i].num < A[j].num){
						A[i].dir = A[j].num > A[three].num ? A[j].dir : A[three].dir;
					}
					A[i].num = A[i].num + A[j].num + A[three].num;
					A[j].num = 0;
					A[three].num = 0;
				}
				else{ // 같은 위치에 4군집
					if(A[i].num > A[j].num){
						if(A[i].num > A[three].num){
							A[i].dir = A[i].num > A[four].num ? A[i].dir : A[four].dir;
						}
					}
					else if(A[i].num > A[j].num){
						if(A[i].num < A[three].num){
							A[i].dir = A[three].num > A[four].num ? A[three].dir : A[four].dir;
						}
					}
					else if(A[i].num < A[j].num){
						if(A[j].num > A[three].num){
							A[i].dir = A[j].num > A[four].num ? A[j].dir : A[four].dir;
						}
					}
					else if(A[i].num < A[j].num){
						if(A[j].num < A[three].num){
							A[i].dir = A[three].num > A[four].num ? A[three].dir : A[four].dir;
						}
					}
					A[i].num = A[i].num + A[j].num + A[three].num + A[four].num;
					A[j].num = 0;
					A[three].num = 0;
					A[four].num = 0;
				}
			}
		}
	}
}

void death(){//죽는다
	for(int i = 0; i < K; i++){
		if(A[i].num == 0) continue; 
		if(is_wall(i)){
			A[i].num = A[i].num/2;
		}
	}
}

int main(){
	int total_TC;

	scanf("%d", &total_TC);

	for(int cur_TC = 1; cur_TC <= total_TC; cur_TC++){
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0; i < K; i++){
			scanf("%d %d %d %d", &A[i].y, &A[i].x, &A[i].num, &A[i].dir);
			A[i].y = A[i].y;
			A[i].x = A[i].x;
			A[i].dir = A[i].dir - 1;
		}
		for(int t = 1; t <= M; t++){
			move();//움직인다
			merge();//합병
			death();//죽어따
		}
		int res = 0;
		for(int i = 0; i < K; i++){
			res += A[i].num;
		}
		printf("#%d %d\n", cur_TC, res);
	}
	return 0;
}
