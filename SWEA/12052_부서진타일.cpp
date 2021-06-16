#include <iostream>

using namespace std;

int main() {
        int total_tc,m,n,cnt,res  = 0;
    
        char tile[51][51] = {0,};
    
        cin >> total_tc;
        for ( int cur_tc = 1; cur_tc <= total_tc; cur_tc++) {
                cin >> n >> m;
                cnt = 0;
                res = 0;
                for (int i = 0 ; i < n ; i++) {
                        for( int j = 0 ; j < m; j++) {
                                cin >> tile[i][j];
                                if(tile[i][j] == '#') cnt++;
                        }
                }
                if (cnt%4 != 0) {
                        res = 1;
                }
                else {
                        for (int i = 0 ; i < n ; i++) {
                                for( int j = 0 ; j < m; j++) {
                                        if( tile[i][j] == '#') 
                                        	if ( tile[i][j+1] != '#' || tile[i+1][j] != '#' || tile[i+1][j+1] != '#') {
                                                	i = n+1, j = m+1;
                                                	res = 1;
                                        	}
                                        else
                                                tile[i][j] = '.', tile[i][j+1] = '.', tile[i+1][j] = '.', tile[i+1][j+1] = '.';
                                }
                        }
                }
                if (res == 0) cout << "#" << cur_tc << " YES" << endl;
                else cout << "#" << cur_tc << " NO" << endl;

        }
        return 0;

}
