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

const int maxN = 2 * 1e5;
ll table[maxN + 5];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<int, int> segs[k];
	for(us x=0;x<k;x++){
		cin >> segs[x].first >> segs[x].second;
	}
	
	sort(segs, segs+k);
	
	fill(table, table+n+1, 0);
	table[0] = 1; table[2] = -1;
	
	for(int x=1;x<=n;x++){
		table[x] += table[x-1];
		table[x] %= smod;
		for(int y=0;y<k;y++){
			int l = segs[y].first, r = segs[y].second;
			if(x+l <= n){
				table[x+l] += table[x];
				table[x+l] %= smod;
			}
			if(x+r+1 <= n){
				table[x+r+1] -= table[x];
				table[x+r+1] %= smod;
			}
		}	
//		for(int x=1;x<=n;x++) cout << table[x] << " ";
//		cout << "\n";
	}
	
	ll ans = table[n];
	while(ans < 0) ans += smod;
	while(ans >= smod) ans -= smod;
	
	cout << ans << "\n";
    return 0;
}

