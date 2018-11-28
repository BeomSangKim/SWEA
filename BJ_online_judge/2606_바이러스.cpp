#include <iostream>
#include <queue>

using namespace std;


int main(){
	queue<int> go;
	int com[101][99] = {0,};
	bool visited[101] = {0,};
	int num, node, j, k;
	cin >> num >> node;
	for(int i = 0; i < node; i++){
		int input1, input2;
		cin >> input1 >> input2;
		j = 0, k = 0;
		for(; com[input1][j] != 0; j++){}
		com[input1][j] = input2;
		for(; com[input2][k] != 0; k++){}
		com[input2][k] = input1;
	}
	visited[1] = true; 
	for(int i = 0; com[1][i] != 0; i++){
		go.push(com[1][i]);
		visited[com[1][i]] = true; 
	}

	while(!go.empty()){
		queue<int> newgo;
		for(int i = 0; !go.empty(); i++){
			int next = go.front();
			go.pop();

			for(j = 0; com[next][j] != 0; j++){
				if(!visited[com[next][j]]){
					newgo.push(com[next][j]);
					visited[com[next][j]] = true; 
				}
			}

		}
		newgo.swap(go);
	}
	int cnt = 0;
	for(int i = 2; i <= num; i++){
		if(visited[i]) cnt++;
	}

	cout << cnt;
	return 0;
}
