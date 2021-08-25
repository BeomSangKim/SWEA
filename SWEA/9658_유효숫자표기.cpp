#include <iostream>

using namespace std;

int main() {
	int total_case;
	cin >> total_case;

	for ( int cur_case = 1; cur_case <= total_case; cur_case++) {
		char string_integer[100000];
		char res[3];
		int idx;
		cin >> string_integer;
		for (int i = 0 ;; i++) {
			if (string_integer[i] == '\0') {
				idx = i;
				break;
			}
		}
		if (string_integer[2] >= '5') {
			res[1] = string_integer[1] + 1 > '9' ? '0' : string_integer[1] + 1;i
			res[0] = res[1] == '0' ? string_integer[0] + 1 : string_integer[0];
			if ( res[0] > '9' ) {
				res[0] = '1';
				res[1] = '0';
				idx ++;
			}

		}
		else {
			res[0] = string_integer[0];
			res[1] = string_integer[1];
		}
		cout << '#' << cur_case << ' ' << res[0] << '.' << res[1] << "*10^" << idx-1 << endl;
	}
	return 0;
}
