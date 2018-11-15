#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
 
int node[100][2] = {0,};
bool visited[100] = {0,};
queue<int> q;
int res = 0;
int cnt = 0;
 
void inputdata(int *tc){  
    int num_of_node;
    int src, dst;
    scanf("%d %d", tc, &num_of_node);
    for(int i = 0 ; i < num_of_node; i++){  
        scanf("%d %d", &src, &dst);
        if(node[src][0] == 0) node[src][0] = dst;
        else node[src][1] = dst;
    }
}
 
void push(int i){
     
    if(node[i][0] != 0 && visited[i] == false){
        q.push(node[i][0]);
        visited[i] = true;
        if(node[i][1] != 0){
            q.push(node[i][1]);
        }
    }
}
 
void search(){
    cnt = 0;
    res = false;
    push(0);
    while(!q.empty() && cnt != 99 && res != 1){
        cnt++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            int a = q.front();
            if(a == 99){
                res = 1;
                break;
            } 
            q.pop();
            push(a);
        }
    }
}
 
int main(){
     
    int tc = 0;
 
    while(tc != 10){
        inputdata(&tc);
 
        search();
        while(!q.empty()){
            q.pop();
        }
        for(int i = 0 ; i < 100; i++)
        memset(node[i], 0, 2*sizeof(int));
        memset(visited, 0, 100*sizeof(bool));
        printf("#%d %d\n", tc, res);
    }
    
 
    return 0;
}