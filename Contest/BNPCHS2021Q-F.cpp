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
	
	int a[n][m], b[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> b[x][y];
		}
	}
	
	int ans = 0;
	int table[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			table[x][y] = (a[x][y]^b[x][y]);
			cout << table[x][y] << " ";
		}
		cout << "\n";
	}
	
	if(ans == 0){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}

