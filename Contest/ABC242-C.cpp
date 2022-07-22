#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 1e6 + 5;

ll table[maxN][10];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	fill(table[0], table[n+1], 0);
	
	for(int x=1;x<=9;x++){
		table[1][x] = 1;
	}
	for(int x=1;x<n;x++){
		for(int y=1;y<=9;y++){
			if(y-1 > 0){
				table[x+1][y-1] += table[x][y];
				if(table[x+1][y-1] >= mod) table[x+1][y-1] -= mod;
			}
			if(y+1 < 10){
				table[x+1][y+1] += table[x][y];
				if(table[x+1][y+1] >= mod) table[x+1][y+1] -= mod;
			}
			
			table[x+1][y] += table[x][y];
			if(table[x+1][y] >= mod) table[x+1][y] -= mod;
		}
	}
	
	ll ans = 0;
	for(int x=1;x<=9;x++){
		ans += table[n][x];
		if(ans >= mod) ans -= mod;
	}
	cout << ans << "\n";
    return 0;
}

