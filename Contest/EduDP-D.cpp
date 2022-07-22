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
	
	pair<ll, ll> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
	
	ll table[m+1][n+1];
	fill(table[0], table[m+1], -inf_ll);
	
	for(int x=0;x<=n;x++){
		table[0][x] = 0;
	}
	for(int x=0;x<=m;x++){
		table[x][0] = 0;
	}
	
	for(int x=0;x<n;x++){
		for(int y=1;y<=m;y++){			
			if(data[x].first <= y) table[y][x+1] = max(table[y][x], table[y-data[x].first][x] + data[x].second);
			else table[y][x+1] = table[y][x];
		}
	}
	cout << table[m][n] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

