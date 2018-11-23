#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int box[100][100][100] = {0,};

struct point{
	int x;
	int y;
	int z;
};

int main(){

	int cur_start_num = 0, new_start_num = 0;

	int rows, cols, h, data, res = -1;

	std::queue<point> q;
	point point, input;

	int cnt = 0;

	scanf("%d %d %d", &rows, &cols, &h);



	for(int k = 0; k < h; k++){
		for(int i = 0; i < cols; i++){
			for(int j = 0; j < rows; j++){

				scanf("%d", &box[i][j][k]);
				if(box[i][j][k] == 1 || box[i][j][k] == -1){
					if(box[i][j][k] == 1){
						cur_start_num++;
						point.x = i;
						point.y = j;
						point.z = k;
						q.push(point);
					}
				}
			}
		}
	}

	while(!q.empty()){
		for(int i = 0; i < cur_start_num; i++){
			point = q.front();
			q.pop();
			for(int j = 0; j < 6; j++){
				int nx = point.x + dx[j];
				int ny = point.y + dy[j];
				int nz = point.z + dz[j];
				if(nx < cols && ny < rows && nz < h && nx >= 0 && ny >= 0 && nz >= 0){

					if(box[nx][ny][nz] == 0){
						box[nx][ny][nz] = 1;
						input.x = nx;
						input.y = ny;
						input.z = nz;
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
			for(int k = 0; k < h; k++){
				if(box[i][j][k] == 0) check = true;
			}
		}
	}
	if(check == true) res = -1;

	printf("%d", res);



	return 0;
}
