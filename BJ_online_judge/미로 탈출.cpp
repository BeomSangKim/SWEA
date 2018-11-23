#include <stdio.h>
#include <queue>
using namespace std;

int N,M, res = 0;
int map[100][100] = {0,};

typedef struct point{
	int x,y;
}point;

queue<point> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool is_wall(int x, int y){
	if(x < 0 || y < 0 || x >= M || y >= N) return true;
	return false;
}

void bfs(){
	point p, input;
	input.x = 0;
	input.y = 0;
	q.push(input);
	int cur = 1, next_cur = 0;
	bool end = false;
	while(!q.empty()){
		if(end == true) break;
		res++;
		for(int i = 0; i < cur; i++){
			p = q.front();
			q.pop();
			if(p.x == M-1 && p.y == N-1){
				end = true;
				break;
			}
			
			for(int dir = 0; dir < 4; dir++){
				input.x = p.x + dx[dir];
				input.y = p.y + dy[dir];
				if(!is_wall(input.x, input.y)){ 
					if(map[input.y][input.x] == 1){
						q.push(input);
						next_cur++;
						map[input.y][input.x] = 0;
					}
				}
			}
		}
		cur = next_cur;
		next_cur = 0;
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();
	printf("%d", res);

	return 0;
}
