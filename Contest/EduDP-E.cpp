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

const int sumV = 1e6 + 5;

ll table[sumV][105];

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
	
	fill(table[0], table[sumV], inf_ll);
	for(int x=0;x<105;x++){
		table[0][x] = 0;
	}
	
	int ans = 0;
	for(int x=1;x<sumV;x++){
		for(int y=0;y<n;y++){
			
			if(data[y].second <= x) table[x][y+1] = min(table[x][y], table[x-data[y].second][y] + data[y].first);
			else table[x][y+1] = table[x][y];
			
			if(table[x][y+1] <= m){
				ans = max(ans, x);
			}
		}
	}
	
//	for(int x=1;x<=sumV;x++){
//		for(int y=0;y<n;y++) cout << table[x][y+1] << " ";
//		cout << "\n";
//	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

