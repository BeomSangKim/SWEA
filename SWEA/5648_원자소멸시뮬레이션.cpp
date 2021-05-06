#include <stdio.h>

#define CANT_MEET 2002 // 대각선 꼭지점에서 만날경우 최대 2001 

typedef struct atom{
	float X, Y;
	int D, K;
	bool alive;
}atom;

int res = 0;
atom a[1000];

float dirx[4] = {0, 0, -1, 1};
float diry[4] = {1, -1, 0, 0};

int x_table[2001] = {0,};

float abs(float x){ // g++ math.h에 abs가 없단다.... 
	if(x > 0)
		return x;
	return -x;
}


float when_meet(atom a1, atom a2){ // 만날 수 있는 모든 경우의 수를 포함한다.
	if(a1.alive == false || a2.alive ==false || a1.D == a2.D) return CANT_MEET;

	if(a1.D == 2 && a2.D == 0){		
		if(abs(a1.X - a2.X) == abs(a2.Y - a1.Y))
			return abs(a1.X - a2.X);
	}
	else if(a1.D == 0 && a2.D == 2){		
		if(abs(a1.X - a2.X) == abs(a2.Y - a1.Y))
			return abs(a1.X - a2.X);
	}
	else if(a1.D == 3 && a2.D == 2){
		if(a1.Y == a2.Y)
			return abs((a2.X - a1.X)/2.0);
	}
	else if(a1.D == 2 && a2.D == 3){
		if(a1.Y == a2.Y)
			return abs((a2.X - a1.X)/2.0);
	}
	else if(a1.D == 3 && a2.D == 0){
		if(abs(a2.X - a1.X) == abs(a1.Y - a2.Y))
			return abs(a2.X - a1.X);
	}
	else if(a1.D == 0 && a2.D == 3){
		if(abs(a2.X - a1.X) == abs(a1.Y - a2.Y))
			return abs(a2.X - a1.X);
	}
	else if(a1.D == 1 && a2.D == 0){
		if(a1.X == a2.X)
			return abs((a2.Y - a1.Y)/2.0);
	}
	else if(a1.D == 0 && a2.D == 1){
		if(a1.X == a2.X)
			return abs((a2.Y - a1.Y)/2.0);
	}
	else if(a1.D == 1 && a2.D == 2){
		if(abs(a2.X - a1.X) == abs(a2.Y - a1.Y))
			return abs(a2.X - a1.X);
	}
	else if(a1.D == 2 && a2.D == 1){
		if(abs(a2.X - a1.X) == abs(a2.Y - a1.Y))
			return abs(a2.X - a1.X);
	}
	else if(a1.D == 1 && a2.D == 3){
		if(abs(a1.X - a2.X) == abs(a2.Y - a1.Y))
			return abs(a1.X - a2.X);
	}
	else if(a1.D == 3 && a2.D == 1){
		if(abs(a1.X - a2.X) == abs(a2.Y - a1.Y))
			return abs(a1.X - a2.X);
	}
	return CANT_MEET;
}


int main(){
	int total_TC, N;
	float x, y, d, k;

	scanf("%d", &total_TC);

	for(int cur_TC = 1; cur_TC <= total_TC; cur_TC++){
		res = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%f %f %f %f", &x, &y, &d, &k);
			a[i].alive = true;
			a[i].D = (int)d;
			a[i].X = x;
			a[i].Y = y;
			a[i].K = (int)k;
		}
		float t;
		while(1){
			t = CANT_MEET;
			for(int i = 0; i < N; i++){
				if(a[i].alive ==false) continue;
				for(int j = i+1; j < N; j++){
					if(a[j].alive == false) continue;
					float nt = when_meet(a[i], a[j]);
					t = nt < t ? nt : t;  // 먼저만나는 순으로 폭발 시키기위해 시간이 적을 수록 ㄱㄱ
				}
			}
			if(t == CANT_MEET) break; // 더이상 만날 원자가 없을경우 탈출
			for(int i = 0; i < N; i++){
				if(a[i].alive == false) continue; // 죽은 원소는 착하다 계산을 하지 않아도 된다
				a[i].X = a[i].X + t * dirx[a[i].D];
				a[i].Y = a[i].Y + t * diry[a[i].D];
				if(a[i].X > 1000 || a[i].Y > 1000 ||a[i].X < -1000 || a[i].Y < -1000) 
					a[i].alive = false; // 어처피 맵밖에선 만날 일이없다.
			}
			for(int i = 0; i < N; i++){
				if(a[i].alive == false) continue; // 죽었다 굳이 계산하지 말고 다음 으로
				int count = 0;
				for(int j = i+1; j < N; j++){
					if(a[i].X == a[j].X){
						if(a[j].alive == false) continue;
						if(a[i].Y == a[j].Y){
							if(count == 0){
								res = res + a[i].K + a[j].K;
								a[i].alive = false;
								a[j].alive = false;
								count++;  // 2개 만나면 2개 더해야하지만 3개 이상일경우 추가된 경우만 폭발
							}
							else{
								res = res + a[j].K; // 위 주석과 동일
								a[j].alive = false; 
							}
						}
					}
				}
			}
		}
		printf("#%d %d\n", cur_TC, res);
	}
	return 0;
}
