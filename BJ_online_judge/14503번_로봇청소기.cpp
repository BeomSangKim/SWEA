#include <stdio.h>

int map[52][52] = {{1,},};
int res = 0, N = 0, M = 0, px = 0, py = 0;

int diry[4] = {0, 1, 0, -1};
int dirx[4] = {-1, 0, 1, 0};

int back_dx[4] = { 1,0,-1,0 };
int back_dy[4] = { 0,-1,0,1 };

void datainput(){
    for(int i = 1; i <= N; i++){
        for(int j = 1 ; j <= M; j++){
            scanf("%d", &map[i][j]);
        }
    }
}

void search(int x, int y, int status){ 
    if (map[x][y] == 1) return;
	
	if (map[x][y] == 0)//1.
    {
        map[x][y] = 2;
        res++;
    }

    for(int i = 0; i < 4; i++){
		int next_direction = status-1 < 0 ? 3 : status-1;
        int next_x = x + dirx[next_direction], next_y = y + diry[next_direction];
        if(map[next_x][next_y] == 0){ // 2.1
            search(next_x, next_y, next_direction);
			return ;
        }
		else
        {
            status = next_direction;
        }
        //2.2
    }
	int next_x = x + back_dx[status], next_y = y + back_dy[status];
	search(next_x, next_y, status);
	
    
}
int main(){
    int status = 0;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &px, &py, &status);

    datainput();
    search(px+1, py+1, status);

    printf("%d \n", res);
    return 0;
}