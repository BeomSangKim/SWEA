#include <stdio.h>

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};
int last_core = 0;
int last_res = 0;
int total_core = 0;
int nmap[12][12] = {0,};
bool connected[12] = {0,};
int N = 0;

typedef struct point{
	int x;
	int y;
}point;

point p[12] = {0,};


void res_update(){
	int res_core = 0;
	for(int i = 0; i < total_core; i++){
		if(connected[i] == true ) res_core++;
	}
	int res = 0;
	for(int y = 0 ; y < N ; y++){
		for(int x = 0; x < N; x++){
			if(nmap[x][y] == 2){
				res++;
			}
		}
	}
	if(res_core > last_core){
		last_res = res;
		last_core = res_core;
	}
	else if(res_core == last_core)
		last_res = res > last_res ? last_res : res;

}

int is_source(int x, int y){
	if(x < 0 || y < 0 || x >=N || y >= N) 
		return 1;
	return 0;
}


int can_connect(int i, int dir){
	int j = 1;
	while(!is_source(p[i].x+dirx[dir]*j, p[i].y+diry[dir]*j)){
		if(nmap[p[i].x+dirx[dir]*j][p[i].y+diry[dir]*j] != 0)
			return 0;
		j++;
	}
	return 1;
}

void connect(int i, int dir){
	int j = 1;
	while(!is_source(p[i].x+dirx[dir]*j, p[i].y+diry[dir]*j)){
		nmap[p[i].x+dirx[dir]*j][p[i].y+diry[dir]*j] = 2;
		j++;
	}
	connected[i] = true;
}

void disconnect(int i, int dir){
	int j = 1;
	while(!is_source(p[i].x+dirx[dir]*j, p[i].y+diry[dir]*j)){
		nmap[p[i].x+dirx[dir]*j][p[i].y+diry[dir]*j] = 0;
		j++;
	}
	connected[i] = false;
}


void combination_for(int num){
	if(num >= total_core){
		res_update();
		return ;
	}
	for(int i = num; i < total_core; i++){
		while(1){
			if(!connected[i]) break;
			i++;
			if(i >= total_core){
				res_update();
				return ;
			}
		}
		for(int j = 0; j < 4; j++){
			if(can_connect(i, j)){
				connect(i, j);
				combination_for(i+1);
				disconnect(i,j);
			}
		}
	}
}

void variable_clr(){
	last_core = 0;
	last_res = 0;
	total_core = 0;
	for(int j = 0 ; j < N; j++){
		for(int k = 0; k < N; k++){
			nmap[j][k] = 0;
		}	
	}
	
	N = 0;
	for(int j = 0 ; j < 12; j++){
		p[j].x = 0;
		p[j].y = 0;
		connected[j] = 0;
	}
}



int main(){
	int total_TC = 0;
	scanf("%d", &total_TC);
	for(int cur_TC = 1 ; cur_TC <= total_TC; cur_TC++){
		variable_clr();
		int cnt = 0;
		scanf("%d", &N);
		for(int y = 0 ; y < N ; y++ ){
			for(int x = 0; x < N; x++){
				scanf("%d", &nmap[x][y]);
				if(nmap[x][y] == 1) {
					total_core++;
					p[cnt].x = x;
					p[cnt].y = y;
					cnt++;
					if(x == 0 || y == 0 || x == N-1 || y == N-1){
						connected[total_core-1] = true;
					}
				}
			}
		}
		
		// 순서가 상관있는 조합식 사용이 맞으나 문제에서 요구하진 않나봄.... 사용하면 시간이 O((4^n)*4!)이네요....
		// 순서 상관없는 조합식 이용 (입력순)
		combination_for(0);

		printf("#%d %d\n", cur_TC, last_res);
	}

	

	return 0;
}
