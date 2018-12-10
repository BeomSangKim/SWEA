#include <iostream>
using namespace std;
int map[66][66] = {0,};

void make_quadtree(int x, int y, int N){
	int first = map[y][x];
	for(int i  = y; i < y+N; i++){
		for(int j = x; j < x+N; j++){
			if(first != map[i][j]){
				cout << "(";
				make_quadtree(x,y,N/2);
				make_quadtree(x+N/2,y,N/2);
				make_quadtree(x,y+N/2,N/2);
				make_quadtree(x+N/2,y+N/2,N/2);
				cout << ")";
				return ;
			}
		}
	}
	cout << first;
}


int main(){
	int N;
	cin >> N;
	for(int i  = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	make_quadtree(0,0,N);
	
	return 0;
}
