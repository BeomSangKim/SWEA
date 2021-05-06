#include <iostream>
#include <functional>
#include <algorithm>
#include <list>

int pow(int a, int b){
	int res = 1;
	for(int i = 0; i < b; i++){
		res *= a;
	}
	return res;
}


using namespace std;
int main(){
	int total_TC;
	cin >> total_TC;

	for(int cur_TC = 1; cur_TC <= total_TC; cur_TC++){
		list<char> input;
		list<long long> num;
		int N, n, k;
		
		cin >> N >> k;
		n = N/4;

		for(int i = 0; i < N; i++){
			char num1;
			cin >> num1;
			input.push_back(num1);
		}

		list<char>::iterator iter;
		list<long long>::iterator iter2;
		for(int i = 0; i < N; i++){
			long long integer = 0;
			for(int j = 0; j < n; j++){
				iter = input.begin();
				for(int k = 0; k < (i+j)%N; k++) iter++;
				if(*iter <= '9' && *iter >= '0')
					integer += (*iter - 0x30) * (pow(16, n-1-j));
				else
					integer += (*iter - 'A' + 10) * (pow(16, n-1-j));
			}
			bool ok = true;
			iter2 = num.begin();
			for(int j = 0; j < num.size(); j++){
				if(*iter2 == integer) ok = false;
				iter2++;
			}
			if(ok == true)	num.push_back(integer);
		}
		num.sort(greater<long long>());
		iter2 = num.begin();

		for(int i = 0; i < k-1; i++) iter2++;
		int res = *iter2;
		cout << "#" << cur_TC << " " << res << "\n";
	}


	return 0;
}
