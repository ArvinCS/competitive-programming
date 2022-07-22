#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		short n, m;
		cin >> n >> m;
		
		int table[n][m];
		char data[n][m];
		for(short x=0;x<n;x++){
			for(short y=0;y<m;y++){
				cin >> data[x][y];
				if(data[x][y] == '.'){
					table[x][y] = 0;
				} else {
					table[x][y] = 1;
				}
			}
		}
		
		int ans = 0;
		for(short x=0;x<n-1;x++){
			for(short y=1;y<m-1;y++){				
				if(data[x][y] == '*' && data[x][y] == data[x+1][y-1] && data[x][y] == data[x+1][y+1] && data[x][y] == data[x+1][y]){
					table[x+1][y+1] = min(table[x][y], min(table[x+1][y-1], table[x+1][y])) + 1;
				}
			}
		}
		
		for(short x=0;x<n;x++){
			for(short y=0;y<m;y++){
//				cout << table[x][y];
				ans += table[x][y];
			}
//			cout << "\n";
		}
		cout << ans << "\n";
	}
	
    return 0;
}

