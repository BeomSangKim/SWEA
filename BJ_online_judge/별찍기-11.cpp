#include <iostream>
#include <deque>
using namespace std;

char star[4][7] = {"  *   "," * *  ","***** ","      "};
char enter = '\n';
char space = ' ';
deque<bool> cmd[3100];
int N;


void print_star(int a){

	for(int i = 0; i < N - 3*a -3; i++) cout << space;

	for(int i = 0; i < a+1; i++){
		if(cmd[a][i+1] == true)
			cout << star[0];
		else cout << star[3];
	}
	for(int i = 0; i < N - 3*a -3; i++) cout << space;
	cout << enter;
	for(int i = 0; i < N - 3*a -3; i++) cout << space;
	for(int i = 0; i < a+1; i++){
		if(cmd[a][i+1] == true)
			cout << star[1];
		else cout << star[3];
	}
	for(int i = 0; i < N - 3*a -3; i++) cout << space;
	cout << enter;
	for(int i = 0; i < N - 3*a -3; i++) cout << space;
	for(int i = 0; i < a+1; i++){
		if(cmd[a][i+1] == true)
			cout << star[2];
		else cout << star[3];
	}
	for(int i = 0; i < N - 3*a -3; i++) cout << space;
	cout << enter;
}

void make_cmd(int N){
	for(int i = 0; i < N; i++){
		if(i == 0) cmd[i].push_back(false), cmd[i].push_back(true), cmd[i].push_back(false);
		else{
			cmd[i].push_back(false);
			for(int j = 0; j <= i; j++){
				bool right_up, left_up;
				left_up = cmd[i-1][j];
				right_up = cmd[i-1][j+1];
				cmd[i].push_back(right_up!=left_up);
			}
			cmd[i].push_back(false);
		}
	}
}



int main(){
	cin.tie();
	ios::sync_with_stdio(false);
	std::cin >> N;

	make_cmd(N/3);

	for(int i = 0; i < N/3; i++){
		print_star(i);
	}


	return 0;
}
