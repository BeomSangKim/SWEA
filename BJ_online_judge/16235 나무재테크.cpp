#include <stdio.h>
#include <deque>
using namespace std;

int N,M,K; // K = 실행 년수
int A[10][10] = {0,};
int nourishment[10][10] = {0,};
int map[10][10] = {0, };
int dirrow[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dircol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

deque<int> TNOT[10][10];

int is_wall(int row, int col){
	if(row < 0 || col < 0 || row >= N || col >= N)
		return 1;
	return 0;
}

void go(){
	// spring : if there is lack of nourishment, tree die, and age up
	for(int row = 0; row <N; row++){
		for(int col = 0; col < N; col++){
			if(TNOT[row][col].size()){
				int j =0;
				for(int i = 0; i < TNOT[row][col].size()+j; i++){ // j번 나무가 죽으면 j만큼 사이즈가 줄어든다 하지만 처음사이즈 만큼 찾아야하기에 추가한다.

					if(map[row][col] >= TNOT[row][col][i-j]){
						map[row][col] -= TNOT[row][col][i-j]; // 영양분이 많으면 먹읍시다
					}
					else{
						nourishment[row][col] += (int)(TNOT[row][col][i-j]/2); // 영양분 맵에 ㄱㄱ
						TNOT[row][col].pop_back();						// pop back해도 sort되어있기때문에 만일 영양분이 3이고 나무가 12345 존한다면 12345 -> 12345 -> 1234 -> 123 -> 12
						j++;											// 나무 수가 줄었기때문에 for문에 1회 추가 index에 -1
					}
				}
			}
		}
	}
	for(int row = 0; row < N; row++){ // age up
		for(int col = 0; col < N; col++){
			for(int i = 0; i < TNOT[row][col].size(); i++){
				TNOT[row][col][i] += 1;
			}
		}
	}
	// summer : in this spring, died tree be nourishment
	for(int row = 0; row <N; row++){
		for(int col = 0; col < N; col++){
			map[row][col] += nourishment[row][col]; //맵에 죽은나무에 의한 영양분 추가
			nourishment[row][col] = 0;
		}
	}
	// authum : breeding's season
	for(int row = 0; row <N; row++){
		for(int col = 0; col < N; col++){
			if(TNOT[row][col].size()){
				for(int i = 0; i < TNOT[row][col].size(); i++){
					if(TNOT[row][col][i]%5 == 0){
						for(int dir = 0; dir < 8; dir++){
							int x = row + dirrow[dir];
							int y = col + dircol[dir];
							if(!is_wall(x, y)){		// 벽이아닐때 푸시 1살
								TNOT[x][y].push_front(1);	// 1살이므로 앞에 넣어주면 sort 필요 x
							}
						}
					}
				}
			}
		}
	}
	// winter : map += A
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			map[row][col] += A[row][col];	//맵에 1년주기로 영양분 공급
		}
	}
}

int main(){

	scanf("%d %d %d", &N, &M, &K);
	
	for(int col = 0; col < N; col++){
		for(int row = 0; row < N; row++){
			scanf("%d", &A[row][col]);
			map[row][col] = 5;
		}
	}
	
	for(int i = 0 ; i < M; i++){
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		TNOT[x-1][y-1].push_front(z);	// 같은위치에 하나씩만 들어가므로 sort 필요 x
	}

	for(int i = 0; i < K; i++){		// k년
		go();
	}

	int ans = 0;
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			ans += TNOT[row][col].size();
		}
	}
	printf("%d\n", ans);
	return 0;
}
