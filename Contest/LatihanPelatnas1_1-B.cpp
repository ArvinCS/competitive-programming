#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

ll table[maxN];
ll backtrack[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	fill(table, table+maxN, 1e18);
	
	for(int x=0;x<=n;x++){
		table[x] = x+m;
		backtrack[x] = 1;
	}
	
	table[1] = 1;
	backtrack[1] = 0;
	
	ll ans = n;
	for(int x=1;x<=n;x++){
		for(int y=2;y*x<=n;y++){
			if(table[x*y] > table[x]+y+m){
				table[x*y] = table[x]+y+m;
				backtrack[x*y] = x;
			}
		}
		
		ans = min(ans, table[x]+(n+x-1)/x);
	}
	
	int cur = 512;
	for(int x=1;x<=n;x++){
		if(table[x]+(n+x-1)/x == ans){
			cur = x;
			while(cur > 0){
				cout << cur << " " << table[cur]+(n+cur-1)/cur << " -\n";
				cur = backtrack[cur];
			}
			cout << "--------\n";
		}
	}
	
	cout << ans << "\n";
    return 0;
}

