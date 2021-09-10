#include <stdio.h>

int main(){

	int test_case, T;
	scanf("%d", &T);;
	int result, A, B, C, D;
	for(test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d %d %d", &A, &B, &C, &D);
		if( C < B && C >= A ) 
			if( D >= B ) result = B - C;
			else result = D - C;
		else if( A <= D && A > C) 
			if ( B >= D ) result = D - A;
			else result = B - A;
		else result = 0;
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}
