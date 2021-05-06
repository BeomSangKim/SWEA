//벽돌 깨기
// 구슬 N회 1~4회 try --> max map size 12 by 15 -> dfs
// 구현 함수 : 입력, 연쇠폭발(bfs), 가라앉음(탐색), 중복조합(for문), is_wall(일정범위만 탐색), res_update(결과 업데이트), data reset(리셋)
// 맵의 갯수 : N+1개필요(최대 5)
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

int N, W, H;
int nmap[5][12][15] = {0,};
int dirrow[4] = {1, 0, -1, 0};
int dircol[4] = {0, 1, 0, -1};
int res = 180;


typedef struct point{	
	int row;
	int col;
}point;

point p, np;
queue<point> q;

int is_wall(int w, int h){
	if(w < 0 || h < 0 || w >= W || h >= H ){
		return 1;
	}
	return 0;
}

void mapscan(int n){
	for(int i = 0; i < W; i++){
		for(int j = 0 ; j < H; j++){
			nmap[n-1][i][j] = nmap[n][i][j];
		}
	}
}

void explode(int row, int col, int n_th){
	p.row = row, p.col = col;
	q.push(p);
	while(!q.empty()){
		int size = q.size();
		for(int i = 0; i < size; i++){
			p = q.front();
			q.pop();
			int explodesize = nmap[n_th][p.row][p.col];
			nmap[n_th][p.row][p.col] = 0;
			for(int j = 0; j < 4; j++){
				for(int k = 1; k < explodesize; k++){
					if(is_wall(p.row+k*dirrow[j], p.col+k*dircol[j]) == 0){
						np.row = p.row+k*dirrow[j];
						np.col = p.col+k*dircol[j];
						q.push(np);
					}
				}
			}
		}
	}
}

void shrink(int n_th){
	for(int i = 0; i < W; i++){

		for(int j = H-1; j >= 0; j--){
			if(nmap[n_th][i][j] == 0){
				for(int k = 0 ; j - k >= 0 ; k++){
					if(nmap[n_th][i][j-k] != 0){
						nmap[n_th][i][j] = nmap[n_th][i][j-k];
						nmap[n_th][i][j-k] = 0;
						break;
					}
				}
			}
		}
	}

}


void start(int k, int n_th){
	for(int i = 0; i < H; i++){
		if(nmap[n_th][k][i] != 0){
			explode(k, i, n_th);
			shrink(n_th);
			break;
		}
	}
}



void connbination(int n){
	if(n == 0) return ;
	for(int i = 0; i < W; i++){
		mapscan(n);
		start(i, n-1);
		if(n == 1){
			//res_update
			int cnt = 0;
			for(int w = 0; w < W; w++){
				for(int h = 0; h < H; h++){
					if(nmap[0][w][h] != 0){
						cnt++;
					}
				}
			}
			res = cnt < res ? cnt : res;
		}
		connbination(n-1);
	}

}

void variable_clr(){
	N=0, W=0, H=0;

	for(int i = 0; i < 5; i++){
		for(int j = 0 ; j < 12; j++){
			for(int k = 0; k < 15; k++){
				nmap[i][j][k] = 0;
			}
		}
	}
	while(!q.empty()){
		q.pop();
	}
	res = 180;
}


int main(){

	int total_TC = 0;
	scanf("%d", &total_TC);

	for(int cur_TC = 1; cur_TC <= total_TC; cur_TC++){
		variable_clr();
		scanf("%d %d %d", &N, &W, &H);
		for(int i = 0; i < H; i++){
			for(int j = 0 ; j < W; j++){
				scanf("%d", &nmap[N][j][i]);
			}
		}
		connbination(N);
		printf("#%d %d\n", cur_TC, res);
		
	}
	

	return 0;

}
