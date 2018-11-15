#include <stdio.h>

int map[100][102] = {{0,}}; // isWall()함수 대신 102로 잡고 padding 생성
int stpx = 0;
int total_TC = 10, cur_TC = 0;


void datainput(){
   scanf("%d", &cur_TC);
    for(int j = 0; j < 100; j++){
        for(int k = 1; k < 101; k++){
            scanf("%1d", &map[j][k]);
            if(map[j][k] == 2){
                stpx = k;
            }
        } 
    }
}


void search(){
    for(int i = 98; i >= 0; i--){

        if(map[i][stpx+1] == 1){    // if~else문으로 양옆 search
            while(map[i][stpx+1] == 1){
                stpx = stpx+1;
            }
        }
        else while(map[i][stpx-1] == 1){
            stpx = stpx-1;
        }
    }
}

int main(){

    int ans = 0;
    for(int i = 1; i <= total_TC; i++){
        datainput();
        search();
        printf("#%d %d\n", cur_TC, stpx-1);
    }
    return 0;
}
