#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int box[1000][1000] = {{0,},};

struct point{
	int x;
	int y;
};

int main(){
	
	int cur_start_num = 0, new_start_num = 0;
	
	int rows, cols, data, res = -1;

	std::queue<point> q;
	point point, input;

	int cnt = 0;

	scanf("%d%d", &rows, &cols);


	
	
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			scanf("%d", &box[i][j]);
			if(box[i][j] == 1 || box[i][j] == -1){
				if(box[i][j] == 1){
					cur_start_num++;
					point.x = i;
					point.y = j;
					q.push(point);
				}
			}
		}
	}
	
	while(!q.empty()){
		for(int i = 0; i < cur_start_num; i++){
			point = q.front();
			q.pop();
			for(int j = 0; j < 4; j++){
				int nx = point.x + dx[j];
				int ny = point.y + dy[j];
				if(nx < cols && ny < rows && nx >= 0 && ny >= 0){

					if(box[nx][ny] == 0){
						box[nx][ny] = 1;
						input.x = nx;
						input.y = ny;
						q.push(input);
						new_start_num++;
					}
				}
				
			}

		}
		cur_start_num = new_start_num;
		new_start_num = 0;
		res++;
	}

	bool check = false;

	for(int i = 0; i < cols; i++ ){
		for(int j = 0; j < rows; j++){
			if(box[i][j] == 0) check = true;
		}
	}
	if(check == true) res = -1;

	printf("%d", res);

	
	
	return 0;
}
