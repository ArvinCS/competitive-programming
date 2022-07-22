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

int n, m;
vector<pair<int, int>> v[25];

ll table[1 << 18];
ll solve(int idx, ll mask){
	if(idx > n){
		return 1ll;
	}
	if(table[mask] >= 0) return table[mask];
	
	int cnt[20];
	cnt[0] = ((mask&1) > 0);
	for(int x=1;x<n;x++){
		cnt[x] = ((mask&(1<<x)) > 0) + cnt[x-1];
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if((mask&(1ll<<x))) continue;
		
		bool valid = true;
		for(auto p : v[idx]){
			if((cnt[p.first-1]+(p.first >= (x+1) ? 1 : 0)) > p.second){
				valid = false;
				break;
			}
		}
		if(valid){
			ans += solve(idx+1, mask|(1ll << x));
		}
	}
	return table[mask] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		v[a].push_back({b, c});
	}
	
	fill(table, table+(1<<18), -1);
	cout << solve(1, 0) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

