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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	bool grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == 'X');
		}
	}
	
	int prefix[m];
	prefix[0] = 0;
	for(int y=1;y<m;y++){
		prefix[y] = prefix[y-1];
		for(int x=1;x<n;x++){
			if(grid[x-1][y] && grid[x][y-1]){
				prefix[y]++;
				break;
			}
		}
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		int cnt = prefix[r] - prefix[l];
		
		if(cnt == 0){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
    return 0;
}

