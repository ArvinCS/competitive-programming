#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	array<ll, 3> w[n];
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			cin >> w[x][y];
		}
	}
	
	vector<array<ll, 3>> v[n];
	for(int x=0;x<n;x++){
		ll cur = w[x][0];
		ll cnt = k, cnt2 = 0;
		for(int y=x;y<n;y++){
			bool prv = (cur < w[y][0]);
			cur = max(cur, w[y][0]*1ll);
			ll need = max(0ll, w[y][2]-cnt+k-1)/k;
			
			if(cur+need <= w[y][1]){
				cnt = (k-(w[y][2]-cnt+k)%k)%k;
				cnt2 += need;
				cur += need;
				
				if(y+1 == n || cur < w[y+1][0]){
					v[x].push_back({y, cnt2*k, k-cnt});
				}
				continue;
			}
			
			break;
		}
	}
	
	ll table[n+1];
	fill(table, table+n+1, 1e18);
	
	table[n] = 0;
	for(int x=n-1;x>=0;x--){
		for(auto y : v[x]){
			table[x] = min(table[x], table[y[0]+1]+y[1]+(y[0]+1 < n ? k : y[2]));
		}
	}
	
	if(table[0] == 1e18) table[0] = -1;
	cout << table[0] << "\n";
    return 0;
}

