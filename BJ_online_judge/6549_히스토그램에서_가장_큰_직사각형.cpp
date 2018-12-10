#include <iostream>
#include <vector>

#define max(x,y) x > y ? x : y
#define min(x,y) x < y ? x : y
using namespace std;
vector<long long> h;

long long solve(int left, int right){
	if(left == right) return h[left];

	int mid = (left + right)/2;

	long long res = max(solve(left, mid), solve(mid+1, right));

	int lo = mid, hi = mid+1;
	long long height = min(h[lo], h[hi]);

	res = max(res, height*2);

	while(left < lo || hi < right){
		if(hi < right && (lo == left || h[lo-1] < h[hi+1])){
			++hi;
			height = min(height, h[hi]);
		}
		else{
			--lo;
			height = min(height, h[lo]);
		}

		res = max(res, height*(hi - lo +1));

	}
	return res;

}

int main(){
	int N,x;
	while(1){
		cin >> N;
		if(N == 0) break;
		for(int i = 0; i < N; i++){
			cin >> x;
			h.push_back(x);
		}
		cout << solve(0, N-1) << "\n";

		h.clear();
	}

	
	return 0;
}
