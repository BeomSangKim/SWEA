#include <iostream>
#include <stack>
 
using namespace std;
 
int main(){
    stack<char> check;
    int N;
    char a;
    for(int cur_TC = 1; cur_TC <= 10; cur_TC++){
        cin >> N;
        int res = 0;
        char map[8][8] = {0,};
        for(int col = 0; col < 8; col++){    
            for(int row = 0; row < 8; row++)
                cin >> map[col][row];
        }
        //가로 확인
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8-N+1; j++){
                int k = 0;
                for(; k < N/2; k++){
                    check.push(map[i][j+k]);
                }
                bool ok = true;
                if(N%2){ // 홀수
                    k++;
                    for(; k < N; k++){
                        a = check.top();
                        check.pop();
                        if(a != map[i][j+k]){
                            ok = false;
                        };
                    }
                }
                else{ //짝수
                    for(; k < N; k++){
                        a = check.top();
                        check.pop();
                        if(a != map[i][j+k]){
                            ok = false;
                        };
                    }
                }
                if(ok == true) res++;
            }
        }
        //세로 확인
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8-N+1; j++){
                int k = 0;
                for(; k < N/2; k++){
                    check.push(map[j+k][i]);
                }
                bool ok = true;
                if(N%2){ // 홀수
                    k++;
                    for(; k < N; k++){
                        a = check.top();
                        check.pop();
                        if(a != map[j+k][i]){
                            ok = false;
                            break;
                        };
                    }
                }
                else{ //짝수
                    for(; k < N; k++){
                        a = check.top();
                        check.pop();
                        if(a != map[j+k][i]){
                            ok = false;
                            break;
                        };
                    }
                }
                if(ok == true) res++;
            }
        }
        cout << "#" << cur_TC << " " << res << "\n";
    }
 
    return 0;
}
