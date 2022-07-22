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
		int n;
		cin >> n;
		
		int a[n][n], b[n][n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				char tmp;
				cin >> tmp;
				
				a[x][y] = (tmp - '0');
			}
		}
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				char tmp;
				cin >> tmp;
				
				b[x][y] = (tmp - '0');
			}
		}
		
		for(int x=0;x<n;x++){
			if(a[x][0] != b[x][0]){
				for(int y=0;y<n;y++) a[x][y] = (a[x][y]+1)%2;	
			}
		}
		
		for(int x=0;x<n;x++){
			if(a[0][x] != b[0][x]){
				for(int y=0;y<n;y++) a[y][x] = (a[y][x]+1)%2;	
			}
		}
		
		bool possible = true;
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(a[x][y] != b[x][y]){
					possible = false;
					break;
				}
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

