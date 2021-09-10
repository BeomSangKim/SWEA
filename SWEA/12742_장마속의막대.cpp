#include <stdio.h>

int main() {
	int test_case, T;
	
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case){
	int result, x, a, b;
	scanf("%d %d",&a, &b);
	x = b - a - 1;
	result = ((x + 1) * x) / 2;
	printf("#%d %d\n", test_case, result);
	}
	return 0;
}
