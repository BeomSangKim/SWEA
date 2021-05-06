#include <iostream>
#include <queue>

int abs(int x){
	return x = x > 0 ? x:-x;
}

using namespace std;

typedef int DIR;

typedef struct person{
	int x,y,charged;

}person;

queue<DIR> q[2]; // 0 = person A, 1 = person B
person A, B;

int dirx[5] = {0, 0, 1, 0, -1};
int diry[5] = {0, -1, 0, 1, 0};
int mid_res, final_res = 0, select_A, select_B;
int map[10][10][8] = {0,};

void clr(){
	for(int i = 0 ; i < 10 ; i ++ )
		for(int j = 0 ; j < 10 ; j ++ )
			for(int k = 0; k < 8; k++) map[i][j][k] = 0;
}


int main(){

	int total_TC, time, NumOfBC;
	int dir, res;
	
	cin >> total_TC;
	for(int cur_TC = 1; cur_TC <=total_TC; cur_TC++){
		// value_clr
		A.x = 0, A.y = 0, A.charged = 0;
		B.x = 9, B.y = 9, B.charged = 0;
		clr();
		
		cin >> time >> NumOfBC;
		for(int i = 0; i < time ; i++){
			cin >> dir;
			q[0].push(dir);
		}
		for(int i = 0; i < time ; i++){
			cin >> dir;
			q[1].push(dir);
		}
		for(int i = 0; i < NumOfBC; i++){
			int x,y,range,perform;
			cin >> x >> y >> range >> perform;
			for(int j = -range; j <= range; j++){
				for(int k = -range; k <= range; k++){
					if( abs(j)+abs(k) <= range && x-1+j >= 0 && y-1+k >= 0 && x-1+j < 10 && y-1+k < 10) map[x-1+j][y-1+k][i] = perform;
				}
			}
		}

		for(int i = 0; i < time; i++){
			final_res = 0;
			for(int j = 0; j < NumOfBC; j++){
				mid_res = 0;
				mid_res += map[A.x][A.y][j];
				for(int k = 0; k < NumOfBC; k++){
					mid_res += map[B.x][B.y][k];
					if(final_res <= mid_res && j != k){
						final_res = mid_res;
						select_A = j, select_B = k;
					}
					mid_res -= map[B.x][B.y][k];
				}
			}
			A.charged += map[A.x][A.y][select_A];
			B.charged += map[B.x][B.y][select_B];
			DIR d;
			d = q[0].front() , q[0].pop();
			A.x += dirx[d], A.y += diry[d];
			d = q[1].front() , q[1].pop();
			B.x += dirx[d], B.y += diry[d];
		}
		final_res = 0;
		for(int j = 0; j < NumOfBC; j++){
			mid_res = 0;
			mid_res += map[A.x][A.y][j];
			for(int k = 0; k < NumOfBC; k++){
				mid_res += map[B.x][B.y][k];
				if(final_res <= mid_res && j != k){
					final_res = mid_res;
					select_A = j, select_B = k;
				}
				mid_res -= map[B.x][B.y][k];
			}
		}
		A.charged += map[A.x][A.y][select_A];
		B.charged += map[B.x][B.y][select_B];


		res = A.charged + B.charged;
		cout << "#" << cur_TC << " " << res << endl;
	}

	return 0;
}
